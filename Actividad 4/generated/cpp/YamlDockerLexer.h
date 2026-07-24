
// Generated from YamlDocker.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  YamlDockerLexer : public antlr4::Lexer {
public:
  enum {
    VERSION_KEY = 1, SERVICES_KEY = 2, NETWORKS_KEY = 3, IMAGE_KEY = 4, 
    PORTS_KEY = 5, ENVIRONMENT_KEY = 6, DRIVER_KEY = 7, COLON = 8, DASH = 9, 
    STRING = 10, NUMBER = 11, NAME = 12, NEWLINE = 13, WS = 14, COMMENT = 15
  };

  explicit YamlDockerLexer(antlr4::CharStream *input);

  ~YamlDockerLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

