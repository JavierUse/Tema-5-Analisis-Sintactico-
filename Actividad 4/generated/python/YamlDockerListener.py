# Generated from YamlDocker.g4 by ANTLR 4.13.1
from antlr4 import *
if "." in __name__:
    from .YamlDockerParser import YamlDockerParser
else:
    from YamlDockerParser import YamlDockerParser

# This class defines a complete listener for a parse tree produced by YamlDockerParser.
class YamlDockerListener(ParseTreeListener):

    # Enter a parse tree produced by YamlDockerParser#document.
    def enterDocument(self, ctx:YamlDockerParser.DocumentContext):
        pass

    # Exit a parse tree produced by YamlDockerParser#document.
    def exitDocument(self, ctx:YamlDockerParser.DocumentContext):
        pass


    # Enter a parse tree produced by YamlDockerParser#version_line.
    def enterVersion_line(self, ctx:YamlDockerParser.Version_lineContext):
        pass

    # Exit a parse tree produced by YamlDockerParser#version_line.
    def exitVersion_line(self, ctx:YamlDockerParser.Version_lineContext):
        pass


    # Enter a parse tree produced by YamlDockerParser#services_block.
    def enterServices_block(self, ctx:YamlDockerParser.Services_blockContext):
        pass

    # Exit a parse tree produced by YamlDockerParser#services_block.
    def exitServices_block(self, ctx:YamlDockerParser.Services_blockContext):
        pass


    # Enter a parse tree produced by YamlDockerParser#service_entry.
    def enterService_entry(self, ctx:YamlDockerParser.Service_entryContext):
        pass

    # Exit a parse tree produced by YamlDockerParser#service_entry.
    def exitService_entry(self, ctx:YamlDockerParser.Service_entryContext):
        pass


    # Enter a parse tree produced by YamlDockerParser#service_prop.
    def enterService_prop(self, ctx:YamlDockerParser.Service_propContext):
        pass

    # Exit a parse tree produced by YamlDockerParser#service_prop.
    def exitService_prop(self, ctx:YamlDockerParser.Service_propContext):
        pass


    # Enter a parse tree produced by YamlDockerParser#image_prop.
    def enterImage_prop(self, ctx:YamlDockerParser.Image_propContext):
        pass

    # Exit a parse tree produced by YamlDockerParser#image_prop.
    def exitImage_prop(self, ctx:YamlDockerParser.Image_propContext):
        pass


    # Enter a parse tree produced by YamlDockerParser#ports_prop.
    def enterPorts_prop(self, ctx:YamlDockerParser.Ports_propContext):
        pass

    # Exit a parse tree produced by YamlDockerParser#ports_prop.
    def exitPorts_prop(self, ctx:YamlDockerParser.Ports_propContext):
        pass


    # Enter a parse tree produced by YamlDockerParser#environment_prop.
    def enterEnvironment_prop(self, ctx:YamlDockerParser.Environment_propContext):
        pass

    # Exit a parse tree produced by YamlDockerParser#environment_prop.
    def exitEnvironment_prop(self, ctx:YamlDockerParser.Environment_propContext):
        pass


    # Enter a parse tree produced by YamlDockerParser#networks_ref_prop.
    def enterNetworks_ref_prop(self, ctx:YamlDockerParser.Networks_ref_propContext):
        pass

    # Exit a parse tree produced by YamlDockerParser#networks_ref_prop.
    def exitNetworks_ref_prop(self, ctx:YamlDockerParser.Networks_ref_propContext):
        pass


    # Enter a parse tree produced by YamlDockerParser#networks_block.
    def enterNetworks_block(self, ctx:YamlDockerParser.Networks_blockContext):
        pass

    # Exit a parse tree produced by YamlDockerParser#networks_block.
    def exitNetworks_block(self, ctx:YamlDockerParser.Networks_blockContext):
        pass


    # Enter a parse tree produced by YamlDockerParser#network_entry.
    def enterNetwork_entry(self, ctx:YamlDockerParser.Network_entryContext):
        pass

    # Exit a parse tree produced by YamlDockerParser#network_entry.
    def exitNetwork_entry(self, ctx:YamlDockerParser.Network_entryContext):
        pass


    # Enter a parse tree produced by YamlDockerParser#network_prop.
    def enterNetwork_prop(self, ctx:YamlDockerParser.Network_propContext):
        pass

    # Exit a parse tree produced by YamlDockerParser#network_prop.
    def exitNetwork_prop(self, ctx:YamlDockerParser.Network_propContext):
        pass


    # Enter a parse tree produced by YamlDockerParser#list_item.
    def enterList_item(self, ctx:YamlDockerParser.List_itemContext):
        pass

    # Exit a parse tree produced by YamlDockerParser#list_item.
    def exitList_item(self, ctx:YamlDockerParser.List_itemContext):
        pass


    # Enter a parse tree produced by YamlDockerParser#value.
    def enterValue(self, ctx:YamlDockerParser.ValueContext):
        pass

    # Exit a parse tree produced by YamlDockerParser#value.
    def exitValue(self, ctx:YamlDockerParser.ValueContext):
        pass



del YamlDockerParser