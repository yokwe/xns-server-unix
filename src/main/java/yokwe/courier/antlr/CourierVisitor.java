// Generated from src/main/java/yokwe/courier/antlr/Courier.g by ANTLR 4.13.2
package yokwe.courier.antlr;
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link CourierParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface CourierVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link CourierParser#courierProgram}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCourierProgram(CourierParser.CourierProgramContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#dependencyList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDependencyList(CourierParser.DependencyListContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#referencedProgramList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitReferencedProgramList(CourierParser.ReferencedProgramListContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#referencedProgram}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitReferencedProgram(CourierParser.ReferencedProgramContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#declarationList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDeclarationList(CourierParser.DeclarationListContext ctx);
	/**
	 * Visit a parse tree produced by the {@code DeclarationType}
	 * labeled alternative in {@link CourierParser#declaration}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDeclarationType(CourierParser.DeclarationTypeContext ctx);
	/**
	 * Visit a parse tree produced by the {@code DeclarationCons}
	 * labeled alternative in {@link CourierParser#declaration}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDeclarationCons(CourierParser.DeclarationConsContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#typeDecl}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeDecl(CourierParser.TypeDeclContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#consDecl}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConsDecl(CourierParser.ConsDeclContext ctx);
	/**
	 * Visit a parse tree produced by the {@code TypeBoolean}
	 * labeled alternative in {@link CourierParser#type}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeBoolean(CourierParser.TypeBooleanContext ctx);
	/**
	 * Visit a parse tree produced by the {@code TypeCardinal}
	 * labeled alternative in {@link CourierParser#type}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeCardinal(CourierParser.TypeCardinalContext ctx);
	/**
	 * Visit a parse tree produced by the {@code TypeLongCardinal}
	 * labeled alternative in {@link CourierParser#type}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeLongCardinal(CourierParser.TypeLongCardinalContext ctx);
	/**
	 * Visit a parse tree produced by the {@code TypeInteger}
	 * labeled alternative in {@link CourierParser#type}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeInteger(CourierParser.TypeIntegerContext ctx);
	/**
	 * Visit a parse tree produced by the {@code TypeLongInteger}
	 * labeled alternative in {@link CourierParser#type}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeLongInteger(CourierParser.TypeLongIntegerContext ctx);
	/**
	 * Visit a parse tree produced by the {@code TypeString}
	 * labeled alternative in {@link CourierParser#type}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeString(CourierParser.TypeStringContext ctx);
	/**
	 * Visit a parse tree produced by the {@code TypeUnspecified}
	 * labeled alternative in {@link CourierParser#type}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeUnspecified(CourierParser.TypeUnspecifiedContext ctx);
	/**
	 * Visit a parse tree produced by the {@code TypeEnumeration}
	 * labeled alternative in {@link CourierParser#type}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeEnumeration(CourierParser.TypeEnumerationContext ctx);
	/**
	 * Visit a parse tree produced by the {@code TypeArray}
	 * labeled alternative in {@link CourierParser#type}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeArray(CourierParser.TypeArrayContext ctx);
	/**
	 * Visit a parse tree produced by the {@code TypeSequence}
	 * labeled alternative in {@link CourierParser#type}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeSequence(CourierParser.TypeSequenceContext ctx);
	/**
	 * Visit a parse tree produced by the {@code TypeRecord}
	 * labeled alternative in {@link CourierParser#type}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeRecord(CourierParser.TypeRecordContext ctx);
	/**
	 * Visit a parse tree produced by the {@code TypeChoice}
	 * labeled alternative in {@link CourierParser#type}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeChoice(CourierParser.TypeChoiceContext ctx);
	/**
	 * Visit a parse tree produced by the {@code TypeProcedure}
	 * labeled alternative in {@link CourierParser#type}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeProcedure(CourierParser.TypeProcedureContext ctx);
	/**
	 * Visit a parse tree produced by the {@code TypeError}
	 * labeled alternative in {@link CourierParser#type}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeError(CourierParser.TypeErrorContext ctx);
	/**
	 * Visit a parse tree produced by the {@code TypeReference}
	 * labeled alternative in {@link CourierParser#type}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeReference(CourierParser.TypeReferenceContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ConsBoolean}
	 * labeled alternative in {@link CourierParser#cons}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConsBoolean(CourierParser.ConsBooleanContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ConsPositive}
	 * labeled alternative in {@link CourierParser#cons}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConsPositive(CourierParser.ConsPositiveContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ConsNegative}
	 * labeled alternative in {@link CourierParser#cons}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConsNegative(CourierParser.ConsNegativeContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ConsString}
	 * labeled alternative in {@link CourierParser#cons}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConsString(CourierParser.ConsStringContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ConsArray}
	 * labeled alternative in {@link CourierParser#cons}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConsArray(CourierParser.ConsArrayContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ConsRecord}
	 * labeled alternative in {@link CourierParser#cons}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConsRecord(CourierParser.ConsRecordContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ConsChoice}
	 * labeled alternative in {@link CourierParser#cons}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConsChoice(CourierParser.ConsChoiceContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ConsReference}
	 * labeled alternative in {@link CourierParser#cons}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConsReference(CourierParser.ConsReferenceContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ReferenceLocal}
	 * labeled alternative in {@link CourierParser#reference}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitReferenceLocal(CourierParser.ReferenceLocalContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ReferenceRemote}
	 * labeled alternative in {@link CourierParser#reference}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitReferenceRemote(CourierParser.ReferenceRemoteContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ReferenceExternal}
	 * labeled alternative in {@link CourierParser#reference}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitReferenceExternal(CourierParser.ReferenceExternalContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#positiveNumber}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPositiveNumber(CourierParser.PositiveNumberContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#negativeNumber}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNegativeNumber(CourierParser.NegativeNumberContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#booleanType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitBooleanType(CourierParser.BooleanTypeContext ctx);
	/**
	 * Visit a parse tree produced by the {@code BooleanConstantTrue}
	 * labeled alternative in {@link CourierParser#booleanConstant}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitBooleanConstantTrue(CourierParser.BooleanConstantTrueContext ctx);
	/**
	 * Visit a parse tree produced by the {@code BooleanConstantFalse}
	 * labeled alternative in {@link CourierParser#booleanConstant}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitBooleanConstantFalse(CourierParser.BooleanConstantFalseContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#cardinalType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCardinalType(CourierParser.CardinalTypeContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#longCardinalType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLongCardinalType(CourierParser.LongCardinalTypeContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#integerType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIntegerType(CourierParser.IntegerTypeContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#longIntegerType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLongIntegerType(CourierParser.LongIntegerTypeContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#stringType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitStringType(CourierParser.StringTypeContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#stringConstant}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitStringConstant(CourierParser.StringConstantContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#unspecifiedType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitUnspecifiedType(CourierParser.UnspecifiedTypeContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#enumerationType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitEnumerationType(CourierParser.EnumerationTypeContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#enumerationConstant}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitEnumerationConstant(CourierParser.EnumerationConstantContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#correspondenceList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCorrespondenceList(CourierParser.CorrespondenceListContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#correspondence}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCorrespondence(CourierParser.CorrespondenceContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ArrayTypeNumber}
	 * labeled alternative in {@link CourierParser#arrayType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitArrayTypeNumber(CourierParser.ArrayTypeNumberContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ArrayTypeReference}
	 * labeled alternative in {@link CourierParser#arrayType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitArrayTypeReference(CourierParser.ArrayTypeReferenceContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ArrayConstantList}
	 * labeled alternative in {@link CourierParser#arrayConstant}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitArrayConstantList(CourierParser.ArrayConstantListContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ArrayConstantEmpty}
	 * labeled alternative in {@link CourierParser#arrayConstant}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitArrayConstantEmpty(CourierParser.ArrayConstantEmptyContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#elementList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitElementList(CourierParser.ElementListContext ctx);
	/**
	 * Visit a parse tree produced by the {@code SequenceTypeEmpty}
	 * labeled alternative in {@link CourierParser#sequenceType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSequenceTypeEmpty(CourierParser.SequenceTypeEmptyContext ctx);
	/**
	 * Visit a parse tree produced by the {@code SequenceTypeNumber}
	 * labeled alternative in {@link CourierParser#sequenceType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSequenceTypeNumber(CourierParser.SequenceTypeNumberContext ctx);
	/**
	 * Visit a parse tree produced by the {@code SequenceTypeReference}
	 * labeled alternative in {@link CourierParser#sequenceType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSequenceTypeReference(CourierParser.SequenceTypeReferenceContext ctx);
	/**
	 * Visit a parse tree produced by the {@code RecordTypeEmpty}
	 * labeled alternative in {@link CourierParser#recordType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitRecordTypeEmpty(CourierParser.RecordTypeEmptyContext ctx);
	/**
	 * Visit a parse tree produced by the {@code RecordTypeList}
	 * labeled alternative in {@link CourierParser#recordType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitRecordTypeList(CourierParser.RecordTypeListContext ctx);
	/**
	 * Visit a parse tree produced by the {@code RecordConstantEmpty}
	 * labeled alternative in {@link CourierParser#recordConstant}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitRecordConstantEmpty(CourierParser.RecordConstantEmptyContext ctx);
	/**
	 * Visit a parse tree produced by the {@code RecordConstantList}
	 * labeled alternative in {@link CourierParser#recordConstant}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitRecordConstantList(CourierParser.RecordConstantListContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#fieldList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFieldList(CourierParser.FieldListContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#field}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitField(CourierParser.FieldContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#componentList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitComponentList(CourierParser.ComponentListContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#component}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitComponent(CourierParser.ComponentContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#nameList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNameList(CourierParser.NameListContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ChoiceTypeAnon}
	 * labeled alternative in {@link CourierParser#choiceType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitChoiceTypeAnon(CourierParser.ChoiceTypeAnonContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ChoiceTypeName}
	 * labeled alternative in {@link CourierParser#choiceType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitChoiceTypeName(CourierParser.ChoiceTypeNameContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#choiceConstant}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitChoiceConstant(CourierParser.ChoiceConstantContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#candidateList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCandidateList(CourierParser.CandidateListContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#candidate}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCandidate(CourierParser.CandidateContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#designatorList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDesignatorList(CourierParser.DesignatorListContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#designator}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDesignator(CourierParser.DesignatorContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#candidateNameList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCandidateNameList(CourierParser.CandidateNameListContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#candidateName}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCandidateName(CourierParser.CandidateNameContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#procedureType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitProcedureType(CourierParser.ProcedureTypeContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#argumentList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitArgumentList(CourierParser.ArgumentListContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#resultList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitResultList(CourierParser.ResultListContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#errorList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitErrorList(CourierParser.ErrorListContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#errorType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitErrorType(CourierParser.ErrorTypeContext ctx);
}