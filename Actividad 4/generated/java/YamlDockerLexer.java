// Generated from YamlDocker.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue", "this-escape"})
public class YamlDockerLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		VERSION_KEY=1, SERVICES_KEY=2, NETWORKS_KEY=3, IMAGE_KEY=4, PORTS_KEY=5, 
		ENVIRONMENT_KEY=6, DRIVER_KEY=7, COLON=8, DASH=9, STRING=10, NUMBER=11, 
		NAME=12, NEWLINE=13, WS=14, COMMENT=15;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"VERSION_KEY", "SERVICES_KEY", "NETWORKS_KEY", "IMAGE_KEY", "PORTS_KEY", 
			"ENVIRONMENT_KEY", "DRIVER_KEY", "COLON", "DASH", "STRING", "NUMBER", 
			"NAME", "NEWLINE", "WS", "COMMENT"
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


	public YamlDockerLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "YamlDocker.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\u0004\u0000\u000f\u00a1\u0006\uffff\uffff\u0002\u0000\u0007\u0000\u0002"+
		"\u0001\u0007\u0001\u0002\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002"+
		"\u0004\u0007\u0004\u0002\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002"+
		"\u0007\u0007\u0007\u0002\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002"+
		"\u000b\u0007\u000b\u0002\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e"+
		"\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000"+
		"\u0001\u0000\u0001\u0000\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003"+
		"\u0001\u0003\u0001\u0003\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006"+
		"\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0007\u0001\u0007\u0001\b\u0001"+
		"\b\u0001\t\u0001\t\u0005\t_\b\t\n\t\f\tb\t\t\u0001\t\u0001\t\u0001\t\u0005"+
		"\tg\b\t\n\t\f\tj\t\t\u0001\t\u0001\t\u0001\t\u0001\t\u0004\tp\b\t\u000b"+
		"\t\f\tq\u0003\tt\b\t\u0001\n\u0004\nw\b\n\u000b\n\f\nx\u0001\n\u0001\n"+
		"\u0004\n}\b\n\u000b\n\f\n~\u0003\n\u0081\b\n\u0001\u000b\u0001\u000b\u0005"+
		"\u000b\u0085\b\u000b\n\u000b\f\u000b\u0088\t\u000b\u0001\f\u0003\f\u008b"+
		"\b\f\u0001\f\u0004\f\u008e\b\f\u000b\f\f\f\u008f\u0001\r\u0004\r\u0093"+
		"\b\r\u000b\r\f\r\u0094\u0001\r\u0001\r\u0001\u000e\u0001\u000e\u0005\u000e"+
		"\u009b\b\u000e\n\u000e\f\u000e\u009e\t\u000e\u0001\u000e\u0001\u000e\u0000"+
		"\u0000\u000f\u0001\u0001\u0003\u0002\u0005\u0003\u0007\u0004\t\u0005\u000b"+
		"\u0006\r\u0007\u000f\b\u0011\t\u0013\n\u0015\u000b\u0017\f\u0019\r\u001b"+
		"\u000e\u001d\u000f\u0001\u0000\t\u0003\u0000\n\n\r\r\"\"\u0003\u0000\n"+
		"\n\r\r\'\'\u0005\u0000\t\n\r\r  ##::\u0003\u0000\t\n\r\r  \u0001\u0000"+
		"09\u0003\u0000AZ__az\u0005\u0000-.09AZ__az\u0002\u0000\t\t  \u0002\u0000"+
		"\n\n\r\r\u00ae\u0000\u0001\u0001\u0000\u0000\u0000\u0000\u0003\u0001\u0000"+
		"\u0000\u0000\u0000\u0005\u0001\u0000\u0000\u0000\u0000\u0007\u0001\u0000"+
		"\u0000\u0000\u0000\t\u0001\u0000\u0000\u0000\u0000\u000b\u0001\u0000\u0000"+
		"\u0000\u0000\r\u0001\u0000\u0000\u0000\u0000\u000f\u0001\u0000\u0000\u0000"+
		"\u0000\u0011\u0001\u0000\u0000\u0000\u0000\u0013\u0001\u0000\u0000\u0000"+
		"\u0000\u0015\u0001\u0000\u0000\u0000\u0000\u0017\u0001\u0000\u0000\u0000"+
		"\u0000\u0019\u0001\u0000\u0000\u0000\u0000\u001b\u0001\u0000\u0000\u0000"+
		"\u0000\u001d\u0001\u0000\u0000\u0000\u0001\u001f\u0001\u0000\u0000\u0000"+
		"\u0003\'\u0001\u0000\u0000\u0000\u00050\u0001\u0000\u0000\u0000\u0007"+
		"9\u0001\u0000\u0000\u0000\t?\u0001\u0000\u0000\u0000\u000bE\u0001\u0000"+
		"\u0000\u0000\rQ\u0001\u0000\u0000\u0000\u000fX\u0001\u0000\u0000\u0000"+
		"\u0011Z\u0001\u0000\u0000\u0000\u0013s\u0001\u0000\u0000\u0000\u0015v"+
		"\u0001\u0000\u0000\u0000\u0017\u0082\u0001\u0000\u0000\u0000\u0019\u008d"+
		"\u0001\u0000\u0000\u0000\u001b\u0092\u0001\u0000\u0000\u0000\u001d\u0098"+
		"\u0001\u0000\u0000\u0000\u001f \u0005v\u0000\u0000 !\u0005e\u0000\u0000"+
		"!\"\u0005r\u0000\u0000\"#\u0005s\u0000\u0000#$\u0005i\u0000\u0000$%\u0005"+
		"o\u0000\u0000%&\u0005n\u0000\u0000&\u0002\u0001\u0000\u0000\u0000\'(\u0005"+
		"s\u0000\u0000()\u0005e\u0000\u0000)*\u0005r\u0000\u0000*+\u0005v\u0000"+
		"\u0000+,\u0005i\u0000\u0000,-\u0005c\u0000\u0000-.\u0005e\u0000\u0000"+
		"./\u0005s\u0000\u0000/\u0004\u0001\u0000\u0000\u000001\u0005n\u0000\u0000"+
		"12\u0005e\u0000\u000023\u0005t\u0000\u000034\u0005w\u0000\u000045\u0005"+
		"o\u0000\u000056\u0005r\u0000\u000067\u0005k\u0000\u000078\u0005s\u0000"+
		"\u00008\u0006\u0001\u0000\u0000\u00009:\u0005i\u0000\u0000:;\u0005m\u0000"+
		"\u0000;<\u0005a\u0000\u0000<=\u0005g\u0000\u0000=>\u0005e\u0000\u0000"+
		">\b\u0001\u0000\u0000\u0000?@\u0005p\u0000\u0000@A\u0005o\u0000\u0000"+
		"AB\u0005r\u0000\u0000BC\u0005t\u0000\u0000CD\u0005s\u0000\u0000D\n\u0001"+
		"\u0000\u0000\u0000EF\u0005e\u0000\u0000FG\u0005n\u0000\u0000GH\u0005v"+
		"\u0000\u0000HI\u0005i\u0000\u0000IJ\u0005r\u0000\u0000JK\u0005o\u0000"+
		"\u0000KL\u0005n\u0000\u0000LM\u0005m\u0000\u0000MN\u0005e\u0000\u0000"+
		"NO\u0005n\u0000\u0000OP\u0005t\u0000\u0000P\f\u0001\u0000\u0000\u0000"+
		"QR\u0005d\u0000\u0000RS\u0005r\u0000\u0000ST\u0005i\u0000\u0000TU\u0005"+
		"v\u0000\u0000UV\u0005e\u0000\u0000VW\u0005r\u0000\u0000W\u000e\u0001\u0000"+
		"\u0000\u0000XY\u0005:\u0000\u0000Y\u0010\u0001\u0000\u0000\u0000Z[\u0005"+
		"-\u0000\u0000[\u0012\u0001\u0000\u0000\u0000\\`\u0005\"\u0000\u0000]_"+
		"\b\u0000\u0000\u0000^]\u0001\u0000\u0000\u0000_b\u0001\u0000\u0000\u0000"+
		"`^\u0001\u0000\u0000\u0000`a\u0001\u0000\u0000\u0000ac\u0001\u0000\u0000"+
		"\u0000b`\u0001\u0000\u0000\u0000ct\u0005\"\u0000\u0000dh\u0005\'\u0000"+
		"\u0000eg\b\u0001\u0000\u0000fe\u0001\u0000\u0000\u0000gj\u0001\u0000\u0000"+
		"\u0000hf\u0001\u0000\u0000\u0000hi\u0001\u0000\u0000\u0000ik\u0001\u0000"+
		"\u0000\u0000jh\u0001\u0000\u0000\u0000kt\u0005\'\u0000\u0000lp\b\u0002"+
		"\u0000\u0000mn\u0005:\u0000\u0000np\b\u0003\u0000\u0000ol\u0001\u0000"+
		"\u0000\u0000om\u0001\u0000\u0000\u0000pq\u0001\u0000\u0000\u0000qo\u0001"+
		"\u0000\u0000\u0000qr\u0001\u0000\u0000\u0000rt\u0001\u0000\u0000\u0000"+
		"s\\\u0001\u0000\u0000\u0000sd\u0001\u0000\u0000\u0000so\u0001\u0000\u0000"+
		"\u0000t\u0014\u0001\u0000\u0000\u0000uw\u0007\u0004\u0000\u0000vu\u0001"+
		"\u0000\u0000\u0000wx\u0001\u0000\u0000\u0000xv\u0001\u0000\u0000\u0000"+
		"xy\u0001\u0000\u0000\u0000y\u0080\u0001\u0000\u0000\u0000z|\u0005.\u0000"+
		"\u0000{}\u0007\u0004\u0000\u0000|{\u0001\u0000\u0000\u0000}~\u0001\u0000"+
		"\u0000\u0000~|\u0001\u0000\u0000\u0000~\u007f\u0001\u0000\u0000\u0000"+
		"\u007f\u0081\u0001\u0000\u0000\u0000\u0080z\u0001\u0000\u0000\u0000\u0080"+
		"\u0081\u0001\u0000\u0000\u0000\u0081\u0016\u0001\u0000\u0000\u0000\u0082"+
		"\u0086\u0007\u0005\u0000\u0000\u0083\u0085\u0007\u0006\u0000\u0000\u0084"+
		"\u0083\u0001\u0000\u0000\u0000\u0085\u0088\u0001\u0000\u0000\u0000\u0086"+
		"\u0084\u0001\u0000\u0000\u0000\u0086\u0087\u0001\u0000\u0000\u0000\u0087"+
		"\u0018\u0001\u0000\u0000\u0000\u0088\u0086\u0001\u0000\u0000\u0000\u0089"+
		"\u008b\u0005\r\u0000\u0000\u008a\u0089\u0001\u0000\u0000\u0000\u008a\u008b"+
		"\u0001\u0000\u0000\u0000\u008b\u008c\u0001\u0000\u0000\u0000\u008c\u008e"+
		"\u0005\n\u0000\u0000\u008d\u008a\u0001\u0000\u0000\u0000\u008e\u008f\u0001"+
		"\u0000\u0000\u0000\u008f\u008d\u0001\u0000\u0000\u0000\u008f\u0090\u0001"+
		"\u0000\u0000\u0000\u0090\u001a\u0001\u0000\u0000\u0000\u0091\u0093\u0007"+
		"\u0007\u0000\u0000\u0092\u0091\u0001\u0000\u0000\u0000\u0093\u0094\u0001"+
		"\u0000\u0000\u0000\u0094\u0092\u0001\u0000\u0000\u0000\u0094\u0095\u0001"+
		"\u0000\u0000\u0000\u0095\u0096\u0001\u0000\u0000\u0000\u0096\u0097\u0006"+
		"\r\u0000\u0000\u0097\u001c\u0001\u0000\u0000\u0000\u0098\u009c\u0005#"+
		"\u0000\u0000\u0099\u009b\b\b\u0000\u0000\u009a\u0099\u0001\u0000\u0000"+
		"\u0000\u009b\u009e\u0001\u0000\u0000\u0000\u009c\u009a\u0001\u0000\u0000"+
		"\u0000\u009c\u009d\u0001\u0000\u0000\u0000\u009d\u009f\u0001\u0000\u0000"+
		"\u0000\u009e\u009c\u0001\u0000\u0000\u0000\u009f\u00a0\u0006\u000e\u0000"+
		"\u0000\u00a0\u001e\u0001\u0000\u0000\u0000\u000e\u0000`hoqsx~\u0080\u0086"+
		"\u008a\u008f\u0094\u009c\u0001\u0006\u0000\u0000";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}