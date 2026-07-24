// Generated from YamlDocker.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link YamlDockerParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface YamlDockerVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link YamlDockerParser#document}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDocument(YamlDockerParser.DocumentContext ctx);
	/**
	 * Visit a parse tree produced by {@link YamlDockerParser#version_line}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVersion_line(YamlDockerParser.Version_lineContext ctx);
	/**
	 * Visit a parse tree produced by {@link YamlDockerParser#services_block}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitServices_block(YamlDockerParser.Services_blockContext ctx);
	/**
	 * Visit a parse tree produced by {@link YamlDockerParser#service_entry}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitService_entry(YamlDockerParser.Service_entryContext ctx);
	/**
	 * Visit a parse tree produced by {@link YamlDockerParser#service_prop}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitService_prop(YamlDockerParser.Service_propContext ctx);
	/**
	 * Visit a parse tree produced by {@link YamlDockerParser#image_prop}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitImage_prop(YamlDockerParser.Image_propContext ctx);
	/**
	 * Visit a parse tree produced by {@link YamlDockerParser#ports_prop}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPorts_prop(YamlDockerParser.Ports_propContext ctx);
	/**
	 * Visit a parse tree produced by {@link YamlDockerParser#environment_prop}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitEnvironment_prop(YamlDockerParser.Environment_propContext ctx);
	/**
	 * Visit a parse tree produced by {@link YamlDockerParser#networks_ref_prop}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNetworks_ref_prop(YamlDockerParser.Networks_ref_propContext ctx);
	/**
	 * Visit a parse tree produced by {@link YamlDockerParser#networks_block}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNetworks_block(YamlDockerParser.Networks_blockContext ctx);
	/**
	 * Visit a parse tree produced by {@link YamlDockerParser#network_entry}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNetwork_entry(YamlDockerParser.Network_entryContext ctx);
	/**
	 * Visit a parse tree produced by {@link YamlDockerParser#network_prop}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNetwork_prop(YamlDockerParser.Network_propContext ctx);
	/**
	 * Visit a parse tree produced by {@link YamlDockerParser#list_item}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitList_item(YamlDockerParser.List_itemContext ctx);
	/**
	 * Visit a parse tree produced by {@link YamlDockerParser#value}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitValue(YamlDockerParser.ValueContext ctx);
}