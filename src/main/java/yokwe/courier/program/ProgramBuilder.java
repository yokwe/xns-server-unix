/*******************************************************************************
 * Copyright (c) 2026, Yasuhiro Hasegawa
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *******************************************************************************/

package yokwe.courier.program;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;

import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.CharStreams;
import org.antlr.v4.runtime.CommonTokenStream;

import yokwe.courier.antlr.CourierLexer;
import yokwe.courier.antlr.CourierParser;
import yokwe.courier.program.Program.Decl;
import yokwe.courier.program.Program.Info;
import yokwe.courier.program.Program.NameCons;
import yokwe.courier.program.Program.NameNumericValue;
import yokwe.courier.program.Program.NameType;
import yokwe.courier.program.Program.NumericValue;
import yokwe.courier.program.Program.Reference;
import yokwe.util.UnexpectedException;

public class ProgramBuilder {
	private static final org.slf4j.Logger logger = yokwe.util.LoggerUtil.getLogger();
	
	private static String COURIER_FILE_SUFFIX = ".cr";
	
	public static void scanDirectory(String pathString) {
		scanDirectory(Paths.get(pathString));
	}
	public static void scanDirectory(Path path) {
		logger.info("path  {}", path.toString());
		if (!Files.exists(path)) {
			logger.error("path does not exist");
			throw new UnexpectedException("Unepxepcted");
		}
		if (!Files.isDirectory(path)) {
			logger.error("path is not directory");
			throw new UnexpectedException("Unepxepcted");
		}
		
		try {
			var filePathList = Files.list(path).filter(o -> o.toString().endsWith(COURIER_FILE_SUFFIX)).collect(Collectors.toList());
			Collections.sort(filePathList);
			
			for(var filePath: filePathList) {
				logger.info("filePath  {}", filePath.toString());
				
				var tree    = getTree(filePath);
				var builder = new ProgramBuilder();
				
				var program = builder.buildProgram(tree);
			}
		} catch (IOException e) {
			String exceptionName = e.getClass().getSimpleName();
			logger.error("{} {}", exceptionName, e);
			throw new UnexpectedException(exceptionName, e);
		}
		
	}
	
	private static CourierParser.CourierProgramContext getTree(Path path) throws IOException{
		CharStream        stream  = CharStreams.fromPath(path);
		CourierLexer      lexer   = new CourierLexer(stream);
		CommonTokenStream tokens  = new CommonTokenStream(lexer);
		CourierParser     parser  = new CourierParser(tokens);
		
		return parser.courierProgram();
	}
	
	
	public Program buildProgram(CourierParser.CourierProgramContext tree) {
		Program program = toProgram(tree);
		program.addDepend(toDependencyList(tree));
		program.addDecl(toDeclList(program, tree));
		
		return program;
	}
	private static Program toProgram(CourierParser.CourierProgramContext tree) {
		var header = tree.programHeader();
		
		var name    = header.name.getText();
		var program = (int)Util.parseLong(header.program.getText());
		var version = (int)Util.parseLong(header.version.getText());
		
		return new Program(new Info(name, program, version));
	}
	private List<Info> toDependencyList(CourierParser.CourierProgramContext tree) {
		var ret = new ArrayList<Info>();
		
		var list = tree.programBody().dependencyList().referencedProgramList();
		if (list == null) return ret;
		
		for(var e: list.elements) {
			var name    = e.name.getText();
			var program = (int)Util.parseLong(e.program.getText());
			var version = (int)Util.parseLong(e.version.getText());
			
			ret.add(new Info(name, program, version));
		}
		return Collections.unmodifiableList(ret);
	}
	//
	// Decl
	//
	private static List<Decl> toDeclList(Program myProgram, CourierParser.CourierProgramContext tree) {
		var ret = new ArrayList<Decl>();
		
		var list = tree.programBody().declarationList();
		if (list == null) return ret;
		for(var e: list.elements) {
			Decl decl = switch(e) {
				case CourierParser.DeclTypeContext ut -> toDecl(myProgram, ut);
				case CourierParser.DeclConsContext ut -> toDecl(myProgram, ut);
				default -> throw new UnexpectedException("Unexpected");
			};
			logger.info("DECL  {}", decl.toString());
			ret.add(decl);
		}
		
		return Collections.unmodifiableList(ret);
	}
	//
	// DeclTyp
	//
	private static Decl toDecl(Program myProgram, CourierParser.DeclTypeContext context) {
		var name = context.name.getText();
		var type = toType(myProgram, context.type());
		
		return new Decl(name, type);
	}
	//
	// Type
	//
	private static Type toType(Program myProgram, CourierParser.TypeContext type) {
		return switch(type) {
			case CourierParser.TypePredefinedContext  ut -> toType(ut.predefinedType());
			case CourierParser.TypeConstructedContext ut -> toType(myProgram, ut.constructedType());
			case CourierParser.TypeReferencedContext  ut -> toType(myProgram, ut.referenced());
			default -> throw new UnexpectedException("Unexpected");
		};
	}
	// Predefined
	private static Type toType(CourierParser.PredefinedTypeContext context) {
		return switch(context) {
			case CourierParser.TypeBooleanContext      ut -> Type.BOOLEAN;
			case CourierParser.TypeCardinalContext     ut -> Type.CARDINAL;
			case CourierParser.TypeLongCardinalContext ut -> Type.LONG_CARDINAL;
			case CourierParser.TypeIntegerContext      ut -> Type.INTEGER;
			case CourierParser.TypeLongIntegerContext  ut -> Type.LONG_INTEGER;
			case CourierParser.TypeStringContext       ut -> Type.STRING;
			case CourierParser.TypeUnspecifiedContext  ut -> Type.UNSPECIFIED;
			default -> throw new UnexpectedException("Unexpected");
		};
	}
	// Constructed
	private static Type toType(Program myProgram, CourierParser.ConstructedTypeContext context) {
		return switch(context) {
			case CourierParser.TypeEnumContext        ut -> toType(myProgram, ut);
			case CourierParser.TypeArrayContext       ut -> toType(myProgram, ut);
			case CourierParser.TypeSequenceContext    ut -> toType(myProgram, ut);
			case CourierParser.TypeRecordContext      ut -> toType(myProgram, ut);
			case CourierParser.TypeRecordEmptyContext ut -> toType(myProgram, ut);
			case CourierParser.TypeChoiceTypedContext ut -> toType(myProgram, ut);
			case CourierParser.TypeChoiceAnonContext  ut -> toType(myProgram, ut);
			case CourierParser.TypeProcedureContext   ut -> toType(myProgram, ut);
			case CourierParser.TypeErrorContext       ut -> toType(myProgram, ut);
			default -> throw new UnexpectedException("Unexpected");
		};
	}
	// Enum
	// NumericValue
	private static NumericValue toNumericValue(Program myProgram, CourierParser.NumericValueContext context) {
		return switch(context) {
			case CourierParser.ValueNumberContext  ut -> {
				var value = (int)Util.parseLong(ut.NUMBER().getText());
				yield new NumericValue(value);
			}
			case CourierParser.ValueRefConsContext ut -> {
				var value = toReference(myProgram, ut.referenced());
				yield new NumericValue(value);
			}
			default -> throw new UnexpectedException("Unexpected");
		};
	}
	private static Type toType(Program myProgram, CourierParser.TypeEnumContext context) {
		var list = toCorrespondenceList(myProgram, context.correspondenceList());
		return new TypeEnum(list);
	}
	private static List<NameNumericValue> toCorrespondenceList(Program myProgram, CourierParser.CorrespondenceListContext context) {
		var ret = new ArrayList<NameNumericValue>();
		for(var e: context.elements) {
			var name  = e.name.getText();
			var value = toNumericValue(myProgram, e.value);
			ret.add(new NameNumericValue(name, value));
		}
		return Collections.unmodifiableList(ret);
	}
	// Array
	private static Type toType(Program myProgram, CourierParser.TypeArrayContext context) {
		var size   = toNumericValue(myProgram, context.numericValue());
		var element = toType(myProgram, context.type());
		return new TypeArray(size, element);
	}
	// Sequence
	private static final NumericValue MAX_SIZE = new NumericValue(TypeSequence.MAX_SIZE);
	private static Type toType(Program myProgram, CourierParser.TypeSequenceContext context) {
		var numericValue = context.maximumNumber().numericValue();
		var size          = numericValue == null ? MAX_SIZE : toNumericValue(myProgram, numericValue);
		var element       = toType(myProgram, context.type());
		return new TypeSequence(size, element);
	}
	// Record
	private static Type toType(Program myProgram, CourierParser.TypeRecordContext context) {
		var fieldList = toFieldList(myProgram, context.fieldList());
		return new TypeRecord(fieldList);
	}
	private static List<NameType> toFieldList(Program myProgram, CourierParser.FieldListContext context) {
		var ret = new ArrayList<NameType>();
		if (context == null) return ret;
		
		for(var e: context.elements) {
			var nameList = toStringList(e.nameList());
			var type     = toType(myProgram, e.type());
			
			// expand nameList
			for(var name: nameList) {
				ret.add(new NameType(name, type));
			}
		}
		return ret;
	}
	private static List<String> toStringList(CourierParser.NameListContext context) {
		var ret = new ArrayList<String>();
		if (context == null) return ret;
		
		for(var e: context.elements) {
			ret.add(e.getText());
		}
		return ret;
	}
	// RecordEmpty
	private static Type toType(Program myProgram, CourierParser.TypeRecordEmptyContext context) {
		return TypeRecord.EMPTY;
	}
	// ChoiceTyped
	private static Type toType(Program myProgram, CourierParser.TypeChoiceTypedContext context) {
		var referenced    = toReference(myProgram, context.referenced());
		var candidateList = new ArrayList<NameType>();
		
		for(var e: context.typedCandidateList().elements) {
			var type = toType(myProgram, e.type());
			for(var ee: e.nameList().elements) {
				var name = ee.getText();
				candidateList.add(new NameType(name, type));
			}
		}
		
		return new TypeChoice.Typed(referenced, candidateList);
	}
	// ChoideAnon
	private static Type toType(Program myProgram, CourierParser.TypeChoiceAnonContext context) {
		// CHOICE OF '{' anonCandidateList '}' 
		var candidateList = new ArrayList<NameType>();
		var designator = new ArrayList<NameNumericValue>();
		
		for(var e: context.anonCandidateList().elements) {
			var type = toType(myProgram, e.type());
			var nameNumericValuelist = toCorrespondenceList(myProgram, e.correspondenceList());
			for(var ee: nameNumericValuelist) {
				var name  = ee.name;
				var value = ee.value;
				
				candidateList.add(new NameType(name, type));
				designator.add(new NameNumericValue(name, value));
			}
		}
		return new TypeChoice.Anon(new TypeEnum(designator), candidateList);
	}
	// Procedure
	private static Type toType(Program myProgram, CourierParser.TypeProcedureContext context) {
		var argumentList = toFieldList(myProgram, context.argumentList().fieldList());
		var resultList   = toFieldList(myProgram, context.resultList().fieldList());
		var errorList    = toStringList(context.errorList().nameList());
		
		return new TypeProcedure(argumentList, resultList, errorList);
	}
	// Error
	private static Type toType(Program myProgram, CourierParser.TypeErrorContext context) {
		var argumentList = toFieldList(myProgram, context.argumentList().fieldList());
		
		return new TypeError(argumentList);
	}
	
	// Reference
	private static Reference toReference(Program myProgram, CourierParser.ReferencedContext context) {
		return switch (context) {
			case CourierParser.TypeRefContext ut -> {
				var refName = ut.name.getText();
				yield new Reference(myProgram, refName);
			}
			case CourierParser.TypeRefQContext ut -> {
				var refProgram = ut.program.getText();
				var refName    = ut.name.getText();
				yield new Reference(myProgram, refProgram, refName);
			}
			case CourierParser.TypeRefExtContext ut -> {
				var refNamespace = ut.namespace.getText();
				var refName      = ut.name.getText();
				yield new Reference(myProgram, refNamespace, refName);
			}
			default -> throw new UnexpectedException("Unexpected");
		};
	}
	private static Type toType(Program myProgram, CourierParser.ReferencedContext context) {
		var reference = toReference(myProgram, context);
		return new TypeReference(reference);
	}
	//
	// DeclCons
	//
	private static Decl toDecl(Program myProgram, CourierParser.DeclConsContext context) {
		var name = context.name.getText();
		var type = toType(myProgram, context.type());
		var cons = toCons(myProgram, context.constant());
		return new Decl(name, type, cons);
	}
	// Cons
	private static Cons toCons(Program myProgram, CourierParser.ConstantContext context) {
		return switch(context) {
			case CourierParser.ConsLiteralContext     ut -> toCons(ut);
			case CourierParser.ConsConstructedContext ut -> toCons(myProgram, ut);
			case CourierParser.ConsRefContext         ut -> toCons(myProgram, ut);
			default -> throw new UnexpectedException("Unexpected");
		};
	}
	// ConsLiteral
	private static Cons toCons(CourierParser.ConsLiteralContext context) {
		var literalConstant = context.literalConstant();
		return switch (literalConstant) {
			case CourierParser.ConsTrueContext           ut -> Cons.TRUE;
			case CourierParser.ConsFalseContext          ut -> Cons.TRUE;
			case CourierParser.ConsNumberContext         ut -> new Cons.NUMBER(ut.value.getText());
			case CourierParser.ConsNumberNegativeContext ut -> new Cons.NUMBER("-" + ut.value.getText());
			case CourierParser.ConsStringContext         ut -> new Cons.STRING(ut.value.getText());
			default -> throw new UnexpectedException("Unexpected");
		};
	}
	// ConsConstructed
	private static Cons toCons(Program myProgram, CourierParser.ConsConstructedContext context) {
		var constructedConstant = context.constructedConstant();
		return switch(constructedConstant) {
			case CourierParser.ConsArrayContext       ut -> toCons(myProgram, ut);
			case CourierParser.ConsRecordContext      ut -> toCons(myProgram, ut);
			case CourierParser.ConsRecordEmptyContext ut -> toCons(ut);
			case CourierParser.ConsChoiceContext      ut -> toCons(myProgram, ut);
			default -> throw new UnexpectedException("Unexpected");
		};
	}
	// ConsArray
	private static Cons toCons(Program myProgram, CourierParser.ConsArrayContext context) {
		var constList = new ArrayList<Cons>();
		for(var e: context.elementList().elements) {
			constList.add(toCons(myProgram, e));
		}
		return new ConsArray(constList);
	}
	// ConsRecord
	private static Cons toCons(Program myProgram, CourierParser.ConsRecordContext context) {
		// '[' componentList ']' # ConsRecord
		var nameConsList = new ArrayList<NameCons>();
		
		for(var e: context.componentList().elements) {
			var cons = toCons(myProgram, e.constant());
			for(var ee: e.nameList().elements) {
				var name = ee.getText();
				
				nameConsList.add(new NameCons(name, cons));
			}
		}
		return new ConsRecord(nameConsList);
	}
	// ConsRecordEmpty
	private static Cons toCons(CourierParser.ConsRecordEmptyContext context) {
		return ConsRecord.EMPTY;
	}
	// ConsChoice
	private static Cons toCons(Program myProgram, CourierParser.ConsChoiceContext context) {
		var name = context.name.getText();
		var cons = toCons(myProgram, context.constant());
		return new ConsChoice(name, cons);
	}
	// ConsRef
	private static Cons toCons(Program myProgram, CourierParser.ConsRefContext context) {
		var ref = toReference(myProgram, context.referenced());
		return new ConsRef(ref);
	}
}
