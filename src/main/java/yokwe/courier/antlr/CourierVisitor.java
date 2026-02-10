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
	 * Visit a parse tree produced by {@link CourierParser#programHeader}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitProgramHeader(CourierParser.ProgramHeaderContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#programBody}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitProgramBody(CourierParser.ProgramBodyContext ctx);
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
	 * Visit a parse tree produced by the {@code DeclType}
	 * labeled alternative in {@link CourierParser#declaration}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDeclType(CourierParser.DeclTypeContext ctx);
	/**
	 * Visit a parse tree produced by the {@code DeclCons}
	 * labeled alternative in {@link CourierParser#declaration}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDeclCons(CourierParser.DeclConsContext ctx);
	/**
	 * Visit a parse tree produced by the {@code TypePredefined}
	 * labeled alternative in {@link CourierParser#type}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypePredefined(CourierParser.TypePredefinedContext ctx);
	/**
	 * Visit a parse tree produced by the {@code TypeConstructed}
	 * labeled alternative in {@link CourierParser#type}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeConstructed(CourierParser.TypeConstructedContext ctx);
	/**
	 * Visit a parse tree produced by the {@code TypeReferenced}
	 * labeled alternative in {@link CourierParser#type}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeReferenced(CourierParser.TypeReferencedContext ctx);
	/**
	 * Visit a parse tree produced by the {@code TypeBoolean}
	 * labeled alternative in {@link CourierParser#predefinedType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeBoolean(CourierParser.TypeBooleanContext ctx);
	/**
	 * Visit a parse tree produced by the {@code TypeCardinal}
	 * labeled alternative in {@link CourierParser#predefinedType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeCardinal(CourierParser.TypeCardinalContext ctx);
	/**
	 * Visit a parse tree produced by the {@code TypeLongCardinal}
	 * labeled alternative in {@link CourierParser#predefinedType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeLongCardinal(CourierParser.TypeLongCardinalContext ctx);
	/**
	 * Visit a parse tree produced by the {@code TypeInteger}
	 * labeled alternative in {@link CourierParser#predefinedType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeInteger(CourierParser.TypeIntegerContext ctx);
	/**
	 * Visit a parse tree produced by the {@code TypeLongInteger}
	 * labeled alternative in {@link CourierParser#predefinedType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeLongInteger(CourierParser.TypeLongIntegerContext ctx);
	/**
	 * Visit a parse tree produced by the {@code TypeString}
	 * labeled alternative in {@link CourierParser#predefinedType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeString(CourierParser.TypeStringContext ctx);
	/**
	 * Visit a parse tree produced by the {@code TypeUnspecified}
	 * labeled alternative in {@link CourierParser#predefinedType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeUnspecified(CourierParser.TypeUnspecifiedContext ctx);
	/**
	 * Visit a parse tree produced by the {@code TypeEnum}
	 * labeled alternative in {@link CourierParser#constructedType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeEnum(CourierParser.TypeEnumContext ctx);
	/**
	 * Visit a parse tree produced by the {@code TypeArray}
	 * labeled alternative in {@link CourierParser#constructedType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeArray(CourierParser.TypeArrayContext ctx);
	/**
	 * Visit a parse tree produced by the {@code TypeSequence}
	 * labeled alternative in {@link CourierParser#constructedType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeSequence(CourierParser.TypeSequenceContext ctx);
	/**
	 * Visit a parse tree produced by the {@code TypeRecord}
	 * labeled alternative in {@link CourierParser#constructedType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeRecord(CourierParser.TypeRecordContext ctx);
	/**
	 * Visit a parse tree produced by the {@code TypeRecordEmpty}
	 * labeled alternative in {@link CourierParser#constructedType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeRecordEmpty(CourierParser.TypeRecordEmptyContext ctx);
	/**
	 * Visit a parse tree produced by the {@code TypeChoiceTyped}
	 * labeled alternative in {@link CourierParser#constructedType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeChoiceTyped(CourierParser.TypeChoiceTypedContext ctx);
	/**
	 * Visit a parse tree produced by the {@code TypeChoiceAnon}
	 * labeled alternative in {@link CourierParser#constructedType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeChoiceAnon(CourierParser.TypeChoiceAnonContext ctx);
	/**
	 * Visit a parse tree produced by the {@code TypeProcedure}
	 * labeled alternative in {@link CourierParser#constructedType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeProcedure(CourierParser.TypeProcedureContext ctx);
	/**
	 * Visit a parse tree produced by the {@code TypeError}
	 * labeled alternative in {@link CourierParser#constructedType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeError(CourierParser.TypeErrorContext ctx);
	/**
	 * Visit a parse tree produced by the {@code TypeRef}
	 * labeled alternative in {@link CourierParser#referenced}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeRef(CourierParser.TypeRefContext ctx);
	/**
	 * Visit a parse tree produced by the {@code TypeRefQ}
	 * labeled alternative in {@link CourierParser#referenced}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeRefQ(CourierParser.TypeRefQContext ctx);
	/**
	 * Visit a parse tree produced by the {@code TypeRefExt}
	 * labeled alternative in {@link CourierParser#referenced}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeRefExt(CourierParser.TypeRefExtContext ctx);
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
	 * Visit a parse tree produced by {@link CourierParser#maximumNumber}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMaximumNumber(CourierParser.MaximumNumberContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ValueNumber}
	 * labeled alternative in {@link CourierParser#numericValue}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitValueNumber(CourierParser.ValueNumberContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ValueRefCons}
	 * labeled alternative in {@link CourierParser#numericValue}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitValueRefCons(CourierParser.ValueRefConsContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#typedCandidateList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypedCandidateList(CourierParser.TypedCandidateListContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#typedCandidate}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypedCandidate(CourierParser.TypedCandidateContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#anonCandidateList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAnonCandidateList(CourierParser.AnonCandidateListContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#anonCandidate}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAnonCandidate(CourierParser.AnonCandidateContext ctx);
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
	 * Visit a parse tree produced by the {@code ConsLiteral}
	 * labeled alternative in {@link CourierParser#constant}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConsLiteral(CourierParser.ConsLiteralContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ConsConstructed}
	 * labeled alternative in {@link CourierParser#constant}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConsConstructed(CourierParser.ConsConstructedContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ConsRef}
	 * labeled alternative in {@link CourierParser#constant}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConsRef(CourierParser.ConsRefContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ConsTrue}
	 * labeled alternative in {@link CourierParser#literalConstant}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConsTrue(CourierParser.ConsTrueContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ConsFalse}
	 * labeled alternative in {@link CourierParser#literalConstant}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConsFalse(CourierParser.ConsFalseContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ConsNumber}
	 * labeled alternative in {@link CourierParser#literalConstant}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConsNumber(CourierParser.ConsNumberContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ConsNumberNegative}
	 * labeled alternative in {@link CourierParser#literalConstant}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConsNumberNegative(CourierParser.ConsNumberNegativeContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ConsString}
	 * labeled alternative in {@link CourierParser#literalConstant}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConsString(CourierParser.ConsStringContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ConsArray}
	 * labeled alternative in {@link CourierParser#constructedConstant}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConsArray(CourierParser.ConsArrayContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ConsRecord}
	 * labeled alternative in {@link CourierParser#constructedConstant}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConsRecord(CourierParser.ConsRecordContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ConsRecordEmpty}
	 * labeled alternative in {@link CourierParser#constructedConstant}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConsRecordEmpty(CourierParser.ConsRecordEmptyContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ConsChoice}
	 * labeled alternative in {@link CourierParser#constructedConstant}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConsChoice(CourierParser.ConsChoiceContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#elementList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitElementList(CourierParser.ElementListContext ctx);
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
}