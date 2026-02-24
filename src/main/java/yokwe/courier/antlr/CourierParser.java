// Generated from src/main/java/yokwe/courier/antlr/Courier.g by ANTLR 4.13.2
package yokwe.courier.antlr;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue", "this-escape"})
public class CourierParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.2", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		T__9=10, T__10=11, T__11=12, T__12=13, T__13=14, ARRAY=15, BEGIN=16, BOOLEAN=17, 
		CARDINAL=18, CHOICE=19, DEPENDS=20, DEPENDENT=21, END=22, ERROR=23, INTEGER=24, 
		LONG=25, MACHINE=26, OF=27, PROCEDURE=28, PROGRAM=29, RECORD=30, REPORTS=31, 
		RETURNS=32, SEQUENCE=33, STRING=34, TYPE=35, UNSPECIFIED=36, UPON=37, 
		VERSION=38, TRUE=39, FALSE=40, NUMBER=41, ID=42, STR=43, COMMENT_PARTIAL=44, 
		COMMENT_LINE=45, SPACE=46;
	public static final int
		RULE_courierProgram = 0, RULE_dependencyList = 1, RULE_referencedProgramList = 2, 
		RULE_referencedProgram = 3, RULE_declarationList = 4, RULE_declaration = 5, 
		RULE_typeDecl = 6, RULE_consDecl = 7, RULE_type = 8, RULE_cons = 9, RULE_positiveNumberType = 10, 
		RULE_signedNumberType = 11, RULE_reference = 12, RULE_positiveNumber = 13, 
		RULE_negativeNumber = 14, RULE_signedNumber = 15, RULE_booleanType = 16, 
		RULE_booleanConstant = 17, RULE_cardinalType = 18, RULE_longCardinalType = 19, 
		RULE_integerType = 20, RULE_longIntegerType = 21, RULE_stringType = 22, 
		RULE_stringConstant = 23, RULE_unspecifiedType = 24, RULE_enumerationType = 25, 
		RULE_enumerationConstant = 26, RULE_correspondenceList = 27, RULE_correspondence = 28, 
		RULE_arrayType = 29, RULE_arrayConstant = 30, RULE_elementList = 31, RULE_sequenceType = 32, 
		RULE_recordType = 33, RULE_recordConstant = 34, RULE_fieldList = 35, RULE_field = 36, 
		RULE_componentList = 37, RULE_component = 38, RULE_nameList = 39, RULE_choiceType = 40, 
		RULE_choiceConstant = 41, RULE_candidateList = 42, RULE_candidate = 43, 
		RULE_designatorList = 44, RULE_designator = 45, RULE_candidateNameList = 46, 
		RULE_candidateName = 47, RULE_procedureType = 48, RULE_argumentList = 49, 
		RULE_resultList = 50, RULE_errorList = 51, RULE_errorType = 52;
	private static String[] makeRuleNames() {
		return new String[] {
			"courierProgram", "dependencyList", "referencedProgramList", "referencedProgram", 
			"declarationList", "declaration", "typeDecl", "consDecl", "type", "cons", 
			"positiveNumberType", "signedNumberType", "reference", "positiveNumber", 
			"negativeNumber", "signedNumber", "booleanType", "booleanConstant", "cardinalType", 
			"longCardinalType", "integerType", "longIntegerType", "stringType", "stringConstant", 
			"unspecifiedType", "enumerationType", "enumerationConstant", "correspondenceList", 
			"correspondence", "arrayType", "arrayConstant", "elementList", "sequenceType", 
			"recordType", "recordConstant", "fieldList", "field", "componentList", 
			"component", "nameList", "choiceType", "choiceConstant", "candidateList", 
			"candidate", "designatorList", "designator", "candidateNameList", "candidateName", 
			"procedureType", "argumentList", "resultList", "errorList", "errorType"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "':'", "'='", "'.'", "';'", "','", "'('", "')'", "'::'", "'-'", 
			"'{'", "'}'", "'['", "']'", "'=>'", "'ARRAY'", "'BEGIN'", "'BOOLEAN'", 
			"'CARDINAL'", "'CHOICE'", "'DEPENDS'", "'DEPENDENT'", "'END'", "'ERROR'", 
			"'INTEGER'", "'LONG'", "'MACHINE'", "'OF'", "'PROCEDURE'", "'PROGRAM'", 
			"'RECORD'", "'REPORTS'", "'RETURNS'", "'SEQUENCE'", "'STRING'", "'TYPE'", 
			"'UNSPECIFIED'", "'UPON'", "'VERSION'", "'TRUE'", "'FALSE'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, "ARRAY", "BEGIN", "BOOLEAN", "CARDINAL", "CHOICE", 
			"DEPENDS", "DEPENDENT", "END", "ERROR", "INTEGER", "LONG", "MACHINE", 
			"OF", "PROCEDURE", "PROGRAM", "RECORD", "REPORTS", "RETURNS", "SEQUENCE", 
			"STRING", "TYPE", "UNSPECIFIED", "UPON", "VERSION", "TRUE", "FALSE", 
			"NUMBER", "ID", "STR", "COMMENT_PARTIAL", "COMMENT_LINE", "SPACE"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "Courier.g"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public CourierParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class CourierProgramContext extends ParserRuleContext {
		public Token name;
		public PositiveNumberContext program;
		public PositiveNumberContext version;
		public TerminalNode PROGRAM() { return getToken(CourierParser.PROGRAM, 0); }
		public TerminalNode VERSION() { return getToken(CourierParser.VERSION, 0); }
		public TerminalNode BEGIN() { return getToken(CourierParser.BEGIN, 0); }
		public DependencyListContext dependencyList() {
			return getRuleContext(DependencyListContext.class,0);
		}
		public DeclarationListContext declarationList() {
			return getRuleContext(DeclarationListContext.class,0);
		}
		public TerminalNode END() { return getToken(CourierParser.END, 0); }
		public TerminalNode ID() { return getToken(CourierParser.ID, 0); }
		public List<PositiveNumberContext> positiveNumber() {
			return getRuleContexts(PositiveNumberContext.class);
		}
		public PositiveNumberContext positiveNumber(int i) {
			return getRuleContext(PositiveNumberContext.class,i);
		}
		public CourierProgramContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_courierProgram; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitCourierProgram(this);
			else return visitor.visitChildren(this);
		}
	}

	public final CourierProgramContext courierProgram() throws RecognitionException {
		CourierProgramContext _localctx = new CourierProgramContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_courierProgram);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(106);
			((CourierProgramContext)_localctx).name = match(ID);
			setState(107);
			match(T__0);
			setState(108);
			match(PROGRAM);
			setState(109);
			((CourierProgramContext)_localctx).program = positiveNumber();
			setState(110);
			match(VERSION);
			setState(111);
			((CourierProgramContext)_localctx).version = positiveNumber();
			setState(112);
			match(T__1);
			setState(113);
			match(BEGIN);
			setState(114);
			dependencyList();
			setState(115);
			declarationList();
			setState(116);
			match(END);
			setState(117);
			match(T__2);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class DependencyListContext extends ParserRuleContext {
		public TerminalNode DEPENDS() { return getToken(CourierParser.DEPENDS, 0); }
		public TerminalNode UPON() { return getToken(CourierParser.UPON, 0); }
		public ReferencedProgramListContext referencedProgramList() {
			return getRuleContext(ReferencedProgramListContext.class,0);
		}
		public DependencyListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_dependencyList; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitDependencyList(this);
			else return visitor.visitChildren(this);
		}
	}

	public final DependencyListContext dependencyList() throws RecognitionException {
		DependencyListContext _localctx = new DependencyListContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_dependencyList);
		try {
			setState(125);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case END:
			case ID:
				enterOuterAlt(_localctx, 1);
				{
				}
				break;
			case DEPENDS:
				enterOuterAlt(_localctx, 2);
				{
				setState(120);
				match(DEPENDS);
				setState(121);
				match(UPON);
				setState(122);
				referencedProgramList();
				setState(123);
				match(T__3);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ReferencedProgramListContext extends ParserRuleContext {
		public ReferencedProgramContext referencedProgram;
		public List<ReferencedProgramContext> elements = new ArrayList<ReferencedProgramContext>();
		public List<ReferencedProgramContext> referencedProgram() {
			return getRuleContexts(ReferencedProgramContext.class);
		}
		public ReferencedProgramContext referencedProgram(int i) {
			return getRuleContext(ReferencedProgramContext.class,i);
		}
		public ReferencedProgramListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_referencedProgramList; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitReferencedProgramList(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ReferencedProgramListContext referencedProgramList() throws RecognitionException {
		ReferencedProgramListContext _localctx = new ReferencedProgramListContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_referencedProgramList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(127);
			((ReferencedProgramListContext)_localctx).referencedProgram = referencedProgram();
			((ReferencedProgramListContext)_localctx).elements.add(((ReferencedProgramListContext)_localctx).referencedProgram);
			setState(132);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__4) {
				{
				{
				setState(128);
				match(T__4);
				setState(129);
				((ReferencedProgramListContext)_localctx).referencedProgram = referencedProgram();
				((ReferencedProgramListContext)_localctx).elements.add(((ReferencedProgramListContext)_localctx).referencedProgram);
				}
				}
				setState(134);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ReferencedProgramContext extends ParserRuleContext {
		public Token name;
		public PositiveNumberContext program;
		public PositiveNumberContext version;
		public TerminalNode VERSION() { return getToken(CourierParser.VERSION, 0); }
		public TerminalNode ID() { return getToken(CourierParser.ID, 0); }
		public List<PositiveNumberContext> positiveNumber() {
			return getRuleContexts(PositiveNumberContext.class);
		}
		public PositiveNumberContext positiveNumber(int i) {
			return getRuleContext(PositiveNumberContext.class,i);
		}
		public ReferencedProgramContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_referencedProgram; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitReferencedProgram(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ReferencedProgramContext referencedProgram() throws RecognitionException {
		ReferencedProgramContext _localctx = new ReferencedProgramContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_referencedProgram);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(135);
			((ReferencedProgramContext)_localctx).name = match(ID);
			setState(136);
			match(T__5);
			setState(137);
			((ReferencedProgramContext)_localctx).program = positiveNumber();
			setState(138);
			match(T__6);
			setState(139);
			match(VERSION);
			setState(140);
			((ReferencedProgramContext)_localctx).version = positiveNumber();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class DeclarationListContext extends ParserRuleContext {
		public DeclarationContext declaration;
		public List<DeclarationContext> elements = new ArrayList<DeclarationContext>();
		public List<DeclarationContext> declaration() {
			return getRuleContexts(DeclarationContext.class);
		}
		public DeclarationContext declaration(int i) {
			return getRuleContext(DeclarationContext.class,i);
		}
		public DeclarationListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declarationList; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitDeclarationList(this);
			else return visitor.visitChildren(this);
		}
	}

	public final DeclarationListContext declarationList() throws RecognitionException {
		DeclarationListContext _localctx = new DeclarationListContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_declarationList);
		int _la;
		try {
			setState(148);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case END:
				enterOuterAlt(_localctx, 1);
				{
				}
				break;
			case ID:
				enterOuterAlt(_localctx, 2);
				{
				setState(144); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(143);
					((DeclarationListContext)_localctx).declaration = declaration();
					((DeclarationListContext)_localctx).elements.add(((DeclarationListContext)_localctx).declaration);
					}
					}
					setState(146); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==ID );
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class DeclarationContext extends ParserRuleContext {
		public DeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declaration; }
	 
		public DeclarationContext() { }
		public void copyFrom(DeclarationContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class DeclarationTypeContext extends DeclarationContext {
		public TypeDeclContext typeDecl() {
			return getRuleContext(TypeDeclContext.class,0);
		}
		public DeclarationTypeContext(DeclarationContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitDeclarationType(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class DeclarationConsContext extends DeclarationContext {
		public ConsDeclContext consDecl() {
			return getRuleContext(ConsDeclContext.class,0);
		}
		public DeclarationConsContext(DeclarationContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitDeclarationCons(this);
			else return visitor.visitChildren(this);
		}
	}

	public final DeclarationContext declaration() throws RecognitionException {
		DeclarationContext _localctx = new DeclarationContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_declaration);
		try {
			setState(152);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
			case 1:
				_localctx = new DeclarationTypeContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(150);
				typeDecl();
				}
				break;
			case 2:
				_localctx = new DeclarationConsContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(151);
				consDecl();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class TypeDeclContext extends ParserRuleContext {
		public Token name;
		public TerminalNode TYPE() { return getToken(CourierParser.TYPE, 0); }
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public TerminalNode ID() { return getToken(CourierParser.ID, 0); }
		public TypeDeclContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_typeDecl; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeDecl(this);
			else return visitor.visitChildren(this);
		}
	}

	public final TypeDeclContext typeDecl() throws RecognitionException {
		TypeDeclContext _localctx = new TypeDeclContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_typeDecl);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(154);
			((TypeDeclContext)_localctx).name = match(ID);
			setState(155);
			match(T__0);
			setState(156);
			match(TYPE);
			setState(157);
			match(T__1);
			setState(158);
			type();
			setState(159);
			match(T__3);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ConsDeclContext extends ParserRuleContext {
		public ConsDeclContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_consDecl; }
	 
		public ConsDeclContext() { }
		public void copyFrom(ConsDeclContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ConsDeclProcedureContext extends ConsDeclContext {
		public Token name;
		public ProcedureTypeContext procedureType() {
			return getRuleContext(ProcedureTypeContext.class,0);
		}
		public PositiveNumberContext positiveNumber() {
			return getRuleContext(PositiveNumberContext.class,0);
		}
		public TerminalNode ID() { return getToken(CourierParser.ID, 0); }
		public ConsDeclProcedureContext(ConsDeclContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitConsDeclProcedure(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ConsDeclStringContext extends ConsDeclContext {
		public Token name;
		public StringTypeContext stringType() {
			return getRuleContext(StringTypeContext.class,0);
		}
		public StringConstantContext stringConstant() {
			return getRuleContext(StringConstantContext.class,0);
		}
		public TerminalNode ID() { return getToken(CourierParser.ID, 0); }
		public ConsDeclStringContext(ConsDeclContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitConsDeclString(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ConsDeclSignedNumberContext extends ConsDeclContext {
		public Token name;
		public SignedNumberTypeContext signedNumberType() {
			return getRuleContext(SignedNumberTypeContext.class,0);
		}
		public SignedNumberContext signedNumber() {
			return getRuleContext(SignedNumberContext.class,0);
		}
		public TerminalNode ID() { return getToken(CourierParser.ID, 0); }
		public ConsDeclSignedNumberContext(ConsDeclContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitConsDeclSignedNumber(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ConsDeclErrorContext extends ConsDeclContext {
		public Token name;
		public ErrorTypeContext errorType() {
			return getRuleContext(ErrorTypeContext.class,0);
		}
		public PositiveNumberContext positiveNumber() {
			return getRuleContext(PositiveNumberContext.class,0);
		}
		public TerminalNode ID() { return getToken(CourierParser.ID, 0); }
		public ConsDeclErrorContext(ConsDeclContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitConsDeclError(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ConsDeclBooleanContext extends ConsDeclContext {
		public Token name;
		public BooleanTypeContext booleanType() {
			return getRuleContext(BooleanTypeContext.class,0);
		}
		public BooleanConstantContext booleanConstant() {
			return getRuleContext(BooleanConstantContext.class,0);
		}
		public TerminalNode ID() { return getToken(CourierParser.ID, 0); }
		public ConsDeclBooleanContext(ConsDeclContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitConsDeclBoolean(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ConsDeclPositiveNumberContext extends ConsDeclContext {
		public Token name;
		public PositiveNumberTypeContext positiveNumberType() {
			return getRuleContext(PositiveNumberTypeContext.class,0);
		}
		public PositiveNumberContext positiveNumber() {
			return getRuleContext(PositiveNumberContext.class,0);
		}
		public TerminalNode ID() { return getToken(CourierParser.ID, 0); }
		public ConsDeclPositiveNumberContext(ConsDeclContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitConsDeclPositiveNumber(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ConsDeclReferenceContext extends ConsDeclContext {
		public Token name;
		public ReferenceContext reference() {
			return getRuleContext(ReferenceContext.class,0);
		}
		public ConsContext cons() {
			return getRuleContext(ConsContext.class,0);
		}
		public TerminalNode ID() { return getToken(CourierParser.ID, 0); }
		public ConsDeclReferenceContext(ConsDeclContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitConsDeclReference(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ConsDeclContext consDecl() throws RecognitionException {
		ConsDeclContext _localctx = new ConsDeclContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_consDecl);
		try {
			setState(210);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,5,_ctx) ) {
			case 1:
				_localctx = new ConsDeclBooleanContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(161);
				((ConsDeclBooleanContext)_localctx).name = match(ID);
				setState(162);
				match(T__0);
				setState(163);
				booleanType();
				setState(164);
				match(T__1);
				setState(165);
				booleanConstant();
				setState(166);
				match(T__3);
				}
				break;
			case 2:
				_localctx = new ConsDeclStringContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(168);
				((ConsDeclStringContext)_localctx).name = match(ID);
				setState(169);
				match(T__0);
				setState(170);
				stringType();
				setState(171);
				match(T__1);
				setState(172);
				stringConstant();
				setState(173);
				match(T__3);
				}
				break;
			case 3:
				_localctx = new ConsDeclPositiveNumberContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(175);
				((ConsDeclPositiveNumberContext)_localctx).name = match(ID);
				setState(176);
				match(T__0);
				setState(177);
				positiveNumberType();
				setState(178);
				match(T__1);
				setState(179);
				positiveNumber();
				setState(180);
				match(T__3);
				}
				break;
			case 4:
				_localctx = new ConsDeclSignedNumberContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(182);
				((ConsDeclSignedNumberContext)_localctx).name = match(ID);
				setState(183);
				match(T__0);
				setState(184);
				signedNumberType();
				setState(185);
				match(T__1);
				setState(186);
				signedNumber();
				setState(187);
				match(T__3);
				}
				break;
			case 5:
				_localctx = new ConsDeclErrorContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(189);
				((ConsDeclErrorContext)_localctx).name = match(ID);
				setState(190);
				match(T__0);
				setState(191);
				errorType();
				setState(192);
				match(T__1);
				setState(193);
				positiveNumber();
				setState(194);
				match(T__3);
				}
				break;
			case 6:
				_localctx = new ConsDeclProcedureContext(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(196);
				((ConsDeclProcedureContext)_localctx).name = match(ID);
				setState(197);
				match(T__0);
				setState(198);
				procedureType();
				setState(199);
				match(T__1);
				setState(200);
				positiveNumber();
				setState(201);
				match(T__3);
				}
				break;
			case 7:
				_localctx = new ConsDeclReferenceContext(_localctx);
				enterOuterAlt(_localctx, 7);
				{
				setState(203);
				((ConsDeclReferenceContext)_localctx).name = match(ID);
				setState(204);
				match(T__0);
				setState(205);
				reference();
				setState(206);
				match(T__1);
				setState(207);
				cons();
				setState(208);
				match(T__3);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class TypeContext extends ParserRuleContext {
		public TypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type; }
	 
		public TypeContext() { }
		public void copyFrom(TypeContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeLongIntegerContext extends TypeContext {
		public LongIntegerTypeContext longIntegerType() {
			return getRuleContext(LongIntegerTypeContext.class,0);
		}
		public TypeLongIntegerContext(TypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeLongInteger(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeArrayContext extends TypeContext {
		public ArrayTypeContext arrayType() {
			return getRuleContext(ArrayTypeContext.class,0);
		}
		public TypeArrayContext(TypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeArray(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeUnspecifiedContext extends TypeContext {
		public UnspecifiedTypeContext unspecifiedType() {
			return getRuleContext(UnspecifiedTypeContext.class,0);
		}
		public TypeUnspecifiedContext(TypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeUnspecified(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeEnumerationContext extends TypeContext {
		public EnumerationTypeContext enumerationType() {
			return getRuleContext(EnumerationTypeContext.class,0);
		}
		public TypeEnumerationContext(TypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeEnumeration(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeStringContext extends TypeContext {
		public StringTypeContext stringType() {
			return getRuleContext(StringTypeContext.class,0);
		}
		public TypeStringContext(TypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeString(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeCardinalContext extends TypeContext {
		public CardinalTypeContext cardinalType() {
			return getRuleContext(CardinalTypeContext.class,0);
		}
		public TypeCardinalContext(TypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeCardinal(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeBooleanContext extends TypeContext {
		public BooleanTypeContext booleanType() {
			return getRuleContext(BooleanTypeContext.class,0);
		}
		public TypeBooleanContext(TypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeBoolean(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeIntegerContext extends TypeContext {
		public IntegerTypeContext integerType() {
			return getRuleContext(IntegerTypeContext.class,0);
		}
		public TypeIntegerContext(TypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeInteger(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeSequenceContext extends TypeContext {
		public SequenceTypeContext sequenceType() {
			return getRuleContext(SequenceTypeContext.class,0);
		}
		public TypeSequenceContext(TypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeSequence(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeChoiceContext extends TypeContext {
		public ChoiceTypeContext choiceType() {
			return getRuleContext(ChoiceTypeContext.class,0);
		}
		public TypeChoiceContext(TypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeChoice(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeLongCardinalContext extends TypeContext {
		public LongCardinalTypeContext longCardinalType() {
			return getRuleContext(LongCardinalTypeContext.class,0);
		}
		public TypeLongCardinalContext(TypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeLongCardinal(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeErrorContext extends TypeContext {
		public ErrorTypeContext errorType() {
			return getRuleContext(ErrorTypeContext.class,0);
		}
		public TypeErrorContext(TypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeError(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeReferenceContext extends TypeContext {
		public ReferenceContext reference() {
			return getRuleContext(ReferenceContext.class,0);
		}
		public TypeReferenceContext(TypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeReference(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeRecordContext extends TypeContext {
		public RecordTypeContext recordType() {
			return getRuleContext(RecordTypeContext.class,0);
		}
		public TypeRecordContext(TypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeRecord(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeProcedureContext extends TypeContext {
		public ProcedureTypeContext procedureType() {
			return getRuleContext(ProcedureTypeContext.class,0);
		}
		public TypeProcedureContext(TypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeProcedure(this);
			else return visitor.visitChildren(this);
		}
	}

	public final TypeContext type() throws RecognitionException {
		TypeContext _localctx = new TypeContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_type);
		try {
			setState(227);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,6,_ctx) ) {
			case 1:
				_localctx = new TypeBooleanContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(212);
				booleanType();
				}
				break;
			case 2:
				_localctx = new TypeStringContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(213);
				stringType();
				}
				break;
			case 3:
				_localctx = new TypeCardinalContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(214);
				cardinalType();
				}
				break;
			case 4:
				_localctx = new TypeLongCardinalContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(215);
				longCardinalType();
				}
				break;
			case 5:
				_localctx = new TypeUnspecifiedContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(216);
				unspecifiedType();
				}
				break;
			case 6:
				_localctx = new TypeIntegerContext(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(217);
				integerType();
				}
				break;
			case 7:
				_localctx = new TypeLongIntegerContext(_localctx);
				enterOuterAlt(_localctx, 7);
				{
				setState(218);
				longIntegerType();
				}
				break;
			case 8:
				_localctx = new TypeEnumerationContext(_localctx);
				enterOuterAlt(_localctx, 8);
				{
				setState(219);
				enumerationType();
				}
				break;
			case 9:
				_localctx = new TypeArrayContext(_localctx);
				enterOuterAlt(_localctx, 9);
				{
				setState(220);
				arrayType();
				}
				break;
			case 10:
				_localctx = new TypeSequenceContext(_localctx);
				enterOuterAlt(_localctx, 10);
				{
				setState(221);
				sequenceType();
				}
				break;
			case 11:
				_localctx = new TypeRecordContext(_localctx);
				enterOuterAlt(_localctx, 11);
				{
				setState(222);
				recordType();
				}
				break;
			case 12:
				_localctx = new TypeChoiceContext(_localctx);
				enterOuterAlt(_localctx, 12);
				{
				setState(223);
				choiceType();
				}
				break;
			case 13:
				_localctx = new TypeProcedureContext(_localctx);
				enterOuterAlt(_localctx, 13);
				{
				setState(224);
				procedureType();
				}
				break;
			case 14:
				_localctx = new TypeErrorContext(_localctx);
				enterOuterAlt(_localctx, 14);
				{
				setState(225);
				errorType();
				}
				break;
			case 15:
				_localctx = new TypeReferenceContext(_localctx);
				enterOuterAlt(_localctx, 15);
				{
				setState(226);
				reference();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ConsContext extends ParserRuleContext {
		public ConsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_cons; }
	 
		public ConsContext() { }
		public void copyFrom(ConsContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ConsBooleanContext extends ConsContext {
		public BooleanConstantContext booleanConstant() {
			return getRuleContext(BooleanConstantContext.class,0);
		}
		public ConsBooleanContext(ConsContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitConsBoolean(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ConsNegativeContext extends ConsContext {
		public NegativeNumberContext negativeNumber() {
			return getRuleContext(NegativeNumberContext.class,0);
		}
		public ConsNegativeContext(ConsContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitConsNegative(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ConsChoiceContext extends ConsContext {
		public ChoiceConstantContext choiceConstant() {
			return getRuleContext(ChoiceConstantContext.class,0);
		}
		public ConsChoiceContext(ConsContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitConsChoice(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ConsArrayContext extends ConsContext {
		public ArrayConstantContext arrayConstant() {
			return getRuleContext(ArrayConstantContext.class,0);
		}
		public ConsArrayContext(ConsContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitConsArray(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ConsPositiveContext extends ConsContext {
		public PositiveNumberContext positiveNumber() {
			return getRuleContext(PositiveNumberContext.class,0);
		}
		public ConsPositiveContext(ConsContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitConsPositive(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ConsReferenceContext extends ConsContext {
		public ReferenceContext reference() {
			return getRuleContext(ReferenceContext.class,0);
		}
		public ConsReferenceContext(ConsContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitConsReference(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ConsStringContext extends ConsContext {
		public StringConstantContext stringConstant() {
			return getRuleContext(StringConstantContext.class,0);
		}
		public ConsStringContext(ConsContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitConsString(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ConsRecordContext extends ConsContext {
		public RecordConstantContext recordConstant() {
			return getRuleContext(RecordConstantContext.class,0);
		}
		public ConsRecordContext(ConsContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitConsRecord(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ConsContext cons() throws RecognitionException {
		ConsContext _localctx = new ConsContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_cons);
		try {
			setState(237);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,7,_ctx) ) {
			case 1:
				_localctx = new ConsBooleanContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(229);
				booleanConstant();
				}
				break;
			case 2:
				_localctx = new ConsStringContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(230);
				stringConstant();
				}
				break;
			case 3:
				_localctx = new ConsPositiveContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(231);
				positiveNumber();
				}
				break;
			case 4:
				_localctx = new ConsNegativeContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(232);
				negativeNumber();
				}
				break;
			case 5:
				_localctx = new ConsArrayContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(233);
				arrayConstant();
				}
				break;
			case 6:
				_localctx = new ConsRecordContext(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(234);
				recordConstant();
				}
				break;
			case 7:
				_localctx = new ConsChoiceContext(_localctx);
				enterOuterAlt(_localctx, 7);
				{
				setState(235);
				choiceConstant();
				}
				break;
			case 8:
				_localctx = new ConsReferenceContext(_localctx);
				enterOuterAlt(_localctx, 8);
				{
				setState(236);
				reference();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class PositiveNumberTypeContext extends ParserRuleContext {
		public PositiveNumberTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_positiveNumberType; }
	 
		public PositiveNumberTypeContext() { }
		public void copyFrom(PositiveNumberTypeContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class PositiveNumberTypeLongCardinalContext extends PositiveNumberTypeContext {
		public LongCardinalTypeContext longCardinalType() {
			return getRuleContext(LongCardinalTypeContext.class,0);
		}
		public PositiveNumberTypeLongCardinalContext(PositiveNumberTypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitPositiveNumberTypeLongCardinal(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class PositiveNumberTypeCardinalContext extends PositiveNumberTypeContext {
		public CardinalTypeContext cardinalType() {
			return getRuleContext(CardinalTypeContext.class,0);
		}
		public PositiveNumberTypeCardinalContext(PositiveNumberTypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitPositiveNumberTypeCardinal(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class PositiveNumberTypeUnspecifiedContext extends PositiveNumberTypeContext {
		public UnspecifiedTypeContext unspecifiedType() {
			return getRuleContext(UnspecifiedTypeContext.class,0);
		}
		public PositiveNumberTypeUnspecifiedContext(PositiveNumberTypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitPositiveNumberTypeUnspecified(this);
			else return visitor.visitChildren(this);
		}
	}

	public final PositiveNumberTypeContext positiveNumberType() throws RecognitionException {
		PositiveNumberTypeContext _localctx = new PositiveNumberTypeContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_positiveNumberType);
		try {
			setState(242);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case CARDINAL:
				_localctx = new PositiveNumberTypeCardinalContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(239);
				cardinalType();
				}
				break;
			case LONG:
				_localctx = new PositiveNumberTypeLongCardinalContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(240);
				longCardinalType();
				}
				break;
			case UNSPECIFIED:
				_localctx = new PositiveNumberTypeUnspecifiedContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(241);
				unspecifiedType();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class SignedNumberTypeContext extends ParserRuleContext {
		public SignedNumberTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_signedNumberType; }
	 
		public SignedNumberTypeContext() { }
		public void copyFrom(SignedNumberTypeContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class SignedNumberTypeIntegerContext extends SignedNumberTypeContext {
		public IntegerTypeContext integerType() {
			return getRuleContext(IntegerTypeContext.class,0);
		}
		public SignedNumberTypeIntegerContext(SignedNumberTypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitSignedNumberTypeInteger(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class SignedNumberTypeLongIntegerContext extends SignedNumberTypeContext {
		public LongIntegerTypeContext longIntegerType() {
			return getRuleContext(LongIntegerTypeContext.class,0);
		}
		public SignedNumberTypeLongIntegerContext(SignedNumberTypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitSignedNumberTypeLongInteger(this);
			else return visitor.visitChildren(this);
		}
	}

	public final SignedNumberTypeContext signedNumberType() throws RecognitionException {
		SignedNumberTypeContext _localctx = new SignedNumberTypeContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_signedNumberType);
		try {
			setState(246);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case INTEGER:
				_localctx = new SignedNumberTypeIntegerContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(244);
				integerType();
				}
				break;
			case LONG:
				_localctx = new SignedNumberTypeLongIntegerContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(245);
				longIntegerType();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ReferenceContext extends ParserRuleContext {
		public ReferenceContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_reference; }
	 
		public ReferenceContext() { }
		public void copyFrom(ReferenceContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ReferenceRemoteContext extends ReferenceContext {
		public Token program;
		public Token name;
		public List<TerminalNode> ID() { return getTokens(CourierParser.ID); }
		public TerminalNode ID(int i) {
			return getToken(CourierParser.ID, i);
		}
		public ReferenceRemoteContext(ReferenceContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitReferenceRemote(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ReferenceExternalContext extends ReferenceContext {
		public Token program;
		public Token name;
		public List<TerminalNode> ID() { return getTokens(CourierParser.ID); }
		public TerminalNode ID(int i) {
			return getToken(CourierParser.ID, i);
		}
		public ReferenceExternalContext(ReferenceContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitReferenceExternal(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ReferenceLocalContext extends ReferenceContext {
		public Token name;
		public TerminalNode ID() { return getToken(CourierParser.ID, 0); }
		public ReferenceLocalContext(ReferenceContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitReferenceLocal(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ReferenceContext reference() throws RecognitionException {
		ReferenceContext _localctx = new ReferenceContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_reference);
		try {
			setState(255);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,10,_ctx) ) {
			case 1:
				_localctx = new ReferenceLocalContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(248);
				((ReferenceLocalContext)_localctx).name = match(ID);
				}
				break;
			case 2:
				_localctx = new ReferenceRemoteContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(249);
				((ReferenceRemoteContext)_localctx).program = match(ID);
				setState(250);
				match(T__2);
				setState(251);
				((ReferenceRemoteContext)_localctx).name = match(ID);
				}
				break;
			case 3:
				_localctx = new ReferenceExternalContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(252);
				((ReferenceExternalContext)_localctx).program = match(ID);
				setState(253);
				match(T__7);
				setState(254);
				((ReferenceExternalContext)_localctx).name = match(ID);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class PositiveNumberContext extends ParserRuleContext {
		public TerminalNode NUMBER() { return getToken(CourierParser.NUMBER, 0); }
		public PositiveNumberContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_positiveNumber; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitPositiveNumber(this);
			else return visitor.visitChildren(this);
		}
	}

	public final PositiveNumberContext positiveNumber() throws RecognitionException {
		PositiveNumberContext _localctx = new PositiveNumberContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_positiveNumber);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(257);
			match(NUMBER);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class NegativeNumberContext extends ParserRuleContext {
		public TerminalNode NUMBER() { return getToken(CourierParser.NUMBER, 0); }
		public NegativeNumberContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_negativeNumber; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitNegativeNumber(this);
			else return visitor.visitChildren(this);
		}
	}

	public final NegativeNumberContext negativeNumber() throws RecognitionException {
		NegativeNumberContext _localctx = new NegativeNumberContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_negativeNumber);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(259);
			match(T__8);
			setState(260);
			match(NUMBER);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class SignedNumberContext extends ParserRuleContext {
		public SignedNumberContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_signedNumber; }
	 
		public SignedNumberContext() { }
		public void copyFrom(SignedNumberContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class SignedNumberPositiveContext extends SignedNumberContext {
		public PositiveNumberContext positiveNumber() {
			return getRuleContext(PositiveNumberContext.class,0);
		}
		public SignedNumberPositiveContext(SignedNumberContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitSignedNumberPositive(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class SignedNumberNegativeContext extends SignedNumberContext {
		public NegativeNumberContext negativeNumber() {
			return getRuleContext(NegativeNumberContext.class,0);
		}
		public SignedNumberNegativeContext(SignedNumberContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitSignedNumberNegative(this);
			else return visitor.visitChildren(this);
		}
	}

	public final SignedNumberContext signedNumber() throws RecognitionException {
		SignedNumberContext _localctx = new SignedNumberContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_signedNumber);
		try {
			setState(264);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case NUMBER:
				_localctx = new SignedNumberPositiveContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(262);
				positiveNumber();
				}
				break;
			case T__8:
				_localctx = new SignedNumberNegativeContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(263);
				negativeNumber();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class BooleanTypeContext extends ParserRuleContext {
		public TerminalNode BOOLEAN() { return getToken(CourierParser.BOOLEAN, 0); }
		public BooleanTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_booleanType; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitBooleanType(this);
			else return visitor.visitChildren(this);
		}
	}

	public final BooleanTypeContext booleanType() throws RecognitionException {
		BooleanTypeContext _localctx = new BooleanTypeContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_booleanType);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(266);
			match(BOOLEAN);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class BooleanConstantContext extends ParserRuleContext {
		public BooleanConstantContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_booleanConstant; }
	 
		public BooleanConstantContext() { }
		public void copyFrom(BooleanConstantContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class BooleanConstantTrueContext extends BooleanConstantContext {
		public TerminalNode TRUE() { return getToken(CourierParser.TRUE, 0); }
		public BooleanConstantTrueContext(BooleanConstantContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitBooleanConstantTrue(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class BooleanConstantFalseContext extends BooleanConstantContext {
		public TerminalNode FALSE() { return getToken(CourierParser.FALSE, 0); }
		public BooleanConstantFalseContext(BooleanConstantContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitBooleanConstantFalse(this);
			else return visitor.visitChildren(this);
		}
	}

	public final BooleanConstantContext booleanConstant() throws RecognitionException {
		BooleanConstantContext _localctx = new BooleanConstantContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_booleanConstant);
		try {
			setState(270);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case TRUE:
				_localctx = new BooleanConstantTrueContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(268);
				match(TRUE);
				}
				break;
			case FALSE:
				_localctx = new BooleanConstantFalseContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(269);
				match(FALSE);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class CardinalTypeContext extends ParserRuleContext {
		public TerminalNode CARDINAL() { return getToken(CourierParser.CARDINAL, 0); }
		public CardinalTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_cardinalType; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitCardinalType(this);
			else return visitor.visitChildren(this);
		}
	}

	public final CardinalTypeContext cardinalType() throws RecognitionException {
		CardinalTypeContext _localctx = new CardinalTypeContext(_ctx, getState());
		enterRule(_localctx, 36, RULE_cardinalType);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(272);
			match(CARDINAL);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class LongCardinalTypeContext extends ParserRuleContext {
		public TerminalNode LONG() { return getToken(CourierParser.LONG, 0); }
		public TerminalNode CARDINAL() { return getToken(CourierParser.CARDINAL, 0); }
		public LongCardinalTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_longCardinalType; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitLongCardinalType(this);
			else return visitor.visitChildren(this);
		}
	}

	public final LongCardinalTypeContext longCardinalType() throws RecognitionException {
		LongCardinalTypeContext _localctx = new LongCardinalTypeContext(_ctx, getState());
		enterRule(_localctx, 38, RULE_longCardinalType);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(274);
			match(LONG);
			setState(275);
			match(CARDINAL);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class IntegerTypeContext extends ParserRuleContext {
		public TerminalNode INTEGER() { return getToken(CourierParser.INTEGER, 0); }
		public IntegerTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_integerType; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitIntegerType(this);
			else return visitor.visitChildren(this);
		}
	}

	public final IntegerTypeContext integerType() throws RecognitionException {
		IntegerTypeContext _localctx = new IntegerTypeContext(_ctx, getState());
		enterRule(_localctx, 40, RULE_integerType);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(277);
			match(INTEGER);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class LongIntegerTypeContext extends ParserRuleContext {
		public TerminalNode LONG() { return getToken(CourierParser.LONG, 0); }
		public TerminalNode INTEGER() { return getToken(CourierParser.INTEGER, 0); }
		public LongIntegerTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_longIntegerType; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitLongIntegerType(this);
			else return visitor.visitChildren(this);
		}
	}

	public final LongIntegerTypeContext longIntegerType() throws RecognitionException {
		LongIntegerTypeContext _localctx = new LongIntegerTypeContext(_ctx, getState());
		enterRule(_localctx, 42, RULE_longIntegerType);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(279);
			match(LONG);
			setState(280);
			match(INTEGER);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StringTypeContext extends ParserRuleContext {
		public TerminalNode STRING() { return getToken(CourierParser.STRING, 0); }
		public StringTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_stringType; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitStringType(this);
			else return visitor.visitChildren(this);
		}
	}

	public final StringTypeContext stringType() throws RecognitionException {
		StringTypeContext _localctx = new StringTypeContext(_ctx, getState());
		enterRule(_localctx, 44, RULE_stringType);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(282);
			match(STRING);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StringConstantContext extends ParserRuleContext {
		public TerminalNode STR() { return getToken(CourierParser.STR, 0); }
		public StringConstantContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_stringConstant; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitStringConstant(this);
			else return visitor.visitChildren(this);
		}
	}

	public final StringConstantContext stringConstant() throws RecognitionException {
		StringConstantContext _localctx = new StringConstantContext(_ctx, getState());
		enterRule(_localctx, 46, RULE_stringConstant);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(284);
			match(STR);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class UnspecifiedTypeContext extends ParserRuleContext {
		public TerminalNode UNSPECIFIED() { return getToken(CourierParser.UNSPECIFIED, 0); }
		public UnspecifiedTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unspecifiedType; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitUnspecifiedType(this);
			else return visitor.visitChildren(this);
		}
	}

	public final UnspecifiedTypeContext unspecifiedType() throws RecognitionException {
		UnspecifiedTypeContext _localctx = new UnspecifiedTypeContext(_ctx, getState());
		enterRule(_localctx, 48, RULE_unspecifiedType);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(286);
			match(UNSPECIFIED);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class EnumerationTypeContext extends ParserRuleContext {
		public CorrespondenceListContext correspondenceList() {
			return getRuleContext(CorrespondenceListContext.class,0);
		}
		public EnumerationTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_enumerationType; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitEnumerationType(this);
			else return visitor.visitChildren(this);
		}
	}

	public final EnumerationTypeContext enumerationType() throws RecognitionException {
		EnumerationTypeContext _localctx = new EnumerationTypeContext(_ctx, getState());
		enterRule(_localctx, 50, RULE_enumerationType);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(288);
			match(T__9);
			setState(289);
			correspondenceList();
			setState(290);
			match(T__10);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class EnumerationConstantContext extends ParserRuleContext {
		public Token name;
		public TerminalNode ID() { return getToken(CourierParser.ID, 0); }
		public EnumerationConstantContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_enumerationConstant; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitEnumerationConstant(this);
			else return visitor.visitChildren(this);
		}
	}

	public final EnumerationConstantContext enumerationConstant() throws RecognitionException {
		EnumerationConstantContext _localctx = new EnumerationConstantContext(_ctx, getState());
		enterRule(_localctx, 52, RULE_enumerationConstant);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(292);
			((EnumerationConstantContext)_localctx).name = match(ID);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class CorrespondenceListContext extends ParserRuleContext {
		public CorrespondenceContext correspondence;
		public List<CorrespondenceContext> elements = new ArrayList<CorrespondenceContext>();
		public List<CorrespondenceContext> correspondence() {
			return getRuleContexts(CorrespondenceContext.class);
		}
		public CorrespondenceContext correspondence(int i) {
			return getRuleContext(CorrespondenceContext.class,i);
		}
		public CorrespondenceListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_correspondenceList; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitCorrespondenceList(this);
			else return visitor.visitChildren(this);
		}
	}

	public final CorrespondenceListContext correspondenceList() throws RecognitionException {
		CorrespondenceListContext _localctx = new CorrespondenceListContext(_ctx, getState());
		enterRule(_localctx, 54, RULE_correspondenceList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(294);
			((CorrespondenceListContext)_localctx).correspondence = correspondence();
			((CorrespondenceListContext)_localctx).elements.add(((CorrespondenceListContext)_localctx).correspondence);
			setState(299);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__4) {
				{
				{
				setState(295);
				match(T__4);
				setState(296);
				((CorrespondenceListContext)_localctx).correspondence = correspondence();
				((CorrespondenceListContext)_localctx).elements.add(((CorrespondenceListContext)_localctx).correspondence);
				}
				}
				setState(301);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class CorrespondenceContext extends ParserRuleContext {
		public Token name;
		public PositiveNumberContext number;
		public TerminalNode ID() { return getToken(CourierParser.ID, 0); }
		public PositiveNumberContext positiveNumber() {
			return getRuleContext(PositiveNumberContext.class,0);
		}
		public CorrespondenceContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_correspondence; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitCorrespondence(this);
			else return visitor.visitChildren(this);
		}
	}

	public final CorrespondenceContext correspondence() throws RecognitionException {
		CorrespondenceContext _localctx = new CorrespondenceContext(_ctx, getState());
		enterRule(_localctx, 56, RULE_correspondence);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(302);
			((CorrespondenceContext)_localctx).name = match(ID);
			setState(303);
			match(T__5);
			setState(304);
			((CorrespondenceContext)_localctx).number = positiveNumber();
			setState(305);
			match(T__6);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ArrayTypeContext extends ParserRuleContext {
		public ArrayTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_arrayType; }
	 
		public ArrayTypeContext() { }
		public void copyFrom(ArrayTypeContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ArrayTypeNumberContext extends ArrayTypeContext {
		public TerminalNode ARRAY() { return getToken(CourierParser.ARRAY, 0); }
		public PositiveNumberContext positiveNumber() {
			return getRuleContext(PositiveNumberContext.class,0);
		}
		public TerminalNode OF() { return getToken(CourierParser.OF, 0); }
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public ArrayTypeNumberContext(ArrayTypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitArrayTypeNumber(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ArrayTypeContext arrayType() throws RecognitionException {
		ArrayTypeContext _localctx = new ArrayTypeContext(_ctx, getState());
		enterRule(_localctx, 58, RULE_arrayType);
		try {
			_localctx = new ArrayTypeNumberContext(_localctx);
			enterOuterAlt(_localctx, 1);
			{
			setState(307);
			match(ARRAY);
			setState(308);
			positiveNumber();
			setState(309);
			match(OF);
			setState(310);
			type();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ArrayConstantContext extends ParserRuleContext {
		public ArrayConstantContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_arrayConstant; }
	 
		public ArrayConstantContext() { }
		public void copyFrom(ArrayConstantContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ArrayConstantEmptyContext extends ArrayConstantContext {
		public ArrayConstantEmptyContext(ArrayConstantContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitArrayConstantEmpty(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ArrayConstantListContext extends ArrayConstantContext {
		public ElementListContext elementList() {
			return getRuleContext(ElementListContext.class,0);
		}
		public ArrayConstantListContext(ArrayConstantContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitArrayConstantList(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ArrayConstantContext arrayConstant() throws RecognitionException {
		ArrayConstantContext _localctx = new ArrayConstantContext(_ctx, getState());
		enterRule(_localctx, 60, RULE_arrayConstant);
		try {
			setState(318);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,14,_ctx) ) {
			case 1:
				_localctx = new ArrayConstantListContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(312);
				match(T__11);
				setState(313);
				elementList();
				setState(314);
				match(T__12);
				}
				break;
			case 2:
				_localctx = new ArrayConstantEmptyContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(316);
				match(T__11);
				setState(317);
				match(T__12);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ElementListContext extends ParserRuleContext {
		public ConsContext cons;
		public List<ConsContext> elements = new ArrayList<ConsContext>();
		public List<ConsContext> cons() {
			return getRuleContexts(ConsContext.class);
		}
		public ConsContext cons(int i) {
			return getRuleContext(ConsContext.class,i);
		}
		public ElementListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_elementList; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitElementList(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ElementListContext elementList() throws RecognitionException {
		ElementListContext _localctx = new ElementListContext(_ctx, getState());
		enterRule(_localctx, 62, RULE_elementList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(320);
			((ElementListContext)_localctx).cons = cons();
			((ElementListContext)_localctx).elements.add(((ElementListContext)_localctx).cons);
			setState(325);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__4) {
				{
				{
				setState(321);
				match(T__4);
				setState(322);
				((ElementListContext)_localctx).cons = cons();
				((ElementListContext)_localctx).elements.add(((ElementListContext)_localctx).cons);
				}
				}
				setState(327);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class SequenceTypeContext extends ParserRuleContext {
		public SequenceTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_sequenceType; }
	 
		public SequenceTypeContext() { }
		public void copyFrom(SequenceTypeContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class SequenceTypeNumberContext extends SequenceTypeContext {
		public TerminalNode SEQUENCE() { return getToken(CourierParser.SEQUENCE, 0); }
		public PositiveNumberContext positiveNumber() {
			return getRuleContext(PositiveNumberContext.class,0);
		}
		public TerminalNode OF() { return getToken(CourierParser.OF, 0); }
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public SequenceTypeNumberContext(SequenceTypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitSequenceTypeNumber(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class SequenceTypeEmptyContext extends SequenceTypeContext {
		public TerminalNode SEQUENCE() { return getToken(CourierParser.SEQUENCE, 0); }
		public TerminalNode OF() { return getToken(CourierParser.OF, 0); }
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public SequenceTypeEmptyContext(SequenceTypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitSequenceTypeEmpty(this);
			else return visitor.visitChildren(this);
		}
	}

	public final SequenceTypeContext sequenceType() throws RecognitionException {
		SequenceTypeContext _localctx = new SequenceTypeContext(_ctx, getState());
		enterRule(_localctx, 64, RULE_sequenceType);
		try {
			setState(336);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,16,_ctx) ) {
			case 1:
				_localctx = new SequenceTypeEmptyContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(328);
				match(SEQUENCE);
				setState(329);
				match(OF);
				setState(330);
				type();
				}
				break;
			case 2:
				_localctx = new SequenceTypeNumberContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(331);
				match(SEQUENCE);
				setState(332);
				positiveNumber();
				setState(333);
				match(OF);
				setState(334);
				type();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class RecordTypeContext extends ParserRuleContext {
		public RecordTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_recordType; }
	 
		public RecordTypeContext() { }
		public void copyFrom(RecordTypeContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class RecordTypeListContext extends RecordTypeContext {
		public TerminalNode RECORD() { return getToken(CourierParser.RECORD, 0); }
		public FieldListContext fieldList() {
			return getRuleContext(FieldListContext.class,0);
		}
		public RecordTypeListContext(RecordTypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitRecordTypeList(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class RecordTypeEmptyContext extends RecordTypeContext {
		public TerminalNode RECORD() { return getToken(CourierParser.RECORD, 0); }
		public RecordTypeEmptyContext(RecordTypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitRecordTypeEmpty(this);
			else return visitor.visitChildren(this);
		}
	}

	public final RecordTypeContext recordType() throws RecognitionException {
		RecordTypeContext _localctx = new RecordTypeContext(_ctx, getState());
		enterRule(_localctx, 66, RULE_recordType);
		try {
			setState(346);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,17,_ctx) ) {
			case 1:
				_localctx = new RecordTypeEmptyContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(338);
				match(RECORD);
				setState(339);
				match(T__11);
				setState(340);
				match(T__12);
				}
				break;
			case 2:
				_localctx = new RecordTypeListContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(341);
				match(RECORD);
				setState(342);
				match(T__11);
				setState(343);
				fieldList();
				setState(344);
				match(T__12);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class RecordConstantContext extends ParserRuleContext {
		public RecordConstantContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_recordConstant; }
	 
		public RecordConstantContext() { }
		public void copyFrom(RecordConstantContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class RecordConstantListContext extends RecordConstantContext {
		public ComponentListContext componentList() {
			return getRuleContext(ComponentListContext.class,0);
		}
		public RecordConstantListContext(RecordConstantContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitRecordConstantList(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class RecordConstantEmptyContext extends RecordConstantContext {
		public RecordConstantEmptyContext(RecordConstantContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitRecordConstantEmpty(this);
			else return visitor.visitChildren(this);
		}
	}

	public final RecordConstantContext recordConstant() throws RecognitionException {
		RecordConstantContext _localctx = new RecordConstantContext(_ctx, getState());
		enterRule(_localctx, 68, RULE_recordConstant);
		try {
			setState(354);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,18,_ctx) ) {
			case 1:
				_localctx = new RecordConstantEmptyContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(348);
				match(T__11);
				setState(349);
				match(T__12);
				}
				break;
			case 2:
				_localctx = new RecordConstantListContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(350);
				match(T__11);
				setState(351);
				componentList();
				setState(352);
				match(T__12);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class FieldListContext extends ParserRuleContext {
		public FieldContext field;
		public List<FieldContext> elements = new ArrayList<FieldContext>();
		public List<FieldContext> field() {
			return getRuleContexts(FieldContext.class);
		}
		public FieldContext field(int i) {
			return getRuleContext(FieldContext.class,i);
		}
		public FieldListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_fieldList; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitFieldList(this);
			else return visitor.visitChildren(this);
		}
	}

	public final FieldListContext fieldList() throws RecognitionException {
		FieldListContext _localctx = new FieldListContext(_ctx, getState());
		enterRule(_localctx, 70, RULE_fieldList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(356);
			((FieldListContext)_localctx).field = field();
			((FieldListContext)_localctx).elements.add(((FieldListContext)_localctx).field);
			setState(361);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__4) {
				{
				{
				setState(357);
				match(T__4);
				setState(358);
				((FieldListContext)_localctx).field = field();
				((FieldListContext)_localctx).elements.add(((FieldListContext)_localctx).field);
				}
				}
				setState(363);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class FieldContext extends ParserRuleContext {
		public NameListContext nameList() {
			return getRuleContext(NameListContext.class,0);
		}
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public FieldContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_field; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitField(this);
			else return visitor.visitChildren(this);
		}
	}

	public final FieldContext field() throws RecognitionException {
		FieldContext _localctx = new FieldContext(_ctx, getState());
		enterRule(_localctx, 72, RULE_field);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(364);
			nameList();
			setState(365);
			match(T__0);
			setState(366);
			type();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ComponentListContext extends ParserRuleContext {
		public ComponentContext component;
		public List<ComponentContext> elements = new ArrayList<ComponentContext>();
		public List<ComponentContext> component() {
			return getRuleContexts(ComponentContext.class);
		}
		public ComponentContext component(int i) {
			return getRuleContext(ComponentContext.class,i);
		}
		public ComponentListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_componentList; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitComponentList(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ComponentListContext componentList() throws RecognitionException {
		ComponentListContext _localctx = new ComponentListContext(_ctx, getState());
		enterRule(_localctx, 74, RULE_componentList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(368);
			((ComponentListContext)_localctx).component = component();
			((ComponentListContext)_localctx).elements.add(((ComponentListContext)_localctx).component);
			setState(373);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__4) {
				{
				{
				setState(369);
				match(T__4);
				setState(370);
				((ComponentListContext)_localctx).component = component();
				((ComponentListContext)_localctx).elements.add(((ComponentListContext)_localctx).component);
				}
				}
				setState(375);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ComponentContext extends ParserRuleContext {
		public NameListContext nameList() {
			return getRuleContext(NameListContext.class,0);
		}
		public ConsContext cons() {
			return getRuleContext(ConsContext.class,0);
		}
		public ComponentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_component; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitComponent(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ComponentContext component() throws RecognitionException {
		ComponentContext _localctx = new ComponentContext(_ctx, getState());
		enterRule(_localctx, 76, RULE_component);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(376);
			nameList();
			setState(377);
			match(T__0);
			setState(378);
			cons();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class NameListContext extends ParserRuleContext {
		public Token ID;
		public List<Token> elements = new ArrayList<Token>();
		public List<TerminalNode> ID() { return getTokens(CourierParser.ID); }
		public TerminalNode ID(int i) {
			return getToken(CourierParser.ID, i);
		}
		public NameListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_nameList; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitNameList(this);
			else return visitor.visitChildren(this);
		}
	}

	public final NameListContext nameList() throws RecognitionException {
		NameListContext _localctx = new NameListContext(_ctx, getState());
		enterRule(_localctx, 78, RULE_nameList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(380);
			((NameListContext)_localctx).ID = match(ID);
			((NameListContext)_localctx).elements.add(((NameListContext)_localctx).ID);
			setState(385);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__4) {
				{
				{
				setState(381);
				match(T__4);
				setState(382);
				((NameListContext)_localctx).ID = match(ID);
				((NameListContext)_localctx).elements.add(((NameListContext)_localctx).ID);
				}
				}
				setState(387);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ChoiceTypeContext extends ParserRuleContext {
		public ChoiceTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_choiceType; }
	 
		public ChoiceTypeContext() { }
		public void copyFrom(ChoiceTypeContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ChoiceTypeAnonContext extends ChoiceTypeContext {
		public TerminalNode CHOICE() { return getToken(CourierParser.CHOICE, 0); }
		public TerminalNode OF() { return getToken(CourierParser.OF, 0); }
		public CandidateListContext candidateList() {
			return getRuleContext(CandidateListContext.class,0);
		}
		public ChoiceTypeAnonContext(ChoiceTypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitChoiceTypeAnon(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ChoiceTypeNameContext extends ChoiceTypeContext {
		public TerminalNode CHOICE() { return getToken(CourierParser.CHOICE, 0); }
		public ReferenceContext reference() {
			return getRuleContext(ReferenceContext.class,0);
		}
		public TerminalNode OF() { return getToken(CourierParser.OF, 0); }
		public CandidateNameListContext candidateNameList() {
			return getRuleContext(CandidateNameListContext.class,0);
		}
		public ChoiceTypeNameContext(ChoiceTypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitChoiceTypeName(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ChoiceTypeContext choiceType() throws RecognitionException {
		ChoiceTypeContext _localctx = new ChoiceTypeContext(_ctx, getState());
		enterRule(_localctx, 80, RULE_choiceType);
		try {
			setState(401);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,22,_ctx) ) {
			case 1:
				_localctx = new ChoiceTypeAnonContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(388);
				match(CHOICE);
				setState(389);
				match(OF);
				setState(390);
				match(T__9);
				setState(391);
				candidateList();
				setState(392);
				match(T__10);
				}
				break;
			case 2:
				_localctx = new ChoiceTypeNameContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(394);
				match(CHOICE);
				setState(395);
				reference();
				setState(396);
				match(OF);
				setState(397);
				match(T__9);
				setState(398);
				candidateNameList();
				setState(399);
				match(T__10);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ChoiceConstantContext extends ParserRuleContext {
		public Token name;
		public ConsContext cons() {
			return getRuleContext(ConsContext.class,0);
		}
		public TerminalNode ID() { return getToken(CourierParser.ID, 0); }
		public ChoiceConstantContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_choiceConstant; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitChoiceConstant(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ChoiceConstantContext choiceConstant() throws RecognitionException {
		ChoiceConstantContext _localctx = new ChoiceConstantContext(_ctx, getState());
		enterRule(_localctx, 82, RULE_choiceConstant);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(403);
			((ChoiceConstantContext)_localctx).name = match(ID);
			setState(404);
			cons();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class CandidateListContext extends ParserRuleContext {
		public CandidateContext candidate;
		public List<CandidateContext> elements = new ArrayList<CandidateContext>();
		public List<CandidateContext> candidate() {
			return getRuleContexts(CandidateContext.class);
		}
		public CandidateContext candidate(int i) {
			return getRuleContext(CandidateContext.class,i);
		}
		public CandidateListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_candidateList; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitCandidateList(this);
			else return visitor.visitChildren(this);
		}
	}

	public final CandidateListContext candidateList() throws RecognitionException {
		CandidateListContext _localctx = new CandidateListContext(_ctx, getState());
		enterRule(_localctx, 84, RULE_candidateList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(406);
			((CandidateListContext)_localctx).candidate = candidate();
			((CandidateListContext)_localctx).elements.add(((CandidateListContext)_localctx).candidate);
			setState(411);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__4) {
				{
				{
				setState(407);
				match(T__4);
				setState(408);
				((CandidateListContext)_localctx).candidate = candidate();
				((CandidateListContext)_localctx).elements.add(((CandidateListContext)_localctx).candidate);
				}
				}
				setState(413);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class CandidateContext extends ParserRuleContext {
		public DesignatorListContext designatorList() {
			return getRuleContext(DesignatorListContext.class,0);
		}
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public CandidateContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_candidate; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitCandidate(this);
			else return visitor.visitChildren(this);
		}
	}

	public final CandidateContext candidate() throws RecognitionException {
		CandidateContext _localctx = new CandidateContext(_ctx, getState());
		enterRule(_localctx, 86, RULE_candidate);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(414);
			designatorList();
			setState(415);
			match(T__13);
			setState(416);
			type();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class DesignatorListContext extends ParserRuleContext {
		public DesignatorContext designator;
		public List<DesignatorContext> elements = new ArrayList<DesignatorContext>();
		public List<DesignatorContext> designator() {
			return getRuleContexts(DesignatorContext.class);
		}
		public DesignatorContext designator(int i) {
			return getRuleContext(DesignatorContext.class,i);
		}
		public DesignatorListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_designatorList; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitDesignatorList(this);
			else return visitor.visitChildren(this);
		}
	}

	public final DesignatorListContext designatorList() throws RecognitionException {
		DesignatorListContext _localctx = new DesignatorListContext(_ctx, getState());
		enterRule(_localctx, 88, RULE_designatorList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(418);
			((DesignatorListContext)_localctx).designator = designator();
			((DesignatorListContext)_localctx).elements.add(((DesignatorListContext)_localctx).designator);
			setState(423);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__4) {
				{
				{
				setState(419);
				match(T__4);
				setState(420);
				((DesignatorListContext)_localctx).designator = designator();
				((DesignatorListContext)_localctx).elements.add(((DesignatorListContext)_localctx).designator);
				}
				}
				setState(425);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class DesignatorContext extends ParserRuleContext {
		public Token name;
		public PositiveNumberContext number;
		public TerminalNode ID() { return getToken(CourierParser.ID, 0); }
		public PositiveNumberContext positiveNumber() {
			return getRuleContext(PositiveNumberContext.class,0);
		}
		public DesignatorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_designator; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitDesignator(this);
			else return visitor.visitChildren(this);
		}
	}

	public final DesignatorContext designator() throws RecognitionException {
		DesignatorContext _localctx = new DesignatorContext(_ctx, getState());
		enterRule(_localctx, 90, RULE_designator);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(426);
			((DesignatorContext)_localctx).name = match(ID);
			setState(427);
			match(T__5);
			setState(428);
			((DesignatorContext)_localctx).number = positiveNumber();
			setState(429);
			match(T__6);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class CandidateNameListContext extends ParserRuleContext {
		public CandidateNameContext candidateName;
		public List<CandidateNameContext> elements = new ArrayList<CandidateNameContext>();
		public List<CandidateNameContext> candidateName() {
			return getRuleContexts(CandidateNameContext.class);
		}
		public CandidateNameContext candidateName(int i) {
			return getRuleContext(CandidateNameContext.class,i);
		}
		public CandidateNameListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_candidateNameList; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitCandidateNameList(this);
			else return visitor.visitChildren(this);
		}
	}

	public final CandidateNameListContext candidateNameList() throws RecognitionException {
		CandidateNameListContext _localctx = new CandidateNameListContext(_ctx, getState());
		enterRule(_localctx, 92, RULE_candidateNameList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(431);
			((CandidateNameListContext)_localctx).candidateName = candidateName();
			((CandidateNameListContext)_localctx).elements.add(((CandidateNameListContext)_localctx).candidateName);
			setState(436);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__4) {
				{
				{
				setState(432);
				match(T__4);
				setState(433);
				((CandidateNameListContext)_localctx).candidateName = candidateName();
				((CandidateNameListContext)_localctx).elements.add(((CandidateNameListContext)_localctx).candidateName);
				}
				}
				setState(438);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class CandidateNameContext extends ParserRuleContext {
		public NameListContext nameList() {
			return getRuleContext(NameListContext.class,0);
		}
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public CandidateNameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_candidateName; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitCandidateName(this);
			else return visitor.visitChildren(this);
		}
	}

	public final CandidateNameContext candidateName() throws RecognitionException {
		CandidateNameContext _localctx = new CandidateNameContext(_ctx, getState());
		enterRule(_localctx, 94, RULE_candidateName);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(439);
			nameList();
			setState(440);
			match(T__13);
			setState(441);
			type();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ProcedureTypeContext extends ParserRuleContext {
		public TerminalNode PROCEDURE() { return getToken(CourierParser.PROCEDURE, 0); }
		public ArgumentListContext argumentList() {
			return getRuleContext(ArgumentListContext.class,0);
		}
		public ResultListContext resultList() {
			return getRuleContext(ResultListContext.class,0);
		}
		public ErrorListContext errorList() {
			return getRuleContext(ErrorListContext.class,0);
		}
		public ProcedureTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_procedureType; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitProcedureType(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ProcedureTypeContext procedureType() throws RecognitionException {
		ProcedureTypeContext _localctx = new ProcedureTypeContext(_ctx, getState());
		enterRule(_localctx, 96, RULE_procedureType);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(443);
			match(PROCEDURE);
			setState(444);
			argumentList();
			setState(445);
			resultList();
			setState(446);
			errorList();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ArgumentListContext extends ParserRuleContext {
		public FieldListContext fieldList() {
			return getRuleContext(FieldListContext.class,0);
		}
		public ArgumentListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_argumentList; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitArgumentList(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ArgumentListContext argumentList() throws RecognitionException {
		ArgumentListContext _localctx = new ArgumentListContext(_ctx, getState());
		enterRule(_localctx, 98, RULE_argumentList);
		try {
			setState(453);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__1:
			case T__3:
			case T__4:
			case T__10:
			case T__12:
			case REPORTS:
			case RETURNS:
				enterOuterAlt(_localctx, 1);
				{
				}
				break;
			case T__11:
				enterOuterAlt(_localctx, 2);
				{
				setState(449);
				match(T__11);
				setState(450);
				fieldList();
				setState(451);
				match(T__12);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ResultListContext extends ParserRuleContext {
		public TerminalNode RETURNS() { return getToken(CourierParser.RETURNS, 0); }
		public FieldListContext fieldList() {
			return getRuleContext(FieldListContext.class,0);
		}
		public ResultListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_resultList; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitResultList(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ResultListContext resultList() throws RecognitionException {
		ResultListContext _localctx = new ResultListContext(_ctx, getState());
		enterRule(_localctx, 100, RULE_resultList);
		try {
			setState(461);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__1:
			case T__3:
			case T__4:
			case T__10:
			case T__12:
			case REPORTS:
				enterOuterAlt(_localctx, 1);
				{
				}
				break;
			case RETURNS:
				enterOuterAlt(_localctx, 2);
				{
				setState(456);
				match(RETURNS);
				setState(457);
				match(T__11);
				setState(458);
				fieldList();
				setState(459);
				match(T__12);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ErrorListContext extends ParserRuleContext {
		public TerminalNode REPORTS() { return getToken(CourierParser.REPORTS, 0); }
		public NameListContext nameList() {
			return getRuleContext(NameListContext.class,0);
		}
		public ErrorListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_errorList; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitErrorList(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ErrorListContext errorList() throws RecognitionException {
		ErrorListContext _localctx = new ErrorListContext(_ctx, getState());
		enterRule(_localctx, 102, RULE_errorList);
		try {
			setState(469);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__1:
			case T__3:
			case T__4:
			case T__10:
			case T__12:
				enterOuterAlt(_localctx, 1);
				{
				}
				break;
			case REPORTS:
				enterOuterAlt(_localctx, 2);
				{
				setState(464);
				match(REPORTS);
				setState(465);
				match(T__11);
				setState(466);
				nameList();
				setState(467);
				match(T__12);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ErrorTypeContext extends ParserRuleContext {
		public TerminalNode ERROR() { return getToken(CourierParser.ERROR, 0); }
		public ArgumentListContext argumentList() {
			return getRuleContext(ArgumentListContext.class,0);
		}
		public ErrorTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_errorType; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitErrorType(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ErrorTypeContext errorType() throws RecognitionException {
		ErrorTypeContext _localctx = new ErrorTypeContext(_ctx, getState());
		enterRule(_localctx, 104, RULE_errorType);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(471);
			match(ERROR);
			setState(472);
			argumentList();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static final String _serializedATN =
		"\u0004\u0001.\u01db\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002"+
		"\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007\u0002"+
		"\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b\u0002"+
		"\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002\u000f\u0007\u000f"+
		"\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011\u0002\u0012\u0007\u0012"+
		"\u0002\u0013\u0007\u0013\u0002\u0014\u0007\u0014\u0002\u0015\u0007\u0015"+
		"\u0002\u0016\u0007\u0016\u0002\u0017\u0007\u0017\u0002\u0018\u0007\u0018"+
		"\u0002\u0019\u0007\u0019\u0002\u001a\u0007\u001a\u0002\u001b\u0007\u001b"+
		"\u0002\u001c\u0007\u001c\u0002\u001d\u0007\u001d\u0002\u001e\u0007\u001e"+
		"\u0002\u001f\u0007\u001f\u0002 \u0007 \u0002!\u0007!\u0002\"\u0007\"\u0002"+
		"#\u0007#\u0002$\u0007$\u0002%\u0007%\u0002&\u0007&\u0002\'\u0007\'\u0002"+
		"(\u0007(\u0002)\u0007)\u0002*\u0007*\u0002+\u0007+\u0002,\u0007,\u0002"+
		"-\u0007-\u0002.\u0007.\u0002/\u0007/\u00020\u00070\u00021\u00071\u0002"+
		"2\u00072\u00023\u00073\u00024\u00074\u0001\u0000\u0001\u0000\u0001\u0000"+
		"\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000"+
		"\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0003\u0001~\b\u0001"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0005\u0002\u0083\b\u0002\n\u0002"+
		"\f\u0002\u0086\t\u0002\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003"+
		"\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0004\u0001\u0004\u0004\u0004"+
		"\u0091\b\u0004\u000b\u0004\f\u0004\u0092\u0003\u0004\u0095\b\u0004\u0001"+
		"\u0005\u0001\u0005\u0003\u0005\u0099\b\u0005\u0001\u0006\u0001\u0006\u0001"+
		"\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0007\u0001"+
		"\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001"+
		"\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001"+
		"\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001"+
		"\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001"+
		"\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001"+
		"\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001"+
		"\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001"+
		"\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0003"+
		"\u0007\u00d3\b\u0007\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001"+
		"\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0003"+
		"\b\u00e4\b\b\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001"+
		"\t\u0003\t\u00ee\b\t\u0001\n\u0001\n\u0001\n\u0003\n\u00f3\b\n\u0001\u000b"+
		"\u0001\u000b\u0003\u000b\u00f7\b\u000b\u0001\f\u0001\f\u0001\f\u0001\f"+
		"\u0001\f\u0001\f\u0001\f\u0003\f\u0100\b\f\u0001\r\u0001\r\u0001\u000e"+
		"\u0001\u000e\u0001\u000e\u0001\u000f\u0001\u000f\u0003\u000f\u0109\b\u000f"+
		"\u0001\u0010\u0001\u0010\u0001\u0011\u0001\u0011\u0003\u0011\u010f\b\u0011"+
		"\u0001\u0012\u0001\u0012\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0014"+
		"\u0001\u0014\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0016\u0001\u0016"+
		"\u0001\u0017\u0001\u0017\u0001\u0018\u0001\u0018\u0001\u0019\u0001\u0019"+
		"\u0001\u0019\u0001\u0019\u0001\u001a\u0001\u001a\u0001\u001b\u0001\u001b"+
		"\u0001\u001b\u0005\u001b\u012a\b\u001b\n\u001b\f\u001b\u012d\t\u001b\u0001"+
		"\u001c\u0001\u001c\u0001\u001c\u0001\u001c\u0001\u001c\u0001\u001d\u0001"+
		"\u001d\u0001\u001d\u0001\u001d\u0001\u001d\u0001\u001e\u0001\u001e\u0001"+
		"\u001e\u0001\u001e\u0001\u001e\u0001\u001e\u0003\u001e\u013f\b\u001e\u0001"+
		"\u001f\u0001\u001f\u0001\u001f\u0005\u001f\u0144\b\u001f\n\u001f\f\u001f"+
		"\u0147\t\u001f\u0001 \u0001 \u0001 \u0001 \u0001 \u0001 \u0001 \u0001"+
		" \u0003 \u0151\b \u0001!\u0001!\u0001!\u0001!\u0001!\u0001!\u0001!\u0001"+
		"!\u0003!\u015b\b!\u0001\"\u0001\"\u0001\"\u0001\"\u0001\"\u0001\"\u0003"+
		"\"\u0163\b\"\u0001#\u0001#\u0001#\u0005#\u0168\b#\n#\f#\u016b\t#\u0001"+
		"$\u0001$\u0001$\u0001$\u0001%\u0001%\u0001%\u0005%\u0174\b%\n%\f%\u0177"+
		"\t%\u0001&\u0001&\u0001&\u0001&\u0001\'\u0001\'\u0001\'\u0005\'\u0180"+
		"\b\'\n\'\f\'\u0183\t\'\u0001(\u0001(\u0001(\u0001(\u0001(\u0001(\u0001"+
		"(\u0001(\u0001(\u0001(\u0001(\u0001(\u0001(\u0003(\u0192\b(\u0001)\u0001"+
		")\u0001)\u0001*\u0001*\u0001*\u0005*\u019a\b*\n*\f*\u019d\t*\u0001+\u0001"+
		"+\u0001+\u0001+\u0001,\u0001,\u0001,\u0005,\u01a6\b,\n,\f,\u01a9\t,\u0001"+
		"-\u0001-\u0001-\u0001-\u0001-\u0001.\u0001.\u0001.\u0005.\u01b3\b.\n."+
		"\f.\u01b6\t.\u0001/\u0001/\u0001/\u0001/\u00010\u00010\u00010\u00010\u0001"+
		"0\u00011\u00011\u00011\u00011\u00011\u00031\u01c6\b1\u00012\u00012\u0001"+
		"2\u00012\u00012\u00012\u00032\u01ce\b2\u00013\u00013\u00013\u00013\u0001"+
		"3\u00013\u00033\u01d6\b3\u00014\u00014\u00014\u00014\u0000\u00005\u0000"+
		"\u0002\u0004\u0006\b\n\f\u000e\u0010\u0012\u0014\u0016\u0018\u001a\u001c"+
		"\u001e \"$&(*,.02468:<>@BDFHJLNPRTVXZ\\^`bdfh\u0000\u0000\u01dc\u0000"+
		"j\u0001\u0000\u0000\u0000\u0002}\u0001\u0000\u0000\u0000\u0004\u007f\u0001"+
		"\u0000\u0000\u0000\u0006\u0087\u0001\u0000\u0000\u0000\b\u0094\u0001\u0000"+
		"\u0000\u0000\n\u0098\u0001\u0000\u0000\u0000\f\u009a\u0001\u0000\u0000"+
		"\u0000\u000e\u00d2\u0001\u0000\u0000\u0000\u0010\u00e3\u0001\u0000\u0000"+
		"\u0000\u0012\u00ed\u0001\u0000\u0000\u0000\u0014\u00f2\u0001\u0000\u0000"+
		"\u0000\u0016\u00f6\u0001\u0000\u0000\u0000\u0018\u00ff\u0001\u0000\u0000"+
		"\u0000\u001a\u0101\u0001\u0000\u0000\u0000\u001c\u0103\u0001\u0000\u0000"+
		"\u0000\u001e\u0108\u0001\u0000\u0000\u0000 \u010a\u0001\u0000\u0000\u0000"+
		"\"\u010e\u0001\u0000\u0000\u0000$\u0110\u0001\u0000\u0000\u0000&\u0112"+
		"\u0001\u0000\u0000\u0000(\u0115\u0001\u0000\u0000\u0000*\u0117\u0001\u0000"+
		"\u0000\u0000,\u011a\u0001\u0000\u0000\u0000.\u011c\u0001\u0000\u0000\u0000"+
		"0\u011e\u0001\u0000\u0000\u00002\u0120\u0001\u0000\u0000\u00004\u0124"+
		"\u0001\u0000\u0000\u00006\u0126\u0001\u0000\u0000\u00008\u012e\u0001\u0000"+
		"\u0000\u0000:\u0133\u0001\u0000\u0000\u0000<\u013e\u0001\u0000\u0000\u0000"+
		">\u0140\u0001\u0000\u0000\u0000@\u0150\u0001\u0000\u0000\u0000B\u015a"+
		"\u0001\u0000\u0000\u0000D\u0162\u0001\u0000\u0000\u0000F\u0164\u0001\u0000"+
		"\u0000\u0000H\u016c\u0001\u0000\u0000\u0000J\u0170\u0001\u0000\u0000\u0000"+
		"L\u0178\u0001\u0000\u0000\u0000N\u017c\u0001\u0000\u0000\u0000P\u0191"+
		"\u0001\u0000\u0000\u0000R\u0193\u0001\u0000\u0000\u0000T\u0196\u0001\u0000"+
		"\u0000\u0000V\u019e\u0001\u0000\u0000\u0000X\u01a2\u0001\u0000\u0000\u0000"+
		"Z\u01aa\u0001\u0000\u0000\u0000\\\u01af\u0001\u0000\u0000\u0000^\u01b7"+
		"\u0001\u0000\u0000\u0000`\u01bb\u0001\u0000\u0000\u0000b\u01c5\u0001\u0000"+
		"\u0000\u0000d\u01cd\u0001\u0000\u0000\u0000f\u01d5\u0001\u0000\u0000\u0000"+
		"h\u01d7\u0001\u0000\u0000\u0000jk\u0005*\u0000\u0000kl\u0005\u0001\u0000"+
		"\u0000lm\u0005\u001d\u0000\u0000mn\u0003\u001a\r\u0000no\u0005&\u0000"+
		"\u0000op\u0003\u001a\r\u0000pq\u0005\u0002\u0000\u0000qr\u0005\u0010\u0000"+
		"\u0000rs\u0003\u0002\u0001\u0000st\u0003\b\u0004\u0000tu\u0005\u0016\u0000"+
		"\u0000uv\u0005\u0003\u0000\u0000v\u0001\u0001\u0000\u0000\u0000w~\u0001"+
		"\u0000\u0000\u0000xy\u0005\u0014\u0000\u0000yz\u0005%\u0000\u0000z{\u0003"+
		"\u0004\u0002\u0000{|\u0005\u0004\u0000\u0000|~\u0001\u0000\u0000\u0000"+
		"}w\u0001\u0000\u0000\u0000}x\u0001\u0000\u0000\u0000~\u0003\u0001\u0000"+
		"\u0000\u0000\u007f\u0084\u0003\u0006\u0003\u0000\u0080\u0081\u0005\u0005"+
		"\u0000\u0000\u0081\u0083\u0003\u0006\u0003\u0000\u0082\u0080\u0001\u0000"+
		"\u0000\u0000\u0083\u0086\u0001\u0000\u0000\u0000\u0084\u0082\u0001\u0000"+
		"\u0000\u0000\u0084\u0085\u0001\u0000\u0000\u0000\u0085\u0005\u0001\u0000"+
		"\u0000\u0000\u0086\u0084\u0001\u0000\u0000\u0000\u0087\u0088\u0005*\u0000"+
		"\u0000\u0088\u0089\u0005\u0006\u0000\u0000\u0089\u008a\u0003\u001a\r\u0000"+
		"\u008a\u008b\u0005\u0007\u0000\u0000\u008b\u008c\u0005&\u0000\u0000\u008c"+
		"\u008d\u0003\u001a\r\u0000\u008d\u0007\u0001\u0000\u0000\u0000\u008e\u0095"+
		"\u0001\u0000\u0000\u0000\u008f\u0091\u0003\n\u0005\u0000\u0090\u008f\u0001"+
		"\u0000\u0000\u0000\u0091\u0092\u0001\u0000\u0000\u0000\u0092\u0090\u0001"+
		"\u0000\u0000\u0000\u0092\u0093\u0001\u0000\u0000\u0000\u0093\u0095\u0001"+
		"\u0000\u0000\u0000\u0094\u008e\u0001\u0000\u0000\u0000\u0094\u0090\u0001"+
		"\u0000\u0000\u0000\u0095\t\u0001\u0000\u0000\u0000\u0096\u0099\u0003\f"+
		"\u0006\u0000\u0097\u0099\u0003\u000e\u0007\u0000\u0098\u0096\u0001\u0000"+
		"\u0000\u0000\u0098\u0097\u0001\u0000\u0000\u0000\u0099\u000b\u0001\u0000"+
		"\u0000\u0000\u009a\u009b\u0005*\u0000\u0000\u009b\u009c\u0005\u0001\u0000"+
		"\u0000\u009c\u009d\u0005#\u0000\u0000\u009d\u009e\u0005\u0002\u0000\u0000"+
		"\u009e\u009f\u0003\u0010\b\u0000\u009f\u00a0\u0005\u0004\u0000\u0000\u00a0"+
		"\r\u0001\u0000\u0000\u0000\u00a1\u00a2\u0005*\u0000\u0000\u00a2\u00a3"+
		"\u0005\u0001\u0000\u0000\u00a3\u00a4\u0003 \u0010\u0000\u00a4\u00a5\u0005"+
		"\u0002\u0000\u0000\u00a5\u00a6\u0003\"\u0011\u0000\u00a6\u00a7\u0005\u0004"+
		"\u0000\u0000\u00a7\u00d3\u0001\u0000\u0000\u0000\u00a8\u00a9\u0005*\u0000"+
		"\u0000\u00a9\u00aa\u0005\u0001\u0000\u0000\u00aa\u00ab\u0003,\u0016\u0000"+
		"\u00ab\u00ac\u0005\u0002\u0000\u0000\u00ac\u00ad\u0003.\u0017\u0000\u00ad"+
		"\u00ae\u0005\u0004\u0000\u0000\u00ae\u00d3\u0001\u0000\u0000\u0000\u00af"+
		"\u00b0\u0005*\u0000\u0000\u00b0\u00b1\u0005\u0001\u0000\u0000\u00b1\u00b2"+
		"\u0003\u0014\n\u0000\u00b2\u00b3\u0005\u0002\u0000\u0000\u00b3\u00b4\u0003"+
		"\u001a\r\u0000\u00b4\u00b5\u0005\u0004\u0000\u0000\u00b5\u00d3\u0001\u0000"+
		"\u0000\u0000\u00b6\u00b7\u0005*\u0000\u0000\u00b7\u00b8\u0005\u0001\u0000"+
		"\u0000\u00b8\u00b9\u0003\u0016\u000b\u0000\u00b9\u00ba\u0005\u0002\u0000"+
		"\u0000\u00ba\u00bb\u0003\u001e\u000f\u0000\u00bb\u00bc\u0005\u0004\u0000"+
		"\u0000\u00bc\u00d3\u0001\u0000\u0000\u0000\u00bd\u00be\u0005*\u0000\u0000"+
		"\u00be\u00bf\u0005\u0001\u0000\u0000\u00bf\u00c0\u0003h4\u0000\u00c0\u00c1"+
		"\u0005\u0002\u0000\u0000\u00c1\u00c2\u0003\u001a\r\u0000\u00c2\u00c3\u0005"+
		"\u0004\u0000\u0000\u00c3\u00d3\u0001\u0000\u0000\u0000\u00c4\u00c5\u0005"+
		"*\u0000\u0000\u00c5\u00c6\u0005\u0001\u0000\u0000\u00c6\u00c7\u0003`0"+
		"\u0000\u00c7\u00c8\u0005\u0002\u0000\u0000\u00c8\u00c9\u0003\u001a\r\u0000"+
		"\u00c9\u00ca\u0005\u0004\u0000\u0000\u00ca\u00d3\u0001\u0000\u0000\u0000"+
		"\u00cb\u00cc\u0005*\u0000\u0000\u00cc\u00cd\u0005\u0001\u0000\u0000\u00cd"+
		"\u00ce\u0003\u0018\f\u0000\u00ce\u00cf\u0005\u0002\u0000\u0000\u00cf\u00d0"+
		"\u0003\u0012\t\u0000\u00d0\u00d1\u0005\u0004\u0000\u0000\u00d1\u00d3\u0001"+
		"\u0000\u0000\u0000\u00d2\u00a1\u0001\u0000\u0000\u0000\u00d2\u00a8\u0001"+
		"\u0000\u0000\u0000\u00d2\u00af\u0001\u0000\u0000\u0000\u00d2\u00b6\u0001"+
		"\u0000\u0000\u0000\u00d2\u00bd\u0001\u0000\u0000\u0000\u00d2\u00c4\u0001"+
		"\u0000\u0000\u0000\u00d2\u00cb\u0001\u0000\u0000\u0000\u00d3\u000f\u0001"+
		"\u0000\u0000\u0000\u00d4\u00e4\u0003 \u0010\u0000\u00d5\u00e4\u0003,\u0016"+
		"\u0000\u00d6\u00e4\u0003$\u0012\u0000\u00d7\u00e4\u0003&\u0013\u0000\u00d8"+
		"\u00e4\u00030\u0018\u0000\u00d9\u00e4\u0003(\u0014\u0000\u00da\u00e4\u0003"+
		"*\u0015\u0000\u00db\u00e4\u00032\u0019\u0000\u00dc\u00e4\u0003:\u001d"+
		"\u0000\u00dd\u00e4\u0003@ \u0000\u00de\u00e4\u0003B!\u0000\u00df\u00e4"+
		"\u0003P(\u0000\u00e0\u00e4\u0003`0\u0000\u00e1\u00e4\u0003h4\u0000\u00e2"+
		"\u00e4\u0003\u0018\f\u0000\u00e3\u00d4\u0001\u0000\u0000\u0000\u00e3\u00d5"+
		"\u0001\u0000\u0000\u0000\u00e3\u00d6\u0001\u0000\u0000\u0000\u00e3\u00d7"+
		"\u0001\u0000\u0000\u0000\u00e3\u00d8\u0001\u0000\u0000\u0000\u00e3\u00d9"+
		"\u0001\u0000\u0000\u0000\u00e3\u00da\u0001\u0000\u0000\u0000\u00e3\u00db"+
		"\u0001\u0000\u0000\u0000\u00e3\u00dc\u0001\u0000\u0000\u0000\u00e3\u00dd"+
		"\u0001\u0000\u0000\u0000\u00e3\u00de\u0001\u0000\u0000\u0000\u00e3\u00df"+
		"\u0001\u0000\u0000\u0000\u00e3\u00e0\u0001\u0000\u0000\u0000\u00e3\u00e1"+
		"\u0001\u0000\u0000\u0000\u00e3\u00e2\u0001\u0000\u0000\u0000\u00e4\u0011"+
		"\u0001\u0000\u0000\u0000\u00e5\u00ee\u0003\"\u0011\u0000\u00e6\u00ee\u0003"+
		".\u0017\u0000\u00e7\u00ee\u0003\u001a\r\u0000\u00e8\u00ee\u0003\u001c"+
		"\u000e\u0000\u00e9\u00ee\u0003<\u001e\u0000\u00ea\u00ee\u0003D\"\u0000"+
		"\u00eb\u00ee\u0003R)\u0000\u00ec\u00ee\u0003\u0018\f\u0000\u00ed\u00e5"+
		"\u0001\u0000\u0000\u0000\u00ed\u00e6\u0001\u0000\u0000\u0000\u00ed\u00e7"+
		"\u0001\u0000\u0000\u0000\u00ed\u00e8\u0001\u0000\u0000\u0000\u00ed\u00e9"+
		"\u0001\u0000\u0000\u0000\u00ed\u00ea\u0001\u0000\u0000\u0000\u00ed\u00eb"+
		"\u0001\u0000\u0000\u0000\u00ed\u00ec\u0001\u0000\u0000\u0000\u00ee\u0013"+
		"\u0001\u0000\u0000\u0000\u00ef\u00f3\u0003$\u0012\u0000\u00f0\u00f3\u0003"+
		"&\u0013\u0000\u00f1\u00f3\u00030\u0018\u0000\u00f2\u00ef\u0001\u0000\u0000"+
		"\u0000\u00f2\u00f0\u0001\u0000\u0000\u0000\u00f2\u00f1\u0001\u0000\u0000"+
		"\u0000\u00f3\u0015\u0001\u0000\u0000\u0000\u00f4\u00f7\u0003(\u0014\u0000"+
		"\u00f5\u00f7\u0003*\u0015\u0000\u00f6\u00f4\u0001\u0000\u0000\u0000\u00f6"+
		"\u00f5\u0001\u0000\u0000\u0000\u00f7\u0017\u0001\u0000\u0000\u0000\u00f8"+
		"\u0100\u0005*\u0000\u0000\u00f9\u00fa\u0005*\u0000\u0000\u00fa\u00fb\u0005"+
		"\u0003\u0000\u0000\u00fb\u0100\u0005*\u0000\u0000\u00fc\u00fd\u0005*\u0000"+
		"\u0000\u00fd\u00fe\u0005\b\u0000\u0000\u00fe\u0100\u0005*\u0000\u0000"+
		"\u00ff\u00f8\u0001\u0000\u0000\u0000\u00ff\u00f9\u0001\u0000\u0000\u0000"+
		"\u00ff\u00fc\u0001\u0000\u0000\u0000\u0100\u0019\u0001\u0000\u0000\u0000"+
		"\u0101\u0102\u0005)\u0000\u0000\u0102\u001b\u0001\u0000\u0000\u0000\u0103"+
		"\u0104\u0005\t\u0000\u0000\u0104\u0105\u0005)\u0000\u0000\u0105\u001d"+
		"\u0001\u0000\u0000\u0000\u0106\u0109\u0003\u001a\r\u0000\u0107\u0109\u0003"+
		"\u001c\u000e\u0000\u0108\u0106\u0001\u0000\u0000\u0000\u0108\u0107\u0001"+
		"\u0000\u0000\u0000\u0109\u001f\u0001\u0000\u0000\u0000\u010a\u010b\u0005"+
		"\u0011\u0000\u0000\u010b!\u0001\u0000\u0000\u0000\u010c\u010f\u0005\'"+
		"\u0000\u0000\u010d\u010f\u0005(\u0000\u0000\u010e\u010c\u0001\u0000\u0000"+
		"\u0000\u010e\u010d\u0001\u0000\u0000\u0000\u010f#\u0001\u0000\u0000\u0000"+
		"\u0110\u0111\u0005\u0012\u0000\u0000\u0111%\u0001\u0000\u0000\u0000\u0112"+
		"\u0113\u0005\u0019\u0000\u0000\u0113\u0114\u0005\u0012\u0000\u0000\u0114"+
		"\'\u0001\u0000\u0000\u0000\u0115\u0116\u0005\u0018\u0000\u0000\u0116)"+
		"\u0001\u0000\u0000\u0000\u0117\u0118\u0005\u0019\u0000\u0000\u0118\u0119"+
		"\u0005\u0018\u0000\u0000\u0119+\u0001\u0000\u0000\u0000\u011a\u011b\u0005"+
		"\"\u0000\u0000\u011b-\u0001\u0000\u0000\u0000\u011c\u011d\u0005+\u0000"+
		"\u0000\u011d/\u0001\u0000\u0000\u0000\u011e\u011f\u0005$\u0000\u0000\u011f"+
		"1\u0001\u0000\u0000\u0000\u0120\u0121\u0005\n\u0000\u0000\u0121\u0122"+
		"\u00036\u001b\u0000\u0122\u0123\u0005\u000b\u0000\u0000\u01233\u0001\u0000"+
		"\u0000\u0000\u0124\u0125\u0005*\u0000\u0000\u01255\u0001\u0000\u0000\u0000"+
		"\u0126\u012b\u00038\u001c\u0000\u0127\u0128\u0005\u0005\u0000\u0000\u0128"+
		"\u012a\u00038\u001c\u0000\u0129\u0127\u0001\u0000\u0000\u0000\u012a\u012d"+
		"\u0001\u0000\u0000\u0000\u012b\u0129\u0001\u0000\u0000\u0000\u012b\u012c"+
		"\u0001\u0000\u0000\u0000\u012c7\u0001\u0000\u0000\u0000\u012d\u012b\u0001"+
		"\u0000\u0000\u0000\u012e\u012f\u0005*\u0000\u0000\u012f\u0130\u0005\u0006"+
		"\u0000\u0000\u0130\u0131\u0003\u001a\r\u0000\u0131\u0132\u0005\u0007\u0000"+
		"\u0000\u01329\u0001\u0000\u0000\u0000\u0133\u0134\u0005\u000f\u0000\u0000"+
		"\u0134\u0135\u0003\u001a\r\u0000\u0135\u0136\u0005\u001b\u0000\u0000\u0136"+
		"\u0137\u0003\u0010\b\u0000\u0137;\u0001\u0000\u0000\u0000\u0138\u0139"+
		"\u0005\f\u0000\u0000\u0139\u013a\u0003>\u001f\u0000\u013a\u013b\u0005"+
		"\r\u0000\u0000\u013b\u013f\u0001\u0000\u0000\u0000\u013c\u013d\u0005\f"+
		"\u0000\u0000\u013d\u013f\u0005\r\u0000\u0000\u013e\u0138\u0001\u0000\u0000"+
		"\u0000\u013e\u013c\u0001\u0000\u0000\u0000\u013f=\u0001\u0000\u0000\u0000"+
		"\u0140\u0145\u0003\u0012\t\u0000\u0141\u0142\u0005\u0005\u0000\u0000\u0142"+
		"\u0144\u0003\u0012\t\u0000\u0143\u0141\u0001\u0000\u0000\u0000\u0144\u0147"+
		"\u0001\u0000\u0000\u0000\u0145\u0143\u0001\u0000\u0000\u0000\u0145\u0146"+
		"\u0001\u0000\u0000\u0000\u0146?\u0001\u0000\u0000\u0000\u0147\u0145\u0001"+
		"\u0000\u0000\u0000\u0148\u0149\u0005!\u0000\u0000\u0149\u014a\u0005\u001b"+
		"\u0000\u0000\u014a\u0151\u0003\u0010\b\u0000\u014b\u014c\u0005!\u0000"+
		"\u0000\u014c\u014d\u0003\u001a\r\u0000\u014d\u014e\u0005\u001b\u0000\u0000"+
		"\u014e\u014f\u0003\u0010\b\u0000\u014f\u0151\u0001\u0000\u0000\u0000\u0150"+
		"\u0148\u0001\u0000\u0000\u0000\u0150\u014b\u0001\u0000\u0000\u0000\u0151"+
		"A\u0001\u0000\u0000\u0000\u0152\u0153\u0005\u001e\u0000\u0000\u0153\u0154"+
		"\u0005\f\u0000\u0000\u0154\u015b\u0005\r\u0000\u0000\u0155\u0156\u0005"+
		"\u001e\u0000\u0000\u0156\u0157\u0005\f\u0000\u0000\u0157\u0158\u0003F"+
		"#\u0000\u0158\u0159\u0005\r\u0000\u0000\u0159\u015b\u0001\u0000\u0000"+
		"\u0000\u015a\u0152\u0001\u0000\u0000\u0000\u015a\u0155\u0001\u0000\u0000"+
		"\u0000\u015bC\u0001\u0000\u0000\u0000\u015c\u015d\u0005\f\u0000\u0000"+
		"\u015d\u0163\u0005\r\u0000\u0000\u015e\u015f\u0005\f\u0000\u0000\u015f"+
		"\u0160\u0003J%\u0000\u0160\u0161\u0005\r\u0000\u0000\u0161\u0163\u0001"+
		"\u0000\u0000\u0000\u0162\u015c\u0001\u0000\u0000\u0000\u0162\u015e\u0001"+
		"\u0000\u0000\u0000\u0163E\u0001\u0000\u0000\u0000\u0164\u0169\u0003H$"+
		"\u0000\u0165\u0166\u0005\u0005\u0000\u0000\u0166\u0168\u0003H$\u0000\u0167"+
		"\u0165\u0001\u0000\u0000\u0000\u0168\u016b\u0001\u0000\u0000\u0000\u0169"+
		"\u0167\u0001\u0000\u0000\u0000\u0169\u016a\u0001\u0000\u0000\u0000\u016a"+
		"G\u0001\u0000\u0000\u0000\u016b\u0169\u0001\u0000\u0000\u0000\u016c\u016d"+
		"\u0003N\'\u0000\u016d\u016e\u0005\u0001\u0000\u0000\u016e\u016f\u0003"+
		"\u0010\b\u0000\u016fI\u0001\u0000\u0000\u0000\u0170\u0175\u0003L&\u0000"+
		"\u0171\u0172\u0005\u0005\u0000\u0000\u0172\u0174\u0003L&\u0000\u0173\u0171"+
		"\u0001\u0000\u0000\u0000\u0174\u0177\u0001\u0000\u0000\u0000\u0175\u0173"+
		"\u0001\u0000\u0000\u0000\u0175\u0176\u0001\u0000\u0000\u0000\u0176K\u0001"+
		"\u0000\u0000\u0000\u0177\u0175\u0001\u0000\u0000\u0000\u0178\u0179\u0003"+
		"N\'\u0000\u0179\u017a\u0005\u0001\u0000\u0000\u017a\u017b\u0003\u0012"+
		"\t\u0000\u017bM\u0001\u0000\u0000\u0000\u017c\u0181\u0005*\u0000\u0000"+
		"\u017d\u017e\u0005\u0005\u0000\u0000\u017e\u0180\u0005*\u0000\u0000\u017f"+
		"\u017d\u0001\u0000\u0000\u0000\u0180\u0183\u0001\u0000\u0000\u0000\u0181"+
		"\u017f\u0001\u0000\u0000\u0000\u0181\u0182\u0001\u0000\u0000\u0000\u0182"+
		"O\u0001\u0000\u0000\u0000\u0183\u0181\u0001\u0000\u0000\u0000\u0184\u0185"+
		"\u0005\u0013\u0000\u0000\u0185\u0186\u0005\u001b\u0000\u0000\u0186\u0187"+
		"\u0005\n\u0000\u0000\u0187\u0188\u0003T*\u0000\u0188\u0189\u0005\u000b"+
		"\u0000\u0000\u0189\u0192\u0001\u0000\u0000\u0000\u018a\u018b\u0005\u0013"+
		"\u0000\u0000\u018b\u018c\u0003\u0018\f\u0000\u018c\u018d\u0005\u001b\u0000"+
		"\u0000\u018d\u018e\u0005\n\u0000\u0000\u018e\u018f\u0003\\.\u0000\u018f"+
		"\u0190\u0005\u000b\u0000\u0000\u0190\u0192\u0001\u0000\u0000\u0000\u0191"+
		"\u0184\u0001\u0000\u0000\u0000\u0191\u018a\u0001\u0000\u0000\u0000\u0192"+
		"Q\u0001\u0000\u0000\u0000\u0193\u0194\u0005*\u0000\u0000\u0194\u0195\u0003"+
		"\u0012\t\u0000\u0195S\u0001\u0000\u0000\u0000\u0196\u019b\u0003V+\u0000"+
		"\u0197\u0198\u0005\u0005\u0000\u0000\u0198\u019a\u0003V+\u0000\u0199\u0197"+
		"\u0001\u0000\u0000\u0000\u019a\u019d\u0001\u0000\u0000\u0000\u019b\u0199"+
		"\u0001\u0000\u0000\u0000\u019b\u019c\u0001\u0000\u0000\u0000\u019cU\u0001"+
		"\u0000\u0000\u0000\u019d\u019b\u0001\u0000\u0000\u0000\u019e\u019f\u0003"+
		"X,\u0000\u019f\u01a0\u0005\u000e\u0000\u0000\u01a0\u01a1\u0003\u0010\b"+
		"\u0000\u01a1W\u0001\u0000\u0000\u0000\u01a2\u01a7\u0003Z-\u0000\u01a3"+
		"\u01a4\u0005\u0005\u0000\u0000\u01a4\u01a6\u0003Z-\u0000\u01a5\u01a3\u0001"+
		"\u0000\u0000\u0000\u01a6\u01a9\u0001\u0000\u0000\u0000\u01a7\u01a5\u0001"+
		"\u0000\u0000\u0000\u01a7\u01a8\u0001\u0000\u0000\u0000\u01a8Y\u0001\u0000"+
		"\u0000\u0000\u01a9\u01a7\u0001\u0000\u0000\u0000\u01aa\u01ab\u0005*\u0000"+
		"\u0000\u01ab\u01ac\u0005\u0006\u0000\u0000\u01ac\u01ad\u0003\u001a\r\u0000"+
		"\u01ad\u01ae\u0005\u0007\u0000\u0000\u01ae[\u0001\u0000\u0000\u0000\u01af"+
		"\u01b4\u0003^/\u0000\u01b0\u01b1\u0005\u0005\u0000\u0000\u01b1\u01b3\u0003"+
		"^/\u0000\u01b2\u01b0\u0001\u0000\u0000\u0000\u01b3\u01b6\u0001\u0000\u0000"+
		"\u0000\u01b4\u01b2\u0001\u0000\u0000\u0000\u01b4\u01b5\u0001\u0000\u0000"+
		"\u0000\u01b5]\u0001\u0000\u0000\u0000\u01b6\u01b4\u0001\u0000\u0000\u0000"+
		"\u01b7\u01b8\u0003N\'\u0000\u01b8\u01b9\u0005\u000e\u0000\u0000\u01b9"+
		"\u01ba\u0003\u0010\b\u0000\u01ba_\u0001\u0000\u0000\u0000\u01bb\u01bc"+
		"\u0005\u001c\u0000\u0000\u01bc\u01bd\u0003b1\u0000\u01bd\u01be\u0003d"+
		"2\u0000\u01be\u01bf\u0003f3\u0000\u01bfa\u0001\u0000\u0000\u0000\u01c0"+
		"\u01c6\u0001\u0000\u0000\u0000\u01c1\u01c2\u0005\f\u0000\u0000\u01c2\u01c3"+
		"\u0003F#\u0000\u01c3\u01c4\u0005\r\u0000\u0000\u01c4\u01c6\u0001\u0000"+
		"\u0000\u0000\u01c5\u01c0\u0001\u0000\u0000\u0000\u01c5\u01c1\u0001\u0000"+
		"\u0000\u0000\u01c6c\u0001\u0000\u0000\u0000\u01c7\u01ce\u0001\u0000\u0000"+
		"\u0000\u01c8\u01c9\u0005 \u0000\u0000\u01c9\u01ca\u0005\f\u0000\u0000"+
		"\u01ca\u01cb\u0003F#\u0000\u01cb\u01cc\u0005\r\u0000\u0000\u01cc\u01ce"+
		"\u0001\u0000\u0000\u0000\u01cd\u01c7\u0001\u0000\u0000\u0000\u01cd\u01c8"+
		"\u0001\u0000\u0000\u0000\u01cee\u0001\u0000\u0000\u0000\u01cf\u01d6\u0001"+
		"\u0000\u0000\u0000\u01d0\u01d1\u0005\u001f\u0000\u0000\u01d1\u01d2\u0005"+
		"\f\u0000\u0000\u01d2\u01d3\u0003N\'\u0000\u01d3\u01d4\u0005\r\u0000\u0000"+
		"\u01d4\u01d6\u0001\u0000\u0000\u0000\u01d5\u01cf\u0001\u0000\u0000\u0000"+
		"\u01d5\u01d0\u0001\u0000\u0000\u0000\u01d6g\u0001\u0000\u0000\u0000\u01d7"+
		"\u01d8\u0005\u0017\u0000\u0000\u01d8\u01d9\u0003b1\u0000\u01d9i\u0001"+
		"\u0000\u0000\u0000\u001d}\u0084\u0092\u0094\u0098\u00d2\u00e3\u00ed\u00f2"+
		"\u00f6\u00ff\u0108\u010e\u012b\u013e\u0145\u0150\u015a\u0162\u0169\u0175"+
		"\u0181\u0191\u019b\u01a7\u01b4\u01c5\u01cd\u01d5";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}