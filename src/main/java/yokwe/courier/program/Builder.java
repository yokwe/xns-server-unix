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
import java.util.Map;
import java.util.TreeMap;
import java.util.stream.Collectors;

import org.antlr.v4.runtime.CharStreams;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.Token;

import yokwe.courier.antlr.CourierLexer;
import yokwe.courier.antlr.CourierParser;
import yokwe.courier.program.Program.Decl;
import yokwe.courier.program.Program.Info;
import yokwe.courier.program.Program.NameCons;
import yokwe.courier.program.Program.NameType;
import yokwe.courier.program.Program.NumberName;
import yokwe.courier.program.TypeChoice.CandidateName;
import yokwe.courier.util.Util;
import yokwe.util.UnexpectedException;

public class Builder {
	private static final org.slf4j.Logger logger = yokwe.util.LoggerUtil.getLogger();

	public static String COURIER_FILE_SUFFIX = ".cr";

	public Map<Info, Program> programMap = new TreeMap<>(); // all program

	public Builder() {
		//
	}

	public boolean needsFix() {
		return Reference.TYPE.context.needsFix() || Reference.CONS.context.needsFix();
	}
	public void fixReference() {
		// fix reference in ReferenceType.all
		Reference.TYPE.fix();
		Reference.CONS.fix();
	}

	public void scanDirectory(final List<String> folderPathList) {
		scanDirectory(folderPathList.toArray(String[]::new));
	}

	public void scanDirectory(final String[] folderPathList) {
		for(var e: folderPathList) {
			scanDirectory(e);
		}
		fixReference();
	}

	public void scanDirectory(final String folderPathString) {
		for(var e: getCourierFileList(folderPathString)) {
			scanFile(e);
		}
	}

	public List<Path> getCourierFileList(final String pathString) {
		var path = Paths.get(pathString);
		// sanity check
		if (!Files.isDirectory(path)) {
			logger.error("path is not directory");
			throw new UnexpectedException("Unepxepcted");
		}

		try {
			var ret = Files.list(path).filter(o -> o.toString().endsWith(COURIER_FILE_SUFFIX)).collect(Collectors.toList());
			Collections.sort(ret);
			return ret;
		} catch (IOException e) {
			var exceptionName = e.getClass().getSimpleName();
			logger.error("{} {}", exceptionName, e);
			throw new UnexpectedException(exceptionName, e);
		}
	}

	public void scanFile(final Path path) {
		var context = getCourierProgramContext(path);
		var program = getProgram(context);
		programMap.put(program.self, program);
	}

	public CourierParser.CourierProgramContext getCourierProgramContext(final Path path) {
		try {
			var stream  = CharStreams.fromPath(path);
			var lexer   = new CourierLexer(stream);
			var tokens  = new CommonTokenStream(lexer);
			var parser  = new CourierParser(tokens);

			return parser.courierProgram();
		} catch (IOException e) {
			var exceptionName = e.getClass().getSimpleName();
			logger.error("{} {}", exceptionName, e);
			throw new UnexpectedException(exceptionName, e);
		}
	}

	public Program getProgram(final CourierParser.CourierProgramContext context) {
		var self           = new Info(context.name.getText(), context.program.getText(), context.version.getText());
		var dependencyList = toInfoList(context.dependencyList());

		var program = new Program(self, dependencyList);
		buildDeclList(program, context.declarationList());
		return program;
	}

	//
	// Convert CourierParse to Program
	//
	List<Info> toInfoList(final CourierParser.DependencyListContext context) {
		var ret = new ArrayList<Info>();

		var list = context.referencedProgramList();
		if (list == null) {
			return ret;
		}

		for(var e: list.elements) {
			ret.add(new Info(e.name.getText(), e.program.getText(), e.version.getText()));
		}

		return ret;
	}
	// build Program.declList
	void buildDeclList(final Program myProgram, final CourierParser.DeclarationListContext context) {
		if (context == null) {
			return;
		}
		for(var e: context.elements) {
			var decl = switch(e) {
				case CourierParser.DeclarationTypeContext ut -> toDecl(myProgram, ut.typeDecl());
				case CourierParser.DeclarationConsContext ut -> toDecl(myProgram, ut.consDecl());
				default -> throw new UnexpectedException("Unexpected");
			};
			myProgram.declList.add(decl);
		}
	}
	// TypeDecl
	Decl toDecl(final Program myProgram, final CourierParser.TypeDeclContext context) {
		var line = context.name.getLine();
		var name = context.name.getText();
		var type = toType(myProgram, context.type());

		/**/
		if (type.isReference()) {
			var myName = myProgram.self.toQName(name);
			var refType = type.toTypeReference().toReferenceType();
			Reference.TYPE.add(myName, refType);
		} else {
			var myName = myProgram.self.toQName(name);
			Reference.TYPE.add(myName, type);

			// special for enum element
			if (type.isEnum()) {
				var typeEnum = type.toTypeEnum();
				for(var e: typeEnum.list) {
					var key = myProgram.self.toQName(e.name);
					var value = new Cons.Number(e.number);
					Reference.CONS.add(key, value);
				}
			}
		}
		/**/

		return new Decl(line, name, type);
	}
	// ConsDecl
	Decl toDecl(final Program myProgram, final CourierParser.ConsDeclContext context) {
		var line = context.name.getLine();
		var name = context.name.getText();
		var type = toType(myProgram, context.type());
		var cons = toCons(myProgram, context.cons());

		/**/
		if (cons.isReference()) {
			var myName = myProgram.self.toQName(name);
			var refCons = cons.toConsReference().toReferenceCons();
			Reference.CONS.add(myName, refCons);
		} else {
			var myName = myProgram.self.toQName(name);
			Reference.CONS.add(myName, cons);
		}
		/**/

		return new Decl(line, name, type, cons);
	}

	//
	// Type
	//
	Type toType(final Program myProgram, final CourierParser.TypeContext context) {
		return switch(context) {
			case CourierParser.TypeBooleanContext      ut -> Type.BOOLEAN;
			case CourierParser.TypeCardinalContext     ut -> Type.CARDINAL;
			case CourierParser.TypeLongCardinalContext ut -> Type.LONG_CARDINAL;
			case CourierParser.TypeIntegerContext      ut -> Type.INTEGER;
			case CourierParser.TypeLongIntegerContext  ut -> Type.LONG_INTEGER;
			case CourierParser.TypeStringContext       ut -> Type.STRING;
			case CourierParser.TypeUnspecifiedContext  ut -> Type.UNSPECIFIED;
			/**/
			case CourierParser.TypeEnumerationContext  ut -> toType(myProgram, ut);
			case CourierParser.TypeArrayContext        ut -> toType(myProgram, ut);
			case CourierParser.TypeSequenceContext     ut -> toType(myProgram, ut);
			case CourierParser.TypeRecordContext       ut -> toType(myProgram, ut);
			case CourierParser.TypeChoiceContext       ut -> toType(myProgram, ut);
			case CourierParser.TypeProcedureContext    ut -> toType(myProgram, ut);
			case CourierParser.TypeErrorContext        ut -> toType(myProgram, ut);
			/**/
			case CourierParser.TypeReferenceContext    ut -> toType(myProgram, ut);
			default -> throw new UnexpectedException("Unexpected");
		};
	}
	Type toType(final Program myProgram, final CourierParser.TypeEnumerationContext context) {
		var list = new ArrayList<NumberName>();

		for(var e: context.enumerationType().correspondenceList().elements) {
			var number = Util.parseInt(e.number.getText());
			var name   = e.name.getText();
			list.add(new NumberName(number, name));
		}

		return new TypeEnum(list);
	}
	Type toType(final Program myProgram, final CourierParser.TypeArrayContext context) {
		return switch(context.arrayType()) {
			case CourierParser.ArrayTypeNumberContext    ut -> {
				var size = Util.parseInt(ut.positiveNumber().NUMBER().getText());
				var type = toType(myProgram, ut.type());
				yield new TypeArray(size, type);
			}
			default -> throw new UnexpectedException("Unexpected");
		};
	}
	Type toType(final Program myProgram, final CourierParser.TypeSequenceContext context) {
		return switch(context.sequenceType()) {
		case CourierParser.SequenceTypeEmptyContext    ut -> {
			var type = toType(myProgram, ut.type());
			yield new TypeSequence(type);
		}
		case CourierParser.SequenceTypeNumberContext   ut -> {
			var size = Util.parseInt(ut.positiveNumber().NUMBER().getText());
			var type = toType(myProgram, ut.type());

			yield new TypeSequence(size, type);
		}
		default -> throw new UnexpectedException("Unexpected");
	};
	}
	Type toType(final Program myProgram, final CourierParser.TypeRecordContext context) {
		return switch (context.recordType()) {
		case CourierParser.RecordTypeEmptyContext ut -> TypeRecord.EMPTY;
		case CourierParser.RecordTypeListContext ut -> {
			var fieldList = toNameTypeList(myProgram, ut.fieldList());
			yield new TypeRecord(fieldList);
		}
		default -> throw new UnexpectedException("Unexpected");
		};
	}
	List<NameType> toNameTypeList(final Program myProgram, final CourierParser.FieldListContext context) {
		var ret = new ArrayList<NameType>();

		if (context == null) {
			return ret;
		}

		for(var e: context.elements) {
			var nameList = e.nameList().elements.stream().map(Token::getText).toList();
			var type = toType(myProgram, e.type());

			for(var name: nameList) {
				ret.add(new NameType(name, type));
			}
		}

		return ret;
	}

	Type toType(final Program myProgram, final CourierParser.TypeChoiceContext context) {
		return switch(context.choiceType()) {
		case CourierParser.ChoiceTypeAnonContext ut -> toType(myProgram, ut);
		case CourierParser.ChoiceTypeNameContext ut -> toType(myProgram, ut);
		default -> throw new UnexpectedException("Unexpected");
		};
	}
	Type toType(final Program myProgram, final CourierParser.ChoiceTypeAnonContext context) {
		var candidateList = new ArrayList<TypeChoice.Candidate>();

		for(var e: context.candidateList().elements) {
			var designatorList = new ArrayList<NumberName>();
			var type           = toType(myProgram, e.type());

			for(var ee: e.designatorList().elements) {
				var name   = ee.name.getText();
				var number = Util.parseInt(ee.positiveNumber().getText());
				designatorList.add(new NumberName(number, name));
			}

			candidateList.add(new TypeChoice.Candidate(designatorList, type));
		}
		return new TypeChoice.Anon(candidateList);
	}
	Type toType(final Program myProgram, final CourierParser.ChoiceTypeNameContext context) {
		var designator        = toReferenceType(myProgram, context.reference()).toTYPE();
		var candidateNameList = new ArrayList<CandidateName>();

		for(var e: context.candidateNameList().elements) {
			var nameList = e.nameList().elements.stream().map(o -> o.getText()).toList();
			var type = toType(myProgram, e.type());
			candidateNameList.add(new CandidateName(nameList, type));
		}
		return new TypeChoice.Name(designator, candidateNameList);
	}
	Type toType(final Program myProgram, final CourierParser.TypeProcedureContext context) {
		var procedureType = context.procedureType();
		var argumentList  = toNameTypeList(myProgram, procedureType.argumentList().fieldList());
		var resultList    = toNameTypeList(myProgram, procedureType.resultList().fieldList());
		var errorList     = procedureType.errorList().nameList().elements.stream().map(Token::getText).toList();
		return new TypeProcedure(argumentList, resultList, errorList);
	}
	Type toType(final Program myProgram, final CourierParser.TypeErrorContext context) {
		var argumentList = toNameTypeList(myProgram, context.errorType().argumentList().fieldList());
		return new TypeError(argumentList);
	}
	Type toType(final Program myProgram, final CourierParser.TypeReferenceContext context) {
		var ref = toReferenceType(myProgram, context.reference());
		return new TypeReference(ref);
	}


	//
	// Cons
	//
	Cons toCons(final Program myProgram, final CourierParser.ConsContext context) {
		return switch(context) {
			case CourierParser.ConsBooleanContext   ut -> toCons(myProgram, ut);
			case CourierParser.ConsPositiveContext  ut -> toCons(myProgram, ut);
			case CourierParser.ConsNegativeContext  ut -> toCons(myProgram, ut);
			case CourierParser.ConsStringContext    ut -> toCons(myProgram, ut);
			/**/
			case CourierParser.ConsArrayContext     ut -> toCons(myProgram, ut);
			case CourierParser.ConsRecordContext    ut -> toCons(myProgram, ut);
			case CourierParser.ConsChoiceContext    ut -> toCons(myProgram, ut);
			/**/
			case CourierParser.ConsReferenceContext ut -> toCons(myProgram, ut);
			default -> throw new UnexpectedException("Unexpected");
		};
	}
	Cons toCons(final Program myProgram, final CourierParser.ConsBooleanContext context) {
		return switch(context.booleanConstant()) {
			case CourierParser.BooleanConstantTrueContext  ut -> Cons.Boolean.TRUE;
			case CourierParser.BooleanConstantFalseContext ut -> Cons.Boolean.FALSE;
			default -> throw new UnexpectedException("Unexpected");
		};
	}
	Cons toCons(final Program myProgram, final CourierParser.ConsPositiveContext context) {
		return new Cons.Number(Util.parseInt(context.positiveNumber().getText()));
	}
	Cons toCons(final Program myProgram, final CourierParser.ConsNegativeContext context) {
		return new Cons.Number(-1 * Util.parseInt(context.negativeNumber().getText()));
	}
	Cons toCons(final Program myProgram, final CourierParser.ConsStringContext context) {
		return new Cons.String(context.stringConstant().getText());
	}
	Cons toCons(final Program myProgram, final CourierParser.ConsArrayContext context) {
		return switch(context.arrayConstant()) {
			case CourierParser.ArrayConstantListContext  ut -> {
				var valueList = ut.elementList().elements.stream().map(o -> toCons(myProgram, o)).toList();
				yield new ConsArray(valueList);
			}
			case CourierParser.ArrayConstantEmptyContext ut -> ConsArray.EMPTY;
			default -> throw new UnexpectedException("Unexpected");
		};
	}
	Cons toCons(final Program myProgram, final CourierParser.ConsRecordContext context) {
		return switch(context.recordConstant()) {
		case CourierParser.RecordConstantListContext ut -> {
			var list = new ArrayList<NameCons>();

			for(var e: ut.componentList().elements) {
				var nameList = e.nameList().elements.stream().map(Token::getText).toList();
				var cons = toCons(myProgram, e.cons());

				for(var name: nameList) {
					list.add(new NameCons(name, cons));
				}
			}

			yield new ConsRecord(list);
		}
		case CourierParser.RecordConstantEmptyContext ut -> ConsRecord.EMPTY;
		default -> throw new UnexpectedException("Unexpected");
		};
	}
	Cons toCons(final Program myProgram, final CourierParser.ConsChoiceContext context) {
		var choiceConstant = context.choiceConstant();
		var name           = choiceConstant.ID().getText();
		var cons           = toCons(myProgram, choiceConstant.cons());
		return new ConsChoice(name, cons);
	}
	Cons toCons(final Program myProgram, final CourierParser.ConsReferenceContext context) {
		var ref = toReferenceCons(myProgram, context.reference());
		return new ConsReference(ref);
	}

	Reference.TYPE toReferenceType(final Program myProgram, final CourierParser.ReferenceContext context) {
		return switch(context) {
			case CourierParser.ReferenceLocalContext ut -> {
				var name = ut.name.getText();
				yield new Reference.TYPE(myProgram, name);
			}
			case CourierParser.ReferenceRemoteContext ut -> {
				var program = ut.program.getText();
				var name = ut.name.getText();
				yield new Reference.TYPE(myProgram, program, name);
			}
			case CourierParser.ReferenceExternalContext ut -> {
				var program = ut.program.getText();
				var name = ut.name.getText();
				yield new Reference.TYPE(program, name);
			}
			default -> throw new UnexpectedException("Unexpected");
		};
	}
	Reference.CONS toReferenceCons(final Program myProgram, final CourierParser.ReferenceContext context) {
		return switch(context) {
			case CourierParser.ReferenceLocalContext ut -> {
				var name = ut.name.getText();
				yield new Reference.CONS(myProgram, name);
			}
			case CourierParser.ReferenceRemoteContext ut -> {
				var program = ut.program.getText();
				var name = ut.name.getText();
				yield new Reference.CONS(myProgram, program, name);
			}
			case CourierParser.ReferenceExternalContext ut -> {
				var program = ut.program.getText();
				var name = ut.name.getText();
				yield new Reference.CONS(program, name);
			}
			default -> throw new UnexpectedException("Unexpected");
		};
	}
}
