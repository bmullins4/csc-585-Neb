
#include <stdlib.h>
#include <iostream>
#include "ast_node.h"

using namespace std;

ast_node* new_datatype_node(ast_int_node* i_value, ast_decimal_node* d_value, ast_string_node* s_value, ast_boolean_node* b_value) {

	ast_datatype_node* node = (ast_datatype_node*)err_malloc(sizeof(node));

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

ast_node* new_node(int node_type, ast_node* left, ast_node* right) {

	ast_node* node = (ast_node*)err_malloc(sizeof(node));

	node -> node_type = node_type;
	node -> left = left;
	node -> right = right;

	return node;
}

ast_node* new_assignment_node(ast_declaration_node* ident, ast_node* value) {

	ast_assignment_node* node = (ast_assignment_node*)err_malloc(sizeof(node));

	node -> node_type = "ASSIGN";
	node -> ident = ident;
	node -> value = value;

	return (ast_node*)node;
}

ast_node* new_declaration_node(ast_datatype_node* datatype, ast_ident_node* name) {

	ast_declaration_node* node = (ast_declaration_node*)err_malloc(sizeof(node));

	node -> node_type = "DECL";
	node -> datatype = datatype;
	node -> name = name;

	return (ast_node*)node;
}

ast_node* new_conditional_node(cond_op op, ast_node* left, ast_node* right) {

	ast_conditional_node* node = (ast_conditional_node*)err_malloc(sizeof(node));

	node -> node_type = "COND";
	node -> op = op;
	node -> left = left;
	node -> right = right;

	return (ast_node*)node;
}

ast_node* new_equality_node(eq_op op, ast_node* left, ast_node* right) {

	ast_equality_node* node = (ast_equality_node*)err_malloc(sizeof(node));

	node -> node_type = "EQ";
	node -> op = op;
	node -> left = left;
	node -> right = right;

	return (ast_node*)node;
}

ast_node* new_fc_node(ast_ident_node* name, ast_declaration_node* params) {

	ast_fc_node* node = (ast_fc_node*)err_malloc(sizeof(node));

	node -> node_type = "FC";
	node -> name = name;
	node -> params = params;

	return (ast_node*)node;
}

ast_node* new_if_node(ast_node* cond, ast_node* if_branch, ast_node* unless_branch, ast_node* otherwise_branch) {

	ast_if_node* node = (ast_if_node*)err_malloc(sizeof(node));

	node -> node_type = "IF";
	node -> cond = cond;
	node -> if_branch = if_branch;
	node-> unless_branch = unless_branch;
	node -> otherwise_branch = otherwise_branch;

	return (ast_node*)node;
}

ast_node* new_choice_node(ast_ident_node* ident, ast_node* choice_expr, ast_node* choice_otherwise) {

	ast_choice_node* node = (ast_choice_node*)err_malloc(sizeof(node));

	node -> node_type = "CHOICE";
	node -> ident = ident;
	node -> choice_expr = choice_expr;
	node -> choice_otherwise = choice_otherwise;

	return (ast_node*)node;
}

ast_node* new_package_node(ast_ident_node* package) {

	ast_package_node* node = (ast_package_node*)err_malloc(sizeof(node));

	node -> node_type = "PACK";
	node -> package = package;

	return (ast_node*)node;
}

ast_node* new_default_loop_node(ast_node* cond, ast_node* def_branch, ast_node* def_unless) {

	ast_default_loop_node* node = (ast_default_loop_node*)err_malloc(sizeof(node));

	node -> node_type = "DEFL";
	node -> cond = cond;
	node -> def_branch = def_branch;
	node -> def_unless = def_unless;

	return (ast_node*)node;
}

ast_node* new_for_loop_node(ast_ident_node* ident, ast_declaration_node* start, ast_int_node* finish) {

	ast_for_loop_node* node = (ast_for_loop_node*)err_malloc(sizeof(node));

	node -> node_type = "FORL";
	node -> ident = ident;
	node -> start = start;
	node -> finish = finish;

	return (ast_node*)node;
}

ast_node* new_print_node(ast_node* write_expr) {

}

ast_node* new_prompt_node(ast_string_node* str, ast_ident_node* ident) {

}

ast_node* new_input_node(ast_ident_node* ident, ast_node* inputs) {

}

void* err_malloc(size_t size) {

	void* pointer = malloc(size);

	if (!pointer)
		cout << "Error: memory allocation failed" << endl;

	return pointer;
}