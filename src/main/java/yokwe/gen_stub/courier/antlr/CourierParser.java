// Generated from src/main/java/yokwe/gen_stub/courier/antlr/Courier.g by ANTLR 4.13.2
package yokwe.gen_stub.courier.antlr;
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
		T__9=10, T__10=11, T__11=12, T__12=13, T__13=14, ARRAY=15, BEGIN=16, BLOCK=17, 
		BOOLEAN=18, BYTE=19, CARDINAL=20, CHOICE=21, DEPENDS=22, DEPENDENT=23, 
		END=24, ERROR=25, INTEGER=26, LONG=27, MACHINE=28, OF=29, PROCEDURE=30, 
		PROGRAM=31, RECORD=32, REPORTS=33, RETURNS=34, SEQUENCE=35, STRING=36, 
		TYPE=37, UNSPECIFIED=38, UNSPECIFIED2=39, UNSPECIFIED3=40, UPON=41, VERSION=42, 
		TRUE=43, FALSE=44, ID=45, NUMBER=46, STR=47, COMMENT_PARTIAL=48, COMMENT_LINE=49, 
		SPACE=50;
	public static final int
		RULE_courierProgram = 0, RULE_programHeader = 1, RULE_programBody = 2, 
		RULE_dependencyList = 3, RULE_referencedProgramList = 4, RULE_referencedProgram = 5, 
		RULE_declarationList = 6, RULE_declaration = 7, RULE_type = 8, RULE_predefinedType = 9, 
		RULE_constructedType = 10, RULE_enumType = 11, RULE_mdType = 12, RULE_referencedType = 13, 
		RULE_correspondenceList = 14, RULE_correspondence = 15, RULE_maximumNumber = 16, 
		RULE_numericValue = 17, RULE_typedCandidateList = 18, RULE_typedCandidate = 19, 
		RULE_anonCandidateList = 20, RULE_anonCandidate = 21, RULE_argumentList = 22, 
		RULE_resultList = 23, RULE_errorList = 24, RULE_fieldList = 25, RULE_field = 26, 
		RULE_mdFieldList = 27, RULE_mdFieldType = 28, RULE_mdField = 29, RULE_constant = 30, 
		RULE_predefinedConstant = 31, RULE_constructedConstant = 32, RULE_referencedConstant = 33, 
		RULE_elementList = 34, RULE_componentList = 35, RULE_component = 36, RULE_nameList = 37;
	private static String[] makeRuleNames() {
		return new String[] {
			"courierProgram", "programHeader", "programBody", "dependencyList", "referencedProgramList", 
			"referencedProgram", "declarationList", "declaration", "type", "predefinedType", 
			"constructedType", "enumType", "mdType", "referencedType", "correspondenceList", 
			"correspondence", "maximumNumber", "numericValue", "typedCandidateList", 
			"typedCandidate", "anonCandidateList", "anonCandidate", "argumentList", 
			"resultList", "errorList", "fieldList", "field", "mdFieldList", "mdFieldType", 
			"mdField", "constant", "predefinedConstant", "constructedConstant", "referencedConstant", 
			"elementList", "componentList", "component", "nameList"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'='", "'.'", "':'", "';'", "','", "'('", "')'", "'{'", "'}'", 
			"'['", "']'", "'=>'", "'..'", "'-'", "'ARRAY'", "'BEGIN'", "'BLOCK'", 
			"'BOOLEAN'", "'BYTE'", "'CARDINAL'", "'CHOICE'", "'DEPENDS'", "'DEPENDENT'", 
			"'END'", "'ERROR'", "'INTEGER'", "'LONG'", "'MACHINE'", "'OF'", "'PROCEDURE'", 
			"'PROGRAM'", "'RECORD'", "'REPORTS'", "'RETURNS'", "'SEQUENCE'", "'STRING'", 
			"'TYPE'", "'UNSPECIFIED'", "'UNSPECIFIED2'", "'UNSPECIFIED3'", "'UPON'", 
			"'VERSION'", "'TRUE'", "'FALSE'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, "ARRAY", "BEGIN", "BLOCK", "BOOLEAN", "BYTE", "CARDINAL", 
			"CHOICE", "DEPENDS", "DEPENDENT", "END", "ERROR", "INTEGER", "LONG", 
			"MACHINE", "OF", "PROCEDURE", "PROGRAM", "RECORD", "REPORTS", "RETURNS", 
			"SEQUENCE", "STRING", "TYPE", "UNSPECIFIED", "UNSPECIFIED2", "UNSPECIFIED3", 
			"UPON", "VERSION", "TRUE", "FALSE", "ID", "NUMBER", "STR", "COMMENT_PARTIAL", 
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
			setState(76);
			programHeader();
			setState(77);
			match(T__0);
			setState(78);
			programBody();
			setState(79);
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
			setState(81);
			((ProgramHeaderContext)_localctx).name = match(ID);
			setState(82);
			match(T__2);
			setState(83);
			match(PROGRAM);
			setState(84);
			((ProgramHeaderContext)_localctx).program = match(NUMBER);
			setState(85);
			match(VERSION);
			setState(86);
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
			setState(88);
			match(BEGIN);
			setState(89);
			dependencyList();
			setState(90);
			declarationList();
			setState(91);
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
			setState(99);
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
				setState(94);
				match(DEPENDS);
				setState(95);
				match(UPON);
				setState(96);
				referencedProgramList();
				setState(97);
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
			setState(101);
			((ReferencedProgramListContext)_localctx).referencedProgram = referencedProgram();
			((ReferencedProgramListContext)_localctx).elements.add(((ReferencedProgramListContext)_localctx).referencedProgram);
			setState(106);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__4) {
				{
				{
				setState(102);
				match(T__4);
				setState(103);
				((ReferencedProgramListContext)_localctx).referencedProgram = referencedProgram();
				((ReferencedProgramListContext)_localctx).elements.add(((ReferencedProgramListContext)_localctx).referencedProgram);
				}
				}
				setState(108);
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
		public Token program;
		public Token number;
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
			setState(109);
			((ReferencedProgramContext)_localctx).program = match(ID);
			setState(110);
			match(T__5);
			setState(111);
			((ReferencedProgramContext)_localctx).number = match(NUMBER);
			setState(112);
			match(T__6);
			setState(113);
			match(VERSION);
			setState(114);
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
			setState(122);
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
				setState(118); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(117);
					((DeclarationListContext)_localctx).declaration = declaration();
					((DeclarationListContext)_localctx).elements.add(((DeclarationListContext)_localctx).declaration);
					}
					}
					setState(120); 
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
	public static class DeclConstContext extends DeclarationContext {
		public Token name;
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public ConstantContext constant() {
			return getRuleContext(ConstantContext.class,0);
		}
		public TerminalNode ID() { return getToken(CourierParser.ID, 0); }
		public DeclConstContext(DeclarationContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitDeclConst(this);
			else return visitor.visitChildren(this);
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

	public final DeclarationContext declaration() throws RecognitionException {
		DeclarationContext _localctx = new DeclarationContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_declaration);
		try {
			setState(138);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
			case 1:
				_localctx = new DeclTypeContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(124);
				((DeclTypeContext)_localctx).name = match(ID);
				setState(125);
				match(T__2);
				setState(126);
				match(TYPE);
				setState(127);
				match(T__0);
				setState(128);
				type();
				setState(129);
				match(T__3);
				}
				break;
			case 2:
				_localctx = new DeclConstContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(131);
				((DeclConstContext)_localctx).name = match(ID);
				setState(132);
				match(T__2);
				setState(133);
				type();
				setState(134);
				match(T__0);
				setState(135);
				constant();
				setState(136);
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
		public PredefinedTypeContext predefinedType() {
			return getRuleContext(PredefinedTypeContext.class,0);
		}
		public ConstructedTypeContext constructedType() {
			return getRuleContext(ConstructedTypeContext.class,0);
		}
		public ReferencedTypeContext referencedType() {
			return getRuleContext(ReferencedTypeContext.class,0);
		}
		public TypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitType(this);
			else return visitor.visitChildren(this);
		}
	}

	public final TypeContext type() throws RecognitionException {
		TypeContext _localctx = new TypeContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_type);
		try {
			setState(143);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case BLOCK:
			case BOOLEAN:
			case BYTE:
			case CARDINAL:
			case LONG:
			case STRING:
			case UNSPECIFIED:
			case UNSPECIFIED2:
			case UNSPECIFIED3:
				enterOuterAlt(_localctx, 1);
				{
				setState(140);
				predefinedType();
				}
				break;
			case T__7:
			case ARRAY:
			case CHOICE:
			case ERROR:
			case MACHINE:
			case PROCEDURE:
			case RECORD:
			case SEQUENCE:
				enterOuterAlt(_localctx, 2);
				{
				setState(141);
				constructedType();
				}
				break;
			case ID:
				enterOuterAlt(_localctx, 3);
				{
				setState(142);
				referencedType();
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
	public static class TypeByteContext extends PredefinedTypeContext {
		public TerminalNode BYTE() { return getToken(CourierParser.BYTE, 0); }
		public TypeByteContext(PredefinedTypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeByte(this);
			else return visitor.visitChildren(this);
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
	public static class TypeUnspecified2Context extends PredefinedTypeContext {
		public TerminalNode UNSPECIFIED2() { return getToken(CourierParser.UNSPECIFIED2, 0); }
		public TypeUnspecified2Context(PredefinedTypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeUnspecified2(this);
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
	public static class TypeUnspecified3Context extends PredefinedTypeContext {
		public TerminalNode UNSPECIFIED3() { return getToken(CourierParser.UNSPECIFIED3, 0); }
		public TypeUnspecified3Context(PredefinedTypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeUnspecified3(this);
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
	public static class TypeBlockContext extends PredefinedTypeContext {
		public TerminalNode BLOCK() { return getToken(CourierParser.BLOCK, 0); }
		public TypeBlockContext(PredefinedTypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeBlock(this);
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
			setState(155);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case BLOCK:
				_localctx = new TypeBlockContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(145);
				match(BLOCK);
				}
				break;
			case BOOLEAN:
				_localctx = new TypeBooleanContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(146);
				match(BOOLEAN);
				}
				break;
			case BYTE:
				_localctx = new TypeByteContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(147);
				match(BYTE);
				}
				break;
			case CARDINAL:
				_localctx = new TypeCardinalContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(148);
				match(CARDINAL);
				}
				break;
			case LONG:
				_localctx = new TypeLongCardinalContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(149);
				match(LONG);
				setState(150);
				match(CARDINAL);
				}
				break;
			case STRING:
				_localctx = new TypeStringContext(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(151);
				match(STRING);
				}
				break;
			case UNSPECIFIED:
				_localctx = new TypeUnspecifiedContext(_localctx);
				enterOuterAlt(_localctx, 7);
				{
				setState(152);
				match(UNSPECIFIED);
				}
				break;
			case UNSPECIFIED2:
				_localctx = new TypeUnspecified2Context(_localctx);
				enterOuterAlt(_localctx, 8);
				{
				setState(153);
				match(UNSPECIFIED2);
				}
				break;
			case UNSPECIFIED3:
				_localctx = new TypeUnspecified3Context(_localctx);
				enterOuterAlt(_localctx, 9);
				{
				setState(154);
				match(UNSPECIFIED3);
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
		public ReferencedTypeContext referencedType() {
			return getRuleContext(ReferencedTypeContext.class,0);
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
	public static class TypeEmptyEnumContext extends ConstructedTypeContext {
		public CorrespondenceListContext correspondenceList() {
			return getRuleContext(CorrespondenceListContext.class,0);
		}
		public TypeEmptyEnumContext(ConstructedTypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeEmptyEnum(this);
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
		public TerminalNode OF() { return getToken(CourierParser.OF, 0); }
		public EnumTypeContext enumType() {
			return getRuleContext(EnumTypeContext.class,0);
		}
		public TypeEnumContext(ConstructedTypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeEnum(this);
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
	@SuppressWarnings("CheckReturnValue")
	public static class TypeEmptyRecordContext extends ConstructedTypeContext {
		public TerminalNode RECORD() { return getToken(CourierParser.RECORD, 0); }
		public TypeEmptyRecordContext(ConstructedTypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeEmptyRecord(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeMachineContext extends ConstructedTypeContext {
		public TerminalNode MACHINE() { return getToken(CourierParser.MACHINE, 0); }
		public TerminalNode DEPENDENT() { return getToken(CourierParser.DEPENDENT, 0); }
		public MdFieldListContext mdFieldList() {
			return getRuleContext(MdFieldListContext.class,0);
		}
		public TerminalNode OF() { return getToken(CourierParser.OF, 0); }
		public MdTypeContext mdType() {
			return getRuleContext(MdTypeContext.class,0);
		}
		public TypeMachineContext(ConstructedTypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeMachine(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ConstructedTypeContext constructedType() throws RecognitionException {
		ConstructedTypeContext _localctx = new ConstructedTypeContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_constructedType);
		try {
			setState(213);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,7,_ctx) ) {
			case 1:
				_localctx = new TypeEmptyEnumContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(157);
				match(T__7);
				setState(158);
				correspondenceList();
				setState(159);
				match(T__8);
				}
				break;
			case 2:
				_localctx = new TypeEnumContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(161);
				match(T__7);
				setState(162);
				correspondenceList();
				setState(163);
				match(T__8);
				setState(164);
				match(OF);
				setState(165);
				enumType();
				}
				break;
			case 3:
				_localctx = new TypeArrayContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(167);
				match(ARRAY);
				setState(168);
				numericValue();
				setState(169);
				match(OF);
				setState(170);
				type();
				}
				break;
			case 4:
				_localctx = new TypeSequenceContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(172);
				match(SEQUENCE);
				setState(173);
				maximumNumber();
				setState(174);
				match(OF);
				setState(175);
				type();
				}
				break;
			case 5:
				_localctx = new TypeRecordContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(177);
				match(RECORD);
				setState(178);
				match(T__9);
				setState(179);
				fieldList();
				setState(180);
				match(T__10);
				}
				break;
			case 6:
				_localctx = new TypeEmptyRecordContext(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(182);
				match(RECORD);
				setState(183);
				match(T__9);
				setState(184);
				match(T__10);
				}
				break;
			case 7:
				_localctx = new TypeChoiceTypedContext(_localctx);
				enterOuterAlt(_localctx, 7);
				{
				setState(185);
				match(CHOICE);
				setState(186);
				referencedType();
				setState(187);
				match(OF);
				setState(188);
				match(T__7);
				setState(189);
				typedCandidateList();
				setState(190);
				match(T__8);
				}
				break;
			case 8:
				_localctx = new TypeChoiceAnonContext(_localctx);
				enterOuterAlt(_localctx, 8);
				{
				setState(192);
				match(CHOICE);
				setState(193);
				match(OF);
				setState(194);
				match(T__7);
				setState(195);
				anonCandidateList();
				setState(196);
				match(T__8);
				}
				break;
			case 9:
				_localctx = new TypeProcedureContext(_localctx);
				enterOuterAlt(_localctx, 9);
				{
				setState(198);
				match(PROCEDURE);
				setState(199);
				argumentList();
				setState(200);
				resultList();
				setState(201);
				errorList();
				}
				break;
			case 10:
				_localctx = new TypeErrorContext(_localctx);
				enterOuterAlt(_localctx, 10);
				{
				setState(203);
				match(ERROR);
				setState(204);
				argumentList();
				}
				break;
			case 11:
				_localctx = new TypeMachineContext(_localctx);
				enterOuterAlt(_localctx, 11);
				{
				setState(205);
				match(MACHINE);
				setState(206);
				match(DEPENDENT);
				setState(207);
				match(T__9);
				setState(208);
				mdFieldList();
				setState(209);
				match(T__10);
				setState(210);
				match(OF);
				setState(211);
				mdType();
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
	public static class EnumTypeContext extends ParserRuleContext {
		public TerminalNode BYTE() { return getToken(CourierParser.BYTE, 0); }
		public TerminalNode UNSPECIFIED() { return getToken(CourierParser.UNSPECIFIED, 0); }
		public TerminalNode UNSPECIFIED2() { return getToken(CourierParser.UNSPECIFIED2, 0); }
		public TerminalNode UNSPECIFIED3() { return getToken(CourierParser.UNSPECIFIED3, 0); }
		public EnumTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_enumType; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitEnumType(this);
			else return visitor.visitChildren(this);
		}
	}

	public final EnumTypeContext enumType() throws RecognitionException {
		EnumTypeContext _localctx = new EnumTypeContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_enumType);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(215);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 1924145872896L) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
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
	public static class MdTypeContext extends ParserRuleContext {
		public TerminalNode BYTE() { return getToken(CourierParser.BYTE, 0); }
		public TerminalNode UNSPECIFIED() { return getToken(CourierParser.UNSPECIFIED, 0); }
		public MdTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_mdType; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitMdType(this);
			else return visitor.visitChildren(this);
		}
	}

	public final MdTypeContext mdType() throws RecognitionException {
		MdTypeContext _localctx = new MdTypeContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_mdType);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(217);
			_la = _input.LA(1);
			if ( !(_la==BYTE || _la==UNSPECIFIED) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
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
	public static class ReferencedTypeContext extends ParserRuleContext {
		public ReferencedTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_referencedType; }
	 
		public ReferencedTypeContext() { }
		public void copyFrom(ReferencedTypeContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeRefQContext extends ReferencedTypeContext {
		public Token program;
		public Token name;
		public List<TerminalNode> ID() { return getTokens(CourierParser.ID); }
		public TerminalNode ID(int i) {
			return getToken(CourierParser.ID, i);
		}
		public TypeRefQContext(ReferencedTypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeRefQ(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeRefContext extends ReferencedTypeContext {
		public Token name;
		public TerminalNode ID() { return getToken(CourierParser.ID, 0); }
		public TypeRefContext(ReferencedTypeContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitTypeRef(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ReferencedTypeContext referencedType() throws RecognitionException {
		ReferencedTypeContext _localctx = new ReferencedTypeContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_referencedType);
		try {
			setState(223);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,8,_ctx) ) {
			case 1:
				_localctx = new TypeRefContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(219);
				((TypeRefContext)_localctx).name = match(ID);
				}
				break;
			case 2:
				_localctx = new TypeRefQContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(220);
				((TypeRefQContext)_localctx).program = match(ID);
				setState(221);
				match(T__1);
				setState(222);
				((TypeRefQContext)_localctx).name = match(ID);
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
		enterRule(_localctx, 28, RULE_correspondenceList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(225);
			((CorrespondenceListContext)_localctx).correspondence = correspondence();
			((CorrespondenceListContext)_localctx).elements.add(((CorrespondenceListContext)_localctx).correspondence);
			setState(230);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__4) {
				{
				{
				setState(226);
				match(T__4);
				setState(227);
				((CorrespondenceListContext)_localctx).correspondence = correspondence();
				((CorrespondenceListContext)_localctx).elements.add(((CorrespondenceListContext)_localctx).correspondence);
				}
				}
				setState(232);
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
		enterRule(_localctx, 30, RULE_correspondence);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(233);
			match(ID);
			setState(234);
			match(T__5);
			setState(235);
			numericValue();
			setState(236);
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
		enterRule(_localctx, 32, RULE_maximumNumber);
		try {
			setState(240);
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
				setState(239);
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
	public static class ValueRefConstsContext extends NumericValueContext {
		public ReferencedConstantContext referencedConstant() {
			return getRuleContext(ReferencedConstantContext.class,0);
		}
		public ValueRefConstsContext(NumericValueContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitValueRefConsts(this);
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
		enterRule(_localctx, 34, RULE_numericValue);
		try {
			setState(244);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case NUMBER:
				_localctx = new ValueNumberContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(242);
				match(NUMBER);
				}
				break;
			case ID:
				_localctx = new ValueRefConstsContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(243);
				referencedConstant();
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
		enterRule(_localctx, 36, RULE_typedCandidateList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(246);
			((TypedCandidateListContext)_localctx).typedCandidate = typedCandidate();
			((TypedCandidateListContext)_localctx).elements.add(((TypedCandidateListContext)_localctx).typedCandidate);
			setState(251);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__4) {
				{
				{
				setState(247);
				match(T__4);
				setState(248);
				((TypedCandidateListContext)_localctx).typedCandidate = typedCandidate();
				((TypedCandidateListContext)_localctx).elements.add(((TypedCandidateListContext)_localctx).typedCandidate);
				}
				}
				setState(253);
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
		enterRule(_localctx, 38, RULE_typedCandidate);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(254);
			nameList();
			setState(255);
			match(T__11);
			setState(256);
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
		enterRule(_localctx, 40, RULE_anonCandidateList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(258);
			((AnonCandidateListContext)_localctx).anonCandidate = anonCandidate();
			((AnonCandidateListContext)_localctx).elements.add(((AnonCandidateListContext)_localctx).anonCandidate);
			setState(263);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__4) {
				{
				{
				setState(259);
				match(T__4);
				setState(260);
				((AnonCandidateListContext)_localctx).anonCandidate = anonCandidate();
				((AnonCandidateListContext)_localctx).elements.add(((AnonCandidateListContext)_localctx).anonCandidate);
				}
				}
				setState(265);
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
		enterRule(_localctx, 42, RULE_anonCandidate);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(266);
			correspondenceList();
			setState(267);
			match(T__11);
			setState(268);
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
		enterRule(_localctx, 44, RULE_argumentList);
		try {
			setState(275);
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
				setState(271);
				match(T__9);
				setState(272);
				fieldList();
				setState(273);
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
		enterRule(_localctx, 46, RULE_resultList);
		try {
			setState(283);
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
				setState(278);
				match(RETURNS);
				setState(279);
				match(T__9);
				setState(280);
				fieldList();
				setState(281);
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
		enterRule(_localctx, 48, RULE_errorList);
		try {
			setState(291);
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
				setState(286);
				match(REPORTS);
				setState(287);
				match(T__9);
				setState(288);
				nameList();
				setState(289);
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
		enterRule(_localctx, 50, RULE_fieldList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(293);
			((FieldListContext)_localctx).field = field();
			((FieldListContext)_localctx).elements.add(((FieldListContext)_localctx).field);
			setState(298);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__4) {
				{
				{
				setState(294);
				match(T__4);
				setState(295);
				((FieldListContext)_localctx).field = field();
				((FieldListContext)_localctx).elements.add(((FieldListContext)_localctx).field);
				}
				}
				setState(300);
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
		enterRule(_localctx, 52, RULE_field);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(301);
			nameList();
			setState(302);
			match(T__2);
			setState(303);
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
	public static class MdFieldListContext extends ParserRuleContext {
		public MdFieldContext mdField;
		public List<MdFieldContext> elements = new ArrayList<MdFieldContext>();
		public List<MdFieldContext> mdField() {
			return getRuleContexts(MdFieldContext.class);
		}
		public MdFieldContext mdField(int i) {
			return getRuleContext(MdFieldContext.class,i);
		}
		public MdFieldListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_mdFieldList; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitMdFieldList(this);
			else return visitor.visitChildren(this);
		}
	}

	public final MdFieldListContext mdFieldList() throws RecognitionException {
		MdFieldListContext _localctx = new MdFieldListContext(_ctx, getState());
		enterRule(_localctx, 54, RULE_mdFieldList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(305);
			((MdFieldListContext)_localctx).mdField = mdField();
			((MdFieldListContext)_localctx).elements.add(((MdFieldListContext)_localctx).mdField);
			setState(310);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__4) {
				{
				{
				setState(306);
				match(T__4);
				setState(307);
				((MdFieldListContext)_localctx).mdField = mdField();
				((MdFieldListContext)_localctx).elements.add(((MdFieldListContext)_localctx).mdField);
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
	public static class MdFieldTypeContext extends ParserRuleContext {
		public TerminalNode BOOLEAN() { return getToken(CourierParser.BOOLEAN, 0); }
		public TerminalNode CARDINAL() { return getToken(CourierParser.CARDINAL, 0); }
		public TerminalNode UNSPECIFIED() { return getToken(CourierParser.UNSPECIFIED, 0); }
		public MdFieldTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_mdFieldType; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitMdFieldType(this);
			else return visitor.visitChildren(this);
		}
	}

	public final MdFieldTypeContext mdFieldType() throws RecognitionException {
		MdFieldTypeContext _localctx = new MdFieldTypeContext(_ctx, getState());
		enterRule(_localctx, 56, RULE_mdFieldType);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(313);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 274879217664L) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
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
	public static class MdFieldContext extends ParserRuleContext {
		public Token name;
		public Token start;
		public Token stop;
		public MdFieldTypeContext mdFieldType() {
			return getRuleContext(MdFieldTypeContext.class,0);
		}
		public TerminalNode ID() { return getToken(CourierParser.ID, 0); }
		public List<TerminalNode> NUMBER() { return getTokens(CourierParser.NUMBER); }
		public TerminalNode NUMBER(int i) {
			return getToken(CourierParser.NUMBER, i);
		}
		public MdFieldContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_mdField; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitMdField(this);
			else return visitor.visitChildren(this);
		}
	}

	public final MdFieldContext mdField() throws RecognitionException {
		MdFieldContext _localctx = new MdFieldContext(_ctx, getState());
		enterRule(_localctx, 58, RULE_mdField);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(315);
			((MdFieldContext)_localctx).name = match(ID);
			setState(316);
			match(T__5);
			setState(317);
			((MdFieldContext)_localctx).start = match(NUMBER);
			setState(318);
			match(T__12);
			setState(319);
			((MdFieldContext)_localctx).stop = match(NUMBER);
			setState(320);
			match(T__6);
			setState(321);
			match(T__2);
			setState(322);
			mdFieldType();
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
		public PredefinedConstantContext predefinedConstant() {
			return getRuleContext(PredefinedConstantContext.class,0);
		}
		public ConstructedConstantContext constructedConstant() {
			return getRuleContext(ConstructedConstantContext.class,0);
		}
		public ReferencedConstantContext referencedConstant() {
			return getRuleContext(ReferencedConstantContext.class,0);
		}
		public ConstantContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constant; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitConstant(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ConstantContext constant() throws RecognitionException {
		ConstantContext _localctx = new ConstantContext(_ctx, getState());
		enterRule(_localctx, 60, RULE_constant);
		try {
			setState(327);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,19,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(324);
				predefinedConstant();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(325);
				constructedConstant();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(326);
				referencedConstant();
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
	public static class PredefinedConstantContext extends ParserRuleContext {
		public PredefinedConstantContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_predefinedConstant; }
	 
		public PredefinedConstantContext() { }
		public void copyFrom(PredefinedConstantContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ConstTrueContext extends PredefinedConstantContext {
		public TerminalNode TRUE() { return getToken(CourierParser.TRUE, 0); }
		public ConstTrueContext(PredefinedConstantContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitConstTrue(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ConstNumberNegativeContext extends PredefinedConstantContext {
		public TerminalNode NUMBER() { return getToken(CourierParser.NUMBER, 0); }
		public ConstNumberNegativeContext(PredefinedConstantContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitConstNumberNegative(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ConstStringContext extends PredefinedConstantContext {
		public TerminalNode STR() { return getToken(CourierParser.STR, 0); }
		public ConstStringContext(PredefinedConstantContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitConstString(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ConstFalseContext extends PredefinedConstantContext {
		public TerminalNode FALSE() { return getToken(CourierParser.FALSE, 0); }
		public ConstFalseContext(PredefinedConstantContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitConstFalse(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ConstNumberContext extends PredefinedConstantContext {
		public TerminalNode NUMBER() { return getToken(CourierParser.NUMBER, 0); }
		public ConstNumberContext(PredefinedConstantContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitConstNumber(this);
			else return visitor.visitChildren(this);
		}
	}

	public final PredefinedConstantContext predefinedConstant() throws RecognitionException {
		PredefinedConstantContext _localctx = new PredefinedConstantContext(_ctx, getState());
		enterRule(_localctx, 62, RULE_predefinedConstant);
		try {
			setState(335);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case TRUE:
				_localctx = new ConstTrueContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(329);
				match(TRUE);
				}
				break;
			case FALSE:
				_localctx = new ConstFalseContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(330);
				match(FALSE);
				}
				break;
			case NUMBER:
				_localctx = new ConstNumberContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(331);
				match(NUMBER);
				}
				break;
			case T__13:
				_localctx = new ConstNumberNegativeContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(332);
				match(T__13);
				setState(333);
				match(NUMBER);
				}
				break;
			case STR:
				_localctx = new ConstStringContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(334);
				match(STR);
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
	public static class ConstChoiceContext extends ConstructedConstantContext {
		public TerminalNode ID() { return getToken(CourierParser.ID, 0); }
		public ConstantContext constant() {
			return getRuleContext(ConstantContext.class,0);
		}
		public ConstChoiceContext(ConstructedConstantContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitConstChoice(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ConstArrayContext extends ConstructedConstantContext {
		public ElementListContext elementList() {
			return getRuleContext(ElementListContext.class,0);
		}
		public ConstArrayContext(ConstructedConstantContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitConstArray(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ConstRecordContext extends ConstructedConstantContext {
		public ComponentListContext componentList() {
			return getRuleContext(ComponentListContext.class,0);
		}
		public ConstRecordContext(ConstructedConstantContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitConstRecord(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ConstEmptyContext extends ConstructedConstantContext {
		public ConstEmptyContext(ConstructedConstantContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitConstEmpty(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ConstructedConstantContext constructedConstant() throws RecognitionException {
		ConstructedConstantContext _localctx = new ConstructedConstantContext(_ctx, getState());
		enterRule(_localctx, 64, RULE_constructedConstant);
		try {
			setState(349);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,21,_ctx) ) {
			case 1:
				_localctx = new ConstArrayContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(337);
				match(T__9);
				setState(338);
				elementList();
				setState(339);
				match(T__10);
				}
				break;
			case 2:
				_localctx = new ConstRecordContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(341);
				match(T__9);
				setState(342);
				componentList();
				setState(343);
				match(T__10);
				}
				break;
			case 3:
				_localctx = new ConstEmptyContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(345);
				match(T__9);
				setState(346);
				match(T__10);
				}
				break;
			case 4:
				_localctx = new ConstChoiceContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(347);
				match(ID);
				setState(348);
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
	public static class ReferencedConstantContext extends ParserRuleContext {
		public ReferencedConstantContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_referencedConstant; }
	 
		public ReferencedConstantContext() { }
		public void copyFrom(ReferencedConstantContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ConstRefContext extends ReferencedConstantContext {
		public Token name;
		public TerminalNode ID() { return getToken(CourierParser.ID, 0); }
		public ConstRefContext(ReferencedConstantContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitConstRef(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ConstRefQContext extends ReferencedConstantContext {
		public Token program;
		public Token name;
		public List<TerminalNode> ID() { return getTokens(CourierParser.ID); }
		public TerminalNode ID(int i) {
			return getToken(CourierParser.ID, i);
		}
		public ConstRefQContext(ReferencedConstantContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CourierVisitor ) return ((CourierVisitor<? extends T>)visitor).visitConstRefQ(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ReferencedConstantContext referencedConstant() throws RecognitionException {
		ReferencedConstantContext _localctx = new ReferencedConstantContext(_ctx, getState());
		enterRule(_localctx, 66, RULE_referencedConstant);
		try {
			setState(355);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,22,_ctx) ) {
			case 1:
				_localctx = new ConstRefContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(351);
				((ConstRefContext)_localctx).name = match(ID);
				}
				break;
			case 2:
				_localctx = new ConstRefQContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(352);
				((ConstRefQContext)_localctx).program = match(ID);
				setState(353);
				match(T__1);
				setState(354);
				((ConstRefQContext)_localctx).name = match(ID);
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
		enterRule(_localctx, 68, RULE_elementList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(357);
			((ElementListContext)_localctx).constant = constant();
			((ElementListContext)_localctx).elements.add(((ElementListContext)_localctx).constant);
			setState(362);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__4) {
				{
				{
				setState(358);
				match(T__4);
				setState(359);
				((ElementListContext)_localctx).constant = constant();
				((ElementListContext)_localctx).elements.add(((ElementListContext)_localctx).constant);
				}
				}
				setState(364);
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
		enterRule(_localctx, 70, RULE_componentList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(365);
			((ComponentListContext)_localctx).component = component();
			((ComponentListContext)_localctx).elements.add(((ComponentListContext)_localctx).component);
			setState(370);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__4) {
				{
				{
				setState(366);
				match(T__4);
				setState(367);
				((ComponentListContext)_localctx).component = component();
				((ComponentListContext)_localctx).elements.add(((ComponentListContext)_localctx).component);
				}
				}
				setState(372);
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
		enterRule(_localctx, 72, RULE_component);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(373);
			nameList();
			setState(374);
			match(T__2);
			setState(375);
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
		enterRule(_localctx, 74, RULE_nameList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(377);
			((NameListContext)_localctx).ID = match(ID);
			((NameListContext)_localctx).elements.add(((NameListContext)_localctx).ID);
			setState(382);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__4) {
				{
				{
				setState(378);
				match(T__4);
				setState(379);
				((NameListContext)_localctx).ID = match(ID);
				((NameListContext)_localctx).elements.add(((NameListContext)_localctx).ID);
				}
				}
				setState(384);
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
		"\u0004\u00012\u0182\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
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
		"#\u0007#\u0002$\u0007$\u0002%\u0007%\u0001\u0000\u0001\u0000\u0001\u0000"+
		"\u0001\u0000\u0001\u0000\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003"+
		"\u0001\u0003\u0001\u0003\u0003\u0003d\b\u0003\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0005\u0004i\b\u0004\n\u0004\f\u0004l\t\u0004\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0006\u0001\u0006\u0004\u0006w\b\u0006\u000b\u0006\f\u0006x\u0003"+
		"\u0006{\b\u0006\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001"+
		"\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001"+
		"\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0003\u0007\u008b\b\u0007\u0001"+
		"\b\u0001\b\u0001\b\u0003\b\u0090\b\b\u0001\t\u0001\t\u0001\t\u0001\t\u0001"+
		"\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0003\t\u009c\b\t\u0001\n\u0001"+
		"\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001"+
		"\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001"+
		"\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001"+
		"\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001"+
		"\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001"+
		"\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001"+
		"\n\u0003\n\u00d6\b\n\u0001\u000b\u0001\u000b\u0001\f\u0001\f\u0001\r\u0001"+
		"\r\u0001\r\u0001\r\u0003\r\u00e0\b\r\u0001\u000e\u0001\u000e\u0001\u000e"+
		"\u0005\u000e\u00e5\b\u000e\n\u000e\f\u000e\u00e8\t\u000e\u0001\u000f\u0001"+
		"\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u0010\u0001\u0010\u0003"+
		"\u0010\u00f1\b\u0010\u0001\u0011\u0001\u0011\u0003\u0011\u00f5\b\u0011"+
		"\u0001\u0012\u0001\u0012\u0001\u0012\u0005\u0012\u00fa\b\u0012\n\u0012"+
		"\f\u0012\u00fd\t\u0012\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013"+
		"\u0001\u0014\u0001\u0014\u0001\u0014\u0005\u0014\u0106\b\u0014\n\u0014"+
		"\f\u0014\u0109\t\u0014\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015"+
		"\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0003\u0016"+
		"\u0114\b\u0016\u0001\u0017\u0001\u0017\u0001\u0017\u0001\u0017\u0001\u0017"+
		"\u0001\u0017\u0003\u0017\u011c\b\u0017\u0001\u0018\u0001\u0018\u0001\u0018"+
		"\u0001\u0018\u0001\u0018\u0001\u0018\u0003\u0018\u0124\b\u0018\u0001\u0019"+
		"\u0001\u0019\u0001\u0019\u0005\u0019\u0129\b\u0019\n\u0019\f\u0019\u012c"+
		"\t\u0019\u0001\u001a\u0001\u001a\u0001\u001a\u0001\u001a\u0001\u001b\u0001"+
		"\u001b\u0001\u001b\u0005\u001b\u0135\b\u001b\n\u001b\f\u001b\u0138\t\u001b"+
		"\u0001\u001c\u0001\u001c\u0001\u001d\u0001\u001d\u0001\u001d\u0001\u001d"+
		"\u0001\u001d\u0001\u001d\u0001\u001d\u0001\u001d\u0001\u001d\u0001\u001e"+
		"\u0001\u001e\u0001\u001e\u0003\u001e\u0148\b\u001e\u0001\u001f\u0001\u001f"+
		"\u0001\u001f\u0001\u001f\u0001\u001f\u0001\u001f\u0003\u001f\u0150\b\u001f"+
		"\u0001 \u0001 \u0001 \u0001 \u0001 \u0001 \u0001 \u0001 \u0001 \u0001"+
		" \u0001 \u0001 \u0003 \u015e\b \u0001!\u0001!\u0001!\u0001!\u0003!\u0164"+
		"\b!\u0001\"\u0001\"\u0001\"\u0005\"\u0169\b\"\n\"\f\"\u016c\t\"\u0001"+
		"#\u0001#\u0001#\u0005#\u0171\b#\n#\f#\u0174\t#\u0001$\u0001$\u0001$\u0001"+
		"$\u0001%\u0001%\u0001%\u0005%\u017d\b%\n%\f%\u0180\t%\u0001%\u0000\u0000"+
		"&\u0000\u0002\u0004\u0006\b\n\f\u000e\u0010\u0012\u0014\u0016\u0018\u001a"+
		"\u001c\u001e \"$&(*,.02468:<>@BDFHJ\u0000\u0003\u0002\u0000\u0013\u0013"+
		"&(\u0002\u0000\u0013\u0013&&\u0003\u0000\u0012\u0012\u0014\u0014&&\u018c"+
		"\u0000L\u0001\u0000\u0000\u0000\u0002Q\u0001\u0000\u0000\u0000\u0004X"+
		"\u0001\u0000\u0000\u0000\u0006c\u0001\u0000\u0000\u0000\be\u0001\u0000"+
		"\u0000\u0000\nm\u0001\u0000\u0000\u0000\fz\u0001\u0000\u0000\u0000\u000e"+
		"\u008a\u0001\u0000\u0000\u0000\u0010\u008f\u0001\u0000\u0000\u0000\u0012"+
		"\u009b\u0001\u0000\u0000\u0000\u0014\u00d5\u0001\u0000\u0000\u0000\u0016"+
		"\u00d7\u0001\u0000\u0000\u0000\u0018\u00d9\u0001\u0000\u0000\u0000\u001a"+
		"\u00df\u0001\u0000\u0000\u0000\u001c\u00e1\u0001\u0000\u0000\u0000\u001e"+
		"\u00e9\u0001\u0000\u0000\u0000 \u00f0\u0001\u0000\u0000\u0000\"\u00f4"+
		"\u0001\u0000\u0000\u0000$\u00f6\u0001\u0000\u0000\u0000&\u00fe\u0001\u0000"+
		"\u0000\u0000(\u0102\u0001\u0000\u0000\u0000*\u010a\u0001\u0000\u0000\u0000"+
		",\u0113\u0001\u0000\u0000\u0000.\u011b\u0001\u0000\u0000\u00000\u0123"+
		"\u0001\u0000\u0000\u00002\u0125\u0001\u0000\u0000\u00004\u012d\u0001\u0000"+
		"\u0000\u00006\u0131\u0001\u0000\u0000\u00008\u0139\u0001\u0000\u0000\u0000"+
		":\u013b\u0001\u0000\u0000\u0000<\u0147\u0001\u0000\u0000\u0000>\u014f"+
		"\u0001\u0000\u0000\u0000@\u015d\u0001\u0000\u0000\u0000B\u0163\u0001\u0000"+
		"\u0000\u0000D\u0165\u0001\u0000\u0000\u0000F\u016d\u0001\u0000\u0000\u0000"+
		"H\u0175\u0001\u0000\u0000\u0000J\u0179\u0001\u0000\u0000\u0000LM\u0003"+
		"\u0002\u0001\u0000MN\u0005\u0001\u0000\u0000NO\u0003\u0004\u0002\u0000"+
		"OP\u0005\u0002\u0000\u0000P\u0001\u0001\u0000\u0000\u0000QR\u0005-\u0000"+
		"\u0000RS\u0005\u0003\u0000\u0000ST\u0005\u001f\u0000\u0000TU\u0005.\u0000"+
		"\u0000UV\u0005*\u0000\u0000VW\u0005.\u0000\u0000W\u0003\u0001\u0000\u0000"+
		"\u0000XY\u0005\u0010\u0000\u0000YZ\u0003\u0006\u0003\u0000Z[\u0003\f\u0006"+
		"\u0000[\\\u0005\u0018\u0000\u0000\\\u0005\u0001\u0000\u0000\u0000]d\u0001"+
		"\u0000\u0000\u0000^_\u0005\u0016\u0000\u0000_`\u0005)\u0000\u0000`a\u0003"+
		"\b\u0004\u0000ab\u0005\u0004\u0000\u0000bd\u0001\u0000\u0000\u0000c]\u0001"+
		"\u0000\u0000\u0000c^\u0001\u0000\u0000\u0000d\u0007\u0001\u0000\u0000"+
		"\u0000ej\u0003\n\u0005\u0000fg\u0005\u0005\u0000\u0000gi\u0003\n\u0005"+
		"\u0000hf\u0001\u0000\u0000\u0000il\u0001\u0000\u0000\u0000jh\u0001\u0000"+
		"\u0000\u0000jk\u0001\u0000\u0000\u0000k\t\u0001\u0000\u0000\u0000lj\u0001"+
		"\u0000\u0000\u0000mn\u0005-\u0000\u0000no\u0005\u0006\u0000\u0000op\u0005"+
		".\u0000\u0000pq\u0005\u0007\u0000\u0000qr\u0005*\u0000\u0000rs\u0005."+
		"\u0000\u0000s\u000b\u0001\u0000\u0000\u0000t{\u0001\u0000\u0000\u0000"+
		"uw\u0003\u000e\u0007\u0000vu\u0001\u0000\u0000\u0000wx\u0001\u0000\u0000"+
		"\u0000xv\u0001\u0000\u0000\u0000xy\u0001\u0000\u0000\u0000y{\u0001\u0000"+
		"\u0000\u0000zt\u0001\u0000\u0000\u0000zv\u0001\u0000\u0000\u0000{\r\u0001"+
		"\u0000\u0000\u0000|}\u0005-\u0000\u0000}~\u0005\u0003\u0000\u0000~\u007f"+
		"\u0005%\u0000\u0000\u007f\u0080\u0005\u0001\u0000\u0000\u0080\u0081\u0003"+
		"\u0010\b\u0000\u0081\u0082\u0005\u0004\u0000\u0000\u0082\u008b\u0001\u0000"+
		"\u0000\u0000\u0083\u0084\u0005-\u0000\u0000\u0084\u0085\u0005\u0003\u0000"+
		"\u0000\u0085\u0086\u0003\u0010\b\u0000\u0086\u0087\u0005\u0001\u0000\u0000"+
		"\u0087\u0088\u0003<\u001e\u0000\u0088\u0089\u0005\u0004\u0000\u0000\u0089"+
		"\u008b\u0001\u0000\u0000\u0000\u008a|\u0001\u0000\u0000\u0000\u008a\u0083"+
		"\u0001\u0000\u0000\u0000\u008b\u000f\u0001\u0000\u0000\u0000\u008c\u0090"+
		"\u0003\u0012\t\u0000\u008d\u0090\u0003\u0014\n\u0000\u008e\u0090\u0003"+
		"\u001a\r\u0000\u008f\u008c\u0001\u0000\u0000\u0000\u008f\u008d\u0001\u0000"+
		"\u0000\u0000\u008f\u008e\u0001\u0000\u0000\u0000\u0090\u0011\u0001\u0000"+
		"\u0000\u0000\u0091\u009c\u0005\u0011\u0000\u0000\u0092\u009c\u0005\u0012"+
		"\u0000\u0000\u0093\u009c\u0005\u0013\u0000\u0000\u0094\u009c\u0005\u0014"+
		"\u0000\u0000\u0095\u0096\u0005\u001b\u0000\u0000\u0096\u009c\u0005\u0014"+
		"\u0000\u0000\u0097\u009c\u0005$\u0000\u0000\u0098\u009c\u0005&\u0000\u0000"+
		"\u0099\u009c\u0005\'\u0000\u0000\u009a\u009c\u0005(\u0000\u0000\u009b"+
		"\u0091\u0001\u0000\u0000\u0000\u009b\u0092\u0001\u0000\u0000\u0000\u009b"+
		"\u0093\u0001\u0000\u0000\u0000\u009b\u0094\u0001\u0000\u0000\u0000\u009b"+
		"\u0095\u0001\u0000\u0000\u0000\u009b\u0097\u0001\u0000\u0000\u0000\u009b"+
		"\u0098\u0001\u0000\u0000\u0000\u009b\u0099\u0001\u0000\u0000\u0000\u009b"+
		"\u009a\u0001\u0000\u0000\u0000\u009c\u0013\u0001\u0000\u0000\u0000\u009d"+
		"\u009e\u0005\b\u0000\u0000\u009e\u009f\u0003\u001c\u000e\u0000\u009f\u00a0"+
		"\u0005\t\u0000\u0000\u00a0\u00d6\u0001\u0000\u0000\u0000\u00a1\u00a2\u0005"+
		"\b\u0000\u0000\u00a2\u00a3\u0003\u001c\u000e\u0000\u00a3\u00a4\u0005\t"+
		"\u0000\u0000\u00a4\u00a5\u0005\u001d\u0000\u0000\u00a5\u00a6\u0003\u0016"+
		"\u000b\u0000\u00a6\u00d6\u0001\u0000\u0000\u0000\u00a7\u00a8\u0005\u000f"+
		"\u0000\u0000\u00a8\u00a9\u0003\"\u0011\u0000\u00a9\u00aa\u0005\u001d\u0000"+
		"\u0000\u00aa\u00ab\u0003\u0010\b\u0000\u00ab\u00d6\u0001\u0000\u0000\u0000"+
		"\u00ac\u00ad\u0005#\u0000\u0000\u00ad\u00ae\u0003 \u0010\u0000\u00ae\u00af"+
		"\u0005\u001d\u0000\u0000\u00af\u00b0\u0003\u0010\b\u0000\u00b0\u00d6\u0001"+
		"\u0000\u0000\u0000\u00b1\u00b2\u0005 \u0000\u0000\u00b2\u00b3\u0005\n"+
		"\u0000\u0000\u00b3\u00b4\u00032\u0019\u0000\u00b4\u00b5\u0005\u000b\u0000"+
		"\u0000\u00b5\u00d6\u0001\u0000\u0000\u0000\u00b6\u00b7\u0005 \u0000\u0000"+
		"\u00b7\u00b8\u0005\n\u0000\u0000\u00b8\u00d6\u0005\u000b\u0000\u0000\u00b9"+
		"\u00ba\u0005\u0015\u0000\u0000\u00ba\u00bb\u0003\u001a\r\u0000\u00bb\u00bc"+
		"\u0005\u001d\u0000\u0000\u00bc\u00bd\u0005\b\u0000\u0000\u00bd\u00be\u0003"+
		"$\u0012\u0000\u00be\u00bf\u0005\t\u0000\u0000\u00bf\u00d6\u0001\u0000"+
		"\u0000\u0000\u00c0\u00c1\u0005\u0015\u0000\u0000\u00c1\u00c2\u0005\u001d"+
		"\u0000\u0000\u00c2\u00c3\u0005\b\u0000\u0000\u00c3\u00c4\u0003(\u0014"+
		"\u0000\u00c4\u00c5\u0005\t\u0000\u0000\u00c5\u00d6\u0001\u0000\u0000\u0000"+
		"\u00c6\u00c7\u0005\u001e\u0000\u0000\u00c7\u00c8\u0003,\u0016\u0000\u00c8"+
		"\u00c9\u0003.\u0017\u0000\u00c9\u00ca\u00030\u0018\u0000\u00ca\u00d6\u0001"+
		"\u0000\u0000\u0000\u00cb\u00cc\u0005\u0019\u0000\u0000\u00cc\u00d6\u0003"+
		",\u0016\u0000\u00cd\u00ce\u0005\u001c\u0000\u0000\u00ce\u00cf\u0005\u0017"+
		"\u0000\u0000\u00cf\u00d0\u0005\n\u0000\u0000\u00d0\u00d1\u00036\u001b"+
		"\u0000\u00d1\u00d2\u0005\u000b\u0000\u0000\u00d2\u00d3\u0005\u001d\u0000"+
		"\u0000\u00d3\u00d4\u0003\u0018\f\u0000\u00d4\u00d6\u0001\u0000\u0000\u0000"+
		"\u00d5\u009d\u0001\u0000\u0000\u0000\u00d5\u00a1\u0001\u0000\u0000\u0000"+
		"\u00d5\u00a7\u0001\u0000\u0000\u0000\u00d5\u00ac\u0001\u0000\u0000\u0000"+
		"\u00d5\u00b1\u0001\u0000\u0000\u0000\u00d5\u00b6\u0001\u0000\u0000\u0000"+
		"\u00d5\u00b9\u0001\u0000\u0000\u0000\u00d5\u00c0\u0001\u0000\u0000\u0000"+
		"\u00d5\u00c6\u0001\u0000\u0000\u0000\u00d5\u00cb\u0001\u0000\u0000\u0000"+
		"\u00d5\u00cd\u0001\u0000\u0000\u0000\u00d6\u0015\u0001\u0000\u0000\u0000"+
		"\u00d7\u00d8\u0007\u0000\u0000\u0000\u00d8\u0017\u0001\u0000\u0000\u0000"+
		"\u00d9\u00da\u0007\u0001\u0000\u0000\u00da\u0019\u0001\u0000\u0000\u0000"+
		"\u00db\u00e0\u0005-\u0000\u0000\u00dc\u00dd\u0005-\u0000\u0000\u00dd\u00de"+
		"\u0005\u0002\u0000\u0000\u00de\u00e0\u0005-\u0000\u0000\u00df\u00db\u0001"+
		"\u0000\u0000\u0000\u00df\u00dc\u0001\u0000\u0000\u0000\u00e0\u001b\u0001"+
		"\u0000\u0000\u0000\u00e1\u00e6\u0003\u001e\u000f\u0000\u00e2\u00e3\u0005"+
		"\u0005\u0000\u0000\u00e3\u00e5\u0003\u001e\u000f\u0000\u00e4\u00e2\u0001"+
		"\u0000\u0000\u0000\u00e5\u00e8\u0001\u0000\u0000\u0000\u00e6\u00e4\u0001"+
		"\u0000\u0000\u0000\u00e6\u00e7\u0001\u0000\u0000\u0000\u00e7\u001d\u0001"+
		"\u0000\u0000\u0000\u00e8\u00e6\u0001\u0000\u0000\u0000\u00e9\u00ea\u0005"+
		"-\u0000\u0000\u00ea\u00eb\u0005\u0006\u0000\u0000\u00eb\u00ec\u0003\""+
		"\u0011\u0000\u00ec\u00ed\u0005\u0007\u0000\u0000\u00ed\u001f\u0001\u0000"+
		"\u0000\u0000\u00ee\u00f1\u0001\u0000\u0000\u0000\u00ef\u00f1\u0003\"\u0011"+
		"\u0000\u00f0\u00ee\u0001\u0000\u0000\u0000\u00f0\u00ef\u0001\u0000\u0000"+
		"\u0000\u00f1!\u0001\u0000\u0000\u0000\u00f2\u00f5\u0005.\u0000\u0000\u00f3"+
		"\u00f5\u0003B!\u0000\u00f4\u00f2\u0001\u0000\u0000\u0000\u00f4\u00f3\u0001"+
		"\u0000\u0000\u0000\u00f5#\u0001\u0000\u0000\u0000\u00f6\u00fb\u0003&\u0013"+
		"\u0000\u00f7\u00f8\u0005\u0005\u0000\u0000\u00f8\u00fa\u0003&\u0013\u0000"+
		"\u00f9\u00f7\u0001\u0000\u0000\u0000\u00fa\u00fd\u0001\u0000\u0000\u0000"+
		"\u00fb\u00f9\u0001\u0000\u0000\u0000\u00fb\u00fc\u0001\u0000\u0000\u0000"+
		"\u00fc%\u0001\u0000\u0000\u0000\u00fd\u00fb\u0001\u0000\u0000\u0000\u00fe"+
		"\u00ff\u0003J%\u0000\u00ff\u0100\u0005\f\u0000\u0000\u0100\u0101\u0003"+
		"\u0010\b\u0000\u0101\'\u0001\u0000\u0000\u0000\u0102\u0107\u0003*\u0015"+
		"\u0000\u0103\u0104\u0005\u0005\u0000\u0000\u0104\u0106\u0003*\u0015\u0000"+
		"\u0105\u0103\u0001\u0000\u0000\u0000\u0106\u0109\u0001\u0000\u0000\u0000"+
		"\u0107\u0105\u0001\u0000\u0000\u0000\u0107\u0108\u0001\u0000\u0000\u0000"+
		"\u0108)\u0001\u0000\u0000\u0000\u0109\u0107\u0001\u0000\u0000\u0000\u010a"+
		"\u010b\u0003\u001c\u000e\u0000\u010b\u010c\u0005\f\u0000\u0000\u010c\u010d"+
		"\u0003\u0010\b\u0000\u010d+\u0001\u0000\u0000\u0000\u010e\u0114\u0001"+
		"\u0000\u0000\u0000\u010f\u0110\u0005\n\u0000\u0000\u0110\u0111\u00032"+
		"\u0019\u0000\u0111\u0112\u0005\u000b\u0000\u0000\u0112\u0114\u0001\u0000"+
		"\u0000\u0000\u0113\u010e\u0001\u0000\u0000\u0000\u0113\u010f\u0001\u0000"+
		"\u0000\u0000\u0114-\u0001\u0000\u0000\u0000\u0115\u011c\u0001\u0000\u0000"+
		"\u0000\u0116\u0117\u0005\"\u0000\u0000\u0117\u0118\u0005\n\u0000\u0000"+
		"\u0118\u0119\u00032\u0019\u0000\u0119\u011a\u0005\u000b\u0000\u0000\u011a"+
		"\u011c\u0001\u0000\u0000\u0000\u011b\u0115\u0001\u0000\u0000\u0000\u011b"+
		"\u0116\u0001\u0000\u0000\u0000\u011c/\u0001\u0000\u0000\u0000\u011d\u0124"+
		"\u0001\u0000\u0000\u0000\u011e\u011f\u0005!\u0000\u0000\u011f\u0120\u0005"+
		"\n\u0000\u0000\u0120\u0121\u0003J%\u0000\u0121\u0122\u0005\u000b\u0000"+
		"\u0000\u0122\u0124\u0001\u0000\u0000\u0000\u0123\u011d\u0001\u0000\u0000"+
		"\u0000\u0123\u011e\u0001\u0000\u0000\u0000\u01241\u0001\u0000\u0000\u0000"+
		"\u0125\u012a\u00034\u001a\u0000\u0126\u0127\u0005\u0005\u0000\u0000\u0127"+
		"\u0129\u00034\u001a\u0000\u0128\u0126\u0001\u0000\u0000\u0000\u0129\u012c"+
		"\u0001\u0000\u0000\u0000\u012a\u0128\u0001\u0000\u0000\u0000\u012a\u012b"+
		"\u0001\u0000\u0000\u0000\u012b3\u0001\u0000\u0000\u0000\u012c\u012a\u0001"+
		"\u0000\u0000\u0000\u012d\u012e\u0003J%\u0000\u012e\u012f\u0005\u0003\u0000"+
		"\u0000\u012f\u0130\u0003\u0010\b\u0000\u01305\u0001\u0000\u0000\u0000"+
		"\u0131\u0136\u0003:\u001d\u0000\u0132\u0133\u0005\u0005\u0000\u0000\u0133"+
		"\u0135\u0003:\u001d\u0000\u0134\u0132\u0001\u0000\u0000\u0000\u0135\u0138"+
		"\u0001\u0000\u0000\u0000\u0136\u0134\u0001\u0000\u0000\u0000\u0136\u0137"+
		"\u0001\u0000\u0000\u0000\u01377\u0001\u0000\u0000\u0000\u0138\u0136\u0001"+
		"\u0000\u0000\u0000\u0139\u013a\u0007\u0002\u0000\u0000\u013a9\u0001\u0000"+
		"\u0000\u0000\u013b\u013c\u0005-\u0000\u0000\u013c\u013d\u0005\u0006\u0000"+
		"\u0000\u013d\u013e\u0005.\u0000\u0000\u013e\u013f\u0005\r\u0000\u0000"+
		"\u013f\u0140\u0005.\u0000\u0000\u0140\u0141\u0005\u0007\u0000\u0000\u0141"+
		"\u0142\u0005\u0003\u0000\u0000\u0142\u0143\u00038\u001c\u0000\u0143;\u0001"+
		"\u0000\u0000\u0000\u0144\u0148\u0003>\u001f\u0000\u0145\u0148\u0003@ "+
		"\u0000\u0146\u0148\u0003B!\u0000\u0147\u0144\u0001\u0000\u0000\u0000\u0147"+
		"\u0145\u0001\u0000\u0000\u0000\u0147\u0146\u0001\u0000\u0000\u0000\u0148"+
		"=\u0001\u0000\u0000\u0000\u0149\u0150\u0005+\u0000\u0000\u014a\u0150\u0005"+
		",\u0000\u0000\u014b\u0150\u0005.\u0000\u0000\u014c\u014d\u0005\u000e\u0000"+
		"\u0000\u014d\u0150\u0005.\u0000\u0000\u014e\u0150\u0005/\u0000\u0000\u014f"+
		"\u0149\u0001\u0000\u0000\u0000\u014f\u014a\u0001\u0000\u0000\u0000\u014f"+
		"\u014b\u0001\u0000\u0000\u0000\u014f\u014c\u0001\u0000\u0000\u0000\u014f"+
		"\u014e\u0001\u0000\u0000\u0000\u0150?\u0001\u0000\u0000\u0000\u0151\u0152"+
		"\u0005\n\u0000\u0000\u0152\u0153\u0003D\"\u0000\u0153\u0154\u0005\u000b"+
		"\u0000\u0000\u0154\u015e\u0001\u0000\u0000\u0000\u0155\u0156\u0005\n\u0000"+
		"\u0000\u0156\u0157\u0003F#\u0000\u0157\u0158\u0005\u000b\u0000\u0000\u0158"+
		"\u015e\u0001\u0000\u0000\u0000\u0159\u015a\u0005\n\u0000\u0000\u015a\u015e"+
		"\u0005\u000b\u0000\u0000\u015b\u015c\u0005-\u0000\u0000\u015c\u015e\u0003"+
		"<\u001e\u0000\u015d\u0151\u0001\u0000\u0000\u0000\u015d\u0155\u0001\u0000"+
		"\u0000\u0000\u015d\u0159\u0001\u0000\u0000\u0000\u015d\u015b\u0001\u0000"+
		"\u0000\u0000\u015eA\u0001\u0000\u0000\u0000\u015f\u0164\u0005-\u0000\u0000"+
		"\u0160\u0161\u0005-\u0000\u0000\u0161\u0162\u0005\u0002\u0000\u0000\u0162"+
		"\u0164\u0005-\u0000\u0000\u0163\u015f\u0001\u0000\u0000\u0000\u0163\u0160"+
		"\u0001\u0000\u0000\u0000\u0164C\u0001\u0000\u0000\u0000\u0165\u016a\u0003"+
		"<\u001e\u0000\u0166\u0167\u0005\u0005\u0000\u0000\u0167\u0169\u0003<\u001e"+
		"\u0000\u0168\u0166\u0001\u0000\u0000\u0000\u0169\u016c\u0001\u0000\u0000"+
		"\u0000\u016a\u0168\u0001\u0000\u0000\u0000\u016a\u016b\u0001\u0000\u0000"+
		"\u0000\u016bE\u0001\u0000\u0000\u0000\u016c\u016a\u0001\u0000\u0000\u0000"+
		"\u016d\u0172\u0003H$\u0000\u016e\u016f\u0005\u0005\u0000\u0000\u016f\u0171"+
		"\u0003H$\u0000\u0170\u016e\u0001\u0000\u0000\u0000\u0171\u0174\u0001\u0000"+
		"\u0000\u0000\u0172\u0170\u0001\u0000\u0000\u0000\u0172\u0173\u0001\u0000"+
		"\u0000\u0000\u0173G\u0001\u0000\u0000\u0000\u0174\u0172\u0001\u0000\u0000"+
		"\u0000\u0175\u0176\u0003J%\u0000\u0176\u0177\u0005\u0003\u0000\u0000\u0177"+
		"\u0178\u0003<\u001e\u0000\u0178I\u0001\u0000\u0000\u0000\u0179\u017e\u0005"+
		"-\u0000\u0000\u017a\u017b\u0005\u0005\u0000\u0000\u017b\u017d\u0005-\u0000"+
		"\u0000\u017c\u017a\u0001\u0000\u0000\u0000\u017d\u0180\u0001\u0000\u0000"+
		"\u0000\u017e\u017c\u0001\u0000\u0000\u0000\u017e\u017f\u0001\u0000\u0000"+
		"\u0000\u017fK\u0001\u0000\u0000\u0000\u0180\u017e\u0001\u0000\u0000\u0000"+
		"\u001acjxz\u008a\u008f\u009b\u00d5\u00df\u00e6\u00f0\u00f4\u00fb\u0107"+
		"\u0113\u011b\u0123\u012a\u0136\u0147\u014f\u015d\u0163\u016a\u0172\u017e";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}