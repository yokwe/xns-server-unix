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
		RULE_typeDecl = 6, RULE_consDecl = 7, RULE_type = 8, RULE_cons = 9, RULE_reference = 10, 
		RULE_positiveNumber = 11, RULE_negativeNumber = 12, RULE_booleanType = 13, 
		RULE_booleanConstant = 14, RULE_cardinalType = 15, RULE_longCardinalType = 16, 
		RULE_integerType = 17, RULE_longIntegerType = 18, RULE_stringType = 19, 
		RULE_stringConstant = 20, RULE_unspecifiedType = 21, RULE_enumerationType = 22, 
		RULE_enumerationConstant = 23, RULE_correspondenceList = 24, RULE_correspondence = 25, 
		RULE_arrayType = 26, RULE_arrayConstant = 27, RULE_elementList = 28, RULE_sequenceType = 29, 
		RULE_recordType = 30, RULE_recordConstant = 31, RULE_fieldList = 32, RULE_field = 33, 
		RULE_componentList = 34, RULE_component = 35, RULE_nameList = 36, RULE_choiceType = 37, 
		RULE_choiceConstant = 38, RULE_candidateList = 39, RULE_candidate = 40, 
		RULE_designatorList = 41, RULE_designator = 42, RULE_candidateNameList = 43, 
		RULE_candidateName = 44, RULE_procedureType = 45, RULE_argumentList = 46, 
		RULE_resultList = 47, RULE_errorList = 48, RULE_errorType = 49;
	private static String[] makeRuleNames() {
		return new String[] {
			"courierProgram", "dependencyList", "referencedProgramList", "referencedProgram", 
			"declarationList", "declaration", "typeDecl", "consDecl", "type", "cons", 
			"reference", "positiveNumber", "negativeNumber", "booleanType", "booleanConstant", 
			"cardinalType", "longCardinalType", "integerType", "longIntegerType", 
			"stringType", "stringConstant", "unspecifiedType", "enumerationType", 
			"enumerationConstant", "correspondenceList", "correspondence", "arrayType", 
			"arrayConstant", "elementList", "sequenceType", "recordType", "recordConstant", 
			"fieldList", "field", "componentList", "component", "nameList", "choiceType", 
			"choiceConstant", "candidateList", "candidate", "designatorList", "designator", 
			"candidateNameList", "candidateName", "procedureType", "argumentList", 
			"resultList", "errorList", "errorType"
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
			setState(100);
			((CourierProgramContext)_localctx).name = match(ID);
			setState(101);
			match(T__0);
			setState(102);
			match(PROGRAM);
			setState(103);
			((CourierProgramContext)_localctx).program = positiveNumber();
			setState(104);
			match(VERSION);
			setState(105);
			((CourierProgramContext)_localctx).version = positiveNumber();
			setState(106);
			match(T__1);
			setState(107);
			match(BEGIN);
			setState(108);
			dependencyList();
			setState(109);
			declarationList();
			setState(110);
			match(END);
			setState(111);
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
			setState(119);
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
				setState(114);
				match(DEPENDS);
				setState(115);
				match(UPON);
				setState(116);
				referencedProgramList();
				setState(117);
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
			setState(121);
			((ReferencedProgramListContext)_localctx).referencedProgram = referencedProgram();
			((ReferencedProgramListContext)_localctx).elements.add(((ReferencedProgramListContext)_localctx).referencedProgram);
			setState(126);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__4) {
				{
				{
				setState(122);
				match(T__4);
				setState(123);
				((ReferencedProgramListContext)_localctx).referencedProgram = referencedProgram();
				((ReferencedProgramListContext)_localctx).elements.add(((ReferencedProgramListContext)_localctx).referencedProgram);
				}
				}
				setState(128);
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
			setState(129);
			((ReferencedProgramContext)_localctx).name = match(ID);
			setState(130);
			match(T__5);
			setState(131);
			((ReferencedProgramContext)_localctx).program = positiveNumber();
			setState(132);
			match(T__6);
			setState(133);
			match(VERSION);
			setState(134);
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
			setState(142);
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
				setState(138); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(137);
					((DeclarationListContext)_localctx).declaration = declaration();
					((DeclarationListContext)_localctx).elements.add(((DeclarationListContext)_localctx).declaration);
					}
					}
					setState(140); 
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
			setState(146);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
			case 1:
				_localctx = new DeclarationTypeContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(144);
				typeDecl();
				}
				break;
			case 2:
				_localctx = new DeclarationConsContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(145);
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
			setState(148);
			((TypeDeclContext)_localctx).name = match(ID);
			setState(149);
			match(T__0);
			setState(150);
			match(TYPE);
			setState(151);
			match(T__1);
			setState(152);
			type();
			setState(153);
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
		public Token name;
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public ConsContext cons() {
			return getRuleContext(ConsContext.class,0);
		}
		public TerminalNode ID() { return getToken(CourierParser.ID, 0); }
		public ConsDeclContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_consDecl; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitConsDecl(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ConsDeclContext consDecl() throws RecognitionException {
		ConsDeclContext _localctx = new ConsDeclContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_consDecl);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(155);
			((ConsDeclContext)_localctx).name = match(ID);
			setState(156);
			match(T__0);
			setState(157);
			type();
			setState(158);
			match(T__1);
			setState(159);
			cons();
			setState(160);
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
			setState(177);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,5,_ctx) ) {
			case 1:
				_localctx = new TypeBooleanContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(162);
				booleanType();
				}
				break;
			case 2:
				_localctx = new TypeCardinalContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(163);
				cardinalType();
				}
				break;
			case 3:
				_localctx = new TypeLongCardinalContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(164);
				longCardinalType();
				}
				break;
			case 4:
				_localctx = new TypeIntegerContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(165);
				integerType();
				}
				break;
			case 5:
				_localctx = new TypeLongIntegerContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(166);
				longIntegerType();
				}
				break;
			case 6:
				_localctx = new TypeStringContext(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(167);
				stringType();
				}
				break;
			case 7:
				_localctx = new TypeUnspecifiedContext(_localctx);
				enterOuterAlt(_localctx, 7);
				{
				setState(168);
				unspecifiedType();
				}
				break;
			case 8:
				_localctx = new TypeEnumerationContext(_localctx);
				enterOuterAlt(_localctx, 8);
				{
				setState(169);
				enumerationType();
				}
				break;
			case 9:
				_localctx = new TypeArrayContext(_localctx);
				enterOuterAlt(_localctx, 9);
				{
				setState(170);
				arrayType();
				}
				break;
			case 10:
				_localctx = new TypeSequenceContext(_localctx);
				enterOuterAlt(_localctx, 10);
				{
				setState(171);
				sequenceType();
				}
				break;
			case 11:
				_localctx = new TypeRecordContext(_localctx);
				enterOuterAlt(_localctx, 11);
				{
				setState(172);
				recordType();
				}
				break;
			case 12:
				_localctx = new TypeChoiceContext(_localctx);
				enterOuterAlt(_localctx, 12);
				{
				setState(173);
				choiceType();
				}
				break;
			case 13:
				_localctx = new TypeProcedureContext(_localctx);
				enterOuterAlt(_localctx, 13);
				{
				setState(174);
				procedureType();
				}
				break;
			case 14:
				_localctx = new TypeErrorContext(_localctx);
				enterOuterAlt(_localctx, 14);
				{
				setState(175);
				errorType();
				}
				break;
			case 15:
				_localctx = new TypeReferenceContext(_localctx);
				enterOuterAlt(_localctx, 15);
				{
				setState(176);
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
			setState(187);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,6,_ctx) ) {
			case 1:
				_localctx = new ConsBooleanContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(179);
				booleanConstant();
				}
				break;
			case 2:
				_localctx = new ConsPositiveContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(180);
				positiveNumber();
				}
				break;
			case 3:
				_localctx = new ConsNegativeContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(181);
				negativeNumber();
				}
				break;
			case 4:
				_localctx = new ConsStringContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(182);
				stringConstant();
				}
				break;
			case 5:
				_localctx = new ConsArrayContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(183);
				arrayConstant();
				}
				break;
			case 6:
				_localctx = new ConsRecordContext(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(184);
				recordConstant();
				}
				break;
			case 7:
				_localctx = new ConsChoiceContext(_localctx);
				enterOuterAlt(_localctx, 7);
				{
				setState(185);
				choiceConstant();
				}
				break;
			case 8:
				_localctx = new ConsReferenceContext(_localctx);
				enterOuterAlt(_localctx, 8);
				{
				setState(186);
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
		enterRule(_localctx, 20, RULE_reference);
		try {
			setState(196);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,7,_ctx) ) {
			case 1:
				_localctx = new ReferenceLocalContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(189);
				((ReferenceLocalContext)_localctx).name = match(ID);
				}
				break;
			case 2:
				_localctx = new ReferenceRemoteContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(190);
				((ReferenceRemoteContext)_localctx).program = match(ID);
				setState(191);
				match(T__2);
				setState(192);
				((ReferenceRemoteContext)_localctx).name = match(ID);
				}
				break;
			case 3:
				_localctx = new ReferenceExternalContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(193);
				((ReferenceExternalContext)_localctx).program = match(ID);
				setState(194);
				match(T__7);
				setState(195);
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
		enterRule(_localctx, 22, RULE_positiveNumber);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(198);
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
		enterRule(_localctx, 24, RULE_negativeNumber);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(200);
			match(T__8);
			setState(201);
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
		enterRule(_localctx, 26, RULE_booleanType);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(203);
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
		enterRule(_localctx, 28, RULE_booleanConstant);
		try {
			setState(207);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case TRUE:
				_localctx = new BooleanConstantTrueContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(205);
				match(TRUE);
				}
				break;
			case FALSE:
				_localctx = new BooleanConstantFalseContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(206);
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
		enterRule(_localctx, 30, RULE_cardinalType);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(209);
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
		enterRule(_localctx, 32, RULE_longCardinalType);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(211);
			match(LONG);
			setState(212);
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
		enterRule(_localctx, 34, RULE_integerType);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(214);
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
		enterRule(_localctx, 36, RULE_longIntegerType);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(216);
			match(LONG);
			setState(217);
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
		enterRule(_localctx, 38, RULE_stringType);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(219);
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
		enterRule(_localctx, 40, RULE_stringConstant);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(221);
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
		enterRule(_localctx, 42, RULE_unspecifiedType);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(223);
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
		enterRule(_localctx, 44, RULE_enumerationType);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(225);
			match(T__9);
			setState(226);
			correspondenceList();
			setState(227);
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
		enterRule(_localctx, 46, RULE_enumerationConstant);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(229);
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
		enterRule(_localctx, 48, RULE_correspondenceList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(231);
			((CorrespondenceListContext)_localctx).correspondence = correspondence();
			((CorrespondenceListContext)_localctx).elements.add(((CorrespondenceListContext)_localctx).correspondence);
			setState(236);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__4) {
				{
				{
				setState(232);
				match(T__4);
				setState(233);
				((CorrespondenceListContext)_localctx).correspondence = correspondence();
				((CorrespondenceListContext)_localctx).elements.add(((CorrespondenceListContext)_localctx).correspondence);
				}
				}
				setState(238);
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
		enterRule(_localctx, 50, RULE_correspondence);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(239);
			((CorrespondenceContext)_localctx).name = match(ID);
			setState(240);
			match(T__5);
			setState(241);
			((CorrespondenceContext)_localctx).number = positiveNumber();
			setState(242);
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
	public static class ArrayTypeReferenceContext extends ArrayTypeContext {
		public TerminalNode ARRAY() { return getToken(CourierParser.ARRAY, 0); }
		public ReferenceContext reference() {
			return getRuleContext(ReferenceContext.class,0);
		}
		public TerminalNode OF() { return getToken(CourierParser.OF, 0); }
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public ArrayTypeReferenceContext(ArrayTypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitArrayTypeReference(this);
			else return visitor.visitChildren(this);
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
		enterRule(_localctx, 52, RULE_arrayType);
		try {
			setState(254);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,10,_ctx) ) {
			case 1:
				_localctx = new ArrayTypeNumberContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(244);
				match(ARRAY);
				setState(245);
				positiveNumber();
				setState(246);
				match(OF);
				setState(247);
				type();
				}
				break;
			case 2:
				_localctx = new ArrayTypeReferenceContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(249);
				match(ARRAY);
				setState(250);
				reference();
				setState(251);
				match(OF);
				setState(252);
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
		enterRule(_localctx, 54, RULE_arrayConstant);
		try {
			setState(262);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,11,_ctx) ) {
			case 1:
				_localctx = new ArrayConstantListContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(256);
				match(T__11);
				setState(257);
				elementList();
				setState(258);
				match(T__12);
				}
				break;
			case 2:
				_localctx = new ArrayConstantEmptyContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(260);
				match(T__11);
				setState(261);
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
		enterRule(_localctx, 56, RULE_elementList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(264);
			((ElementListContext)_localctx).cons = cons();
			((ElementListContext)_localctx).elements.add(((ElementListContext)_localctx).cons);
			setState(269);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__4) {
				{
				{
				setState(265);
				match(T__4);
				setState(266);
				((ElementListContext)_localctx).cons = cons();
				((ElementListContext)_localctx).elements.add(((ElementListContext)_localctx).cons);
				}
				}
				setState(271);
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
	public static class SequenceTypeReferenceContext extends SequenceTypeContext {
		public TerminalNode SEQUENCE() { return getToken(CourierParser.SEQUENCE, 0); }
		public ReferenceContext reference() {
			return getRuleContext(ReferenceContext.class,0);
		}
		public TerminalNode OF() { return getToken(CourierParser.OF, 0); }
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public SequenceTypeReferenceContext(SequenceTypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitSequenceTypeReference(this);
			else return visitor.visitChildren(this);
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
		enterRule(_localctx, 58, RULE_sequenceType);
		try {
			setState(285);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,13,_ctx) ) {
			case 1:
				_localctx = new SequenceTypeEmptyContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(272);
				match(SEQUENCE);
				setState(273);
				match(OF);
				setState(274);
				type();
				}
				break;
			case 2:
				_localctx = new SequenceTypeNumberContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(275);
				match(SEQUENCE);
				setState(276);
				positiveNumber();
				setState(277);
				match(OF);
				setState(278);
				type();
				}
				break;
			case 3:
				_localctx = new SequenceTypeReferenceContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(280);
				match(SEQUENCE);
				setState(281);
				reference();
				setState(282);
				match(OF);
				setState(283);
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
		enterRule(_localctx, 60, RULE_recordType);
		try {
			setState(295);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,14,_ctx) ) {
			case 1:
				_localctx = new RecordTypeEmptyContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(287);
				match(RECORD);
				setState(288);
				match(T__11);
				setState(289);
				match(T__12);
				}
				break;
			case 2:
				_localctx = new RecordTypeListContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(290);
				match(RECORD);
				setState(291);
				match(T__11);
				setState(292);
				fieldList();
				setState(293);
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
		enterRule(_localctx, 62, RULE_recordConstant);
		try {
			setState(303);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,15,_ctx) ) {
			case 1:
				_localctx = new RecordConstantEmptyContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(297);
				match(T__11);
				setState(298);
				match(T__12);
				}
				break;
			case 2:
				_localctx = new RecordConstantListContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(299);
				match(T__11);
				setState(300);
				componentList();
				setState(301);
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
		enterRule(_localctx, 64, RULE_fieldList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(305);
			((FieldListContext)_localctx).field = field();
			((FieldListContext)_localctx).elements.add(((FieldListContext)_localctx).field);
			setState(310);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__4) {
				{
				{
				setState(306);
				match(T__4);
				setState(307);
				((FieldListContext)_localctx).field = field();
				((FieldListContext)_localctx).elements.add(((FieldListContext)_localctx).field);
				}
				}
				setState(312);
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
		enterRule(_localctx, 66, RULE_field);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(313);
			nameList();
			setState(314);
			match(T__0);
			setState(315);
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
		enterRule(_localctx, 68, RULE_componentList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(317);
			((ComponentListContext)_localctx).component = component();
			((ComponentListContext)_localctx).elements.add(((ComponentListContext)_localctx).component);
			setState(322);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__4) {
				{
				{
				setState(318);
				match(T__4);
				setState(319);
				((ComponentListContext)_localctx).component = component();
				((ComponentListContext)_localctx).elements.add(((ComponentListContext)_localctx).component);
				}
				}
				setState(324);
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
		enterRule(_localctx, 70, RULE_component);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(325);
			nameList();
			setState(326);
			match(T__0);
			setState(327);
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
		enterRule(_localctx, 72, RULE_nameList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(329);
			((NameListContext)_localctx).ID = match(ID);
			((NameListContext)_localctx).elements.add(((NameListContext)_localctx).ID);
			setState(334);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__4) {
				{
				{
				setState(330);
				match(T__4);
				setState(331);
				((NameListContext)_localctx).ID = match(ID);
				((NameListContext)_localctx).elements.add(((NameListContext)_localctx).ID);
				}
				}
				setState(336);
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
		enterRule(_localctx, 74, RULE_choiceType);
		try {
			setState(350);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,19,_ctx) ) {
			case 1:
				_localctx = new ChoiceTypeAnonContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(337);
				match(CHOICE);
				setState(338);
				match(OF);
				setState(339);
				match(T__9);
				setState(340);
				candidateList();
				setState(341);
				match(T__10);
				}
				break;
			case 2:
				_localctx = new ChoiceTypeNameContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(343);
				match(CHOICE);
				setState(344);
				reference();
				setState(345);
				match(OF);
				setState(346);
				match(T__9);
				setState(347);
				candidateNameList();
				setState(348);
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
		enterRule(_localctx, 76, RULE_choiceConstant);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(352);
			((ChoiceConstantContext)_localctx).name = match(ID);
			setState(353);
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
		enterRule(_localctx, 78, RULE_candidateList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(355);
			((CandidateListContext)_localctx).candidate = candidate();
			((CandidateListContext)_localctx).elements.add(((CandidateListContext)_localctx).candidate);
			setState(360);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__4) {
				{
				{
				setState(356);
				match(T__4);
				setState(357);
				((CandidateListContext)_localctx).candidate = candidate();
				((CandidateListContext)_localctx).elements.add(((CandidateListContext)_localctx).candidate);
				}
				}
				setState(362);
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
		enterRule(_localctx, 80, RULE_candidate);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(363);
			designatorList();
			setState(364);
			match(T__13);
			setState(365);
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
		enterRule(_localctx, 82, RULE_designatorList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(367);
			((DesignatorListContext)_localctx).designator = designator();
			((DesignatorListContext)_localctx).elements.add(((DesignatorListContext)_localctx).designator);
			setState(372);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__4) {
				{
				{
				setState(368);
				match(T__4);
				setState(369);
				((DesignatorListContext)_localctx).designator = designator();
				((DesignatorListContext)_localctx).elements.add(((DesignatorListContext)_localctx).designator);
				}
				}
				setState(374);
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
		enterRule(_localctx, 84, RULE_designator);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(375);
			((DesignatorContext)_localctx).name = match(ID);
			setState(376);
			match(T__5);
			setState(377);
			((DesignatorContext)_localctx).number = positiveNumber();
			setState(378);
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
		enterRule(_localctx, 86, RULE_candidateNameList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(380);
			((CandidateNameListContext)_localctx).candidateName = candidateName();
			((CandidateNameListContext)_localctx).elements.add(((CandidateNameListContext)_localctx).candidateName);
			setState(385);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__4) {
				{
				{
				setState(381);
				match(T__4);
				setState(382);
				((CandidateNameListContext)_localctx).candidateName = candidateName();
				((CandidateNameListContext)_localctx).elements.add(((CandidateNameListContext)_localctx).candidateName);
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
		enterRule(_localctx, 88, RULE_candidateName);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(388);
			nameList();
			setState(389);
			match(T__13);
			setState(390);
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
		enterRule(_localctx, 90, RULE_procedureType);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(392);
			match(PROCEDURE);
			setState(393);
			argumentList();
			setState(394);
			resultList();
			setState(395);
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
		enterRule(_localctx, 92, RULE_argumentList);
		try {
			setState(402);
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
				setState(398);
				match(T__11);
				setState(399);
				fieldList();
				setState(400);
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
		enterRule(_localctx, 94, RULE_resultList);
		try {
			setState(410);
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
				setState(405);
				match(RETURNS);
				setState(406);
				match(T__11);
				setState(407);
				fieldList();
				setState(408);
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
		enterRule(_localctx, 96, RULE_errorList);
		try {
			setState(418);
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
				setState(413);
				match(REPORTS);
				setState(414);
				match(T__11);
				setState(415);
				nameList();
				setState(416);
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
		enterRule(_localctx, 98, RULE_errorType);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(420);
			match(ERROR);
			setState(421);
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
		"\u0004\u0001.\u01a8\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
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
		"-\u0007-\u0002.\u0007.\u0002/\u0007/\u00020\u00070\u00021\u00071\u0001"+
		"\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001"+
		"\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001"+
		"\u0000\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0003\u0001x\b\u0001\u0001\u0002\u0001\u0002\u0001\u0002\u0005"+
		"\u0002}\b\u0002\n\u0002\f\u0002\u0080\t\u0002\u0001\u0003\u0001\u0003"+
		"\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0004"+
		"\u0001\u0004\u0004\u0004\u008b\b\u0004\u000b\u0004\f\u0004\u008c\u0003"+
		"\u0004\u008f\b\u0004\u0001\u0005\u0001\u0005\u0003\u0005\u0093\b\u0005"+
		"\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006"+
		"\u0001\u0006\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007"+
		"\u0001\u0007\u0001\u0007\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001"+
		"\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001"+
		"\b\u0003\b\u00b2\b\b\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001"+
		"\t\u0001\t\u0003\t\u00bc\b\t\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001"+
		"\n\u0001\n\u0003\n\u00c5\b\n\u0001\u000b\u0001\u000b\u0001\f\u0001\f\u0001"+
		"\f\u0001\r\u0001\r\u0001\u000e\u0001\u000e\u0003\u000e\u00d0\b\u000e\u0001"+
		"\u000f\u0001\u000f\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0011\u0001"+
		"\u0011\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0013\u0001\u0013\u0001"+
		"\u0014\u0001\u0014\u0001\u0015\u0001\u0015\u0001\u0016\u0001\u0016\u0001"+
		"\u0016\u0001\u0016\u0001\u0017\u0001\u0017\u0001\u0018\u0001\u0018\u0001"+
		"\u0018\u0005\u0018\u00eb\b\u0018\n\u0018\f\u0018\u00ee\t\u0018\u0001\u0019"+
		"\u0001\u0019\u0001\u0019\u0001\u0019\u0001\u0019\u0001\u001a\u0001\u001a"+
		"\u0001\u001a\u0001\u001a\u0001\u001a\u0001\u001a\u0001\u001a\u0001\u001a"+
		"\u0001\u001a\u0001\u001a\u0003\u001a\u00ff\b\u001a\u0001\u001b\u0001\u001b"+
		"\u0001\u001b\u0001\u001b\u0001\u001b\u0001\u001b\u0003\u001b\u0107\b\u001b"+
		"\u0001\u001c\u0001\u001c\u0001\u001c\u0005\u001c\u010c\b\u001c\n\u001c"+
		"\f\u001c\u010f\t\u001c\u0001\u001d\u0001\u001d\u0001\u001d\u0001\u001d"+
		"\u0001\u001d\u0001\u001d\u0001\u001d\u0001\u001d\u0001\u001d\u0001\u001d"+
		"\u0001\u001d\u0001\u001d\u0001\u001d\u0003\u001d\u011e\b\u001d\u0001\u001e"+
		"\u0001\u001e\u0001\u001e\u0001\u001e\u0001\u001e\u0001\u001e\u0001\u001e"+
		"\u0001\u001e\u0003\u001e\u0128\b\u001e\u0001\u001f\u0001\u001f\u0001\u001f"+
		"\u0001\u001f\u0001\u001f\u0001\u001f\u0003\u001f\u0130\b\u001f\u0001 "+
		"\u0001 \u0001 \u0005 \u0135\b \n \f \u0138\t \u0001!\u0001!\u0001!\u0001"+
		"!\u0001\"\u0001\"\u0001\"\u0005\"\u0141\b\"\n\"\f\"\u0144\t\"\u0001#\u0001"+
		"#\u0001#\u0001#\u0001$\u0001$\u0001$\u0005$\u014d\b$\n$\f$\u0150\t$\u0001"+
		"%\u0001%\u0001%\u0001%\u0001%\u0001%\u0001%\u0001%\u0001%\u0001%\u0001"+
		"%\u0001%\u0001%\u0003%\u015f\b%\u0001&\u0001&\u0001&\u0001\'\u0001\'\u0001"+
		"\'\u0005\'\u0167\b\'\n\'\f\'\u016a\t\'\u0001(\u0001(\u0001(\u0001(\u0001"+
		")\u0001)\u0001)\u0005)\u0173\b)\n)\f)\u0176\t)\u0001*\u0001*\u0001*\u0001"+
		"*\u0001*\u0001+\u0001+\u0001+\u0005+\u0180\b+\n+\f+\u0183\t+\u0001,\u0001"+
		",\u0001,\u0001,\u0001-\u0001-\u0001-\u0001-\u0001-\u0001.\u0001.\u0001"+
		".\u0001.\u0001.\u0003.\u0193\b.\u0001/\u0001/\u0001/\u0001/\u0001/\u0001"+
		"/\u0003/\u019b\b/\u00010\u00010\u00010\u00010\u00010\u00010\u00030\u01a3"+
		"\b0\u00011\u00011\u00011\u00011\u0000\u00002\u0000\u0002\u0004\u0006\b"+
		"\n\f\u000e\u0010\u0012\u0014\u0016\u0018\u001a\u001c\u001e \"$&(*,.02"+
		"468:<>@BDFHJLNPRTVXZ\\^`b\u0000\u0000\u01a4\u0000d\u0001\u0000\u0000\u0000"+
		"\u0002w\u0001\u0000\u0000\u0000\u0004y\u0001\u0000\u0000\u0000\u0006\u0081"+
		"\u0001\u0000\u0000\u0000\b\u008e\u0001\u0000\u0000\u0000\n\u0092\u0001"+
		"\u0000\u0000\u0000\f\u0094\u0001\u0000\u0000\u0000\u000e\u009b\u0001\u0000"+
		"\u0000\u0000\u0010\u00b1\u0001\u0000\u0000\u0000\u0012\u00bb\u0001\u0000"+
		"\u0000\u0000\u0014\u00c4\u0001\u0000\u0000\u0000\u0016\u00c6\u0001\u0000"+
		"\u0000\u0000\u0018\u00c8\u0001\u0000\u0000\u0000\u001a\u00cb\u0001\u0000"+
		"\u0000\u0000\u001c\u00cf\u0001\u0000\u0000\u0000\u001e\u00d1\u0001\u0000"+
		"\u0000\u0000 \u00d3\u0001\u0000\u0000\u0000\"\u00d6\u0001\u0000\u0000"+
		"\u0000$\u00d8\u0001\u0000\u0000\u0000&\u00db\u0001\u0000\u0000\u0000("+
		"\u00dd\u0001\u0000\u0000\u0000*\u00df\u0001\u0000\u0000\u0000,\u00e1\u0001"+
		"\u0000\u0000\u0000.\u00e5\u0001\u0000\u0000\u00000\u00e7\u0001\u0000\u0000"+
		"\u00002\u00ef\u0001\u0000\u0000\u00004\u00fe\u0001\u0000\u0000\u00006"+
		"\u0106\u0001\u0000\u0000\u00008\u0108\u0001\u0000\u0000\u0000:\u011d\u0001"+
		"\u0000\u0000\u0000<\u0127\u0001\u0000\u0000\u0000>\u012f\u0001\u0000\u0000"+
		"\u0000@\u0131\u0001\u0000\u0000\u0000B\u0139\u0001\u0000\u0000\u0000D"+
		"\u013d\u0001\u0000\u0000\u0000F\u0145\u0001\u0000\u0000\u0000H\u0149\u0001"+
		"\u0000\u0000\u0000J\u015e\u0001\u0000\u0000\u0000L\u0160\u0001\u0000\u0000"+
		"\u0000N\u0163\u0001\u0000\u0000\u0000P\u016b\u0001\u0000\u0000\u0000R"+
		"\u016f\u0001\u0000\u0000\u0000T\u0177\u0001\u0000\u0000\u0000V\u017c\u0001"+
		"\u0000\u0000\u0000X\u0184\u0001\u0000\u0000\u0000Z\u0188\u0001\u0000\u0000"+
		"\u0000\\\u0192\u0001\u0000\u0000\u0000^\u019a\u0001\u0000\u0000\u0000"+
		"`\u01a2\u0001\u0000\u0000\u0000b\u01a4\u0001\u0000\u0000\u0000de\u0005"+
		"*\u0000\u0000ef\u0005\u0001\u0000\u0000fg\u0005\u001d\u0000\u0000gh\u0003"+
		"\u0016\u000b\u0000hi\u0005&\u0000\u0000ij\u0003\u0016\u000b\u0000jk\u0005"+
		"\u0002\u0000\u0000kl\u0005\u0010\u0000\u0000lm\u0003\u0002\u0001\u0000"+
		"mn\u0003\b\u0004\u0000no\u0005\u0016\u0000\u0000op\u0005\u0003\u0000\u0000"+
		"p\u0001\u0001\u0000\u0000\u0000qx\u0001\u0000\u0000\u0000rs\u0005\u0014"+
		"\u0000\u0000st\u0005%\u0000\u0000tu\u0003\u0004\u0002\u0000uv\u0005\u0004"+
		"\u0000\u0000vx\u0001\u0000\u0000\u0000wq\u0001\u0000\u0000\u0000wr\u0001"+
		"\u0000\u0000\u0000x\u0003\u0001\u0000\u0000\u0000y~\u0003\u0006\u0003"+
		"\u0000z{\u0005\u0005\u0000\u0000{}\u0003\u0006\u0003\u0000|z\u0001\u0000"+
		"\u0000\u0000}\u0080\u0001\u0000\u0000\u0000~|\u0001\u0000\u0000\u0000"+
		"~\u007f\u0001\u0000\u0000\u0000\u007f\u0005\u0001\u0000\u0000\u0000\u0080"+
		"~\u0001\u0000\u0000\u0000\u0081\u0082\u0005*\u0000\u0000\u0082\u0083\u0005"+
		"\u0006\u0000\u0000\u0083\u0084\u0003\u0016\u000b\u0000\u0084\u0085\u0005"+
		"\u0007\u0000\u0000\u0085\u0086\u0005&\u0000\u0000\u0086\u0087\u0003\u0016"+
		"\u000b\u0000\u0087\u0007\u0001\u0000\u0000\u0000\u0088\u008f\u0001\u0000"+
		"\u0000\u0000\u0089\u008b\u0003\n\u0005\u0000\u008a\u0089\u0001\u0000\u0000"+
		"\u0000\u008b\u008c\u0001\u0000\u0000\u0000\u008c\u008a\u0001\u0000\u0000"+
		"\u0000\u008c\u008d\u0001\u0000\u0000\u0000\u008d\u008f\u0001\u0000\u0000"+
		"\u0000\u008e\u0088\u0001\u0000\u0000\u0000\u008e\u008a\u0001\u0000\u0000"+
		"\u0000\u008f\t\u0001\u0000\u0000\u0000\u0090\u0093\u0003\f\u0006\u0000"+
		"\u0091\u0093\u0003\u000e\u0007\u0000\u0092\u0090\u0001\u0000\u0000\u0000"+
		"\u0092\u0091\u0001\u0000\u0000\u0000\u0093\u000b\u0001\u0000\u0000\u0000"+
		"\u0094\u0095\u0005*\u0000\u0000\u0095\u0096\u0005\u0001\u0000\u0000\u0096"+
		"\u0097\u0005#\u0000\u0000\u0097\u0098\u0005\u0002\u0000\u0000\u0098\u0099"+
		"\u0003\u0010\b\u0000\u0099\u009a\u0005\u0004\u0000\u0000\u009a\r\u0001"+
		"\u0000\u0000\u0000\u009b\u009c\u0005*\u0000\u0000\u009c\u009d\u0005\u0001"+
		"\u0000\u0000\u009d\u009e\u0003\u0010\b\u0000\u009e\u009f\u0005\u0002\u0000"+
		"\u0000\u009f\u00a0\u0003\u0012\t\u0000\u00a0\u00a1\u0005\u0004\u0000\u0000"+
		"\u00a1\u000f\u0001\u0000\u0000\u0000\u00a2\u00b2\u0003\u001a\r\u0000\u00a3"+
		"\u00b2\u0003\u001e\u000f\u0000\u00a4\u00b2\u0003 \u0010\u0000\u00a5\u00b2"+
		"\u0003\"\u0011\u0000\u00a6\u00b2\u0003$\u0012\u0000\u00a7\u00b2\u0003"+
		"&\u0013\u0000\u00a8\u00b2\u0003*\u0015\u0000\u00a9\u00b2\u0003,\u0016"+
		"\u0000\u00aa\u00b2\u00034\u001a\u0000\u00ab\u00b2\u0003:\u001d\u0000\u00ac"+
		"\u00b2\u0003<\u001e\u0000\u00ad\u00b2\u0003J%\u0000\u00ae\u00b2\u0003"+
		"Z-\u0000\u00af\u00b2\u0003b1\u0000\u00b0\u00b2\u0003\u0014\n\u0000\u00b1"+
		"\u00a2\u0001\u0000\u0000\u0000\u00b1\u00a3\u0001\u0000\u0000\u0000\u00b1"+
		"\u00a4\u0001\u0000\u0000\u0000\u00b1\u00a5\u0001\u0000\u0000\u0000\u00b1"+
		"\u00a6\u0001\u0000\u0000\u0000\u00b1\u00a7\u0001\u0000\u0000\u0000\u00b1"+
		"\u00a8\u0001\u0000\u0000\u0000\u00b1\u00a9\u0001\u0000\u0000\u0000\u00b1"+
		"\u00aa\u0001\u0000\u0000\u0000\u00b1\u00ab\u0001\u0000\u0000\u0000\u00b1"+
		"\u00ac\u0001\u0000\u0000\u0000\u00b1\u00ad\u0001\u0000\u0000\u0000\u00b1"+
		"\u00ae\u0001\u0000\u0000\u0000\u00b1\u00af\u0001\u0000\u0000\u0000\u00b1"+
		"\u00b0\u0001\u0000\u0000\u0000\u00b2\u0011\u0001\u0000\u0000\u0000\u00b3"+
		"\u00bc\u0003\u001c\u000e\u0000\u00b4\u00bc\u0003\u0016\u000b\u0000\u00b5"+
		"\u00bc\u0003\u0018\f\u0000\u00b6\u00bc\u0003(\u0014\u0000\u00b7\u00bc"+
		"\u00036\u001b\u0000\u00b8\u00bc\u0003>\u001f\u0000\u00b9\u00bc\u0003L"+
		"&\u0000\u00ba\u00bc\u0003\u0014\n\u0000\u00bb\u00b3\u0001\u0000\u0000"+
		"\u0000\u00bb\u00b4\u0001\u0000\u0000\u0000\u00bb\u00b5\u0001\u0000\u0000"+
		"\u0000\u00bb\u00b6\u0001\u0000\u0000\u0000\u00bb\u00b7\u0001\u0000\u0000"+
		"\u0000\u00bb\u00b8\u0001\u0000\u0000\u0000\u00bb\u00b9\u0001\u0000\u0000"+
		"\u0000\u00bb\u00ba\u0001\u0000\u0000\u0000\u00bc\u0013\u0001\u0000\u0000"+
		"\u0000\u00bd\u00c5\u0005*\u0000\u0000\u00be\u00bf\u0005*\u0000\u0000\u00bf"+
		"\u00c0\u0005\u0003\u0000\u0000\u00c0\u00c5\u0005*\u0000\u0000\u00c1\u00c2"+
		"\u0005*\u0000\u0000\u00c2\u00c3\u0005\b\u0000\u0000\u00c3\u00c5\u0005"+
		"*\u0000\u0000\u00c4\u00bd\u0001\u0000\u0000\u0000\u00c4\u00be\u0001\u0000"+
		"\u0000\u0000\u00c4\u00c1\u0001\u0000\u0000\u0000\u00c5\u0015\u0001\u0000"+
		"\u0000\u0000\u00c6\u00c7\u0005)\u0000\u0000\u00c7\u0017\u0001\u0000\u0000"+
		"\u0000\u00c8\u00c9\u0005\t\u0000\u0000\u00c9\u00ca\u0005)\u0000\u0000"+
		"\u00ca\u0019\u0001\u0000\u0000\u0000\u00cb\u00cc\u0005\u0011\u0000\u0000"+
		"\u00cc\u001b\u0001\u0000\u0000\u0000\u00cd\u00d0\u0005\'\u0000\u0000\u00ce"+
		"\u00d0\u0005(\u0000\u0000\u00cf\u00cd\u0001\u0000\u0000\u0000\u00cf\u00ce"+
		"\u0001\u0000\u0000\u0000\u00d0\u001d\u0001\u0000\u0000\u0000\u00d1\u00d2"+
		"\u0005\u0012\u0000\u0000\u00d2\u001f\u0001\u0000\u0000\u0000\u00d3\u00d4"+
		"\u0005\u0019\u0000\u0000\u00d4\u00d5\u0005\u0012\u0000\u0000\u00d5!\u0001"+
		"\u0000\u0000\u0000\u00d6\u00d7\u0005\u0018\u0000\u0000\u00d7#\u0001\u0000"+
		"\u0000\u0000\u00d8\u00d9\u0005\u0019\u0000\u0000\u00d9\u00da\u0005\u0018"+
		"\u0000\u0000\u00da%\u0001\u0000\u0000\u0000\u00db\u00dc\u0005\"\u0000"+
		"\u0000\u00dc\'\u0001\u0000\u0000\u0000\u00dd\u00de\u0005+\u0000\u0000"+
		"\u00de)\u0001\u0000\u0000\u0000\u00df\u00e0\u0005$\u0000\u0000\u00e0+"+
		"\u0001\u0000\u0000\u0000\u00e1\u00e2\u0005\n\u0000\u0000\u00e2\u00e3\u0003"+
		"0\u0018\u0000\u00e3\u00e4\u0005\u000b\u0000\u0000\u00e4-\u0001\u0000\u0000"+
		"\u0000\u00e5\u00e6\u0005*\u0000\u0000\u00e6/\u0001\u0000\u0000\u0000\u00e7"+
		"\u00ec\u00032\u0019\u0000\u00e8\u00e9\u0005\u0005\u0000\u0000\u00e9\u00eb"+
		"\u00032\u0019\u0000\u00ea\u00e8\u0001\u0000\u0000\u0000\u00eb\u00ee\u0001"+
		"\u0000\u0000\u0000\u00ec\u00ea\u0001\u0000\u0000\u0000\u00ec\u00ed\u0001"+
		"\u0000\u0000\u0000\u00ed1\u0001\u0000\u0000\u0000\u00ee\u00ec\u0001\u0000"+
		"\u0000\u0000\u00ef\u00f0\u0005*\u0000\u0000\u00f0\u00f1\u0005\u0006\u0000"+
		"\u0000\u00f1\u00f2\u0003\u0016\u000b\u0000\u00f2\u00f3\u0005\u0007\u0000"+
		"\u0000\u00f33\u0001\u0000\u0000\u0000\u00f4\u00f5\u0005\u000f\u0000\u0000"+
		"\u00f5\u00f6\u0003\u0016\u000b\u0000\u00f6\u00f7\u0005\u001b\u0000\u0000"+
		"\u00f7\u00f8\u0003\u0010\b\u0000\u00f8\u00ff\u0001\u0000\u0000\u0000\u00f9"+
		"\u00fa\u0005\u000f\u0000\u0000\u00fa\u00fb\u0003\u0014\n\u0000\u00fb\u00fc"+
		"\u0005\u001b\u0000\u0000\u00fc\u00fd\u0003\u0010\b\u0000\u00fd\u00ff\u0001"+
		"\u0000\u0000\u0000\u00fe\u00f4\u0001\u0000\u0000\u0000\u00fe\u00f9\u0001"+
		"\u0000\u0000\u0000\u00ff5\u0001\u0000\u0000\u0000\u0100\u0101\u0005\f"+
		"\u0000\u0000\u0101\u0102\u00038\u001c\u0000\u0102\u0103\u0005\r\u0000"+
		"\u0000\u0103\u0107\u0001\u0000\u0000\u0000\u0104\u0105\u0005\f\u0000\u0000"+
		"\u0105\u0107\u0005\r\u0000\u0000\u0106\u0100\u0001\u0000\u0000\u0000\u0106"+
		"\u0104\u0001\u0000\u0000\u0000\u01077\u0001\u0000\u0000\u0000\u0108\u010d"+
		"\u0003\u0012\t\u0000\u0109\u010a\u0005\u0005\u0000\u0000\u010a\u010c\u0003"+
		"\u0012\t\u0000\u010b\u0109\u0001\u0000\u0000\u0000\u010c\u010f\u0001\u0000"+
		"\u0000\u0000\u010d\u010b\u0001\u0000\u0000\u0000\u010d\u010e\u0001\u0000"+
		"\u0000\u0000\u010e9\u0001\u0000\u0000\u0000\u010f\u010d\u0001\u0000\u0000"+
		"\u0000\u0110\u0111\u0005!\u0000\u0000\u0111\u0112\u0005\u001b\u0000\u0000"+
		"\u0112\u011e\u0003\u0010\b\u0000\u0113\u0114\u0005!\u0000\u0000\u0114"+
		"\u0115\u0003\u0016\u000b\u0000\u0115\u0116\u0005\u001b\u0000\u0000\u0116"+
		"\u0117\u0003\u0010\b\u0000\u0117\u011e\u0001\u0000\u0000\u0000\u0118\u0119"+
		"\u0005!\u0000\u0000\u0119\u011a\u0003\u0014\n\u0000\u011a\u011b\u0005"+
		"\u001b\u0000\u0000\u011b\u011c\u0003\u0010\b\u0000\u011c\u011e\u0001\u0000"+
		"\u0000\u0000\u011d\u0110\u0001\u0000\u0000\u0000\u011d\u0113\u0001\u0000"+
		"\u0000\u0000\u011d\u0118\u0001\u0000\u0000\u0000\u011e;\u0001\u0000\u0000"+
		"\u0000\u011f\u0120\u0005\u001e\u0000\u0000\u0120\u0121\u0005\f\u0000\u0000"+
		"\u0121\u0128\u0005\r\u0000\u0000\u0122\u0123\u0005\u001e\u0000\u0000\u0123"+
		"\u0124\u0005\f\u0000\u0000\u0124\u0125\u0003@ \u0000\u0125\u0126\u0005"+
		"\r\u0000\u0000\u0126\u0128\u0001\u0000\u0000\u0000\u0127\u011f\u0001\u0000"+
		"\u0000\u0000\u0127\u0122\u0001\u0000\u0000\u0000\u0128=\u0001\u0000\u0000"+
		"\u0000\u0129\u012a\u0005\f\u0000\u0000\u012a\u0130\u0005\r\u0000\u0000"+
		"\u012b\u012c\u0005\f\u0000\u0000\u012c\u012d\u0003D\"\u0000\u012d\u012e"+
		"\u0005\r\u0000\u0000\u012e\u0130\u0001\u0000\u0000\u0000\u012f\u0129\u0001"+
		"\u0000\u0000\u0000\u012f\u012b\u0001\u0000\u0000\u0000\u0130?\u0001\u0000"+
		"\u0000\u0000\u0131\u0136\u0003B!\u0000\u0132\u0133\u0005\u0005\u0000\u0000"+
		"\u0133\u0135\u0003B!\u0000\u0134\u0132\u0001\u0000\u0000\u0000\u0135\u0138"+
		"\u0001\u0000\u0000\u0000\u0136\u0134\u0001\u0000\u0000\u0000\u0136\u0137"+
		"\u0001\u0000\u0000\u0000\u0137A\u0001\u0000\u0000\u0000\u0138\u0136\u0001"+
		"\u0000\u0000\u0000\u0139\u013a\u0003H$\u0000\u013a\u013b\u0005\u0001\u0000"+
		"\u0000\u013b\u013c\u0003\u0010\b\u0000\u013cC\u0001\u0000\u0000\u0000"+
		"\u013d\u0142\u0003F#\u0000\u013e\u013f\u0005\u0005\u0000\u0000\u013f\u0141"+
		"\u0003F#\u0000\u0140\u013e\u0001\u0000\u0000\u0000\u0141\u0144\u0001\u0000"+
		"\u0000\u0000\u0142\u0140\u0001\u0000\u0000\u0000\u0142\u0143\u0001\u0000"+
		"\u0000\u0000\u0143E\u0001\u0000\u0000\u0000\u0144\u0142\u0001\u0000\u0000"+
		"\u0000\u0145\u0146\u0003H$\u0000\u0146\u0147\u0005\u0001\u0000\u0000\u0147"+
		"\u0148\u0003\u0012\t\u0000\u0148G\u0001\u0000\u0000\u0000\u0149\u014e"+
		"\u0005*\u0000\u0000\u014a\u014b\u0005\u0005\u0000\u0000\u014b\u014d\u0005"+
		"*\u0000\u0000\u014c\u014a\u0001\u0000\u0000\u0000\u014d\u0150\u0001\u0000"+
		"\u0000\u0000\u014e\u014c\u0001\u0000\u0000\u0000\u014e\u014f\u0001\u0000"+
		"\u0000\u0000\u014fI\u0001\u0000\u0000\u0000\u0150\u014e\u0001\u0000\u0000"+
		"\u0000\u0151\u0152\u0005\u0013\u0000\u0000\u0152\u0153\u0005\u001b\u0000"+
		"\u0000\u0153\u0154\u0005\n\u0000\u0000\u0154\u0155\u0003N\'\u0000\u0155"+
		"\u0156\u0005\u000b\u0000\u0000\u0156\u015f\u0001\u0000\u0000\u0000\u0157"+
		"\u0158\u0005\u0013\u0000\u0000\u0158\u0159\u0003\u0014\n\u0000\u0159\u015a"+
		"\u0005\u001b\u0000\u0000\u015a\u015b\u0005\n\u0000\u0000\u015b\u015c\u0003"+
		"V+\u0000\u015c\u015d\u0005\u000b\u0000\u0000\u015d\u015f\u0001\u0000\u0000"+
		"\u0000\u015e\u0151\u0001\u0000\u0000\u0000\u015e\u0157\u0001\u0000\u0000"+
		"\u0000\u015fK\u0001\u0000\u0000\u0000\u0160\u0161\u0005*\u0000\u0000\u0161"+
		"\u0162\u0003\u0012\t\u0000\u0162M\u0001\u0000\u0000\u0000\u0163\u0168"+
		"\u0003P(\u0000\u0164\u0165\u0005\u0005\u0000\u0000\u0165\u0167\u0003P"+
		"(\u0000\u0166\u0164\u0001\u0000\u0000\u0000\u0167\u016a\u0001\u0000\u0000"+
		"\u0000\u0168\u0166\u0001\u0000\u0000\u0000\u0168\u0169\u0001\u0000\u0000"+
		"\u0000\u0169O\u0001\u0000\u0000\u0000\u016a\u0168\u0001\u0000\u0000\u0000"+
		"\u016b\u016c\u0003R)\u0000\u016c\u016d\u0005\u000e\u0000\u0000\u016d\u016e"+
		"\u0003\u0010\b\u0000\u016eQ\u0001\u0000\u0000\u0000\u016f\u0174\u0003"+
		"T*\u0000\u0170\u0171\u0005\u0005\u0000\u0000\u0171\u0173\u0003T*\u0000"+
		"\u0172\u0170\u0001\u0000\u0000\u0000\u0173\u0176\u0001\u0000\u0000\u0000"+
		"\u0174\u0172\u0001\u0000\u0000\u0000\u0174\u0175\u0001\u0000\u0000\u0000"+
		"\u0175S\u0001\u0000\u0000\u0000\u0176\u0174\u0001\u0000\u0000\u0000\u0177"+
		"\u0178\u0005*\u0000\u0000\u0178\u0179\u0005\u0006\u0000\u0000\u0179\u017a"+
		"\u0003\u0016\u000b\u0000\u017a\u017b\u0005\u0007\u0000\u0000\u017bU\u0001"+
		"\u0000\u0000\u0000\u017c\u0181\u0003X,\u0000\u017d\u017e\u0005\u0005\u0000"+
		"\u0000\u017e\u0180\u0003X,\u0000\u017f\u017d\u0001\u0000\u0000\u0000\u0180"+
		"\u0183\u0001\u0000\u0000\u0000\u0181\u017f\u0001\u0000\u0000\u0000\u0181"+
		"\u0182\u0001\u0000\u0000\u0000\u0182W\u0001\u0000\u0000\u0000\u0183\u0181"+
		"\u0001\u0000\u0000\u0000\u0184\u0185\u0003H$\u0000\u0185\u0186\u0005\u000e"+
		"\u0000\u0000\u0186\u0187\u0003\u0010\b\u0000\u0187Y\u0001\u0000\u0000"+
		"\u0000\u0188\u0189\u0005\u001c\u0000\u0000\u0189\u018a\u0003\\.\u0000"+
		"\u018a\u018b\u0003^/\u0000\u018b\u018c\u0003`0\u0000\u018c[\u0001\u0000"+
		"\u0000\u0000\u018d\u0193\u0001\u0000\u0000\u0000\u018e\u018f\u0005\f\u0000"+
		"\u0000\u018f\u0190\u0003@ \u0000\u0190\u0191\u0005\r\u0000\u0000\u0191"+
		"\u0193\u0001\u0000\u0000\u0000\u0192\u018d\u0001\u0000\u0000\u0000\u0192"+
		"\u018e\u0001\u0000\u0000\u0000\u0193]\u0001\u0000\u0000\u0000\u0194\u019b"+
		"\u0001\u0000\u0000\u0000\u0195\u0196\u0005 \u0000\u0000\u0196\u0197\u0005"+
		"\f\u0000\u0000\u0197\u0198\u0003@ \u0000\u0198\u0199\u0005\r\u0000\u0000"+
		"\u0199\u019b\u0001\u0000\u0000\u0000\u019a\u0194\u0001\u0000\u0000\u0000"+
		"\u019a\u0195\u0001\u0000\u0000\u0000\u019b_\u0001\u0000\u0000\u0000\u019c"+
		"\u01a3\u0001\u0000\u0000\u0000\u019d\u019e\u0005\u001f\u0000\u0000\u019e"+
		"\u019f\u0005\f\u0000\u0000\u019f\u01a0\u0003H$\u0000\u01a0\u01a1\u0005"+
		"\r\u0000\u0000\u01a1\u01a3\u0001\u0000\u0000\u0000\u01a2\u019c\u0001\u0000"+
		"\u0000\u0000\u01a2\u019d\u0001\u0000\u0000\u0000\u01a3a\u0001\u0000\u0000"+
		"\u0000\u01a4\u01a5\u0005\u0017\u0000\u0000\u01a5\u01a6\u0003\\.\u0000"+
		"\u01a6c\u0001\u0000\u0000\u0000\u001aw~\u008c\u008e\u0092\u00b1\u00bb"+
		"\u00c4\u00cf\u00ec\u00fe\u0106\u010d\u011d\u0127\u012f\u0136\u0142\u014e"+
		"\u015e\u0168\u0174\u0181\u0192\u019a\u01a2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}