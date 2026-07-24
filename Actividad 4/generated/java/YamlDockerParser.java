// Generated from YamlDocker.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class YamlDockerParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		VERSION_KEY=1, SERVICES_KEY=2, NETWORKS_KEY=3, IMAGE_KEY=4, PORTS_KEY=5, 
		ENVIRONMENT_KEY=6, DRIVER_KEY=7, COLON=8, DASH=9, STRING=10, NUMBER=11, 
		NAME=12, NEWLINE=13, WS=14, COMMENT=15;
	public static final int
		RULE_document = 0, RULE_version_line = 1, RULE_services_block = 2, RULE_service_entry = 3, 
		RULE_service_prop = 4, RULE_image_prop = 5, RULE_ports_prop = 6, RULE_environment_prop = 7, 
		RULE_networks_ref_prop = 8, RULE_networks_block = 9, RULE_network_entry = 10, 
		RULE_network_prop = 11, RULE_list_item = 12, RULE_value = 13;
	private static String[] makeRuleNames() {
		return new String[] {
			"document", "version_line", "services_block", "service_entry", "service_prop", 
			"image_prop", "ports_prop", "environment_prop", "networks_ref_prop", 
			"networks_block", "network_entry", "network_prop", "list_item", "value"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'version'", "'services'", "'networks'", "'image'", "'ports'", 
			"'environment'", "'driver'", "':'", "'-'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "VERSION_KEY", "SERVICES_KEY", "NETWORKS_KEY", "IMAGE_KEY", "PORTS_KEY", 
			"ENVIRONMENT_KEY", "DRIVER_KEY", "COLON", "DASH", "STRING", "NUMBER", 
			"NAME", "NEWLINE", "WS", "COMMENT"
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
	public String getGrammarFileName() { return "YamlDocker.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public YamlDockerParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class DocumentContext extends ParserRuleContext {
		public TerminalNode EOF() { return getToken(YamlDockerParser.EOF, 0); }
		public List<TerminalNode> NEWLINE() { return getTokens(YamlDockerParser.NEWLINE); }
		public TerminalNode NEWLINE(int i) {
			return getToken(YamlDockerParser.NEWLINE, i);
		}
		public Version_lineContext version_line() {
			return getRuleContext(Version_lineContext.class,0);
		}
		public Services_blockContext services_block() {
			return getRuleContext(Services_blockContext.class,0);
		}
		public Networks_blockContext networks_block() {
			return getRuleContext(Networks_blockContext.class,0);
		}
		public DocumentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_document; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof YamlDockerListener ) ((YamlDockerListener)listener).enterDocument(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof YamlDockerListener ) ((YamlDockerListener)listener).exitDocument(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof YamlDockerVisitor ) return ((YamlDockerVisitor<? extends T>)visitor).visitDocument(this);
			else return visitor.visitChildren(this);
		}
	}

	public final DocumentContext document() throws RecognitionException {
		DocumentContext _localctx = new DocumentContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_document);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(31);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,0,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(28);
					match(NEWLINE);
					}
					} 
				}
				setState(33);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,0,_ctx);
			}
			setState(35);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==VERSION_KEY) {
				{
				setState(34);
				version_line();
				}
			}

			setState(38);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==SERVICES_KEY) {
				{
				setState(37);
				services_block();
				}
			}

			setState(41);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==NETWORKS_KEY) {
				{
				setState(40);
				networks_block();
				}
			}

			setState(46);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==NEWLINE) {
				{
				{
				setState(43);
				match(NEWLINE);
				}
				}
				setState(48);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(49);
			match(EOF);
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
	public static class Version_lineContext extends ParserRuleContext {
		public TerminalNode VERSION_KEY() { return getToken(YamlDockerParser.VERSION_KEY, 0); }
		public TerminalNode COLON() { return getToken(YamlDockerParser.COLON, 0); }
		public ValueContext value() {
			return getRuleContext(ValueContext.class,0);
		}
		public TerminalNode NEWLINE() { return getToken(YamlDockerParser.NEWLINE, 0); }
		public Version_lineContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_version_line; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof YamlDockerListener ) ((YamlDockerListener)listener).enterVersion_line(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof YamlDockerListener ) ((YamlDockerListener)listener).exitVersion_line(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof YamlDockerVisitor ) return ((YamlDockerVisitor<? extends T>)visitor).visitVersion_line(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Version_lineContext version_line() throws RecognitionException {
		Version_lineContext _localctx = new Version_lineContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_version_line);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(51);
			match(VERSION_KEY);
			setState(52);
			match(COLON);
			setState(53);
			value();
			setState(54);
			match(NEWLINE);
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
	public static class Services_blockContext extends ParserRuleContext {
		public TerminalNode SERVICES_KEY() { return getToken(YamlDockerParser.SERVICES_KEY, 0); }
		public TerminalNode COLON() { return getToken(YamlDockerParser.COLON, 0); }
		public TerminalNode NEWLINE() { return getToken(YamlDockerParser.NEWLINE, 0); }
		public List<Service_entryContext> service_entry() {
			return getRuleContexts(Service_entryContext.class);
		}
		public Service_entryContext service_entry(int i) {
			return getRuleContext(Service_entryContext.class,i);
		}
		public Services_blockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_services_block; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof YamlDockerListener ) ((YamlDockerListener)listener).enterServices_block(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof YamlDockerListener ) ((YamlDockerListener)listener).exitServices_block(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof YamlDockerVisitor ) return ((YamlDockerVisitor<? extends T>)visitor).visitServices_block(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Services_blockContext services_block() throws RecognitionException {
		Services_blockContext _localctx = new Services_blockContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_services_block);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(56);
			match(SERVICES_KEY);
			setState(57);
			match(COLON);
			setState(58);
			match(NEWLINE);
			setState(60); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(59);
				service_entry();
				}
				}
				setState(62); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( _la==NAME );
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
	public static class Service_entryContext extends ParserRuleContext {
		public TerminalNode NAME() { return getToken(YamlDockerParser.NAME, 0); }
		public TerminalNode COLON() { return getToken(YamlDockerParser.COLON, 0); }
		public TerminalNode NEWLINE() { return getToken(YamlDockerParser.NEWLINE, 0); }
		public List<Service_propContext> service_prop() {
			return getRuleContexts(Service_propContext.class);
		}
		public Service_propContext service_prop(int i) {
			return getRuleContext(Service_propContext.class,i);
		}
		public Service_entryContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_service_entry; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof YamlDockerListener ) ((YamlDockerListener)listener).enterService_entry(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof YamlDockerListener ) ((YamlDockerListener)listener).exitService_entry(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof YamlDockerVisitor ) return ((YamlDockerVisitor<? extends T>)visitor).visitService_entry(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Service_entryContext service_entry() throws RecognitionException {
		Service_entryContext _localctx = new Service_entryContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_service_entry);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(64);
			match(NAME);
			setState(65);
			match(COLON);
			setState(66);
			match(NEWLINE);
			setState(68); 
			_errHandler.sync(this);
			_alt = 1;
			do {
				switch (_alt) {
				case 1:
					{
					{
					setState(67);
					service_prop();
					}
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(70); 
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,6,_ctx);
			} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
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
	public static class Service_propContext extends ParserRuleContext {
		public Image_propContext image_prop() {
			return getRuleContext(Image_propContext.class,0);
		}
		public Ports_propContext ports_prop() {
			return getRuleContext(Ports_propContext.class,0);
		}
		public Environment_propContext environment_prop() {
			return getRuleContext(Environment_propContext.class,0);
		}
		public Networks_ref_propContext networks_ref_prop() {
			return getRuleContext(Networks_ref_propContext.class,0);
		}
		public Service_propContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_service_prop; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof YamlDockerListener ) ((YamlDockerListener)listener).enterService_prop(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof YamlDockerListener ) ((YamlDockerListener)listener).exitService_prop(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof YamlDockerVisitor ) return ((YamlDockerVisitor<? extends T>)visitor).visitService_prop(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Service_propContext service_prop() throws RecognitionException {
		Service_propContext _localctx = new Service_propContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_service_prop);
		try {
			setState(76);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case IMAGE_KEY:
				enterOuterAlt(_localctx, 1);
				{
				setState(72);
				image_prop();
				}
				break;
			case PORTS_KEY:
				enterOuterAlt(_localctx, 2);
				{
				setState(73);
				ports_prop();
				}
				break;
			case ENVIRONMENT_KEY:
				enterOuterAlt(_localctx, 3);
				{
				setState(74);
				environment_prop();
				}
				break;
			case NETWORKS_KEY:
				enterOuterAlt(_localctx, 4);
				{
				setState(75);
				networks_ref_prop();
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
	public static class Image_propContext extends ParserRuleContext {
		public TerminalNode IMAGE_KEY() { return getToken(YamlDockerParser.IMAGE_KEY, 0); }
		public TerminalNode COLON() { return getToken(YamlDockerParser.COLON, 0); }
		public ValueContext value() {
			return getRuleContext(ValueContext.class,0);
		}
		public TerminalNode NEWLINE() { return getToken(YamlDockerParser.NEWLINE, 0); }
		public Image_propContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_image_prop; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof YamlDockerListener ) ((YamlDockerListener)listener).enterImage_prop(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof YamlDockerListener ) ((YamlDockerListener)listener).exitImage_prop(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof YamlDockerVisitor ) return ((YamlDockerVisitor<? extends T>)visitor).visitImage_prop(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Image_propContext image_prop() throws RecognitionException {
		Image_propContext _localctx = new Image_propContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_image_prop);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(78);
			match(IMAGE_KEY);
			setState(79);
			match(COLON);
			setState(80);
			value();
			setState(81);
			match(NEWLINE);
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
	public static class Ports_propContext extends ParserRuleContext {
		public TerminalNode PORTS_KEY() { return getToken(YamlDockerParser.PORTS_KEY, 0); }
		public TerminalNode COLON() { return getToken(YamlDockerParser.COLON, 0); }
		public TerminalNode NEWLINE() { return getToken(YamlDockerParser.NEWLINE, 0); }
		public List<List_itemContext> list_item() {
			return getRuleContexts(List_itemContext.class);
		}
		public List_itemContext list_item(int i) {
			return getRuleContext(List_itemContext.class,i);
		}
		public Ports_propContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_ports_prop; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof YamlDockerListener ) ((YamlDockerListener)listener).enterPorts_prop(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof YamlDockerListener ) ((YamlDockerListener)listener).exitPorts_prop(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof YamlDockerVisitor ) return ((YamlDockerVisitor<? extends T>)visitor).visitPorts_prop(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Ports_propContext ports_prop() throws RecognitionException {
		Ports_propContext _localctx = new Ports_propContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_ports_prop);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(83);
			match(PORTS_KEY);
			setState(84);
			match(COLON);
			setState(85);
			match(NEWLINE);
			setState(87); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(86);
				list_item();
				}
				}
				setState(89); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( _la==DASH );
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
	public static class Environment_propContext extends ParserRuleContext {
		public TerminalNode ENVIRONMENT_KEY() { return getToken(YamlDockerParser.ENVIRONMENT_KEY, 0); }
		public TerminalNode COLON() { return getToken(YamlDockerParser.COLON, 0); }
		public TerminalNode NEWLINE() { return getToken(YamlDockerParser.NEWLINE, 0); }
		public List<List_itemContext> list_item() {
			return getRuleContexts(List_itemContext.class);
		}
		public List_itemContext list_item(int i) {
			return getRuleContext(List_itemContext.class,i);
		}
		public Environment_propContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_environment_prop; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof YamlDockerListener ) ((YamlDockerListener)listener).enterEnvironment_prop(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof YamlDockerListener ) ((YamlDockerListener)listener).exitEnvironment_prop(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof YamlDockerVisitor ) return ((YamlDockerVisitor<? extends T>)visitor).visitEnvironment_prop(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Environment_propContext environment_prop() throws RecognitionException {
		Environment_propContext _localctx = new Environment_propContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_environment_prop);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(91);
			match(ENVIRONMENT_KEY);
			setState(92);
			match(COLON);
			setState(93);
			match(NEWLINE);
			setState(95); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(94);
				list_item();
				}
				}
				setState(97); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( _la==DASH );
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
	public static class Networks_ref_propContext extends ParserRuleContext {
		public TerminalNode NETWORKS_KEY() { return getToken(YamlDockerParser.NETWORKS_KEY, 0); }
		public TerminalNode COLON() { return getToken(YamlDockerParser.COLON, 0); }
		public TerminalNode NEWLINE() { return getToken(YamlDockerParser.NEWLINE, 0); }
		public List<List_itemContext> list_item() {
			return getRuleContexts(List_itemContext.class);
		}
		public List_itemContext list_item(int i) {
			return getRuleContext(List_itemContext.class,i);
		}
		public Networks_ref_propContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_networks_ref_prop; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof YamlDockerListener ) ((YamlDockerListener)listener).enterNetworks_ref_prop(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof YamlDockerListener ) ((YamlDockerListener)listener).exitNetworks_ref_prop(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof YamlDockerVisitor ) return ((YamlDockerVisitor<? extends T>)visitor).visitNetworks_ref_prop(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Networks_ref_propContext networks_ref_prop() throws RecognitionException {
		Networks_ref_propContext _localctx = new Networks_ref_propContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_networks_ref_prop);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(99);
			match(NETWORKS_KEY);
			setState(100);
			match(COLON);
			setState(101);
			match(NEWLINE);
			setState(103); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(102);
				list_item();
				}
				}
				setState(105); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( _la==DASH );
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
	public static class Networks_blockContext extends ParserRuleContext {
		public TerminalNode NETWORKS_KEY() { return getToken(YamlDockerParser.NETWORKS_KEY, 0); }
		public TerminalNode COLON() { return getToken(YamlDockerParser.COLON, 0); }
		public TerminalNode NEWLINE() { return getToken(YamlDockerParser.NEWLINE, 0); }
		public List<Network_entryContext> network_entry() {
			return getRuleContexts(Network_entryContext.class);
		}
		public Network_entryContext network_entry(int i) {
			return getRuleContext(Network_entryContext.class,i);
		}
		public Networks_blockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_networks_block; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof YamlDockerListener ) ((YamlDockerListener)listener).enterNetworks_block(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof YamlDockerListener ) ((YamlDockerListener)listener).exitNetworks_block(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof YamlDockerVisitor ) return ((YamlDockerVisitor<? extends T>)visitor).visitNetworks_block(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Networks_blockContext networks_block() throws RecognitionException {
		Networks_blockContext _localctx = new Networks_blockContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_networks_block);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(107);
			match(NETWORKS_KEY);
			setState(108);
			match(COLON);
			setState(109);
			match(NEWLINE);
			setState(111); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(110);
				network_entry();
				}
				}
				setState(113); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( _la==NAME );
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
	public static class Network_entryContext extends ParserRuleContext {
		public TerminalNode NAME() { return getToken(YamlDockerParser.NAME, 0); }
		public TerminalNode COLON() { return getToken(YamlDockerParser.COLON, 0); }
		public TerminalNode NEWLINE() { return getToken(YamlDockerParser.NEWLINE, 0); }
		public List<Network_propContext> network_prop() {
			return getRuleContexts(Network_propContext.class);
		}
		public Network_propContext network_prop(int i) {
			return getRuleContext(Network_propContext.class,i);
		}
		public Network_entryContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_network_entry; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof YamlDockerListener ) ((YamlDockerListener)listener).enterNetwork_entry(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof YamlDockerListener ) ((YamlDockerListener)listener).exitNetwork_entry(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof YamlDockerVisitor ) return ((YamlDockerVisitor<? extends T>)visitor).visitNetwork_entry(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Network_entryContext network_entry() throws RecognitionException {
		Network_entryContext _localctx = new Network_entryContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_network_entry);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(115);
			match(NAME);
			setState(116);
			match(COLON);
			setState(117);
			match(NEWLINE);
			setState(121);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==DRIVER_KEY) {
				{
				{
				setState(118);
				network_prop();
				}
				}
				setState(123);
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
	public static class Network_propContext extends ParserRuleContext {
		public TerminalNode DRIVER_KEY() { return getToken(YamlDockerParser.DRIVER_KEY, 0); }
		public TerminalNode COLON() { return getToken(YamlDockerParser.COLON, 0); }
		public ValueContext value() {
			return getRuleContext(ValueContext.class,0);
		}
		public TerminalNode NEWLINE() { return getToken(YamlDockerParser.NEWLINE, 0); }
		public Network_propContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_network_prop; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof YamlDockerListener ) ((YamlDockerListener)listener).enterNetwork_prop(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof YamlDockerListener ) ((YamlDockerListener)listener).exitNetwork_prop(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof YamlDockerVisitor ) return ((YamlDockerVisitor<? extends T>)visitor).visitNetwork_prop(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Network_propContext network_prop() throws RecognitionException {
		Network_propContext _localctx = new Network_propContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_network_prop);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(124);
			match(DRIVER_KEY);
			setState(125);
			match(COLON);
			setState(126);
			value();
			setState(127);
			match(NEWLINE);
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
	public static class List_itemContext extends ParserRuleContext {
		public TerminalNode DASH() { return getToken(YamlDockerParser.DASH, 0); }
		public ValueContext value() {
			return getRuleContext(ValueContext.class,0);
		}
		public TerminalNode NEWLINE() { return getToken(YamlDockerParser.NEWLINE, 0); }
		public List_itemContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_list_item; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof YamlDockerListener ) ((YamlDockerListener)listener).enterList_item(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof YamlDockerListener ) ((YamlDockerListener)listener).exitList_item(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof YamlDockerVisitor ) return ((YamlDockerVisitor<? extends T>)visitor).visitList_item(this);
			else return visitor.visitChildren(this);
		}
	}

	public final List_itemContext list_item() throws RecognitionException {
		List_itemContext _localctx = new List_itemContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_list_item);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(129);
			match(DASH);
			setState(130);
			value();
			setState(131);
			match(NEWLINE);
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
	public static class ValueContext extends ParserRuleContext {
		public TerminalNode STRING() { return getToken(YamlDockerParser.STRING, 0); }
		public TerminalNode NUMBER() { return getToken(YamlDockerParser.NUMBER, 0); }
		public ValueContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_value; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof YamlDockerListener ) ((YamlDockerListener)listener).enterValue(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof YamlDockerListener ) ((YamlDockerListener)listener).exitValue(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof YamlDockerVisitor ) return ((YamlDockerVisitor<? extends T>)visitor).visitValue(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ValueContext value() throws RecognitionException {
		ValueContext _localctx = new ValueContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_value);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(133);
			_la = _input.LA(1);
			if ( !(_la==STRING || _la==NUMBER) ) {
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

	public static final String _serializedATN =
		"\u0004\u0001\u000f\u0088\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001"+
		"\u0002\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004"+
		"\u0002\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007"+
		"\u0002\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b"+
		"\u0002\f\u0007\f\u0002\r\u0007\r\u0001\u0000\u0005\u0000\u001e\b\u0000"+
		"\n\u0000\f\u0000!\t\u0000\u0001\u0000\u0003\u0000$\b\u0000\u0001\u0000"+
		"\u0003\u0000\'\b\u0000\u0001\u0000\u0003\u0000*\b\u0000\u0001\u0000\u0005"+
		"\u0000-\b\u0000\n\u0000\f\u00000\t\u0000\u0001\u0000\u0001\u0000\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0004\u0002=\b\u0002\u000b\u0002\f\u0002"+
		">\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0004\u0003E\b\u0003"+
		"\u000b\u0003\f\u0003F\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0003\u0004M\b\u0004\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0004\u0006"+
		"X\b\u0006\u000b\u0006\f\u0006Y\u0001\u0007\u0001\u0007\u0001\u0007\u0001"+
		"\u0007\u0004\u0007`\b\u0007\u000b\u0007\f\u0007a\u0001\b\u0001\b\u0001"+
		"\b\u0001\b\u0004\bh\b\b\u000b\b\f\bi\u0001\t\u0001\t\u0001\t\u0001\t\u0004"+
		"\tp\b\t\u000b\t\f\tq\u0001\n\u0001\n\u0001\n\u0001\n\u0005\nx\b\n\n\n"+
		"\f\n{\t\n\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b"+
		"\u0001\f\u0001\f\u0001\f\u0001\f\u0001\r\u0001\r\u0001\r\u0000\u0000\u000e"+
		"\u0000\u0002\u0004\u0006\b\n\f\u000e\u0010\u0012\u0014\u0016\u0018\u001a"+
		"\u0000\u0001\u0001\u0000\n\u000b\u0088\u0000\u001f\u0001\u0000\u0000\u0000"+
		"\u00023\u0001\u0000\u0000\u0000\u00048\u0001\u0000\u0000\u0000\u0006@"+
		"\u0001\u0000\u0000\u0000\bL\u0001\u0000\u0000\u0000\nN\u0001\u0000\u0000"+
		"\u0000\fS\u0001\u0000\u0000\u0000\u000e[\u0001\u0000\u0000\u0000\u0010"+
		"c\u0001\u0000\u0000\u0000\u0012k\u0001\u0000\u0000\u0000\u0014s\u0001"+
		"\u0000\u0000\u0000\u0016|\u0001\u0000\u0000\u0000\u0018\u0081\u0001\u0000"+
		"\u0000\u0000\u001a\u0085\u0001\u0000\u0000\u0000\u001c\u001e\u0005\r\u0000"+
		"\u0000\u001d\u001c\u0001\u0000\u0000\u0000\u001e!\u0001\u0000\u0000\u0000"+
		"\u001f\u001d\u0001\u0000\u0000\u0000\u001f \u0001\u0000\u0000\u0000 #"+
		"\u0001\u0000\u0000\u0000!\u001f\u0001\u0000\u0000\u0000\"$\u0003\u0002"+
		"\u0001\u0000#\"\u0001\u0000\u0000\u0000#$\u0001\u0000\u0000\u0000$&\u0001"+
		"\u0000\u0000\u0000%\'\u0003\u0004\u0002\u0000&%\u0001\u0000\u0000\u0000"+
		"&\'\u0001\u0000\u0000\u0000\')\u0001\u0000\u0000\u0000(*\u0003\u0012\t"+
		"\u0000)(\u0001\u0000\u0000\u0000)*\u0001\u0000\u0000\u0000*.\u0001\u0000"+
		"\u0000\u0000+-\u0005\r\u0000\u0000,+\u0001\u0000\u0000\u0000-0\u0001\u0000"+
		"\u0000\u0000.,\u0001\u0000\u0000\u0000./\u0001\u0000\u0000\u0000/1\u0001"+
		"\u0000\u0000\u00000.\u0001\u0000\u0000\u000012\u0005\u0000\u0000\u0001"+
		"2\u0001\u0001\u0000\u0000\u000034\u0005\u0001\u0000\u000045\u0005\b\u0000"+
		"\u000056\u0003\u001a\r\u000067\u0005\r\u0000\u00007\u0003\u0001\u0000"+
		"\u0000\u000089\u0005\u0002\u0000\u00009:\u0005\b\u0000\u0000:<\u0005\r"+
		"\u0000\u0000;=\u0003\u0006\u0003\u0000<;\u0001\u0000\u0000\u0000=>\u0001"+
		"\u0000\u0000\u0000><\u0001\u0000\u0000\u0000>?\u0001\u0000\u0000\u0000"+
		"?\u0005\u0001\u0000\u0000\u0000@A\u0005\f\u0000\u0000AB\u0005\b\u0000"+
		"\u0000BD\u0005\r\u0000\u0000CE\u0003\b\u0004\u0000DC\u0001\u0000\u0000"+
		"\u0000EF\u0001\u0000\u0000\u0000FD\u0001\u0000\u0000\u0000FG\u0001\u0000"+
		"\u0000\u0000G\u0007\u0001\u0000\u0000\u0000HM\u0003\n\u0005\u0000IM\u0003"+
		"\f\u0006\u0000JM\u0003\u000e\u0007\u0000KM\u0003\u0010\b\u0000LH\u0001"+
		"\u0000\u0000\u0000LI\u0001\u0000\u0000\u0000LJ\u0001\u0000\u0000\u0000"+
		"LK\u0001\u0000\u0000\u0000M\t\u0001\u0000\u0000\u0000NO\u0005\u0004\u0000"+
		"\u0000OP\u0005\b\u0000\u0000PQ\u0003\u001a\r\u0000QR\u0005\r\u0000\u0000"+
		"R\u000b\u0001\u0000\u0000\u0000ST\u0005\u0005\u0000\u0000TU\u0005\b\u0000"+
		"\u0000UW\u0005\r\u0000\u0000VX\u0003\u0018\f\u0000WV\u0001\u0000\u0000"+
		"\u0000XY\u0001\u0000\u0000\u0000YW\u0001\u0000\u0000\u0000YZ\u0001\u0000"+
		"\u0000\u0000Z\r\u0001\u0000\u0000\u0000[\\\u0005\u0006\u0000\u0000\\]"+
		"\u0005\b\u0000\u0000]_\u0005\r\u0000\u0000^`\u0003\u0018\f\u0000_^\u0001"+
		"\u0000\u0000\u0000`a\u0001\u0000\u0000\u0000a_\u0001\u0000\u0000\u0000"+
		"ab\u0001\u0000\u0000\u0000b\u000f\u0001\u0000\u0000\u0000cd\u0005\u0003"+
		"\u0000\u0000de\u0005\b\u0000\u0000eg\u0005\r\u0000\u0000fh\u0003\u0018"+
		"\f\u0000gf\u0001\u0000\u0000\u0000hi\u0001\u0000\u0000\u0000ig\u0001\u0000"+
		"\u0000\u0000ij\u0001\u0000\u0000\u0000j\u0011\u0001\u0000\u0000\u0000"+
		"kl\u0005\u0003\u0000\u0000lm\u0005\b\u0000\u0000mo\u0005\r\u0000\u0000"+
		"np\u0003\u0014\n\u0000on\u0001\u0000\u0000\u0000pq\u0001\u0000\u0000\u0000"+
		"qo\u0001\u0000\u0000\u0000qr\u0001\u0000\u0000\u0000r\u0013\u0001\u0000"+
		"\u0000\u0000st\u0005\f\u0000\u0000tu\u0005\b\u0000\u0000uy\u0005\r\u0000"+
		"\u0000vx\u0003\u0016\u000b\u0000wv\u0001\u0000\u0000\u0000x{\u0001\u0000"+
		"\u0000\u0000yw\u0001\u0000\u0000\u0000yz\u0001\u0000\u0000\u0000z\u0015"+
		"\u0001\u0000\u0000\u0000{y\u0001\u0000\u0000\u0000|}\u0005\u0007\u0000"+
		"\u0000}~\u0005\b\u0000\u0000~\u007f\u0003\u001a\r\u0000\u007f\u0080\u0005"+
		"\r\u0000\u0000\u0080\u0017\u0001\u0000\u0000\u0000\u0081\u0082\u0005\t"+
		"\u0000\u0000\u0082\u0083\u0003\u001a\r\u0000\u0083\u0084\u0005\r\u0000"+
		"\u0000\u0084\u0019\u0001\u0000\u0000\u0000\u0085\u0086\u0007\u0000\u0000"+
		"\u0000\u0086\u001b\u0001\u0000\u0000\u0000\r\u001f#&).>FLYaiqy";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}