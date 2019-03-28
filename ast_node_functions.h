
#ifndef AST_NODE_FUNCTIONS_H
#define AST_NODE_FUNCTIONS_H

#include "ast_node.h"

ast_node* new_node(char* node_type, ast_node* left, ast_node* right);
ast_node* new_ident_reference_node(ast_ident_node* name);
ast_node* new_datatype_node(ast_int_node* i_value, ast_decimal_node* d_value, ast_string_node* s_value, ast_boolean_node* b_value);
ast_node* new_assignment_node(ast_node* ident, ast_node* value);
ast_node* new_small_assign_node(ast_node* ident, small_op* op);
ast_node* new_opeq_assign_node(ast_node* ident, op_equal* op, ast_node* value);
ast_node* new_declaration_node(ast_node* datatype, ast_node* name);
ast_node* new_conditional_node(cond_op* op, ast_node* left, ast_node* right);
ast_node* new_fc_node(ast_node* name, ast_node* params);
ast_node* new_if_node(ast_node* cond, ast_node* if_branch, ast_node* unless_branch);
ast_node* new_choice_node(ast_node* ident, ast_node* choice_expr, ast_node* choice_otherwise);
ast_node* new_unless_node(ast_node* cond, ast_node* unless_branch, ast_node* otherwise_branch);
ast_node* new_package_node(ast_node* package);
ast_node* new_default_loop_node(ast_node* cond1, ast_node* cond2, ast_node* def_branch, ast_node* def_unless);
ast_node* new_for_loop_node(ast_node* ident, ast_node* start, ast_node* finish);
ast_node* new_print_node(ast_node* write_expr);
ast_node* new_prompt_node(ast_node* str, ast_node* ident);
ast_node* new_input_node(ast_node* ident);
ast_node* new_return_node(ast_node* list);

#endif
