// Generated from src/main/java/yokwe/gen_stub/courier/antlr/Courier.g by ANTLR 4.13.2
package yokwe.gen_stub.courier.antlr;
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
	 * Visit a parse tree produced by the {@code DeclConst}
	 * labeled alternative in {@link CourierParser#declaration}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDeclConst(CourierParser.DeclConstContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#type}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitType(CourierParser.TypeContext ctx);
	/**
	 * Visit a parse tree produced by the {@code TypeBlock}
	 * labeled alternative in {@link CourierParser#predefinedType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeBlock(CourierParser.TypeBlockContext ctx);
	/**
	 * Visit a parse tree produced by the {@code TypeBoolean}
	 * labeled alternative in {@link CourierParser#predefinedType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeBoolean(CourierParser.TypeBooleanContext ctx);
	/**
	 * Visit a parse tree produced by the {@code TypeByte}
	 * labeled alternative in {@link CourierParser#predefinedType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeByte(CourierParser.TypeByteContext ctx);
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
	 * Visit a parse tree produced by the {@code TypeUnspecified2}
	 * labeled alternative in {@link CourierParser#predefinedType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeUnspecified2(CourierParser.TypeUnspecified2Context ctx);
	/**
	 * Visit a parse tree produced by the {@code TypeUnspecified3}
	 * labeled alternative in {@link CourierParser#predefinedType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeUnspecified3(CourierParser.TypeUnspecified3Context ctx);
	/**
	 * Visit a parse tree produced by the {@code TypeEmptyEnum}
	 * labeled alternative in {@link CourierParser#constructedType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeEmptyEnum(CourierParser.TypeEmptyEnumContext ctx);
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
	 * Visit a parse tree produced by the {@code TypeEmptyRecord}
	 * labeled alternative in {@link CourierParser#constructedType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeEmptyRecord(CourierParser.TypeEmptyRecordContext ctx);
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
	 * Visit a parse tree produced by the {@code TypeMachine}
	 * labeled alternative in {@link CourierParser#constructedType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeMachine(CourierParser.TypeMachineContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#enumType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitEnumType(CourierParser.EnumTypeContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#mdType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMdType(CourierParser.MdTypeContext ctx);
	/**
	 * Visit a parse tree produced by the {@code TypeRef}
	 * labeled alternative in {@link CourierParser#referencedType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeRef(CourierParser.TypeRefContext ctx);
	/**
	 * Visit a parse tree produced by the {@code TypeRefQ}
	 * labeled alternative in {@link CourierParser#referencedType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeRefQ(CourierParser.TypeRefQContext ctx);
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
	 * Visit a parse tree produced by the {@code ValueRefConsts}
	 * labeled alternative in {@link CourierParser#numericValue}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitValueRefConsts(CourierParser.ValueRefConstsContext ctx);
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
	 * Visit a parse tree produced by {@link CourierParser#mdFieldList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMdFieldList(CourierParser.MdFieldListContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#mdFieldType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMdFieldType(CourierParser.MdFieldTypeContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#mdField}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMdField(CourierParser.MdFieldContext ctx);
	/**
	 * Visit a parse tree produced by {@link CourierParser#constant}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConstant(CourierParser.ConstantContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ConstTrue}
	 * labeled alternative in {@link CourierParser#predefinedConstant}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConstTrue(CourierParser.ConstTrueContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ConstFalse}
	 * labeled alternative in {@link CourierParser#predefinedConstant}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConstFalse(CourierParser.ConstFalseContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ConstNumber}
	 * labeled alternative in {@link CourierParser#predefinedConstant}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConstNumber(CourierParser.ConstNumberContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ConstNumberNegative}
	 * labeled alternative in {@link CourierParser#predefinedConstant}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConstNumberNegative(CourierParser.ConstNumberNegativeContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ConstString}
	 * labeled alternative in {@link CourierParser#predefinedConstant}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConstString(CourierParser.ConstStringContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ConstArray}
	 * labeled alternative in {@link CourierParser#constructedConstant}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConstArray(CourierParser.ConstArrayContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ConstRecord}
	 * labeled alternative in {@link CourierParser#constructedConstant}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConstRecord(CourierParser.ConstRecordContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ConstEmpty}
	 * labeled alternative in {@link CourierParser#constructedConstant}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConstEmpty(CourierParser.ConstEmptyContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ConstChoice}
	 * labeled alternative in {@link CourierParser#constructedConstant}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConstChoice(CourierParser.ConstChoiceContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ConstRef}
	 * labeled alternative in {@link CourierParser#referencedConstant}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConstRef(CourierParser.ConstRefContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ConstRefQ}
	 * labeled alternative in {@link CourierParser#referencedConstant}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConstRefQ(CourierParser.ConstRefQContext ctx);
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