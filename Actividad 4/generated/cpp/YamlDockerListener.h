
// Generated from YamlDocker.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "YamlDockerParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by YamlDockerParser.
 */
class  YamlDockerListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterDocument(YamlDockerParser::DocumentContext *ctx) = 0;
  virtual void exitDocument(YamlDockerParser::DocumentContext *ctx) = 0;

  virtual void enterVersion_line(YamlDockerParser::Version_lineContext *ctx) = 0;
  virtual void exitVersion_line(YamlDockerParser::Version_lineContext *ctx) = 0;

  virtual void enterServices_block(YamlDockerParser::Services_blockContext *ctx) = 0;
  virtual void exitServices_block(YamlDockerParser::Services_blockContext *ctx) = 0;

  virtual void enterService_entry(YamlDockerParser::Service_entryContext *ctx) = 0;
  virtual void exitService_entry(YamlDockerParser::Service_entryContext *ctx) = 0;

  virtual void enterService_prop(YamlDockerParser::Service_propContext *ctx) = 0;
  virtual void exitService_prop(YamlDockerParser::Service_propContext *ctx) = 0;

  virtual void enterImage_prop(YamlDockerParser::Image_propContext *ctx) = 0;
  virtual void exitImage_prop(YamlDockerParser::Image_propContext *ctx) = 0;

  virtual void enterPorts_prop(YamlDockerParser::Ports_propContext *ctx) = 0;
  virtual void exitPorts_prop(YamlDockerParser::Ports_propContext *ctx) = 0;

  virtual void enterEnvironment_prop(YamlDockerParser::Environment_propContext *ctx) = 0;
  virtual void exitEnvironment_prop(YamlDockerParser::Environment_propContext *ctx) = 0;

  virtual void enterNetworks_ref_prop(YamlDockerParser::Networks_ref_propContext *ctx) = 0;
  virtual void exitNetworks_ref_prop(YamlDockerParser::Networks_ref_propContext *ctx) = 0;

  virtual void enterNetworks_block(YamlDockerParser::Networks_blockContext *ctx) = 0;
  virtual void exitNetworks_block(YamlDockerParser::Networks_blockContext *ctx) = 0;

  virtual void enterNetwork_entry(YamlDockerParser::Network_entryContext *ctx) = 0;
  virtual void exitNetwork_entry(YamlDockerParser::Network_entryContext *ctx) = 0;

  virtual void enterNetwork_prop(YamlDockerParser::Network_propContext *ctx) = 0;
  virtual void exitNetwork_prop(YamlDockerParser::Network_propContext *ctx) = 0;

  virtual void enterList_item(YamlDockerParser::List_itemContext *ctx) = 0;
  virtual void exitList_item(YamlDockerParser::List_itemContext *ctx) = 0;

  virtual void enterValue(YamlDockerParser::ValueContext *ctx) = 0;
  virtual void exitValue(YamlDockerParser::ValueContext *ctx) = 0;


};

