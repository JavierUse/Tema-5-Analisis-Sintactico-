// Generated from YamlDocker.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link YamlDockerParser}.
 */
public interface YamlDockerListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link YamlDockerParser#document}.
	 * @param ctx the parse tree
	 */
	void enterDocument(YamlDockerParser.DocumentContext ctx);
	/**
	 * Exit a parse tree produced by {@link YamlDockerParser#document}.
	 * @param ctx the parse tree
	 */
	void exitDocument(YamlDockerParser.DocumentContext ctx);
	/**
	 * Enter a parse tree produced by {@link YamlDockerParser#version_line}.
	 * @param ctx the parse tree
	 */
	void enterVersion_line(YamlDockerParser.Version_lineContext ctx);
	/**
	 * Exit a parse tree produced by {@link YamlDockerParser#version_line}.
	 * @param ctx the parse tree
	 */
	void exitVersion_line(YamlDockerParser.Version_lineContext ctx);
	/**
	 * Enter a parse tree produced by {@link YamlDockerParser#services_block}.
	 * @param ctx the parse tree
	 */
	void enterServices_block(YamlDockerParser.Services_blockContext ctx);
	/**
	 * Exit a parse tree produced by {@link YamlDockerParser#services_block}.
	 * @param ctx the parse tree
	 */
	void exitServices_block(YamlDockerParser.Services_blockContext ctx);
	/**
	 * Enter a parse tree produced by {@link YamlDockerParser#service_entry}.
	 * @param ctx the parse tree
	 */
	void enterService_entry(YamlDockerParser.Service_entryContext ctx);
	/**
	 * Exit a parse tree produced by {@link YamlDockerParser#service_entry}.
	 * @param ctx the parse tree
	 */
	void exitService_entry(YamlDockerParser.Service_entryContext ctx);
	/**
	 * Enter a parse tree produced by {@link YamlDockerParser#service_prop}.
	 * @param ctx the parse tree
	 */
	void enterService_prop(YamlDockerParser.Service_propContext ctx);
	/**
	 * Exit a parse tree produced by {@link YamlDockerParser#service_prop}.
	 * @param ctx the parse tree
	 */
	void exitService_prop(YamlDockerParser.Service_propContext ctx);
	/**
	 * Enter a parse tree produced by {@link YamlDockerParser#image_prop}.
	 * @param ctx the parse tree
	 */
	void enterImage_prop(YamlDockerParser.Image_propContext ctx);
	/**
	 * Exit a parse tree produced by {@link YamlDockerParser#image_prop}.
	 * @param ctx the parse tree
	 */
	void exitImage_prop(YamlDockerParser.Image_propContext ctx);
	/**
	 * Enter a parse tree produced by {@link YamlDockerParser#ports_prop}.
	 * @param ctx the parse tree
	 */
	void enterPorts_prop(YamlDockerParser.Ports_propContext ctx);
	/**
	 * Exit a parse tree produced by {@link YamlDockerParser#ports_prop}.
	 * @param ctx the parse tree
	 */
	void exitPorts_prop(YamlDockerParser.Ports_propContext ctx);
	/**
	 * Enter a parse tree produced by {@link YamlDockerParser#environment_prop}.
	 * @param ctx the parse tree
	 */
	void enterEnvironment_prop(YamlDockerParser.Environment_propContext ctx);
	/**
	 * Exit a parse tree produced by {@link YamlDockerParser#environment_prop}.
	 * @param ctx the parse tree
	 */
	void exitEnvironment_prop(YamlDockerParser.Environment_propContext ctx);
	/**
	 * Enter a parse tree produced by {@link YamlDockerParser#networks_ref_prop}.
	 * @param ctx the parse tree
	 */
	void enterNetworks_ref_prop(YamlDockerParser.Networks_ref_propContext ctx);
	/**
	 * Exit a parse tree produced by {@link YamlDockerParser#networks_ref_prop}.
	 * @param ctx the parse tree
	 */
	void exitNetworks_ref_prop(YamlDockerParser.Networks_ref_propContext ctx);
	/**
	 * Enter a parse tree produced by {@link YamlDockerParser#networks_block}.
	 * @param ctx the parse tree
	 */
	void enterNetworks_block(YamlDockerParser.Networks_blockContext ctx);
	/**
	 * Exit a parse tree produced by {@link YamlDockerParser#networks_block}.
	 * @param ctx the parse tree
	 */
	void exitNetworks_block(YamlDockerParser.Networks_blockContext ctx);
	/**
	 * Enter a parse tree produced by {@link YamlDockerParser#network_entry}.
	 * @param ctx the parse tree
	 */
	void enterNetwork_entry(YamlDockerParser.Network_entryContext ctx);
	/**
	 * Exit a parse tree produced by {@link YamlDockerParser#network_entry}.
	 * @param ctx the parse tree
	 */
	void exitNetwork_entry(YamlDockerParser.Network_entryContext ctx);
	/**
	 * Enter a parse tree produced by {@link YamlDockerParser#network_prop}.
	 * @param ctx the parse tree
	 */
	void enterNetwork_prop(YamlDockerParser.Network_propContext ctx);
	/**
	 * Exit a parse tree produced by {@link YamlDockerParser#network_prop}.
	 * @param ctx the parse tree
	 */
	void exitNetwork_prop(YamlDockerParser.Network_propContext ctx);
	/**
	 * Enter a parse tree produced by {@link YamlDockerParser#list_item}.
	 * @param ctx the parse tree
	 */
	void enterList_item(YamlDockerParser.List_itemContext ctx);
	/**
	 * Exit a parse tree produced by {@link YamlDockerParser#list_item}.
	 * @param ctx the parse tree
	 */
	void exitList_item(YamlDockerParser.List_itemContext ctx);
	/**
	 * Enter a parse tree produced by {@link YamlDockerParser#value}.
	 * @param ctx the parse tree
	 */
	void enterValue(YamlDockerParser.ValueContext ctx);
	/**
	 * Exit a parse tree produced by {@link YamlDockerParser#value}.
	 * @param ctx the parse tree
	 */
	void exitValue(YamlDockerParser.ValueContext ctx);
}