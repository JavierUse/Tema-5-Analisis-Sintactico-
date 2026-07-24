# Generated from YamlDocker.g4 by ANTLR 4.13.1
from antlr4 import *
if "." in __name__:
    from .YamlDockerParser import YamlDockerParser
else:
    from YamlDockerParser import YamlDockerParser

# This class defines a complete generic visitor for a parse tree produced by YamlDockerParser.

class YamlDockerVisitor(ParseTreeVisitor):

    # Visit a parse tree produced by YamlDockerParser#document.
    def visitDocument(self, ctx:YamlDockerParser.DocumentContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by YamlDockerParser#version_line.
    def visitVersion_line(self, ctx:YamlDockerParser.Version_lineContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by YamlDockerParser#services_block.
    def visitServices_block(self, ctx:YamlDockerParser.Services_blockContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by YamlDockerParser#service_entry.
    def visitService_entry(self, ctx:YamlDockerParser.Service_entryContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by YamlDockerParser#service_prop.
    def visitService_prop(self, ctx:YamlDockerParser.Service_propContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by YamlDockerParser#image_prop.
    def visitImage_prop(self, ctx:YamlDockerParser.Image_propContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by YamlDockerParser#ports_prop.
    def visitPorts_prop(self, ctx:YamlDockerParser.Ports_propContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by YamlDockerParser#environment_prop.
    def visitEnvironment_prop(self, ctx:YamlDockerParser.Environment_propContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by YamlDockerParser#networks_ref_prop.
    def visitNetworks_ref_prop(self, ctx:YamlDockerParser.Networks_ref_propContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by YamlDockerParser#networks_block.
    def visitNetworks_block(self, ctx:YamlDockerParser.Networks_blockContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by YamlDockerParser#network_entry.
    def visitNetwork_entry(self, ctx:YamlDockerParser.Network_entryContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by YamlDockerParser#network_prop.
    def visitNetwork_prop(self, ctx:YamlDockerParser.Network_propContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by YamlDockerParser#list_item.
    def visitList_item(self, ctx:YamlDockerParser.List_itemContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by YamlDockerParser#value.
    def visitValue(self, ctx:YamlDockerParser.ValueContext):
        return self.visitChildren(ctx)



del YamlDockerParser