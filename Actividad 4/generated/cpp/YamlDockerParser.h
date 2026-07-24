
// Generated from YamlDocker.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  YamlDockerParser : public antlr4::Parser {
public:
  enum {
    VERSION_KEY = 1, SERVICES_KEY = 2, NETWORKS_KEY = 3, IMAGE_KEY = 4, 
    PORTS_KEY = 5, ENVIRONMENT_KEY = 6, DRIVER_KEY = 7, COLON = 8, DASH = 9, 
    STRING = 10, NUMBER = 11, NAME = 12, NEWLINE = 13, WS = 14, COMMENT = 15
  };

  enum {
    RuleDocument = 0, RuleVersion_line = 1, RuleServices_block = 2, RuleService_entry = 3, 
    RuleService_prop = 4, RuleImage_prop = 5, RulePorts_prop = 6, RuleEnvironment_prop = 7, 
    RuleNetworks_ref_prop = 8, RuleNetworks_block = 9, RuleNetwork_entry = 10, 
    RuleNetwork_prop = 11, RuleList_item = 12, RuleValue = 13
  };

  explicit YamlDockerParser(antlr4::TokenStream *input);

  YamlDockerParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~YamlDockerParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class DocumentContext;
  class Version_lineContext;
  class Services_blockContext;
  class Service_entryContext;
  class Service_propContext;
  class Image_propContext;
  class Ports_propContext;
  class Environment_propContext;
  class Networks_ref_propContext;
  class Networks_blockContext;
  class Network_entryContext;
  class Network_propContext;
  class List_itemContext;
  class ValueContext; 

  class  DocumentContext : public antlr4::ParserRuleContext {
  public:
    DocumentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    Version_lineContext *version_line();
    Services_blockContext *services_block();
    Networks_blockContext *networks_block();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DocumentContext* document();

  class  Version_lineContext : public antlr4::ParserRuleContext {
  public:
    Version_lineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VERSION_KEY();
    antlr4::tree::TerminalNode *COLON();
    ValueContext *value();
    antlr4::tree::TerminalNode *NEWLINE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Version_lineContext* version_line();

  class  Services_blockContext : public antlr4::ParserRuleContext {
  public:
    Services_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SERVICES_KEY();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *NEWLINE();
    std::vector<Service_entryContext *> service_entry();
    Service_entryContext* service_entry(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Services_blockContext* services_block();

  class  Service_entryContext : public antlr4::ParserRuleContext {
  public:
    Service_entryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *NEWLINE();
    std::vector<Service_propContext *> service_prop();
    Service_propContext* service_prop(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Service_entryContext* service_entry();

  class  Service_propContext : public antlr4::ParserRuleContext {
  public:
    Service_propContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Image_propContext *image_prop();
    Ports_propContext *ports_prop();
    Environment_propContext *environment_prop();
    Networks_ref_propContext *networks_ref_prop();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Service_propContext* service_prop();

  class  Image_propContext : public antlr4::ParserRuleContext {
  public:
    Image_propContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IMAGE_KEY();
    antlr4::tree::TerminalNode *COLON();
    ValueContext *value();
    antlr4::tree::TerminalNode *NEWLINE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Image_propContext* image_prop();

  class  Ports_propContext : public antlr4::ParserRuleContext {
  public:
    Ports_propContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PORTS_KEY();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *NEWLINE();
    std::vector<List_itemContext *> list_item();
    List_itemContext* list_item(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Ports_propContext* ports_prop();

  class  Environment_propContext : public antlr4::ParserRuleContext {
  public:
    Environment_propContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ENVIRONMENT_KEY();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *NEWLINE();
    std::vector<List_itemContext *> list_item();
    List_itemContext* list_item(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Environment_propContext* environment_prop();

  class  Networks_ref_propContext : public antlr4::ParserRuleContext {
  public:
    Networks_ref_propContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NETWORKS_KEY();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *NEWLINE();
    std::vector<List_itemContext *> list_item();
    List_itemContext* list_item(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Networks_ref_propContext* networks_ref_prop();

  class  Networks_blockContext : public antlr4::ParserRuleContext {
  public:
    Networks_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NETWORKS_KEY();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *NEWLINE();
    std::vector<Network_entryContext *> network_entry();
    Network_entryContext* network_entry(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Networks_blockContext* networks_block();

  class  Network_entryContext : public antlr4::ParserRuleContext {
  public:
    Network_entryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *NEWLINE();
    std::vector<Network_propContext *> network_prop();
    Network_propContext* network_prop(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Network_entryContext* network_entry();

  class  Network_propContext : public antlr4::ParserRuleContext {
  public:
    Network_propContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DRIVER_KEY();
    antlr4::tree::TerminalNode *COLON();
    ValueContext *value();
    antlr4::tree::TerminalNode *NEWLINE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Network_propContext* network_prop();

  class  List_itemContext : public antlr4::ParserRuleContext {
  public:
    List_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DASH();
    ValueContext *value();
    antlr4::tree::TerminalNode *NEWLINE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  List_itemContext* list_item();

  class  ValueContext : public antlr4::ParserRuleContext {
  public:
    ValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *NUMBER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ValueContext* value();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

