
// Generated from YamlDocker.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "YamlDockerListener.h"


/**
 * This class provides an empty implementation of YamlDockerListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  YamlDockerBaseListener : public YamlDockerListener {
public:

  virtual void enterDocument(YamlDockerParser::DocumentContext * /*ctx*/) override { }
  virtual void exitDocument(YamlDockerParser::DocumentContext * /*ctx*/) override { }

  virtual void enterVersion_line(YamlDockerParser::Version_lineContext * /*ctx*/) override { }
  virtual void exitVersion_line(YamlDockerParser::Version_lineContext * /*ctx*/) override { }

  virtual void enterServices_block(YamlDockerParser::Services_blockContext * /*ctx*/) override { }
  virtual void exitServices_block(YamlDockerParser::Services_blockContext * /*ctx*/) override { }

  virtual void enterService_entry(YamlDockerParser::Service_entryContext * /*ctx*/) override { }
  virtual void exitService_entry(YamlDockerParser::Service_entryContext * /*ctx*/) override { }

  virtual void enterService_prop(YamlDockerParser::Service_propContext * /*ctx*/) override { }
  virtual void exitService_prop(YamlDockerParser::Service_propContext * /*ctx*/) override { }

  virtual void enterImage_prop(YamlDockerParser::Image_propContext * /*ctx*/) override { }
  virtual void exitImage_prop(YamlDockerParser::Image_propContext * /*ctx*/) override { }

  virtual void enterPorts_prop(YamlDockerParser::Ports_propContext * /*ctx*/) override { }
  virtual void exitPorts_prop(YamlDockerParser::Ports_propContext * /*ctx*/) override { }

  virtual void enterEnvironment_prop(YamlDockerParser::Environment_propContext * /*ctx*/) override { }
  virtual void exitEnvironment_prop(YamlDockerParser::Environment_propContext * /*ctx*/) override { }

  virtual void enterNetworks_ref_prop(YamlDockerParser::Networks_ref_propContext * /*ctx*/) override { }
  virtual void exitNetworks_ref_prop(YamlDockerParser::Networks_ref_propContext * /*ctx*/) override { }

  virtual void enterNetworks_block(YamlDockerParser::Networks_blockContext * /*ctx*/) override { }
  virtual void exitNetworks_block(YamlDockerParser::Networks_blockContext * /*ctx*/) override { }

  virtual void enterNetwork_entry(YamlDockerParser::Network_entryContext * /*ctx*/) override { }
  virtual void exitNetwork_entry(YamlDockerParser::Network_entryContext * /*ctx*/) override { }

  virtual void enterNetwork_prop(YamlDockerParser::Network_propContext * /*ctx*/) override { }
  virtual void exitNetwork_prop(YamlDockerParser::Network_propContext * /*ctx*/) override { }

  virtual void enterList_item(YamlDockerParser::List_itemContext * /*ctx*/) override { }
  virtual void exitList_item(YamlDockerParser::List_itemContext * /*ctx*/) override { }

  virtual void enterValue(YamlDockerParser::ValueContext * /*ctx*/) override { }
  virtual void exitValue(YamlDockerParser::ValueContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

