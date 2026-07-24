
// Generated from YamlDocker.g4 by ANTLR 4.13.1


#include "YamlDockerListener.h"
#include "YamlDockerVisitor.h"

#include "YamlDockerParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct YamlDockerParserStaticData final {
  YamlDockerParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  YamlDockerParserStaticData(const YamlDockerParserStaticData&) = delete;
  YamlDockerParserStaticData(YamlDockerParserStaticData&&) = delete;
  YamlDockerParserStaticData& operator=(const YamlDockerParserStaticData&) = delete;
  YamlDockerParserStaticData& operator=(YamlDockerParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag yamldockerParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
YamlDockerParserStaticData *yamldockerParserStaticData = nullptr;

void yamldockerParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (yamldockerParserStaticData != nullptr) {
    return;
  }
#else
  assert(yamldockerParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<YamlDockerParserStaticData>(
    std::vector<std::string>{
      "document", "version_line", "services_block", "service_entry", "service_prop", 
      "image_prop", "ports_prop", "environment_prop", "networks_ref_prop", 
      "networks_block", "network_entry", "network_prop", "list_item", "value"
    },
    std::vector<std::string>{
      "", "'version'", "'services'", "'networks'", "'image'", "'ports'", 
      "'environment'", "'driver'", "':'", "'-'"
    },
    std::vector<std::string>{
      "", "VERSION_KEY", "SERVICES_KEY", "NETWORKS_KEY", "IMAGE_KEY", "PORTS_KEY", 
      "ENVIRONMENT_KEY", "DRIVER_KEY", "COLON", "DASH", "STRING", "NUMBER", 
      "NAME", "NEWLINE", "WS", "COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,15,136,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,1,0,5,0,
  	30,8,0,10,0,12,0,33,9,0,1,0,3,0,36,8,0,1,0,3,0,39,8,0,1,0,3,0,42,8,0,
  	1,0,5,0,45,8,0,10,0,12,0,48,9,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,
  	2,1,2,4,2,61,8,2,11,2,12,2,62,1,3,1,3,1,3,1,3,4,3,69,8,3,11,3,12,3,70,
  	1,4,1,4,1,4,1,4,3,4,77,8,4,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,4,6,88,
  	8,6,11,6,12,6,89,1,7,1,7,1,7,1,7,4,7,96,8,7,11,7,12,7,97,1,8,1,8,1,8,
  	1,8,4,8,104,8,8,11,8,12,8,105,1,9,1,9,1,9,1,9,4,9,112,8,9,11,9,12,9,113,
  	1,10,1,10,1,10,1,10,5,10,120,8,10,10,10,12,10,123,9,10,1,11,1,11,1,11,
  	1,11,1,11,1,12,1,12,1,12,1,12,1,13,1,13,1,13,0,0,14,0,2,4,6,8,10,12,14,
  	16,18,20,22,24,26,0,1,1,0,10,11,136,0,31,1,0,0,0,2,51,1,0,0,0,4,56,1,
  	0,0,0,6,64,1,0,0,0,8,76,1,0,0,0,10,78,1,0,0,0,12,83,1,0,0,0,14,91,1,0,
  	0,0,16,99,1,0,0,0,18,107,1,0,0,0,20,115,1,0,0,0,22,124,1,0,0,0,24,129,
  	1,0,0,0,26,133,1,0,0,0,28,30,5,13,0,0,29,28,1,0,0,0,30,33,1,0,0,0,31,
  	29,1,0,0,0,31,32,1,0,0,0,32,35,1,0,0,0,33,31,1,0,0,0,34,36,3,2,1,0,35,
  	34,1,0,0,0,35,36,1,0,0,0,36,38,1,0,0,0,37,39,3,4,2,0,38,37,1,0,0,0,38,
  	39,1,0,0,0,39,41,1,0,0,0,40,42,3,18,9,0,41,40,1,0,0,0,41,42,1,0,0,0,42,
  	46,1,0,0,0,43,45,5,13,0,0,44,43,1,0,0,0,45,48,1,0,0,0,46,44,1,0,0,0,46,
  	47,1,0,0,0,47,49,1,0,0,0,48,46,1,0,0,0,49,50,5,0,0,1,50,1,1,0,0,0,51,
  	52,5,1,0,0,52,53,5,8,0,0,53,54,3,26,13,0,54,55,5,13,0,0,55,3,1,0,0,0,
  	56,57,5,2,0,0,57,58,5,8,0,0,58,60,5,13,0,0,59,61,3,6,3,0,60,59,1,0,0,
  	0,61,62,1,0,0,0,62,60,1,0,0,0,62,63,1,0,0,0,63,5,1,0,0,0,64,65,5,12,0,
  	0,65,66,5,8,0,0,66,68,5,13,0,0,67,69,3,8,4,0,68,67,1,0,0,0,69,70,1,0,
  	0,0,70,68,1,0,0,0,70,71,1,0,0,0,71,7,1,0,0,0,72,77,3,10,5,0,73,77,3,12,
  	6,0,74,77,3,14,7,0,75,77,3,16,8,0,76,72,1,0,0,0,76,73,1,0,0,0,76,74,1,
  	0,0,0,76,75,1,0,0,0,77,9,1,0,0,0,78,79,5,4,0,0,79,80,5,8,0,0,80,81,3,
  	26,13,0,81,82,5,13,0,0,82,11,1,0,0,0,83,84,5,5,0,0,84,85,5,8,0,0,85,87,
  	5,13,0,0,86,88,3,24,12,0,87,86,1,0,0,0,88,89,1,0,0,0,89,87,1,0,0,0,89,
  	90,1,0,0,0,90,13,1,0,0,0,91,92,5,6,0,0,92,93,5,8,0,0,93,95,5,13,0,0,94,
  	96,3,24,12,0,95,94,1,0,0,0,96,97,1,0,0,0,97,95,1,0,0,0,97,98,1,0,0,0,
  	98,15,1,0,0,0,99,100,5,3,0,0,100,101,5,8,0,0,101,103,5,13,0,0,102,104,
  	3,24,12,0,103,102,1,0,0,0,104,105,1,0,0,0,105,103,1,0,0,0,105,106,1,0,
  	0,0,106,17,1,0,0,0,107,108,5,3,0,0,108,109,5,8,0,0,109,111,5,13,0,0,110,
  	112,3,20,10,0,111,110,1,0,0,0,112,113,1,0,0,0,113,111,1,0,0,0,113,114,
  	1,0,0,0,114,19,1,0,0,0,115,116,5,12,0,0,116,117,5,8,0,0,117,121,5,13,
  	0,0,118,120,3,22,11,0,119,118,1,0,0,0,120,123,1,0,0,0,121,119,1,0,0,0,
  	121,122,1,0,0,0,122,21,1,0,0,0,123,121,1,0,0,0,124,125,5,7,0,0,125,126,
  	5,8,0,0,126,127,3,26,13,0,127,128,5,13,0,0,128,23,1,0,0,0,129,130,5,9,
  	0,0,130,131,3,26,13,0,131,132,5,13,0,0,132,25,1,0,0,0,133,134,7,0,0,0,
  	134,27,1,0,0,0,13,31,35,38,41,46,62,70,76,89,97,105,113,121
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  yamldockerParserStaticData = staticData.release();
}

}

YamlDockerParser::YamlDockerParser(TokenStream *input) : YamlDockerParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

YamlDockerParser::YamlDockerParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  YamlDockerParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *yamldockerParserStaticData->atn, yamldockerParserStaticData->decisionToDFA, yamldockerParserStaticData->sharedContextCache, options);
}

YamlDockerParser::~YamlDockerParser() {
  delete _interpreter;
}

const atn::ATN& YamlDockerParser::getATN() const {
  return *yamldockerParserStaticData->atn;
}

std::string YamlDockerParser::getGrammarFileName() const {
  return "YamlDocker.g4";
}

const std::vector<std::string>& YamlDockerParser::getRuleNames() const {
  return yamldockerParserStaticData->ruleNames;
}

const dfa::Vocabulary& YamlDockerParser::getVocabulary() const {
  return yamldockerParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView YamlDockerParser::getSerializedATN() const {
  return yamldockerParserStaticData->serializedATN;
}


//----------------- DocumentContext ------------------------------------------------------------------

YamlDockerParser::DocumentContext::DocumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* YamlDockerParser::DocumentContext::EOF() {
  return getToken(YamlDockerParser::EOF, 0);
}

std::vector<tree::TerminalNode *> YamlDockerParser::DocumentContext::NEWLINE() {
  return getTokens(YamlDockerParser::NEWLINE);
}

tree::TerminalNode* YamlDockerParser::DocumentContext::NEWLINE(size_t i) {
  return getToken(YamlDockerParser::NEWLINE, i);
}

YamlDockerParser::Version_lineContext* YamlDockerParser::DocumentContext::version_line() {
  return getRuleContext<YamlDockerParser::Version_lineContext>(0);
}

YamlDockerParser::Services_blockContext* YamlDockerParser::DocumentContext::services_block() {
  return getRuleContext<YamlDockerParser::Services_blockContext>(0);
}

YamlDockerParser::Networks_blockContext* YamlDockerParser::DocumentContext::networks_block() {
  return getRuleContext<YamlDockerParser::Networks_blockContext>(0);
}


size_t YamlDockerParser::DocumentContext::getRuleIndex() const {
  return YamlDockerParser::RuleDocument;
}

void YamlDockerParser::DocumentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YamlDockerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDocument(this);
}

void YamlDockerParser::DocumentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YamlDockerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDocument(this);
}


std::any YamlDockerParser::DocumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<YamlDockerVisitor*>(visitor))
    return parserVisitor->visitDocument(this);
  else
    return visitor->visitChildren(this);
}

YamlDockerParser::DocumentContext* YamlDockerParser::document() {
  DocumentContext *_localctx = _tracker.createInstance<DocumentContext>(_ctx, getState());
  enterRule(_localctx, 0, YamlDockerParser::RuleDocument);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(31);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(28);
        match(YamlDockerParser::NEWLINE); 
      }
      setState(33);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
    setState(35);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == YamlDockerParser::VERSION_KEY) {
      setState(34);
      version_line();
    }
    setState(38);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == YamlDockerParser::SERVICES_KEY) {
      setState(37);
      services_block();
    }
    setState(41);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == YamlDockerParser::NETWORKS_KEY) {
      setState(40);
      networks_block();
    }
    setState(46);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == YamlDockerParser::NEWLINE) {
      setState(43);
      match(YamlDockerParser::NEWLINE);
      setState(48);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(49);
    match(YamlDockerParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Version_lineContext ------------------------------------------------------------------

YamlDockerParser::Version_lineContext::Version_lineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* YamlDockerParser::Version_lineContext::VERSION_KEY() {
  return getToken(YamlDockerParser::VERSION_KEY, 0);
}

tree::TerminalNode* YamlDockerParser::Version_lineContext::COLON() {
  return getToken(YamlDockerParser::COLON, 0);
}

YamlDockerParser::ValueContext* YamlDockerParser::Version_lineContext::value() {
  return getRuleContext<YamlDockerParser::ValueContext>(0);
}

tree::TerminalNode* YamlDockerParser::Version_lineContext::NEWLINE() {
  return getToken(YamlDockerParser::NEWLINE, 0);
}


size_t YamlDockerParser::Version_lineContext::getRuleIndex() const {
  return YamlDockerParser::RuleVersion_line;
}

void YamlDockerParser::Version_lineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YamlDockerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVersion_line(this);
}

void YamlDockerParser::Version_lineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YamlDockerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVersion_line(this);
}


std::any YamlDockerParser::Version_lineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<YamlDockerVisitor*>(visitor))
    return parserVisitor->visitVersion_line(this);
  else
    return visitor->visitChildren(this);
}

YamlDockerParser::Version_lineContext* YamlDockerParser::version_line() {
  Version_lineContext *_localctx = _tracker.createInstance<Version_lineContext>(_ctx, getState());
  enterRule(_localctx, 2, YamlDockerParser::RuleVersion_line);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(51);
    match(YamlDockerParser::VERSION_KEY);
    setState(52);
    match(YamlDockerParser::COLON);
    setState(53);
    value();
    setState(54);
    match(YamlDockerParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Services_blockContext ------------------------------------------------------------------

YamlDockerParser::Services_blockContext::Services_blockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* YamlDockerParser::Services_blockContext::SERVICES_KEY() {
  return getToken(YamlDockerParser::SERVICES_KEY, 0);
}

tree::TerminalNode* YamlDockerParser::Services_blockContext::COLON() {
  return getToken(YamlDockerParser::COLON, 0);
}

tree::TerminalNode* YamlDockerParser::Services_blockContext::NEWLINE() {
  return getToken(YamlDockerParser::NEWLINE, 0);
}

std::vector<YamlDockerParser::Service_entryContext *> YamlDockerParser::Services_blockContext::service_entry() {
  return getRuleContexts<YamlDockerParser::Service_entryContext>();
}

YamlDockerParser::Service_entryContext* YamlDockerParser::Services_blockContext::service_entry(size_t i) {
  return getRuleContext<YamlDockerParser::Service_entryContext>(i);
}


size_t YamlDockerParser::Services_blockContext::getRuleIndex() const {
  return YamlDockerParser::RuleServices_block;
}

void YamlDockerParser::Services_blockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YamlDockerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterServices_block(this);
}

void YamlDockerParser::Services_blockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YamlDockerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitServices_block(this);
}


std::any YamlDockerParser::Services_blockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<YamlDockerVisitor*>(visitor))
    return parserVisitor->visitServices_block(this);
  else
    return visitor->visitChildren(this);
}

YamlDockerParser::Services_blockContext* YamlDockerParser::services_block() {
  Services_blockContext *_localctx = _tracker.createInstance<Services_blockContext>(_ctx, getState());
  enterRule(_localctx, 4, YamlDockerParser::RuleServices_block);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(56);
    match(YamlDockerParser::SERVICES_KEY);
    setState(57);
    match(YamlDockerParser::COLON);
    setState(58);
    match(YamlDockerParser::NEWLINE);
    setState(60); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(59);
      service_entry();
      setState(62); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == YamlDockerParser::NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Service_entryContext ------------------------------------------------------------------

YamlDockerParser::Service_entryContext::Service_entryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* YamlDockerParser::Service_entryContext::NAME() {
  return getToken(YamlDockerParser::NAME, 0);
}

tree::TerminalNode* YamlDockerParser::Service_entryContext::COLON() {
  return getToken(YamlDockerParser::COLON, 0);
}

tree::TerminalNode* YamlDockerParser::Service_entryContext::NEWLINE() {
  return getToken(YamlDockerParser::NEWLINE, 0);
}

std::vector<YamlDockerParser::Service_propContext *> YamlDockerParser::Service_entryContext::service_prop() {
  return getRuleContexts<YamlDockerParser::Service_propContext>();
}

YamlDockerParser::Service_propContext* YamlDockerParser::Service_entryContext::service_prop(size_t i) {
  return getRuleContext<YamlDockerParser::Service_propContext>(i);
}


size_t YamlDockerParser::Service_entryContext::getRuleIndex() const {
  return YamlDockerParser::RuleService_entry;
}

void YamlDockerParser::Service_entryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YamlDockerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterService_entry(this);
}

void YamlDockerParser::Service_entryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YamlDockerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitService_entry(this);
}


std::any YamlDockerParser::Service_entryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<YamlDockerVisitor*>(visitor))
    return parserVisitor->visitService_entry(this);
  else
    return visitor->visitChildren(this);
}

YamlDockerParser::Service_entryContext* YamlDockerParser::service_entry() {
  Service_entryContext *_localctx = _tracker.createInstance<Service_entryContext>(_ctx, getState());
  enterRule(_localctx, 6, YamlDockerParser::RuleService_entry);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(64);
    match(YamlDockerParser::NAME);
    setState(65);
    match(YamlDockerParser::COLON);
    setState(66);
    match(YamlDockerParser::NEWLINE);
    setState(68); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(67);
              service_prop();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(70); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Service_propContext ------------------------------------------------------------------

YamlDockerParser::Service_propContext::Service_propContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YamlDockerParser::Image_propContext* YamlDockerParser::Service_propContext::image_prop() {
  return getRuleContext<YamlDockerParser::Image_propContext>(0);
}

YamlDockerParser::Ports_propContext* YamlDockerParser::Service_propContext::ports_prop() {
  return getRuleContext<YamlDockerParser::Ports_propContext>(0);
}

YamlDockerParser::Environment_propContext* YamlDockerParser::Service_propContext::environment_prop() {
  return getRuleContext<YamlDockerParser::Environment_propContext>(0);
}

YamlDockerParser::Networks_ref_propContext* YamlDockerParser::Service_propContext::networks_ref_prop() {
  return getRuleContext<YamlDockerParser::Networks_ref_propContext>(0);
}


size_t YamlDockerParser::Service_propContext::getRuleIndex() const {
  return YamlDockerParser::RuleService_prop;
}

void YamlDockerParser::Service_propContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YamlDockerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterService_prop(this);
}

void YamlDockerParser::Service_propContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YamlDockerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitService_prop(this);
}


std::any YamlDockerParser::Service_propContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<YamlDockerVisitor*>(visitor))
    return parserVisitor->visitService_prop(this);
  else
    return visitor->visitChildren(this);
}

YamlDockerParser::Service_propContext* YamlDockerParser::service_prop() {
  Service_propContext *_localctx = _tracker.createInstance<Service_propContext>(_ctx, getState());
  enterRule(_localctx, 8, YamlDockerParser::RuleService_prop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(76);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case YamlDockerParser::IMAGE_KEY: {
        enterOuterAlt(_localctx, 1);
        setState(72);
        image_prop();
        break;
      }

      case YamlDockerParser::PORTS_KEY: {
        enterOuterAlt(_localctx, 2);
        setState(73);
        ports_prop();
        break;
      }

      case YamlDockerParser::ENVIRONMENT_KEY: {
        enterOuterAlt(_localctx, 3);
        setState(74);
        environment_prop();
        break;
      }

      case YamlDockerParser::NETWORKS_KEY: {
        enterOuterAlt(_localctx, 4);
        setState(75);
        networks_ref_prop();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Image_propContext ------------------------------------------------------------------

YamlDockerParser::Image_propContext::Image_propContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* YamlDockerParser::Image_propContext::IMAGE_KEY() {
  return getToken(YamlDockerParser::IMAGE_KEY, 0);
}

tree::TerminalNode* YamlDockerParser::Image_propContext::COLON() {
  return getToken(YamlDockerParser::COLON, 0);
}

YamlDockerParser::ValueContext* YamlDockerParser::Image_propContext::value() {
  return getRuleContext<YamlDockerParser::ValueContext>(0);
}

tree::TerminalNode* YamlDockerParser::Image_propContext::NEWLINE() {
  return getToken(YamlDockerParser::NEWLINE, 0);
}


size_t YamlDockerParser::Image_propContext::getRuleIndex() const {
  return YamlDockerParser::RuleImage_prop;
}

void YamlDockerParser::Image_propContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YamlDockerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImage_prop(this);
}

void YamlDockerParser::Image_propContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YamlDockerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImage_prop(this);
}


std::any YamlDockerParser::Image_propContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<YamlDockerVisitor*>(visitor))
    return parserVisitor->visitImage_prop(this);
  else
    return visitor->visitChildren(this);
}

YamlDockerParser::Image_propContext* YamlDockerParser::image_prop() {
  Image_propContext *_localctx = _tracker.createInstance<Image_propContext>(_ctx, getState());
  enterRule(_localctx, 10, YamlDockerParser::RuleImage_prop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(78);
    match(YamlDockerParser::IMAGE_KEY);
    setState(79);
    match(YamlDockerParser::COLON);
    setState(80);
    value();
    setState(81);
    match(YamlDockerParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Ports_propContext ------------------------------------------------------------------

YamlDockerParser::Ports_propContext::Ports_propContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* YamlDockerParser::Ports_propContext::PORTS_KEY() {
  return getToken(YamlDockerParser::PORTS_KEY, 0);
}

tree::TerminalNode* YamlDockerParser::Ports_propContext::COLON() {
  return getToken(YamlDockerParser::COLON, 0);
}

tree::TerminalNode* YamlDockerParser::Ports_propContext::NEWLINE() {
  return getToken(YamlDockerParser::NEWLINE, 0);
}

std::vector<YamlDockerParser::List_itemContext *> YamlDockerParser::Ports_propContext::list_item() {
  return getRuleContexts<YamlDockerParser::List_itemContext>();
}

YamlDockerParser::List_itemContext* YamlDockerParser::Ports_propContext::list_item(size_t i) {
  return getRuleContext<YamlDockerParser::List_itemContext>(i);
}


size_t YamlDockerParser::Ports_propContext::getRuleIndex() const {
  return YamlDockerParser::RulePorts_prop;
}

void YamlDockerParser::Ports_propContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YamlDockerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPorts_prop(this);
}

void YamlDockerParser::Ports_propContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YamlDockerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPorts_prop(this);
}


std::any YamlDockerParser::Ports_propContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<YamlDockerVisitor*>(visitor))
    return parserVisitor->visitPorts_prop(this);
  else
    return visitor->visitChildren(this);
}

YamlDockerParser::Ports_propContext* YamlDockerParser::ports_prop() {
  Ports_propContext *_localctx = _tracker.createInstance<Ports_propContext>(_ctx, getState());
  enterRule(_localctx, 12, YamlDockerParser::RulePorts_prop);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(83);
    match(YamlDockerParser::PORTS_KEY);
    setState(84);
    match(YamlDockerParser::COLON);
    setState(85);
    match(YamlDockerParser::NEWLINE);
    setState(87); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(86);
      list_item();
      setState(89); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == YamlDockerParser::DASH);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Environment_propContext ------------------------------------------------------------------

YamlDockerParser::Environment_propContext::Environment_propContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* YamlDockerParser::Environment_propContext::ENVIRONMENT_KEY() {
  return getToken(YamlDockerParser::ENVIRONMENT_KEY, 0);
}

tree::TerminalNode* YamlDockerParser::Environment_propContext::COLON() {
  return getToken(YamlDockerParser::COLON, 0);
}

tree::TerminalNode* YamlDockerParser::Environment_propContext::NEWLINE() {
  return getToken(YamlDockerParser::NEWLINE, 0);
}

std::vector<YamlDockerParser::List_itemContext *> YamlDockerParser::Environment_propContext::list_item() {
  return getRuleContexts<YamlDockerParser::List_itemContext>();
}

YamlDockerParser::List_itemContext* YamlDockerParser::Environment_propContext::list_item(size_t i) {
  return getRuleContext<YamlDockerParser::List_itemContext>(i);
}


size_t YamlDockerParser::Environment_propContext::getRuleIndex() const {
  return YamlDockerParser::RuleEnvironment_prop;
}

void YamlDockerParser::Environment_propContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YamlDockerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnvironment_prop(this);
}

void YamlDockerParser::Environment_propContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YamlDockerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnvironment_prop(this);
}


std::any YamlDockerParser::Environment_propContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<YamlDockerVisitor*>(visitor))
    return parserVisitor->visitEnvironment_prop(this);
  else
    return visitor->visitChildren(this);
}

YamlDockerParser::Environment_propContext* YamlDockerParser::environment_prop() {
  Environment_propContext *_localctx = _tracker.createInstance<Environment_propContext>(_ctx, getState());
  enterRule(_localctx, 14, YamlDockerParser::RuleEnvironment_prop);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(91);
    match(YamlDockerParser::ENVIRONMENT_KEY);
    setState(92);
    match(YamlDockerParser::COLON);
    setState(93);
    match(YamlDockerParser::NEWLINE);
    setState(95); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(94);
      list_item();
      setState(97); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == YamlDockerParser::DASH);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Networks_ref_propContext ------------------------------------------------------------------

YamlDockerParser::Networks_ref_propContext::Networks_ref_propContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* YamlDockerParser::Networks_ref_propContext::NETWORKS_KEY() {
  return getToken(YamlDockerParser::NETWORKS_KEY, 0);
}

tree::TerminalNode* YamlDockerParser::Networks_ref_propContext::COLON() {
  return getToken(YamlDockerParser::COLON, 0);
}

tree::TerminalNode* YamlDockerParser::Networks_ref_propContext::NEWLINE() {
  return getToken(YamlDockerParser::NEWLINE, 0);
}

std::vector<YamlDockerParser::List_itemContext *> YamlDockerParser::Networks_ref_propContext::list_item() {
  return getRuleContexts<YamlDockerParser::List_itemContext>();
}

YamlDockerParser::List_itemContext* YamlDockerParser::Networks_ref_propContext::list_item(size_t i) {
  return getRuleContext<YamlDockerParser::List_itemContext>(i);
}


size_t YamlDockerParser::Networks_ref_propContext::getRuleIndex() const {
  return YamlDockerParser::RuleNetworks_ref_prop;
}

void YamlDockerParser::Networks_ref_propContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YamlDockerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNetworks_ref_prop(this);
}

void YamlDockerParser::Networks_ref_propContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YamlDockerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNetworks_ref_prop(this);
}


std::any YamlDockerParser::Networks_ref_propContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<YamlDockerVisitor*>(visitor))
    return parserVisitor->visitNetworks_ref_prop(this);
  else
    return visitor->visitChildren(this);
}

YamlDockerParser::Networks_ref_propContext* YamlDockerParser::networks_ref_prop() {
  Networks_ref_propContext *_localctx = _tracker.createInstance<Networks_ref_propContext>(_ctx, getState());
  enterRule(_localctx, 16, YamlDockerParser::RuleNetworks_ref_prop);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(99);
    match(YamlDockerParser::NETWORKS_KEY);
    setState(100);
    match(YamlDockerParser::COLON);
    setState(101);
    match(YamlDockerParser::NEWLINE);
    setState(103); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(102);
      list_item();
      setState(105); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == YamlDockerParser::DASH);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Networks_blockContext ------------------------------------------------------------------

YamlDockerParser::Networks_blockContext::Networks_blockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* YamlDockerParser::Networks_blockContext::NETWORKS_KEY() {
  return getToken(YamlDockerParser::NETWORKS_KEY, 0);
}

tree::TerminalNode* YamlDockerParser::Networks_blockContext::COLON() {
  return getToken(YamlDockerParser::COLON, 0);
}

tree::TerminalNode* YamlDockerParser::Networks_blockContext::NEWLINE() {
  return getToken(YamlDockerParser::NEWLINE, 0);
}

std::vector<YamlDockerParser::Network_entryContext *> YamlDockerParser::Networks_blockContext::network_entry() {
  return getRuleContexts<YamlDockerParser::Network_entryContext>();
}

YamlDockerParser::Network_entryContext* YamlDockerParser::Networks_blockContext::network_entry(size_t i) {
  return getRuleContext<YamlDockerParser::Network_entryContext>(i);
}


size_t YamlDockerParser::Networks_blockContext::getRuleIndex() const {
  return YamlDockerParser::RuleNetworks_block;
}

void YamlDockerParser::Networks_blockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YamlDockerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNetworks_block(this);
}

void YamlDockerParser::Networks_blockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YamlDockerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNetworks_block(this);
}


std::any YamlDockerParser::Networks_blockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<YamlDockerVisitor*>(visitor))
    return parserVisitor->visitNetworks_block(this);
  else
    return visitor->visitChildren(this);
}

YamlDockerParser::Networks_blockContext* YamlDockerParser::networks_block() {
  Networks_blockContext *_localctx = _tracker.createInstance<Networks_blockContext>(_ctx, getState());
  enterRule(_localctx, 18, YamlDockerParser::RuleNetworks_block);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(107);
    match(YamlDockerParser::NETWORKS_KEY);
    setState(108);
    match(YamlDockerParser::COLON);
    setState(109);
    match(YamlDockerParser::NEWLINE);
    setState(111); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(110);
      network_entry();
      setState(113); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == YamlDockerParser::NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Network_entryContext ------------------------------------------------------------------

YamlDockerParser::Network_entryContext::Network_entryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* YamlDockerParser::Network_entryContext::NAME() {
  return getToken(YamlDockerParser::NAME, 0);
}

tree::TerminalNode* YamlDockerParser::Network_entryContext::COLON() {
  return getToken(YamlDockerParser::COLON, 0);
}

tree::TerminalNode* YamlDockerParser::Network_entryContext::NEWLINE() {
  return getToken(YamlDockerParser::NEWLINE, 0);
}

std::vector<YamlDockerParser::Network_propContext *> YamlDockerParser::Network_entryContext::network_prop() {
  return getRuleContexts<YamlDockerParser::Network_propContext>();
}

YamlDockerParser::Network_propContext* YamlDockerParser::Network_entryContext::network_prop(size_t i) {
  return getRuleContext<YamlDockerParser::Network_propContext>(i);
}


size_t YamlDockerParser::Network_entryContext::getRuleIndex() const {
  return YamlDockerParser::RuleNetwork_entry;
}

void YamlDockerParser::Network_entryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YamlDockerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNetwork_entry(this);
}

void YamlDockerParser::Network_entryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YamlDockerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNetwork_entry(this);
}


std::any YamlDockerParser::Network_entryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<YamlDockerVisitor*>(visitor))
    return parserVisitor->visitNetwork_entry(this);
  else
    return visitor->visitChildren(this);
}

YamlDockerParser::Network_entryContext* YamlDockerParser::network_entry() {
  Network_entryContext *_localctx = _tracker.createInstance<Network_entryContext>(_ctx, getState());
  enterRule(_localctx, 20, YamlDockerParser::RuleNetwork_entry);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(115);
    match(YamlDockerParser::NAME);
    setState(116);
    match(YamlDockerParser::COLON);
    setState(117);
    match(YamlDockerParser::NEWLINE);
    setState(121);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == YamlDockerParser::DRIVER_KEY) {
      setState(118);
      network_prop();
      setState(123);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Network_propContext ------------------------------------------------------------------

YamlDockerParser::Network_propContext::Network_propContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* YamlDockerParser::Network_propContext::DRIVER_KEY() {
  return getToken(YamlDockerParser::DRIVER_KEY, 0);
}

tree::TerminalNode* YamlDockerParser::Network_propContext::COLON() {
  return getToken(YamlDockerParser::COLON, 0);
}

YamlDockerParser::ValueContext* YamlDockerParser::Network_propContext::value() {
  return getRuleContext<YamlDockerParser::ValueContext>(0);
}

tree::TerminalNode* YamlDockerParser::Network_propContext::NEWLINE() {
  return getToken(YamlDockerParser::NEWLINE, 0);
}


size_t YamlDockerParser::Network_propContext::getRuleIndex() const {
  return YamlDockerParser::RuleNetwork_prop;
}

void YamlDockerParser::Network_propContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YamlDockerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNetwork_prop(this);
}

void YamlDockerParser::Network_propContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YamlDockerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNetwork_prop(this);
}


std::any YamlDockerParser::Network_propContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<YamlDockerVisitor*>(visitor))
    return parserVisitor->visitNetwork_prop(this);
  else
    return visitor->visitChildren(this);
}

YamlDockerParser::Network_propContext* YamlDockerParser::network_prop() {
  Network_propContext *_localctx = _tracker.createInstance<Network_propContext>(_ctx, getState());
  enterRule(_localctx, 22, YamlDockerParser::RuleNetwork_prop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(124);
    match(YamlDockerParser::DRIVER_KEY);
    setState(125);
    match(YamlDockerParser::COLON);
    setState(126);
    value();
    setState(127);
    match(YamlDockerParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- List_itemContext ------------------------------------------------------------------

YamlDockerParser::List_itemContext::List_itemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* YamlDockerParser::List_itemContext::DASH() {
  return getToken(YamlDockerParser::DASH, 0);
}

YamlDockerParser::ValueContext* YamlDockerParser::List_itemContext::value() {
  return getRuleContext<YamlDockerParser::ValueContext>(0);
}

tree::TerminalNode* YamlDockerParser::List_itemContext::NEWLINE() {
  return getToken(YamlDockerParser::NEWLINE, 0);
}


size_t YamlDockerParser::List_itemContext::getRuleIndex() const {
  return YamlDockerParser::RuleList_item;
}

void YamlDockerParser::List_itemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YamlDockerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterList_item(this);
}

void YamlDockerParser::List_itemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YamlDockerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitList_item(this);
}


std::any YamlDockerParser::List_itemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<YamlDockerVisitor*>(visitor))
    return parserVisitor->visitList_item(this);
  else
    return visitor->visitChildren(this);
}

YamlDockerParser::List_itemContext* YamlDockerParser::list_item() {
  List_itemContext *_localctx = _tracker.createInstance<List_itemContext>(_ctx, getState());
  enterRule(_localctx, 24, YamlDockerParser::RuleList_item);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(129);
    match(YamlDockerParser::DASH);
    setState(130);
    value();
    setState(131);
    match(YamlDockerParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValueContext ------------------------------------------------------------------

YamlDockerParser::ValueContext::ValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* YamlDockerParser::ValueContext::STRING() {
  return getToken(YamlDockerParser::STRING, 0);
}

tree::TerminalNode* YamlDockerParser::ValueContext::NUMBER() {
  return getToken(YamlDockerParser::NUMBER, 0);
}


size_t YamlDockerParser::ValueContext::getRuleIndex() const {
  return YamlDockerParser::RuleValue;
}

void YamlDockerParser::ValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YamlDockerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValue(this);
}

void YamlDockerParser::ValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YamlDockerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValue(this);
}


std::any YamlDockerParser::ValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<YamlDockerVisitor*>(visitor))
    return parserVisitor->visitValue(this);
  else
    return visitor->visitChildren(this);
}

YamlDockerParser::ValueContext* YamlDockerParser::value() {
  ValueContext *_localctx = _tracker.createInstance<ValueContext>(_ctx, getState());
  enterRule(_localctx, 26, YamlDockerParser::RuleValue);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(133);
    _la = _input->LA(1);
    if (!(_la == YamlDockerParser::STRING

    || _la == YamlDockerParser::NUMBER)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void YamlDockerParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  yamldockerParserInitialize();
#else
  ::antlr4::internal::call_once(yamldockerParserOnceFlag, yamldockerParserInitialize);
#endif
}
