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

import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.CharStreams;
import org.antlr.v4.runtime.CommonTokenStream;

import yokwe.courier.antlr.CourierLexer;
import yokwe.courier.antlr.CourierParser;
import yokwe.courier.program.Program.Decl;
import yokwe.courier.program.Program.Info;
import yokwe.courier.program.Program.NameCons;
import yokwe.courier.program.Program.NameNumberType;
import yokwe.courier.program.Program.NameType;
import yokwe.courier.program.Program.NumberName;
import yokwe.courier.program.Program.Reference;
import yokwe.courier.program.Program.ReferenceCons;
import yokwe.courier.program.Program.ReferenceType;
import yokwe.util.UnexpectedException;

public class Builder {
	private static final org.slf4j.Logger logger = yokwe.util.LoggerUtil.getLogger();
	
	public static String COURIER_FILE_SUFFIX = ".cr";
		
	public Map<Info, Program> programMap = new TreeMap<>(); // all program
	
	public Map<String, Type>  typeMap    = new TreeMap<>(); // only concrete type
	public Map<String, Cons>  consMap    = new TreeMap<>(); // only concrete Cons
	
	public Map<String, ReferenceType>  typeMapRef  = new TreeMap<>(); // all reference to type
	public Map<String, ReferenceCons>  consMapRef  = new TreeMap<>(); // all reference to cons
	
	Type getType(String name) {
		String newName = name;
		while(typeMapRef.containsKey(newName)) {
			var ref = typeMapRef.get(newName);
			newName = ref.toName();
		}
		
		if (typeMap.containsKey(newName)) {
			return typeMap.get(newName);
		}
		logger.error("getType  Unexpected name  {}  {}", name, newName);
//		return null;
		throw new UnexpectedException("Unexpected");
	}
	Cons getCons(String name) {
		if (consMap.containsKey(name)) return consMap.get(name);
		if (consMapRef.containsKey(name)) {
			var newName = consMapRef.get(name).toName();
			return getCons(newName);
		}
		logger.error("getCons  Unexpected name  {}", name);
//		return null;
		throw new UnexpectedException("Unexpected");
	}
	public void fixReference() {
		for(var e: typeMapRef.entrySet()) {
			var ref = e.getValue();
			if (ref.fixed()) continue;
			var name = ref.toName();
			if (typeMap.containsKey(name)) {
				ref.value = typeMap.get(name);
			}
		}
		for(var e: consMapRef.entrySet()) {
			var ref = e.getValue();
			if (ref.fixed()) continue;
			var name = ref.toName();
			if (consMap.containsKey(name)) {
				ref.value = consMap.get(name);
			}
		}
		
		
		for(var program: programMap.values()) {
			for(var e: program.declList) {
				var name = program.self.toName(e.name);;
				if (e.isType()) {
					var type = e.type;
					if (type.isReference()) {
						var ref = type.toTypeReference().ref.toReferenceType();
						if (ref.needsFix()) {
							ref.value = getType(ref.toName());
						}
					}
				}
				if (e.isCons()) {
					var type = e.type;
					if (type.isReference()) {
						var ref = type.toTypeReference().ref.toReferenceType();
						if (ref.needsFix()) {
							ref.value = getType(ref.toName());
						}
					}
					
					var cons = e.cons;
					if (cons.isReference()) {
						var ref = cons.toConsReference().ref.toReferenceCons();
						if (ref.needsFix()) {
							ref.value = getCons(name);
						}
					}
				}
			}
		}
		
		
		// sanity check
		for(var program: programMap.values()) {
			for(var e: program.declList) {
				if (e.isType()) {
					var type = e.type;
					if (type.isReference()) {
						var ref = type.toTypeReference().ref;
						if (ref.needsFix()) {
							logger.error("decltype not fixed  {}  {}", program.self.toName(), e.toString());
						}
					}
				}
				if (e.isCons()) {
					var type = e.type;
					if (type.isReference()) {
						var ref = type.toTypeReference().ref;
						if (ref.needsFix()) {
							logger.error("declcons type not fixed  {}  {}", program.self.toName(), e.toString());
						}
					}
					var cons = e.cons;
					if (cons.isReference()) {
						var ref = cons.toConsReference().ref;
						if (ref.needsFix()) {
							logger.error("declcons cons not fixed  {}  {}", program.self.toName(), e.toString());
						}
					}
				}
			}
		}
	}
	
	public List<Path> getCourierFileList(String pathString) {
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
			String exceptionName = e.getClass().getSimpleName();
			logger.error("{} {}", exceptionName, e);
			throw new UnexpectedException(exceptionName, e);
		}
	}
	
	public void scanDirectory(String folderPathString) {
		var list = getCourierFileList(folderPathString);
		for(var e: list) {
			scanFile(e);
		}
	}
	
	public void scanFile(Path path) {
		var context = getContext(path);
		var program = getProgram(context);
		programMap.put(program.self, program);
	}
	public CourierParser.CourierProgramContext getContext(Path path) {
		try {
			CharStream        stream  = CharStreams.fromPath(path);
			CourierLexer      lexer   = new CourierLexer(stream);
			CommonTokenStream tokens  = new CommonTokenStream(lexer);
			CourierParser     parser  = new CourierParser(tokens);
			
			return parser.courierProgram();
		} catch (IOException e) {
			String exceptionName = e.getClass().getSimpleName();
			logger.error("{} {}", exceptionName, e);
			throw new UnexpectedException(exceptionName, e);
		}
	}
	public Program getProgram(CourierParser.CourierProgramContext context) {
		var self           = new Info(context.name.getText(), context.program.getText(), context.version.getText());
		var dependencyList = toInfoList(context.dependencyList());
		
		var program = new Program(self, dependencyList);
		buildDeclList(program, context.declarationList());
		return program;
	}
	
	//
	// Convert CourierParse to Program
	//
	List<Info> toInfoList(CourierParser.DependencyListContext context) {
		var ret = new ArrayList<Info>();
		
		var list = context.referencedProgramList();
		if (list == null) return ret;
		
		for(var e: list.elements) {
			ret.add(new Info(e.name.getText(), e.program.getText(), e.version.getText()));
		}
		
		return ret;
	}
	
	void buildDeclList(Program myProgram, CourierParser.DeclarationListContext context) {
		if (context == null) return;
		for(var e: context.elements) {
			var decl = switch(e) {
				case CourierParser.DeclarationTypeContext ut -> toDecl(myProgram, ut.typeDecl());
				case CourierParser.DeclarationConsContext ut -> toDecl(myProgram, ut.consDecl());
				default -> throw new UnexpectedException("Unexpected");
			};
			myProgram.declList.add(decl);
		}
	}
	// Type
	Decl toDecl(Program myProgram, CourierParser.TypeDeclContext context) {
		var name = context.name.getText();
		var type = toType(myProgram, context.type());
		
		var myName = myProgram.self.toName(name);
		if (type instanceof TypeReference) {
			var ref = type.toTypeReference().ref;
			var refType = (ReferenceType)ref;
			
			if (typeMapRef.containsKey(myName)) {
				// already in typeMapRef
			} else {
				typeMapRef.put(myName, refType);
			}
		} else {
			typeMap.put(myName, type);
			
			// special for enum element
			if (type.isEnum()) {
				var typeEnum = type.toTypeEnum();
				for(var e: typeEnum.list) {
					var key = myProgram.self.toName(e.name);
					var value = new Cons.Number(e.number);
					consMap.put(key, value);
				}
			}
		}
		
		return new Decl(name, type);
	}
	Decl toDecl(Program myProgram, CourierParser.ConsDeclContext context) {
		var name = context.name.getText();
		var type = toType(myProgram, context.type());
		var cons = toCons(myProgram, context.cons());
		
		var myName = myProgram.self.toName(name);
		
		if (type instanceof TypeReference) {
			var ref = type.toTypeReference().ref;
			var refType = (ReferenceType)ref;
			if (typeMapRef.containsKey(myName)) {
				// already in typeMapRef
			} else {
				typeMapRef.put(myName, refType);
			}
		}

		if (cons instanceof ConsReference) {
			var ref = cons.toConsReference().ref;
			var refType = (ReferenceCons)ref;
			consMapRef.put(myName, refType);
		} else {
			consMap.put(myName, cons);
		}
		
		return new Decl(name, type, cons);
	}
	
	//
	// Type
	//
	Type toType(Program myProgram, CourierParser.TypeContext context) {
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
	Type toType(Program myProgram, CourierParser.TypeEnumerationContext context) {
		var list = new ArrayList<NumberName>();
			
		for(var e: context.enumerationType().correspondenceList().elements) {
			var number = Util.parseInt(e.number.getText());
			var name   = e.name.getText();
			list.add(new NumberName(number, name));
		}
		
		return new TypeEnum(list);
	}
	Type toType(Program myProgram, CourierParser.TypeArrayContext context) {
		return switch(context.arrayType()) {
			case CourierParser.ArrayTypeNumberContext    ut -> {
				var size = Util.parseInt(ut.positiveNumber().NUMBER().getText());
				var type = toType(myProgram, ut.type());
				yield new TypeArray(size, type);
			}
			case CourierParser.ArrayTypeReferenceContext ut -> {
				var ref  = toReferenceCons(myProgram, ut.reference());
				var type = toType(myProgram, ut.type());
				yield new TypeArray(ref, type);
			}
			default -> throw new UnexpectedException("Unexpected");
		};
	}
	Type toType(Program myProgram, CourierParser.TypeSequenceContext context) {
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
		case CourierParser.SequenceTypeReferenceContext ut -> {
			var ref  = toReferenceCons(myProgram, ut.reference());
			var type = toType(myProgram, ut.type());
			yield new TypeSequence(ref, type);
		}
		default -> throw new UnexpectedException("Unexpected");
	};
	}
	Type toType(Program myProgram, CourierParser.TypeRecordContext context) {
		return switch (context.recordType()) {
		case CourierParser.RecordTypeEmptyContext ut -> TypeRecord.EMPTY;
		case CourierParser.RecordTypeListContext ut -> {
			var fieldList = toNameTypeList(myProgram, ut.fieldList());
			yield new TypeRecord(fieldList);
		}
		default -> throw new UnexpectedException("Unexpected");
		};
	}
	List<NameType> toNameTypeList(Program myProgram, CourierParser.FieldListContext context) {
		var ret = new ArrayList<NameType>();
		
		if (context == null) return ret;
		
		for(var e: context.elements) {
			var nameList = e.nameList().elements.stream().map(o -> o.getText()).toList();
			var type = toType(myProgram, e.type());
			
			for(var name: nameList) {
				ret.add(new NameType(name, type));
			}
		}
		
		return ret;
	}
	
	Type toType(Program myProgram, CourierParser.TypeChoiceContext context) {
		return switch(context.choiceType()) {
		case CourierParser.ChoiceTypeAnonContext ut -> toType(myProgram, ut);
		case CourierParser.ChoiceTypeNameContext ut -> toType(myProgram, ut);
		default -> throw new UnexpectedException("Unexpected");
		};
	}
	Type toType(Program myProgram, CourierParser.ChoiceTypeAnonContext context) {
		var candidateList = new ArrayList<NameNumberType>();
		
		for(var e: context.candidateList().elements) {
			var type = toType(myProgram, e.type());
			for(var ee: e.designatorList().elements) {
				var name   = ee.name.getText();
				var number = Util.parseInt(ee.positiveNumber().getText());
				
				candidateList.add(new NameNumberType(name, number, type));
			}
		}
		return new TypeChoice.Anon(candidateList);
	}
	Type toType(Program myProgram, CourierParser.ChoiceTypeNameContext context) {
		var designator = toReferenceType(myProgram, context.reference());
		var candidateList = new ArrayList<NameType>();
		
		for(var e: context.candidateNameList().elements) {
			var type = toType(myProgram, e.type());
			for(var ee: e.nameList().elements) {
				var name   = ee.getText();
				
				candidateList.add(new NameType(name, type));
			}
		}
		return new TypeChoice.Name(designator, candidateList);
	}
	Type toType(Program myProgram, CourierParser.TypeProcedureContext context) {
		// PROCEDURE argumentList resultList errorList
		var procedureType = context.procedureType();
		
		var argumentList = toNameTypeList(myProgram, procedureType.argumentList().fieldList());
		var resultList = toNameTypeList(myProgram, procedureType.resultList().fieldList());
		var errorList = procedureType.errorList().nameList().elements.stream().map(o -> o.getText()).toList();
		
		return new TypeProcedure(argumentList, resultList, errorList);
	}
	Type toType(Program myProgram, CourierParser.TypeErrorContext context) {
		var argumentList = toNameTypeList(myProgram, context.errorType().argumentList().fieldList());
		return new TypeError(argumentList);
	}
	Type toType(Program myProgram, CourierParser.TypeReferenceContext context) {
		var ref = toReferenceType(myProgram, context.reference());
		return new TypeReference(ref);
	}
	
	
	//
	// Cons
	//
	Cons toCons(Program myProgram, CourierParser.ConsContext context) {
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
	Cons toCons(Program myProgram, CourierParser.ConsBooleanContext context) {
		return switch(context.booleanConstant()) {
			case CourierParser.BooleanConstantTrueContext  ut -> Cons.Boolean.TRUE;
			case CourierParser.BooleanConstantFalseContext ut -> Cons.Boolean.FALSE;
			default -> throw new UnexpectedException("Unexpected");
		};
	}
	Cons toCons(Program myProgram, CourierParser.ConsPositiveContext context) {
		return new Cons.Number(Util.parseInt(context.positiveNumber().getText()));
	}
	Cons toCons(Program myProgram, CourierParser.ConsNegativeContext context) {
		return new Cons.Number(-1 * Util.parseInt(context.negativeNumber().getText()));
	}
	Cons toCons(Program myProgram, CourierParser.ConsStringContext context) {
		return new Cons.String(context.stringConstant().getText());
	}
	Cons toCons(Program myProgram, CourierParser.ConsArrayContext context) {
		return switch(context.arrayConstant()) {
			case CourierParser.ArrayConstantListContext  ut -> {
				var valueList = ut.elementList().elements.stream().map(o -> toCons(myProgram, o)).toList();
				yield new ConsArray(valueList);
			}
			case CourierParser.ArrayConstantEmptyContext ut -> ConsArray.EMPTY;
			default -> throw new UnexpectedException("Unexpected");
		};
	}
	Cons toCons(Program myProgram, CourierParser.ConsRecordContext context) {
		return switch(context.recordConstant()) {
		case CourierParser.RecordConstantListContext ut -> {
			var list = new ArrayList<NameCons>();
			
			for(var e: ut.componentList().elements) {
				var nameList = e.nameList().elements.stream().map(o -> o.getText()).toList();
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
	Cons toCons(Program myProgram, CourierParser.ConsChoiceContext context) {
		var choiceConstant = context.choiceConstant();
		var name           = choiceConstant.ID().getText();
		var cons           = toCons(myProgram, choiceConstant.cons());
		return new ConsChoice(name, cons);
	}
	Cons toCons(Program myProgram, CourierParser.ConsReferenceContext context) {
		var ref = toReferenceCons(myProgram, context.reference());
		return new ConsReference(ref);
	}
	
	Reference toReferenceType(Program myProgram, CourierParser.ReferenceContext context) {
		var ret= switch(context) {
			case CourierParser.ReferenceLocalContext ut -> {
				var name = ut.name.getText();
				yield new ReferenceType(myProgram, name);
			}
			case CourierParser.ReferenceRemoteContext ut -> {
				var program = ut.program.getText();
				var name = ut.name.getText();
				yield new ReferenceType(myProgram, program, name);
			}
			case CourierParser.ReferenceExternalContext ut -> {
				var program = ut.program.getText();
				var name = ut.name.getText();
				yield new ReferenceType(program, name);
			}
			default -> throw new UnexpectedException("Unexpected");
		};
		return ret;
	}
	Reference toReferenceCons(Program myProgram, CourierParser.ReferenceContext context) {
		var ret = switch(context) {
			case CourierParser.ReferenceLocalContext ut -> {
				var name = ut.name.getText();
				yield new ReferenceCons(myProgram, name);
			}
			case CourierParser.ReferenceRemoteContext ut -> {
				var program = ut.program.getText();
				var name = ut.name.getText();
				yield new ReferenceCons(myProgram, program, name);
			}
			case CourierParser.ReferenceExternalContext ut -> {
				var program = ut.program.getText();
				var name = ut.name.getText();
				yield new ReferenceCons(program, name);
			}
			default -> throw new UnexpectedException("Unexpected");
		};
		return ret;
	}
}
