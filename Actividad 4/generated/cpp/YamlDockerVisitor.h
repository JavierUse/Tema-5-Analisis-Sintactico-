
// Generated from YamlDocker.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "YamlDockerParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by YamlDockerParser.
 */
class  YamlDockerVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by YamlDockerParser.
   */
    virtual std::any visitDocument(YamlDockerParser::DocumentContext *context) = 0;

    virtual std::any visitVersion_line(YamlDockerParser::Version_lineContext *context) = 0;

    virtual std::any visitServices_block(YamlDockerParser::Services_blockContext *context) = 0;

    virtual std::any visitService_entry(YamlDockerParser::Service_entryContext *context) = 0;

    virtual std::any visitService_prop(YamlDockerParser::Service_propContext *context) = 0;

    virtual std::any visitImage_prop(YamlDockerParser::Image_propContext *context) = 0;

    virtual std::any visitPorts_prop(YamlDockerParser::Ports_propContext *context) = 0;

    virtual std::any visitEnvironment_prop(YamlDockerParser::Environment_propContext *context) = 0;

    virtual std::any visitNetworks_ref_prop(YamlDockerParser::Networks_ref_propContext *context) = 0;

    virtual std::any visitNetworks_block(YamlDockerParser::Networks_blockContext *context) = 0;

    virtual std::any visitNetwork_entry(YamlDockerParser::Network_entryContext *context) = 0;

    virtual std::any visitNetwork_prop(YamlDockerParser::Network_propContext *context) = 0;

    virtual std::any visitList_item(YamlDockerParser::List_itemContext *context) = 0;

    virtual std::any visitValue(YamlDockerParser::ValueContext *context) = 0;


};

