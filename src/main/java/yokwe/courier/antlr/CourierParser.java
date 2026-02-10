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
		RETURNS=32, SEQUENCE=33, STRING=34, TYPE=35, UNSPECIFIED=36, UNSPECIFIED2=37, 
		UNSPECIFIED3=38, UPON=39, VERSION=40, TRUE=41, FALSE=42, ID=43, NUMBER=44, 
		STR=45, COMMENT_PARTIAL=46, COMMENT_LINE=47, SPACE=48;
	public static final int
		RULE_courierProgram = 0, RULE_programHeader = 1, RULE_programBody = 2, 
		RULE_dependencyList = 3, RULE_referencedProgramList = 4, RULE_referencedProgram = 5, 
		RULE_declarationList = 6, RULE_declaration = 7, RULE_type = 8, RULE_predefinedType = 9, 
		RULE_constructedType = 10, RULE_referenced = 11, RULE_correspondenceList = 12, 
		RULE_correspondence = 13, RULE_maximumNumber = 14, RULE_numericValue = 15, 
		RULE_typedCandidateList = 16, RULE_typedCandidate = 17, RULE_anonCandidateList = 18, 
		RULE_anonCandidate = 19, RULE_argumentList = 20, RULE_resultList = 21, 
		RULE_errorList = 22, RULE_fieldList = 23, RULE_field = 24, RULE_constant = 25, 
		RULE_literalConstant = 26, RULE_constructedConstant = 27, RULE_elementList = 28, 
		RULE_componentList = 29, RULE_component = 30, RULE_nameList = 31;
	private static String[] makeRuleNames() {
		return new String[] {
			"courierProgram", "programHeader", "programBody", "dependencyList", "referencedProgramList", 
			"referencedProgram", "declarationList", "declaration", "type", "predefinedType", 
			"constructedType", "referenced", "correspondenceList", "correspondence", 
			"maximumNumber", "numericValue", "typedCandidateList", "typedCandidate", 
			"anonCandidateList", "anonCandidate", "argumentList", "resultList", "errorList", 
			"fieldList", "field", "constant", "literalConstant", "constructedConstant", 
			"elementList", "componentList", "component", "nameList"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'='", "'.'", "':'", "';'", "','", "'('", "')'", "'{'", "'}'", 
			"'['", "']'", "'::'", "'=>'", "'-'", "'ARRAY'", "'BEGIN'", "'BOOLEAN'", 
			"'CARDINAL'", "'CHOICE'", "'DEPENDS'", "'DEPENDENT'", "'END'", "'ERROR'", 
			"'INTEGER'", "'LONG'", "'MACHINE'", "'OF'", "'PROCEDURE'", "'PROGRAM'", 
			"'RECORD'", "'REPORTS'", "'RETURNS'", "'SEQUENCE'", "'STRING'", "'TYPE'", 
			"'UNSPECIFIED'", "'UNSPECIFIED2'", "'UNSPECIFIED3'", "'UPON'", "'VERSION'", 
			"'TRUE'", "'FALSE'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, "ARRAY", "BEGIN", "BOOLEAN", "CARDINAL", "CHOICE", 
			"DEPENDS", "DEPENDENT", "END", "ERROR", "INTEGER", "LONG", "MACHINE", 
			"OF", "PROCEDURE", "PROGRAM", "RECORD", "REPORTS", "RETURNS", "SEQUENCE", 
			"STRING", "TYPE", "UNSPECIFIED", "UNSPECIFIED2", "UNSPECIFIED3", "UPON", 
			"VERSION", "TRUE", "FALSE", "ID", "NUMBER", "STR", "COMMENT_PARTIAL", 
			"COMMENT_LINE", "SPACE"
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
		public ProgramHeaderContext programHeader() {
			return getRuleContext(ProgramHeaderContext.class,0);
		}
		public ProgramBodyContext programBody() {
			return getRuleContext(ProgramBodyContext.class,0);
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
			setState(64);
			programHeader();
			setState(65);
			match(T__0);
			setState(66);
			programBody();
			setState(67);
			match(T__1);
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
	public static class ProgramHeaderContext extends ParserRuleContext {
		public Token name;
		public Token program;
		public Token version;
		public TerminalNode PROGRAM() { return getToken(CourierParser.PROGRAM, 0); }
		public TerminalNode VERSION() { return getToken(CourierParser.VERSION, 0); }
		public TerminalNode ID() { return getToken(CourierParser.ID, 0); }
		public List<TerminalNode> NUMBER() { return getTokens(CourierParser.NUMBER); }
		public TerminalNode NUMBER(int i) {
			return getToken(CourierParser.NUMBER, i);
		}
		public ProgramHeaderContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_programHeader; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitProgramHeader(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ProgramHeaderContext programHeader() throws RecognitionException {
		ProgramHeaderContext _localctx = new ProgramHeaderContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_programHeader);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(69);
			((ProgramHeaderContext)_localctx).name = match(ID);
			setState(70);
			match(T__2);
			setState(71);
			match(PROGRAM);
			setState(72);
			((ProgramHeaderContext)_localctx).program = match(NUMBER);
			setState(73);
			match(VERSION);
			setState(74);
			((ProgramHeaderContext)_localctx).version = match(NUMBER);
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
	public static class ProgramBodyContext extends ParserRuleContext {
		public TerminalNode BEGIN() { return getToken(CourierParser.BEGIN, 0); }
		public DependencyListContext dependencyList() {
			return getRuleContext(DependencyListContext.class,0);
		}
		public DeclarationListContext declarationList() {
			return getRuleContext(DeclarationListContext.class,0);
		}
		public TerminalNode END() { return getToken(CourierParser.END, 0); }
		public ProgramBodyContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_programBody; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitProgramBody(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ProgramBodyContext programBody() throws RecognitionException {
		ProgramBodyContext _localctx = new ProgramBodyContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_programBody);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(76);
			match(BEGIN);
			setState(77);
			dependencyList();
			setState(78);
			declarationList();
			setState(79);
			match(END);
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
		enterRule(_localctx, 6, RULE_dependencyList);
		try {
			setState(87);
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
				setState(82);
				match(DEPENDS);
				setState(83);
				match(UPON);
				setState(84);
				referencedProgramList();
				setState(85);
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
		enterRule(_localctx, 8, RULE_referencedProgramList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(89);
			((ReferencedProgramListContext)_localctx).referencedProgram = referencedProgram();
			((ReferencedProgramListContext)_localctx).elements.add(((ReferencedProgramListContext)_localctx).referencedProgram);
			setState(94);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__4) {
				{
				{
				setState(90);
				match(T__4);
				setState(91);
				((ReferencedProgramListContext)_localctx).referencedProgram = referencedProgram();
				((ReferencedProgramListContext)_localctx).elements.add(((ReferencedProgramListContext)_localctx).referencedProgram);
				}
				}
				setState(96);
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
		public Token program;
		public Token version;
		public TerminalNode VERSION() { return getToken(CourierParser.VERSION, 0); }
		public TerminalNode ID() { return getToken(CourierParser.ID, 0); }
		public List<TerminalNode> NUMBER() { return getTokens(CourierParser.NUMBER); }
		public TerminalNode NUMBER(int i) {
			return getToken(CourierParser.NUMBER, i);
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
		enterRule(_localctx, 10, RULE_referencedProgram);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(97);
			((ReferencedProgramContext)_localctx).name = match(ID);
			setState(98);
			match(T__5);
			setState(99);
			((ReferencedProgramContext)_localctx).program = match(NUMBER);
			setState(100);
			match(T__6);
			setState(101);
			match(VERSION);
			setState(102);
			((ReferencedProgramContext)_localctx).version = match(NUMBER);
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
		enterRule(_localctx, 12, RULE_declarationList);
		int _la;
		try {
			setState(110);
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
				setState(106); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(105);
					((DeclarationListContext)_localctx).declaration = declaration();
					((DeclarationListContext)_localctx).elements.add(((DeclarationListContext)_localctx).declaration);
					}
					}
					setState(108); 
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
	public static class DeclTypeContext extends DeclarationContext {
		public Token name;
		public TerminalNode TYPE() { return getToken(CourierParser.TYPE, 0); }
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public TerminalNode ID() { return getToken(CourierParser.ID, 0); }
		public DeclTypeContext(DeclarationContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitDeclType(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class DeclConsContext extends DeclarationContext {
		public Token name;
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public ConstantContext constant() {
			return getRuleContext(ConstantContext.class,0);
		}
		public TerminalNode ID() { return getToken(CourierParser.ID, 0); }
		public DeclConsContext(DeclarationContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitDeclCons(this);
			else return visitor.visitChildren(this);
		}
	}

	public final DeclarationContext declaration() throws RecognitionException {
		DeclarationContext _localctx = new DeclarationContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_declaration);
		try {
			setState(126);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
			case 1:
				_localctx = new DeclTypeContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(112);
				((DeclTypeContext)_localctx).name = match(ID);
				setState(113);
				match(T__2);
				setState(114);
				match(TYPE);
				setState(115);
				match(T__0);
				setState(116);
				type();
				setState(117);
				match(T__3);
				}
				break;
			case 2:
				_localctx = new DeclConsContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(119);
				((DeclConsContext)_localctx).name = match(ID);
				setState(120);
				match(T__2);
				setState(121);
				type();
				setState(122);
				match(T__0);
				setState(123);
				constant();
				setState(124);
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
	public static class TypePredefinedContext extends TypeContext {
		public PredefinedTypeContext predefinedType() {
			return getRuleContext(PredefinedTypeContext.class,0);
		}
		public TypePredefinedContext(TypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypePredefined(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeConstructedContext extends TypeContext {
		public ConstructedTypeContext constructedType() {
			return getRuleContext(ConstructedTypeContext.class,0);
		}
		public TypeConstructedContext(TypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeConstructed(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeReferencedContext extends TypeContext {
		public ReferencedContext referenced() {
			return getRuleContext(ReferencedContext.class,0);
		}
		public TypeReferencedContext(TypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeReferenced(this);
			else return visitor.visitChildren(this);
		}
	}

	public final TypeContext type() throws RecognitionException {
		TypeContext _localctx = new TypeContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_type);
		try {
			setState(131);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case BOOLEAN:
			case CARDINAL:
			case INTEGER:
			case LONG:
			case STRING:
			case UNSPECIFIED:
				_localctx = new TypePredefinedContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(128);
				predefinedType();
				}
				break;
			case T__7:
			case ARRAY:
			case CHOICE:
			case ERROR:
			case PROCEDURE:
			case RECORD:
			case SEQUENCE:
				_localctx = new TypeConstructedContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(129);
				constructedType();
				}
				break;
			case ID:
				_localctx = new TypeReferencedContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(130);
				referenced();
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
	public static class PredefinedTypeContext extends ParserRuleContext {
		public PredefinedTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_predefinedType; }
	 
		public PredefinedTypeContext() { }
		public void copyFrom(PredefinedTypeContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeCardinalContext extends PredefinedTypeContext {
		public TerminalNode CARDINAL() { return getToken(CourierParser.CARDINAL, 0); }
		public TypeCardinalContext(PredefinedTypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeCardinal(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeLongIntegerContext extends PredefinedTypeContext {
		public TerminalNode LONG() { return getToken(CourierParser.LONG, 0); }
		public TerminalNode INTEGER() { return getToken(CourierParser.INTEGER, 0); }
		public TypeLongIntegerContext(PredefinedTypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeLongInteger(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeBooleanContext extends PredefinedTypeContext {
		public TerminalNode BOOLEAN() { return getToken(CourierParser.BOOLEAN, 0); }
		public TypeBooleanContext(PredefinedTypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeBoolean(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeIntegerContext extends PredefinedTypeContext {
		public TerminalNode INTEGER() { return getToken(CourierParser.INTEGER, 0); }
		public TypeIntegerContext(PredefinedTypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeInteger(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeUnspecifiedContext extends PredefinedTypeContext {
		public TerminalNode UNSPECIFIED() { return getToken(CourierParser.UNSPECIFIED, 0); }
		public TypeUnspecifiedContext(PredefinedTypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeUnspecified(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeLongCardinalContext extends PredefinedTypeContext {
		public TerminalNode LONG() { return getToken(CourierParser.LONG, 0); }
		public TerminalNode CARDINAL() { return getToken(CourierParser.CARDINAL, 0); }
		public TypeLongCardinalContext(PredefinedTypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeLongCardinal(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeStringContext extends PredefinedTypeContext {
		public TerminalNode STRING() { return getToken(CourierParser.STRING, 0); }
		public TypeStringContext(PredefinedTypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeString(this);
			else return visitor.visitChildren(this);
		}
	}

	public final PredefinedTypeContext predefinedType() throws RecognitionException {
		PredefinedTypeContext _localctx = new PredefinedTypeContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_predefinedType);
		try {
			setState(142);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,6,_ctx) ) {
			case 1:
				_localctx = new TypeBooleanContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(133);
				match(BOOLEAN);
				}
				break;
			case 2:
				_localctx = new TypeCardinalContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(134);
				match(CARDINAL);
				}
				break;
			case 3:
				_localctx = new TypeLongCardinalContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(135);
				match(LONG);
				setState(136);
				match(CARDINAL);
				}
				break;
			case 4:
				_localctx = new TypeIntegerContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(137);
				match(INTEGER);
				}
				break;
			case 5:
				_localctx = new TypeLongIntegerContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(138);
				match(LONG);
				setState(139);
				match(INTEGER);
				}
				break;
			case 6:
				_localctx = new TypeStringContext(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(140);
				match(STRING);
				}
				break;
			case 7:
				_localctx = new TypeUnspecifiedContext(_localctx);
				enterOuterAlt(_localctx, 7);
				{
				setState(141);
				match(UNSPECIFIED);
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
	public static class ConstructedTypeContext extends ParserRuleContext {
		public ConstructedTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constructedType; }
	 
		public ConstructedTypeContext() { }
		public void copyFrom(ConstructedTypeContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeArrayContext extends ConstructedTypeContext {
		public TerminalNode ARRAY() { return getToken(CourierParser.ARRAY, 0); }
		public NumericValueContext numericValue() {
			return getRuleContext(NumericValueContext.class,0);
		}
		public TerminalNode OF() { return getToken(CourierParser.OF, 0); }
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public TypeArrayContext(ConstructedTypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeArray(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeChoiceTypedContext extends ConstructedTypeContext {
		public TerminalNode CHOICE() { return getToken(CourierParser.CHOICE, 0); }
		public ReferencedContext referenced() {
			return getRuleContext(ReferencedContext.class,0);
		}
		public TerminalNode OF() { return getToken(CourierParser.OF, 0); }
		public TypedCandidateListContext typedCandidateList() {
			return getRuleContext(TypedCandidateListContext.class,0);
		}
		public TypeChoiceTypedContext(ConstructedTypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeChoiceTyped(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeSequenceContext extends ConstructedTypeContext {
		public TerminalNode SEQUENCE() { return getToken(CourierParser.SEQUENCE, 0); }
		public MaximumNumberContext maximumNumber() {
			return getRuleContext(MaximumNumberContext.class,0);
		}
		public TerminalNode OF() { return getToken(CourierParser.OF, 0); }
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public TypeSequenceContext(ConstructedTypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeSequence(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeEnumContext extends ConstructedTypeContext {
		public CorrespondenceListContext correspondenceList() {
			return getRuleContext(CorrespondenceListContext.class,0);
		}
		public TypeEnumContext(ConstructedTypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeEnum(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeRecordEmptyContext extends ConstructedTypeContext {
		public TerminalNode RECORD() { return getToken(CourierParser.RECORD, 0); }
		public TypeRecordEmptyContext(ConstructedTypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeRecordEmpty(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeErrorContext extends ConstructedTypeContext {
		public TerminalNode ERROR() { return getToken(CourierParser.ERROR, 0); }
		public ArgumentListContext argumentList() {
			return getRuleContext(ArgumentListContext.class,0);
		}
		public TypeErrorContext(ConstructedTypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeError(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeChoiceAnonContext extends ConstructedTypeContext {
		public TerminalNode CHOICE() { return getToken(CourierParser.CHOICE, 0); }
		public TerminalNode OF() { return getToken(CourierParser.OF, 0); }
		public AnonCandidateListContext anonCandidateList() {
			return getRuleContext(AnonCandidateListContext.class,0);
		}
		public TypeChoiceAnonContext(ConstructedTypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeChoiceAnon(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeRecordContext extends ConstructedTypeContext {
		public TerminalNode RECORD() { return getToken(CourierParser.RECORD, 0); }
		public FieldListContext fieldList() {
			return getRuleContext(FieldListContext.class,0);
		}
		public TypeRecordContext(ConstructedTypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeRecord(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeProcedureContext extends ConstructedTypeContext {
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
		public TypeProcedureContext(ConstructedTypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeProcedure(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ConstructedTypeContext constructedType() throws RecognitionException {
		ConstructedTypeContext _localctx = new ConstructedTypeContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_constructedType);
		try {
			setState(186);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,7,_ctx) ) {
			case 1:
				_localctx = new TypeEnumContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(144);
				match(T__7);
				setState(145);
				correspondenceList();
				setState(146);
				match(T__8);
				}
				break;
			case 2:
				_localctx = new TypeArrayContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(148);
				match(ARRAY);
				setState(149);
				numericValue();
				setState(150);
				match(OF);
				setState(151);
				type();
				}
				break;
			case 3:
				_localctx = new TypeSequenceContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(153);
				match(SEQUENCE);
				setState(154);
				maximumNumber();
				setState(155);
				match(OF);
				setState(156);
				type();
				}
				break;
			case 4:
				_localctx = new TypeRecordContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(158);
				match(RECORD);
				setState(159);
				match(T__9);
				setState(160);
				fieldList();
				setState(161);
				match(T__10);
				}
				break;
			case 5:
				_localctx = new TypeRecordEmptyContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(163);
				match(RECORD);
				setState(164);
				match(T__9);
				setState(165);
				match(T__10);
				}
				break;
			case 6:
				_localctx = new TypeChoiceTypedContext(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(166);
				match(CHOICE);
				setState(167);
				referenced();
				setState(168);
				match(OF);
				setState(169);
				match(T__7);
				setState(170);
				typedCandidateList();
				setState(171);
				match(T__8);
				}
				break;
			case 7:
				_localctx = new TypeChoiceAnonContext(_localctx);
				enterOuterAlt(_localctx, 7);
				{
				setState(173);
				match(CHOICE);
				setState(174);
				match(OF);
				setState(175);
				match(T__7);
				setState(176);
				anonCandidateList();
				setState(177);
				match(T__8);
				}
				break;
			case 8:
				_localctx = new TypeProcedureContext(_localctx);
				enterOuterAlt(_localctx, 8);
				{
				setState(179);
				match(PROCEDURE);
				setState(180);
				argumentList();
				setState(181);
				resultList();
				setState(182);
				errorList();
				}
				break;
			case 9:
				_localctx = new TypeErrorContext(_localctx);
				enterOuterAlt(_localctx, 9);
				{
				setState(184);
				match(ERROR);
				setState(185);
				argumentList();
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
	public static class ReferencedContext extends ParserRuleContext {
		public ReferencedContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_referenced; }
	 
		public ReferencedContext() { }
		public void copyFrom(ReferencedContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeRefQContext extends ReferencedContext {
		public Token program;
		public Token name;
		public List<TerminalNode> ID() { return getTokens(CourierParser.ID); }
		public TerminalNode ID(int i) {
			return getToken(CourierParser.ID, i);
		}
		public TypeRefQContext(ReferencedContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeRefQ(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeRefContext extends ReferencedContext {
		public Token name;
		public TerminalNode ID() { return getToken(CourierParser.ID, 0); }
		public TypeRefContext(ReferencedContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeRef(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeRefExtContext extends ReferencedContext {
		public Token namespace;
		public Token name;
		public List<TerminalNode> ID() { return getTokens(CourierParser.ID); }
		public TerminalNode ID(int i) {
			return getToken(CourierParser.ID, i);
		}
		public TypeRefExtContext(ReferencedContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeRefExt(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ReferencedContext referenced() throws RecognitionException {
		ReferencedContext _localctx = new ReferencedContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_referenced);
		try {
			setState(195);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,8,_ctx) ) {
			case 1:
				_localctx = new TypeRefContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(188);
				((TypeRefContext)_localctx).name = match(ID);
				}
				break;
			case 2:
				_localctx = new TypeRefQContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(189);
				((TypeRefQContext)_localctx).program = match(ID);
				setState(190);
				match(T__1);
				setState(191);
				((TypeRefQContext)_localctx).name = match(ID);
				}
				break;
			case 3:
				_localctx = new TypeRefExtContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(192);
				((TypeRefExtContext)_localctx).namespace = match(ID);
				setState(193);
				match(T__11);
				setState(194);
				((TypeRefExtContext)_localctx).name = match(ID);
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
		enterRule(_localctx, 24, RULE_correspondenceList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(197);
			((CorrespondenceListContext)_localctx).correspondence = correspondence();
			((CorrespondenceListContext)_localctx).elements.add(((CorrespondenceListContext)_localctx).correspondence);
			setState(202);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__4) {
				{
				{
				setState(198);
				match(T__4);
				setState(199);
				((CorrespondenceListContext)_localctx).correspondence = correspondence();
				((CorrespondenceListContext)_localctx).elements.add(((CorrespondenceListContext)_localctx).correspondence);
				}
				}
				setState(204);
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
		public NumericValueContext value;
		public TerminalNode ID() { return getToken(CourierParser.ID, 0); }
		public NumericValueContext numericValue() {
			return getRuleContext(NumericValueContext.class,0);
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
		enterRule(_localctx, 26, RULE_correspondence);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(205);
			((CorrespondenceContext)_localctx).name = match(ID);
			setState(206);
			match(T__5);
			setState(207);
			((CorrespondenceContext)_localctx).value = numericValue();
			setState(208);
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
	public static class MaximumNumberContext extends ParserRuleContext {
		public NumericValueContext numericValue() {
			return getRuleContext(NumericValueContext.class,0);
		}
		public MaximumNumberContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_maximumNumber; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitMaximumNumber(this);
			else return visitor.visitChildren(this);
		}
	}

	public final MaximumNumberContext maximumNumber() throws RecognitionException {
		MaximumNumberContext _localctx = new MaximumNumberContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_maximumNumber);
		try {
			setState(212);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case OF:
				enterOuterAlt(_localctx, 1);
				{
				}
				break;
			case ID:
			case NUMBER:
				enterOuterAlt(_localctx, 2);
				{
				setState(211);
				numericValue();
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
	public static class NumericValueContext extends ParserRuleContext {
		public NumericValueContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_numericValue; }
	 
		public NumericValueContext() { }
		public void copyFrom(NumericValueContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ValueRefConsContext extends NumericValueContext {
		public ReferencedContext referenced() {
			return getRuleContext(ReferencedContext.class,0);
		}
		public ValueRefConsContext(NumericValueContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitValueRefCons(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ValueNumberContext extends NumericValueContext {
		public TerminalNode NUMBER() { return getToken(CourierParser.NUMBER, 0); }
		public ValueNumberContext(NumericValueContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitValueNumber(this);
			else return visitor.visitChildren(this);
		}
	}

	public final NumericValueContext numericValue() throws RecognitionException {
		NumericValueContext _localctx = new NumericValueContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_numericValue);
		try {
			setState(216);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case NUMBER:
				_localctx = new ValueNumberContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(214);
				match(NUMBER);
				}
				break;
			case ID:
				_localctx = new ValueRefConsContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(215);
				referenced();
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
	public static class TypedCandidateListContext extends ParserRuleContext {
		public TypedCandidateContext typedCandidate;
		public List<TypedCandidateContext> elements = new ArrayList<TypedCandidateContext>();
		public List<TypedCandidateContext> typedCandidate() {
			return getRuleContexts(TypedCandidateContext.class);
		}
		public TypedCandidateContext typedCandidate(int i) {
			return getRuleContext(TypedCandidateContext.class,i);
		}
		public TypedCandidateListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_typedCandidateList; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypedCandidateList(this);
			else return visitor.visitChildren(this);
		}
	}

	public final TypedCandidateListContext typedCandidateList() throws RecognitionException {
		TypedCandidateListContext _localctx = new TypedCandidateListContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_typedCandidateList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(218);
			((TypedCandidateListContext)_localctx).typedCandidate = typedCandidate();
			((TypedCandidateListContext)_localctx).elements.add(((TypedCandidateListContext)_localctx).typedCandidate);
			setState(223);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__4) {
				{
				{
				setState(219);
				match(T__4);
				setState(220);
				((TypedCandidateListContext)_localctx).typedCandidate = typedCandidate();
				((TypedCandidateListContext)_localctx).elements.add(((TypedCandidateListContext)_localctx).typedCandidate);
				}
				}
				setState(225);
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
	public static class TypedCandidateContext extends ParserRuleContext {
		public NameListContext nameList() {
			return getRuleContext(NameListContext.class,0);
		}
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public TypedCandidateContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_typedCandidate; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypedCandidate(this);
			else return visitor.visitChildren(this);
		}
	}

	public final TypedCandidateContext typedCandidate() throws RecognitionException {
		TypedCandidateContext _localctx = new TypedCandidateContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_typedCandidate);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(226);
			nameList();
			setState(227);
			match(T__12);
			setState(228);
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
	public static class AnonCandidateListContext extends ParserRuleContext {
		public AnonCandidateContext anonCandidate;
		public List<AnonCandidateContext> elements = new ArrayList<AnonCandidateContext>();
		public List<AnonCandidateContext> anonCandidate() {
			return getRuleContexts(AnonCandidateContext.class);
		}
		public AnonCandidateContext anonCandidate(int i) {
			return getRuleContext(AnonCandidateContext.class,i);
		}
		public AnonCandidateListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_anonCandidateList; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitAnonCandidateList(this);
			else return visitor.visitChildren(this);
		}
	}

	public final AnonCandidateListContext anonCandidateList() throws RecognitionException {
		AnonCandidateListContext _localctx = new AnonCandidateListContext(_ctx, getState());
		enterRule(_localctx, 36, RULE_anonCandidateList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(230);
			((AnonCandidateListContext)_localctx).anonCandidate = anonCandidate();
			((AnonCandidateListContext)_localctx).elements.add(((AnonCandidateListContext)_localctx).anonCandidate);
			setState(235);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__4) {
				{
				{
				setState(231);
				match(T__4);
				setState(232);
				((AnonCandidateListContext)_localctx).anonCandidate = anonCandidate();
				((AnonCandidateListContext)_localctx).elements.add(((AnonCandidateListContext)_localctx).anonCandidate);
				}
				}
				setState(237);
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
	public static class AnonCandidateContext extends ParserRuleContext {
		public CorrespondenceListContext correspondenceList() {
			return getRuleContext(CorrespondenceListContext.class,0);
		}
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public AnonCandidateContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_anonCandidate; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitAnonCandidate(this);
			else return visitor.visitChildren(this);
		}
	}

	public final AnonCandidateContext anonCandidate() throws RecognitionException {
		AnonCandidateContext _localctx = new AnonCandidateContext(_ctx, getState());
		enterRule(_localctx, 38, RULE_anonCandidate);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(238);
			correspondenceList();
			setState(239);
			match(T__12);
			setState(240);
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
		enterRule(_localctx, 40, RULE_argumentList);
		try {
			setState(247);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__0:
			case T__3:
			case T__4:
			case T__8:
			case T__10:
			case REPORTS:
			case RETURNS:
				enterOuterAlt(_localctx, 1);
				{
				}
				break;
			case T__9:
				enterOuterAlt(_localctx, 2);
				{
				setState(243);
				match(T__9);
				setState(244);
				fieldList();
				setState(245);
				match(T__10);
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
		enterRule(_localctx, 42, RULE_resultList);
		try {
			setState(255);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__0:
			case T__3:
			case T__4:
			case T__8:
			case T__10:
			case REPORTS:
				enterOuterAlt(_localctx, 1);
				{
				}
				break;
			case RETURNS:
				enterOuterAlt(_localctx, 2);
				{
				setState(250);
				match(RETURNS);
				setState(251);
				match(T__9);
				setState(252);
				fieldList();
				setState(253);
				match(T__10);
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
		enterRule(_localctx, 44, RULE_errorList);
		try {
			setState(263);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__0:
			case T__3:
			case T__4:
			case T__8:
			case T__10:
				enterOuterAlt(_localctx, 1);
				{
				}
				break;
			case REPORTS:
				enterOuterAlt(_localctx, 2);
				{
				setState(258);
				match(REPORTS);
				setState(259);
				match(T__9);
				setState(260);
				nameList();
				setState(261);
				match(T__10);
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
		enterRule(_localctx, 46, RULE_fieldList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(265);
			((FieldListContext)_localctx).field = field();
			((FieldListContext)_localctx).elements.add(((FieldListContext)_localctx).field);
			setState(270);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__4) {
				{
				{
				setState(266);
				match(T__4);
				setState(267);
				((FieldListContext)_localctx).field = field();
				((FieldListContext)_localctx).elements.add(((FieldListContext)_localctx).field);
				}
				}
				setState(272);
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
		enterRule(_localctx, 48, RULE_field);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(273);
			nameList();
			setState(274);
			match(T__2);
			setState(275);
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
	public static class ConstantContext extends ParserRuleContext {
		public ConstantContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constant; }
	 
		public ConstantContext() { }
		public void copyFrom(ConstantContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ConsLiteralContext extends ConstantContext {
		public LiteralConstantContext literalConstant() {
			return getRuleContext(LiteralConstantContext.class,0);
		}
		public ConsLiteralContext(ConstantContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitConsLiteral(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ConsConstructedContext extends ConstantContext {
		public ConstructedConstantContext constructedConstant() {
			return getRuleContext(ConstructedConstantContext.class,0);
		}
		public ConsConstructedContext(ConstantContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitConsConstructed(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ConsRefContext extends ConstantContext {
		public ReferencedContext referenced() {
			return getRuleContext(ReferencedContext.class,0);
		}
		public ConsRefContext(ConstantContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitConsRef(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ConstantContext constant() throws RecognitionException {
		ConstantContext _localctx = new ConstantContext(_ctx, getState());
		enterRule(_localctx, 50, RULE_constant);
		try {
			setState(280);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,18,_ctx) ) {
			case 1:
				_localctx = new ConsLiteralContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(277);
				literalConstant();
				}
				break;
			case 2:
				_localctx = new ConsConstructedContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(278);
				constructedConstant();
				}
				break;
			case 3:
				_localctx = new ConsRefContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(279);
				referenced();
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
	public static class LiteralConstantContext extends ParserRuleContext {
		public LiteralConstantContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_literalConstant; }
	 
		public LiteralConstantContext() { }
		public void copyFrom(LiteralConstantContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ConsNumberNegativeContext extends LiteralConstantContext {
		public Token value;
		public TerminalNode NUMBER() { return getToken(CourierParser.NUMBER, 0); }
		public ConsNumberNegativeContext(LiteralConstantContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitConsNumberNegative(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ConsNumberContext extends LiteralConstantContext {
		public Token value;
		public TerminalNode NUMBER() { return getToken(CourierParser.NUMBER, 0); }
		public ConsNumberContext(LiteralConstantContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitConsNumber(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ConsTrueContext extends LiteralConstantContext {
		public TerminalNode TRUE() { return getToken(CourierParser.TRUE, 0); }
		public ConsTrueContext(LiteralConstantContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitConsTrue(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ConsFalseContext extends LiteralConstantContext {
		public TerminalNode FALSE() { return getToken(CourierParser.FALSE, 0); }
		public ConsFalseContext(LiteralConstantContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitConsFalse(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ConsStringContext extends LiteralConstantContext {
		public Token value;
		public TerminalNode STR() { return getToken(CourierParser.STR, 0); }
		public ConsStringContext(LiteralConstantContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitConsString(this);
			else return visitor.visitChildren(this);
		}
	}

	public final LiteralConstantContext literalConstant() throws RecognitionException {
		LiteralConstantContext _localctx = new LiteralConstantContext(_ctx, getState());
		enterRule(_localctx, 52, RULE_literalConstant);
		try {
			setState(288);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case TRUE:
				_localctx = new ConsTrueContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(282);
				match(TRUE);
				}
				break;
			case FALSE:
				_localctx = new ConsFalseContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(283);
				match(FALSE);
				}
				break;
			case NUMBER:
				_localctx = new ConsNumberContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(284);
				((ConsNumberContext)_localctx).value = match(NUMBER);
				}
				break;
			case T__13:
				_localctx = new ConsNumberNegativeContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(285);
				match(T__13);
				setState(286);
				((ConsNumberNegativeContext)_localctx).value = match(NUMBER);
				}
				break;
			case STR:
				_localctx = new ConsStringContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(287);
				((ConsStringContext)_localctx).value = match(STR);
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
	public static class ConstructedConstantContext extends ParserRuleContext {
		public ConstructedConstantContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constructedConstant; }
	 
		public ConstructedConstantContext() { }
		public void copyFrom(ConstructedConstantContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ConsChoiceContext extends ConstructedConstantContext {
		public Token name;
		public ConstantContext constant() {
			return getRuleContext(ConstantContext.class,0);
		}
		public TerminalNode ID() { return getToken(CourierParser.ID, 0); }
		public ConsChoiceContext(ConstructedConstantContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitConsChoice(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ConsArrayContext extends ConstructedConstantContext {
		public ElementListContext elementList() {
			return getRuleContext(ElementListContext.class,0);
		}
		public ConsArrayContext(ConstructedConstantContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitConsArray(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ConsRecordEmptyContext extends ConstructedConstantContext {
		public ConsRecordEmptyContext(ConstructedConstantContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitConsRecordEmpty(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ConsRecordContext extends ConstructedConstantContext {
		public ComponentListContext componentList() {
			return getRuleContext(ComponentListContext.class,0);
		}
		public ConsRecordContext(ConstructedConstantContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitConsRecord(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ConstructedConstantContext constructedConstant() throws RecognitionException {
		ConstructedConstantContext _localctx = new ConstructedConstantContext(_ctx, getState());
		enterRule(_localctx, 54, RULE_constructedConstant);
		try {
			setState(302);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,20,_ctx) ) {
			case 1:
				_localctx = new ConsArrayContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(290);
				match(T__9);
				setState(291);
				elementList();
				setState(292);
				match(T__10);
				}
				break;
			case 2:
				_localctx = new ConsRecordContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(294);
				match(T__9);
				setState(295);
				componentList();
				setState(296);
				match(T__10);
				}
				break;
			case 3:
				_localctx = new ConsRecordEmptyContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(298);
				match(T__9);
				setState(299);
				match(T__10);
				}
				break;
			case 4:
				_localctx = new ConsChoiceContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(300);
				((ConsChoiceContext)_localctx).name = match(ID);
				setState(301);
				constant();
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
		public ConstantContext constant;
		public List<ConstantContext> elements = new ArrayList<ConstantContext>();
		public List<ConstantContext> constant() {
			return getRuleContexts(ConstantContext.class);
		}
		public ConstantContext constant(int i) {
			return getRuleContext(ConstantContext.class,i);
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
			setState(304);
			((ElementListContext)_localctx).constant = constant();
			((ElementListContext)_localctx).elements.add(((ElementListContext)_localctx).constant);
			setState(309);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__4) {
				{
				{
				setState(305);
				match(T__4);
				setState(306);
				((ElementListContext)_localctx).constant = constant();
				((ElementListContext)_localctx).elements.add(((ElementListContext)_localctx).constant);
				}
				}
				setState(311);
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
		enterRule(_localctx, 58, RULE_componentList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(312);
			((ComponentListContext)_localctx).component = component();
			((ComponentListContext)_localctx).elements.add(((ComponentListContext)_localctx).component);
			setState(317);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__4) {
				{
				{
				setState(313);
				match(T__4);
				setState(314);
				((ComponentListContext)_localctx).component = component();
				((ComponentListContext)_localctx).elements.add(((ComponentListContext)_localctx).component);
				}
				}
				setState(319);
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
		public ConstantContext constant() {
			return getRuleContext(ConstantContext.class,0);
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
		enterRule(_localctx, 60, RULE_component);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(320);
			nameList();
			setState(321);
			match(T__2);
			setState(322);
			constant();
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
		enterRule(_localctx, 62, RULE_nameList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(324);
			((NameListContext)_localctx).ID = match(ID);
			((NameListContext)_localctx).elements.add(((NameListContext)_localctx).ID);
			setState(329);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__4) {
				{
				{
				setState(325);
				match(T__4);
				setState(326);
				((NameListContext)_localctx).ID = match(ID);
				((NameListContext)_localctx).elements.add(((NameListContext)_localctx).ID);
				}
				}
				setState(331);
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

	public static final String _serializedATN =
		"\u0004\u00010\u014d\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002"+
		"\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007\u0002"+
		"\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b\u0002"+
		"\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002\u000f\u0007\u000f"+
		"\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011\u0002\u0012\u0007\u0012"+
		"\u0002\u0013\u0007\u0013\u0002\u0014\u0007\u0014\u0002\u0015\u0007\u0015"+
		"\u0002\u0016\u0007\u0016\u0002\u0017\u0007\u0017\u0002\u0018\u0007\u0018"+
		"\u0002\u0019\u0007\u0019\u0002\u001a\u0007\u001a\u0002\u001b\u0007\u001b"+
		"\u0002\u001c\u0007\u001c\u0002\u001d\u0007\u001d\u0002\u001e\u0007\u001e"+
		"\u0002\u001f\u0007\u001f\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000"+
		"\u0001\u0000\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003"+
		"\u0001\u0003\u0003\u0003X\b\u0003\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0005\u0004]\b\u0004\n\u0004\f\u0004`\t\u0004\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0006"+
		"\u0001\u0006\u0004\u0006k\b\u0006\u000b\u0006\f\u0006l\u0003\u0006o\b"+
		"\u0006\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001"+
		"\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001"+
		"\u0007\u0001\u0007\u0001\u0007\u0003\u0007\u007f\b\u0007\u0001\b\u0001"+
		"\b\u0001\b\u0003\b\u0084\b\b\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001"+
		"\t\u0001\t\u0001\t\u0001\t\u0003\t\u008f\b\t\u0001\n\u0001\n\u0001\n\u0001"+
		"\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001"+
		"\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001"+
		"\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001"+
		"\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001"+
		"\n\u0001\n\u0001\n\u0003\n\u00bb\b\n\u0001\u000b\u0001\u000b\u0001\u000b"+
		"\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0003\u000b\u00c4\b\u000b"+
		"\u0001\f\u0001\f\u0001\f\u0005\f\u00c9\b\f\n\f\f\f\u00cc\t\f\u0001\r\u0001"+
		"\r\u0001\r\u0001\r\u0001\r\u0001\u000e\u0001\u000e\u0003\u000e\u00d5\b"+
		"\u000e\u0001\u000f\u0001\u000f\u0003\u000f\u00d9\b\u000f\u0001\u0010\u0001"+
		"\u0010\u0001\u0010\u0005\u0010\u00de\b\u0010\n\u0010\f\u0010\u00e1\t\u0010"+
		"\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0012\u0001\u0012"+
		"\u0001\u0012\u0005\u0012\u00ea\b\u0012\n\u0012\f\u0012\u00ed\t\u0012\u0001"+
		"\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0014\u0001\u0014\u0001"+
		"\u0014\u0001\u0014\u0001\u0014\u0003\u0014\u00f8\b\u0014\u0001\u0015\u0001"+
		"\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0003\u0015\u0100"+
		"\b\u0015\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001"+
		"\u0016\u0003\u0016\u0108\b\u0016\u0001\u0017\u0001\u0017\u0001\u0017\u0005"+
		"\u0017\u010d\b\u0017\n\u0017\f\u0017\u0110\t\u0017\u0001\u0018\u0001\u0018"+
		"\u0001\u0018\u0001\u0018\u0001\u0019\u0001\u0019\u0001\u0019\u0003\u0019"+
		"\u0119\b\u0019\u0001\u001a\u0001\u001a\u0001\u001a\u0001\u001a\u0001\u001a"+
		"\u0001\u001a\u0003\u001a\u0121\b\u001a\u0001\u001b\u0001\u001b\u0001\u001b"+
		"\u0001\u001b\u0001\u001b\u0001\u001b\u0001\u001b\u0001\u001b\u0001\u001b"+
		"\u0001\u001b\u0001\u001b\u0001\u001b\u0003\u001b\u012f\b\u001b\u0001\u001c"+
		"\u0001\u001c\u0001\u001c\u0005\u001c\u0134\b\u001c\n\u001c\f\u001c\u0137"+
		"\t\u001c\u0001\u001d\u0001\u001d\u0001\u001d\u0005\u001d\u013c\b\u001d"+
		"\n\u001d\f\u001d\u013f\t\u001d\u0001\u001e\u0001\u001e\u0001\u001e\u0001"+
		"\u001e\u0001\u001f\u0001\u001f\u0001\u001f\u0005\u001f\u0148\b\u001f\n"+
		"\u001f\f\u001f\u014b\t\u001f\u0001\u001f\u0000\u0000 \u0000\u0002\u0004"+
		"\u0006\b\n\f\u000e\u0010\u0012\u0014\u0016\u0018\u001a\u001c\u001e \""+
		"$&(*,.02468:<>\u0000\u0000\u0158\u0000@\u0001\u0000\u0000\u0000\u0002"+
		"E\u0001\u0000\u0000\u0000\u0004L\u0001\u0000\u0000\u0000\u0006W\u0001"+
		"\u0000\u0000\u0000\bY\u0001\u0000\u0000\u0000\na\u0001\u0000\u0000\u0000"+
		"\fn\u0001\u0000\u0000\u0000\u000e~\u0001\u0000\u0000\u0000\u0010\u0083"+
		"\u0001\u0000\u0000\u0000\u0012\u008e\u0001\u0000\u0000\u0000\u0014\u00ba"+
		"\u0001\u0000\u0000\u0000\u0016\u00c3\u0001\u0000\u0000\u0000\u0018\u00c5"+
		"\u0001\u0000\u0000\u0000\u001a\u00cd\u0001\u0000\u0000\u0000\u001c\u00d4"+
		"\u0001\u0000\u0000\u0000\u001e\u00d8\u0001\u0000\u0000\u0000 \u00da\u0001"+
		"\u0000\u0000\u0000\"\u00e2\u0001\u0000\u0000\u0000$\u00e6\u0001\u0000"+
		"\u0000\u0000&\u00ee\u0001\u0000\u0000\u0000(\u00f7\u0001\u0000\u0000\u0000"+
		"*\u00ff\u0001\u0000\u0000\u0000,\u0107\u0001\u0000\u0000\u0000.\u0109"+
		"\u0001\u0000\u0000\u00000\u0111\u0001\u0000\u0000\u00002\u0118\u0001\u0000"+
		"\u0000\u00004\u0120\u0001\u0000\u0000\u00006\u012e\u0001\u0000\u0000\u0000"+
		"8\u0130\u0001\u0000\u0000\u0000:\u0138\u0001\u0000\u0000\u0000<\u0140"+
		"\u0001\u0000\u0000\u0000>\u0144\u0001\u0000\u0000\u0000@A\u0003\u0002"+
		"\u0001\u0000AB\u0005\u0001\u0000\u0000BC\u0003\u0004\u0002\u0000CD\u0005"+
		"\u0002\u0000\u0000D\u0001\u0001\u0000\u0000\u0000EF\u0005+\u0000\u0000"+
		"FG\u0005\u0003\u0000\u0000GH\u0005\u001d\u0000\u0000HI\u0005,\u0000\u0000"+
		"IJ\u0005(\u0000\u0000JK\u0005,\u0000\u0000K\u0003\u0001\u0000\u0000\u0000"+
		"LM\u0005\u0010\u0000\u0000MN\u0003\u0006\u0003\u0000NO\u0003\f\u0006\u0000"+
		"OP\u0005\u0016\u0000\u0000P\u0005\u0001\u0000\u0000\u0000QX\u0001\u0000"+
		"\u0000\u0000RS\u0005\u0014\u0000\u0000ST\u0005\'\u0000\u0000TU\u0003\b"+
		"\u0004\u0000UV\u0005\u0004\u0000\u0000VX\u0001\u0000\u0000\u0000WQ\u0001"+
		"\u0000\u0000\u0000WR\u0001\u0000\u0000\u0000X\u0007\u0001\u0000\u0000"+
		"\u0000Y^\u0003\n\u0005\u0000Z[\u0005\u0005\u0000\u0000[]\u0003\n\u0005"+
		"\u0000\\Z\u0001\u0000\u0000\u0000]`\u0001\u0000\u0000\u0000^\\\u0001\u0000"+
		"\u0000\u0000^_\u0001\u0000\u0000\u0000_\t\u0001\u0000\u0000\u0000`^\u0001"+
		"\u0000\u0000\u0000ab\u0005+\u0000\u0000bc\u0005\u0006\u0000\u0000cd\u0005"+
		",\u0000\u0000de\u0005\u0007\u0000\u0000ef\u0005(\u0000\u0000fg\u0005,"+
		"\u0000\u0000g\u000b\u0001\u0000\u0000\u0000ho\u0001\u0000\u0000\u0000"+
		"ik\u0003\u000e\u0007\u0000ji\u0001\u0000\u0000\u0000kl\u0001\u0000\u0000"+
		"\u0000lj\u0001\u0000\u0000\u0000lm\u0001\u0000\u0000\u0000mo\u0001\u0000"+
		"\u0000\u0000nh\u0001\u0000\u0000\u0000nj\u0001\u0000\u0000\u0000o\r\u0001"+
		"\u0000\u0000\u0000pq\u0005+\u0000\u0000qr\u0005\u0003\u0000\u0000rs\u0005"+
		"#\u0000\u0000st\u0005\u0001\u0000\u0000tu\u0003\u0010\b\u0000uv\u0005"+
		"\u0004\u0000\u0000v\u007f\u0001\u0000\u0000\u0000wx\u0005+\u0000\u0000"+
		"xy\u0005\u0003\u0000\u0000yz\u0003\u0010\b\u0000z{\u0005\u0001\u0000\u0000"+
		"{|\u00032\u0019\u0000|}\u0005\u0004\u0000\u0000}\u007f\u0001\u0000\u0000"+
		"\u0000~p\u0001\u0000\u0000\u0000~w\u0001\u0000\u0000\u0000\u007f\u000f"+
		"\u0001\u0000\u0000\u0000\u0080\u0084\u0003\u0012\t\u0000\u0081\u0084\u0003"+
		"\u0014\n\u0000\u0082\u0084\u0003\u0016\u000b\u0000\u0083\u0080\u0001\u0000"+
		"\u0000\u0000\u0083\u0081\u0001\u0000\u0000\u0000\u0083\u0082\u0001\u0000"+
		"\u0000\u0000\u0084\u0011\u0001\u0000\u0000\u0000\u0085\u008f\u0005\u0011"+
		"\u0000\u0000\u0086\u008f\u0005\u0012\u0000\u0000\u0087\u0088\u0005\u0019"+
		"\u0000\u0000\u0088\u008f\u0005\u0012\u0000\u0000\u0089\u008f\u0005\u0018"+
		"\u0000\u0000\u008a\u008b\u0005\u0019\u0000\u0000\u008b\u008f\u0005\u0018"+
		"\u0000\u0000\u008c\u008f\u0005\"\u0000\u0000\u008d\u008f\u0005$\u0000"+
		"\u0000\u008e\u0085\u0001\u0000\u0000\u0000\u008e\u0086\u0001\u0000\u0000"+
		"\u0000\u008e\u0087\u0001\u0000\u0000\u0000\u008e\u0089\u0001\u0000\u0000"+
		"\u0000\u008e\u008a\u0001\u0000\u0000\u0000\u008e\u008c\u0001\u0000\u0000"+
		"\u0000\u008e\u008d\u0001\u0000\u0000\u0000\u008f\u0013\u0001\u0000\u0000"+
		"\u0000\u0090\u0091\u0005\b\u0000\u0000\u0091\u0092\u0003\u0018\f\u0000"+
		"\u0092\u0093\u0005\t\u0000\u0000\u0093\u00bb\u0001\u0000\u0000\u0000\u0094"+
		"\u0095\u0005\u000f\u0000\u0000\u0095\u0096\u0003\u001e\u000f\u0000\u0096"+
		"\u0097\u0005\u001b\u0000\u0000\u0097\u0098\u0003\u0010\b\u0000\u0098\u00bb"+
		"\u0001\u0000\u0000\u0000\u0099\u009a\u0005!\u0000\u0000\u009a\u009b\u0003"+
		"\u001c\u000e\u0000\u009b\u009c\u0005\u001b\u0000\u0000\u009c\u009d\u0003"+
		"\u0010\b\u0000\u009d\u00bb\u0001\u0000\u0000\u0000\u009e\u009f\u0005\u001e"+
		"\u0000\u0000\u009f\u00a0\u0005\n\u0000\u0000\u00a0\u00a1\u0003.\u0017"+
		"\u0000\u00a1\u00a2\u0005\u000b\u0000\u0000\u00a2\u00bb\u0001\u0000\u0000"+
		"\u0000\u00a3\u00a4\u0005\u001e\u0000\u0000\u00a4\u00a5\u0005\n\u0000\u0000"+
		"\u00a5\u00bb\u0005\u000b\u0000\u0000\u00a6\u00a7\u0005\u0013\u0000\u0000"+
		"\u00a7\u00a8\u0003\u0016\u000b\u0000\u00a8\u00a9\u0005\u001b\u0000\u0000"+
		"\u00a9\u00aa\u0005\b\u0000\u0000\u00aa\u00ab\u0003 \u0010\u0000\u00ab"+
		"\u00ac\u0005\t\u0000\u0000\u00ac\u00bb\u0001\u0000\u0000\u0000\u00ad\u00ae"+
		"\u0005\u0013\u0000\u0000\u00ae\u00af\u0005\u001b\u0000\u0000\u00af\u00b0"+
		"\u0005\b\u0000\u0000\u00b0\u00b1\u0003$\u0012\u0000\u00b1\u00b2\u0005"+
		"\t\u0000\u0000\u00b2\u00bb\u0001\u0000\u0000\u0000\u00b3\u00b4\u0005\u001c"+
		"\u0000\u0000\u00b4\u00b5\u0003(\u0014\u0000\u00b5\u00b6\u0003*\u0015\u0000"+
		"\u00b6\u00b7\u0003,\u0016\u0000\u00b7\u00bb\u0001\u0000\u0000\u0000\u00b8"+
		"\u00b9\u0005\u0017\u0000\u0000\u00b9\u00bb\u0003(\u0014\u0000\u00ba\u0090"+
		"\u0001\u0000\u0000\u0000\u00ba\u0094\u0001\u0000\u0000\u0000\u00ba\u0099"+
		"\u0001\u0000\u0000\u0000\u00ba\u009e\u0001\u0000\u0000\u0000\u00ba\u00a3"+
		"\u0001\u0000\u0000\u0000\u00ba\u00a6\u0001\u0000\u0000\u0000\u00ba\u00ad"+
		"\u0001\u0000\u0000\u0000\u00ba\u00b3\u0001\u0000\u0000\u0000\u00ba\u00b8"+
		"\u0001\u0000\u0000\u0000\u00bb\u0015\u0001\u0000\u0000\u0000\u00bc\u00c4"+
		"\u0005+\u0000\u0000\u00bd\u00be\u0005+\u0000\u0000\u00be\u00bf\u0005\u0002"+
		"\u0000\u0000\u00bf\u00c4\u0005+\u0000\u0000\u00c0\u00c1\u0005+\u0000\u0000"+
		"\u00c1\u00c2\u0005\f\u0000\u0000\u00c2\u00c4\u0005+\u0000\u0000\u00c3"+
		"\u00bc\u0001\u0000\u0000\u0000\u00c3\u00bd\u0001\u0000\u0000\u0000\u00c3"+
		"\u00c0\u0001\u0000\u0000\u0000\u00c4\u0017\u0001\u0000\u0000\u0000\u00c5"+
		"\u00ca\u0003\u001a\r\u0000\u00c6\u00c7\u0005\u0005\u0000\u0000\u00c7\u00c9"+
		"\u0003\u001a\r\u0000\u00c8\u00c6\u0001\u0000\u0000\u0000\u00c9\u00cc\u0001"+
		"\u0000\u0000\u0000\u00ca\u00c8\u0001\u0000\u0000\u0000\u00ca\u00cb\u0001"+
		"\u0000\u0000\u0000\u00cb\u0019\u0001\u0000\u0000\u0000\u00cc\u00ca\u0001"+
		"\u0000\u0000\u0000\u00cd\u00ce\u0005+\u0000\u0000\u00ce\u00cf\u0005\u0006"+
		"\u0000\u0000\u00cf\u00d0\u0003\u001e\u000f\u0000\u00d0\u00d1\u0005\u0007"+
		"\u0000\u0000\u00d1\u001b\u0001\u0000\u0000\u0000\u00d2\u00d5\u0001\u0000"+
		"\u0000\u0000\u00d3\u00d5\u0003\u001e\u000f\u0000\u00d4\u00d2\u0001\u0000"+
		"\u0000\u0000\u00d4\u00d3\u0001\u0000\u0000\u0000\u00d5\u001d\u0001\u0000"+
		"\u0000\u0000\u00d6\u00d9\u0005,\u0000\u0000\u00d7\u00d9\u0003\u0016\u000b"+
		"\u0000\u00d8\u00d6\u0001\u0000\u0000\u0000\u00d8\u00d7\u0001\u0000\u0000"+
		"\u0000\u00d9\u001f\u0001\u0000\u0000\u0000\u00da\u00df\u0003\"\u0011\u0000"+
		"\u00db\u00dc\u0005\u0005\u0000\u0000\u00dc\u00de\u0003\"\u0011\u0000\u00dd"+
		"\u00db\u0001\u0000\u0000\u0000\u00de\u00e1\u0001\u0000\u0000\u0000\u00df"+
		"\u00dd\u0001\u0000\u0000\u0000\u00df\u00e0\u0001\u0000\u0000\u0000\u00e0"+
		"!\u0001\u0000\u0000\u0000\u00e1\u00df\u0001\u0000\u0000\u0000\u00e2\u00e3"+
		"\u0003>\u001f\u0000\u00e3\u00e4\u0005\r\u0000\u0000\u00e4\u00e5\u0003"+
		"\u0010\b\u0000\u00e5#\u0001\u0000\u0000\u0000\u00e6\u00eb\u0003&\u0013"+
		"\u0000\u00e7\u00e8\u0005\u0005\u0000\u0000\u00e8\u00ea\u0003&\u0013\u0000"+
		"\u00e9\u00e7\u0001\u0000\u0000\u0000\u00ea\u00ed\u0001\u0000\u0000\u0000"+
		"\u00eb\u00e9\u0001\u0000\u0000\u0000\u00eb\u00ec\u0001\u0000\u0000\u0000"+
		"\u00ec%\u0001\u0000\u0000\u0000\u00ed\u00eb\u0001\u0000\u0000\u0000\u00ee"+
		"\u00ef\u0003\u0018\f\u0000\u00ef\u00f0\u0005\r\u0000\u0000\u00f0\u00f1"+
		"\u0003\u0010\b\u0000\u00f1\'\u0001\u0000\u0000\u0000\u00f2\u00f8\u0001"+
		"\u0000\u0000\u0000\u00f3\u00f4\u0005\n\u0000\u0000\u00f4\u00f5\u0003."+
		"\u0017\u0000\u00f5\u00f6\u0005\u000b\u0000\u0000\u00f6\u00f8\u0001\u0000"+
		"\u0000\u0000\u00f7\u00f2\u0001\u0000\u0000\u0000\u00f7\u00f3\u0001\u0000"+
		"\u0000\u0000\u00f8)\u0001\u0000\u0000\u0000\u00f9\u0100\u0001\u0000\u0000"+
		"\u0000\u00fa\u00fb\u0005 \u0000\u0000\u00fb\u00fc\u0005\n\u0000\u0000"+
		"\u00fc\u00fd\u0003.\u0017\u0000\u00fd\u00fe\u0005\u000b\u0000\u0000\u00fe"+
		"\u0100\u0001\u0000\u0000\u0000\u00ff\u00f9\u0001\u0000\u0000\u0000\u00ff"+
		"\u00fa\u0001\u0000\u0000\u0000\u0100+\u0001\u0000\u0000\u0000\u0101\u0108"+
		"\u0001\u0000\u0000\u0000\u0102\u0103\u0005\u001f\u0000\u0000\u0103\u0104"+
		"\u0005\n\u0000\u0000\u0104\u0105\u0003>\u001f\u0000\u0105\u0106\u0005"+
		"\u000b\u0000\u0000\u0106\u0108\u0001\u0000\u0000\u0000\u0107\u0101\u0001"+
		"\u0000\u0000\u0000\u0107\u0102\u0001\u0000\u0000\u0000\u0108-\u0001\u0000"+
		"\u0000\u0000\u0109\u010e\u00030\u0018\u0000\u010a\u010b\u0005\u0005\u0000"+
		"\u0000\u010b\u010d\u00030\u0018\u0000\u010c\u010a\u0001\u0000\u0000\u0000"+
		"\u010d\u0110\u0001\u0000\u0000\u0000\u010e\u010c\u0001\u0000\u0000\u0000"+
		"\u010e\u010f\u0001\u0000\u0000\u0000\u010f/\u0001\u0000\u0000\u0000\u0110"+
		"\u010e\u0001\u0000\u0000\u0000\u0111\u0112\u0003>\u001f\u0000\u0112\u0113"+
		"\u0005\u0003\u0000\u0000\u0113\u0114\u0003\u0010\b\u0000\u01141\u0001"+
		"\u0000\u0000\u0000\u0115\u0119\u00034\u001a\u0000\u0116\u0119\u00036\u001b"+
		"\u0000\u0117\u0119\u0003\u0016\u000b\u0000\u0118\u0115\u0001\u0000\u0000"+
		"\u0000\u0118\u0116\u0001\u0000\u0000\u0000\u0118\u0117\u0001\u0000\u0000"+
		"\u0000\u01193\u0001\u0000\u0000\u0000\u011a\u0121\u0005)\u0000\u0000\u011b"+
		"\u0121\u0005*\u0000\u0000\u011c\u0121\u0005,\u0000\u0000\u011d\u011e\u0005"+
		"\u000e\u0000\u0000\u011e\u0121\u0005,\u0000\u0000\u011f\u0121\u0005-\u0000"+
		"\u0000\u0120\u011a\u0001\u0000\u0000\u0000\u0120\u011b\u0001\u0000\u0000"+
		"\u0000\u0120\u011c\u0001\u0000\u0000\u0000\u0120\u011d\u0001\u0000\u0000"+
		"\u0000\u0120\u011f\u0001\u0000\u0000\u0000\u01215\u0001\u0000\u0000\u0000"+
		"\u0122\u0123\u0005\n\u0000\u0000\u0123\u0124\u00038\u001c\u0000\u0124"+
		"\u0125\u0005\u000b\u0000\u0000\u0125\u012f\u0001\u0000\u0000\u0000\u0126"+
		"\u0127\u0005\n\u0000\u0000\u0127\u0128\u0003:\u001d\u0000\u0128\u0129"+
		"\u0005\u000b\u0000\u0000\u0129\u012f\u0001\u0000\u0000\u0000\u012a\u012b"+
		"\u0005\n\u0000\u0000\u012b\u012f\u0005\u000b\u0000\u0000\u012c\u012d\u0005"+
		"+\u0000\u0000\u012d\u012f\u00032\u0019\u0000\u012e\u0122\u0001\u0000\u0000"+
		"\u0000\u012e\u0126\u0001\u0000\u0000\u0000\u012e\u012a\u0001\u0000\u0000"+
		"\u0000\u012e\u012c\u0001\u0000\u0000\u0000\u012f7\u0001\u0000\u0000\u0000"+
		"\u0130\u0135\u00032\u0019\u0000\u0131\u0132\u0005\u0005\u0000\u0000\u0132"+
		"\u0134\u00032\u0019\u0000\u0133\u0131\u0001\u0000\u0000\u0000\u0134\u0137"+
		"\u0001\u0000\u0000\u0000\u0135\u0133\u0001\u0000\u0000\u0000\u0135\u0136"+
		"\u0001\u0000\u0000\u0000\u01369\u0001\u0000\u0000\u0000\u0137\u0135\u0001"+
		"\u0000\u0000\u0000\u0138\u013d\u0003<\u001e\u0000\u0139\u013a\u0005\u0005"+
		"\u0000\u0000\u013a\u013c\u0003<\u001e\u0000\u013b\u0139\u0001\u0000\u0000"+
		"\u0000\u013c\u013f\u0001\u0000\u0000\u0000\u013d\u013b\u0001\u0000\u0000"+
		"\u0000\u013d\u013e\u0001\u0000\u0000\u0000\u013e;\u0001\u0000\u0000\u0000"+
		"\u013f\u013d\u0001\u0000\u0000\u0000\u0140\u0141\u0003>\u001f\u0000\u0141"+
		"\u0142\u0005\u0003\u0000\u0000\u0142\u0143\u00032\u0019\u0000\u0143=\u0001"+
		"\u0000\u0000\u0000\u0144\u0149\u0005+\u0000\u0000\u0145\u0146\u0005\u0005"+
		"\u0000\u0000\u0146\u0148\u0005+\u0000\u0000\u0147\u0145\u0001\u0000\u0000"+
		"\u0000\u0148\u014b\u0001\u0000\u0000\u0000\u0149\u0147\u0001\u0000\u0000"+
		"\u0000\u0149\u014a\u0001\u0000\u0000\u0000\u014a?\u0001\u0000\u0000\u0000"+
		"\u014b\u0149\u0001\u0000\u0000\u0000\u0018W^ln~\u0083\u008e\u00ba\u00c3"+
		"\u00ca\u00d4\u00d8\u00df\u00eb\u00f7\u00ff\u0107\u010e\u0118\u0120\u012e"+
		"\u0135\u013d\u0149";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}