
#include <stdlib.h>
#include <iostream>
#include <stdarg.h>
#include "ast_node.h"

using namespace std;

void print_err(char* format, ...) {

	va_list args;
	va_start(args, format);
	vfprintf(stderr, format, args);
	va_end(args);
	exit(EXIT_FAILURE);
}

void* err_malloc(size_t size) {

	void* pointer = malloc(size);

	if (!pointer)
		print_err("Error: malloc(%u) failed!\n", size);

	return pointer;
}

ast_node* new_datatype_node(ast_int_node* i_value, ast_decimal_node* d_value, ast_string_node* s_value, ast_boolean_node* b_value) {

	ast_datatype_node* node = (ast_datatype_node*)err_malloc(sizeof(node));

	node -> node_type = "LIT";
	node -> i_value = i_value;
	node -> d_value = d_value;
	node -> s_value = s_value;
	node -> b_value = b_value;
	
	return (ast_node*)node;
}

ast_node* new_ident_reference_node(ast_ident_node* name) {

	ast_ident_reference_node* node = (ast_ident_reference_node*)err_malloc(sizeof(node));

	node -> node_type = "IDRF";
	node -> name = name;

	return (ast_node*)node;
}

ast_node* new_node(char* node_type, ast_node* left, ast_node* right) {

	ast_node* node = (ast_node*)err_malloc(sizeof(node));

	node -> node_type = node_type;
	node -> left = left;
	node -> right = right;

	return node;
}

ast_node* new_assignment_node(ast_node* ident, ast_node* value) {

	ast_assignment_node* node = (ast_assignment_node*)err_malloc(sizeof(node));

	node -> node_type = "ASSIGN";
	node -> ident = ident;
	node -> value = value;

	return (ast_node*)node;
}

ast_node* new_small_assign_node(ast_node* ident, small_op* op) {

	ast_small_assign_node* node = (ast_small_assign_node*)err_malloc(sizeof(node));

	node -> node_type = "S_ASSIGN";
	node -> ident = ident;
	node -> op = op;

	return (ast_node*)node;
}

ast_node* new_opeq_assign_node(ast_node* ident, op_equal* op, ast_node* value) {

	ast_opeq_assign_node* node = (ast_opeq_assign_node*)err_malloc(sizeof(node));

	node -> node_type = "O_ASSIGN";
	node -> ident = ident;
	node -> op = op;
	node -> value = value;

	return (ast_node*)node;
}

ast_node* new_declaration_node(ast_node* datatype, ast_node* name) {

	ast_declaration_node* node = (ast_declaration_node*)err_malloc(sizeof(node));

	node -> node_type = "DECL";
	node -> datatype = datatype;
	node -> name = name;

	return (ast_node*)node;
}

ast_node* new_conditional_node(cond_op* op, ast_node* left, ast_node* right) {

	ast_conditional_node* node = (ast_conditional_node*)err_malloc(sizeof(node));

	node -> node_type = "COND";
	node -> op = op;
	node -> left = left;
	node -> right = right;

	return (ast_node*)node;
}

ast_node* new_fc_node(ast_node* name, ast_node* params) {

	ast_fc_node* node = (ast_fc_node*)err_malloc(sizeof(node));

	node -> node_type = "FC";
	node -> name = name;
	node -> params = params;

	return (ast_node*)node;
}

ast_node* new_if_node(ast_node* cond, ast_node* if_branch, ast_node* unless_branch) {

	ast_if_node* node = (ast_if_node*)err_malloc(sizeof(node));

	node -> node_type = "IF";
	node -> cond = cond;
	node -> if_branch = if_branch;
	node-> unless_branch = unless_branch;

	return (ast_node*)node;
}

ast_node* new_choice_node(ast_node* ident, ast_node* choice_expr, ast_node* choice_otherwise) {

	ast_choice_node* node = (ast_choice_node*)err_malloc(sizeof(node));

	node -> node_type = "CHOICE";
	node -> ident = ident;
	node -> choice_expr = choice_expr;
	node -> choice_otherwise = choice_otherwise;

	return (ast_node*)node;
}

ast_node* new_unless_node(ast_node* cond, ast_node* unless_branch, ast_node* otherwise_branch) {

	ast_unless_node* node = (ast_unless_node*)err_malloc(sizeof(node));

	node -> node_type = "UNLESS";
	node -> cond = cond;
	node -> unless_branch = unless_branch;
	node -> otherwise_branch = otherwise_branch;

	return (ast_node*)node;
}

ast_node* new_package_node(ast_node* package) {

	ast_package_node* node = (ast_package_node*)err_malloc(sizeof(node));

	node -> node_type = "PACK";
	node -> package = package;

	return (ast_node*)node;
}

ast_node* new_default_loop_node(ast_node* cond1, ast_node* cond2, ast_node* def_branch, ast_node* def_unless) {

	ast_default_loop_node* node = (ast_default_loop_node*)err_malloc(sizeof(node));

	node -> node_type = "DEFL";
	node -> cond1 = cond1;
	node -> cond2 = cond2;
	node -> def_branch = def_branch;
	node -> def_unless = def_unless;

	return (ast_node*)node;
}

ast_node* new_for_loop_node(ast_node* ident, ast_node* start, ast_node* finish) {

	ast_for_loop_node* node = (ast_for_loop_node*)err_malloc(sizeof(node));

	node -> node_type = "FORL";
	node -> ident = ident;
	node -> start = start;
	node -> finish = finish;

	return (ast_node*)node;
}

ast_node* new_print_node(ast_node* write_expr) {

	ast_print_node* node = (ast_print_node*)err_malloc(sizeof(node));

	node-> node_type = "PRINT";
	node -> write_expr = write_expr;

	return (ast_node*)node;
}

ast_node* new_prompt_node(ast_node* str, ast_node* ident) {

	ast_prompt_node* node = (ast_prompt_node*)err_malloc(sizeof(node));

	node -> node_type = "PROMPT";
	node -> str = str;
	node -> ident = ident;

	return (ast_node*)node;
}

ast_node* new_input_node(ast_node* ident) {

	ast_input_node* node = (ast_input_node*)err_malloc(sizeof(node));

	node -> node_type = "INPUT";
	node -> ident = ident;

	return (ast_node*)node;
}

ast_node* new_return_node(ast_node* list) {

	ast_return_node* node = (ast_return_node*)err_malloc(sizeof(node));

	node -> node_type = "RETURN";
	node -> list = list;

	return (ast_node*)node;
}

void free_tree_mem(ast_node* tree) {

	if (!tree) return;

	if (tree -> node_type == "+" || tree -> node_type == "-" ||
		tree -> node_type == "*" || tree -> node_type == "/" ||
		tree -> node_type == "%" || tree -> node_type == "^" ||
		tree -> node_type == "L") {
		free_tree_mem(tree -> right);
	}
	else if (tree->node_type == "LIT" || tree->node_type == "IDRF") {}
	else if(tree -> node_type == "ASSIGN") {
		ast_assignment_node* node = (ast_assignment_node*)tree;
		free_tree_mem(node -> ident);
		free_tree_mem(node -> value);
	} else if(tree -> node_type == "S_ASSIGN") {
		ast_small_assign_node* node = (ast_small_assign_node*)tree;
		free_tree_mem(node -> ident);
	} else if(tree -> node_type == "O_ASSIGN") {
		ast_opeq_assign_node* node = (ast_opeq_assign_node*)tree;
		free_tree_mem(node -> ident);
		free_tree_mem(node -> value);
	} else if(tree -> node_type == "DECL") {
		ast_declaration_node* node = (ast_declaration_node*)tree;
		free_tree_mem(node -> name);
	} else if(tree -> node_type == "COND") {
		ast_conditional_node* node = (ast_conditional_node*)tree;
		free_tree_mem(node -> left);
		free_tree_mem(node -> right);
	} else if(tree -> node_type == "FC") {
		ast_fc_node* node = (ast_fc_node*)tree;
		free_tree_mem(node -> name);
		if(node -> params)
			free_tree_mem(node -> params);
	} else if(tree -> node_type == "IF") {
		ast_if_node* node = (ast_if_node*)tree;
		free_tree_mem(node -> cond);
		if(node -> if_branch)
			free_tree_mem(node -> if_branch);
		if(node -> unless_branch)
			free_tree_mem(node -> unless_branch);
	} else if(tree -> node_type == "CHOICE") {
		ast_choice_node* node = (ast_choice_node*)tree;
		if(node -> choice_expr)
			free_tree_mem(node -> choice_expr);
		if(node -> choice_otherwise)
			free_tree_mem(node -> choice_otherwise);
	} else if(tree -> node_type == "UNLESS") {
		ast_unless_node* node = (ast_unless_node*)tree;
		free_tree_mem(node -> cond);
		if(node -> unless_branch)
			free_tree_mem(node -> unless_branch);
		if(node -> otherwise_branch)
			free_tree_mem(node -> otherwise_branch);
	} else if(tree -> node_type == "PACK") {
		ast_package_node* node = (ast_package_node*)tree;
		free_tree_mem(node -> package);
	} else if(tree -> node_type == "DEFL") {
		ast_default_loop_node* node = (ast_default_loop_node*)tree;
		free_tree_mem(node -> cond1);
		free_tree_mem(node -> cond2);
		if(node -> def_branch)
			free_tree_mem(node -> def_branch);
		if(node -> def_unless)
			free_tree_mem(node -> def_unless);
	} else if(tree -> node_type == "FORL") {
		ast_for_loop_node* node = (ast_for_loop_node*)tree;
		if(node -> ident)
			free_tree_mem(node -> ident);
		if(node -> start)
			free_tree_mem(node -> start);
		free_tree_mem(node -> finish);
	} else if(tree -> node_type == "PRINT") {
		ast_print_node* node = (ast_print_node*)tree;
		free_tree_mem(node -> write_expr);
	} else if(tree -> node_type == "PROMPT") {
		ast_prompt_node* node = (ast_prompt_node*)tree;
		if(node -> str)
			free_tree_mem(node -> str);
		if(node -> ident)
			free_tree_mem(node -> ident);
	} else if(tree -> node_type == "INPUT") {
		ast_input_node* node = (ast_input_node*)tree;
		free_tree_mem(node -> ident);
	} else if(tree -> node_type == "RETURN") {
		ast_return_node* node = (ast_return_node*)tree;
		free_tree_mem(node -> list);
	} else print_err("Error: Bad node type '%c' to free!\n", tree -> node_type);

	free(tree);
}
