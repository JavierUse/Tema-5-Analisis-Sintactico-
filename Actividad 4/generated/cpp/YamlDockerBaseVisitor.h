
// Generated from YamlDocker.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "YamlDockerVisitor.h"


/**
 * This class provides an empty implementation of YamlDockerVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  YamlDockerBaseVisitor : public YamlDockerVisitor {
public:

  virtual std::any visitDocument(YamlDockerParser::DocumentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVersion_line(YamlDockerParser::Version_lineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitServices_block(YamlDockerParser::Services_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitService_entry(YamlDockerParser::Service_entryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitService_prop(YamlDockerParser::Service_propContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitImage_prop(YamlDockerParser::Image_propContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPorts_prop(YamlDockerParser::Ports_propContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEnvironment_prop(YamlDockerParser::Environment_propContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNetworks_ref_prop(YamlDockerParser::Networks_ref_propContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNetworks_block(YamlDockerParser::Networks_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNetwork_entry(YamlDockerParser::Network_entryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNetwork_prop(YamlDockerParser::Network_propContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitList_item(YamlDockerParser::List_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitValue(YamlDockerParser::ValueContext *ctx) override {
    return visitChildren(ctx);
  }


};

