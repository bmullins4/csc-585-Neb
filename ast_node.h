
#ifndef AST_NODE_H
#define AST_NODE_H

#include <string>

enum op_equal {
	ADD_EQ, SUB_EQ,
	MUL_EQ, DIV_EQ,
	MOD_EQ, EXP_EQ
};

enum small_op {
	INCREMENT, DECREMENT
};

enum cond_op {
	LESSTHAN, GREATERTHAN,
	IS_EQ_TO, LTorEQ, GTorEQ
};

enum eq_op {
	EQUAL, NOT_EQ
};


struct ast_datatype_node {
	string node_type;
	ast_int_node* i_value;
	ast_decimal_node* d_value;
	ast_string_node* s_value;
	ast_boolean_node* b_value;
};

//data types
struct ast_int_node {
	string node_type;
	int value;
};

struct ast_decimal_node {
	string node_type;
	double value;
};

struct ast_string_node {
	string node_type;
	char* value;
};

struct ast_boolean_node {
	string node_type;
	bool value;
};

//identifier
struct ast_ident_node {
	string node_type;
	char* name;
};


//for operations/expressions/parameters
struct ast_node {
	string node_type;
	ast_node* left;
	ast_node* right;
};

struct ast_assignment_node {
	string node_type;
	ast_declaration_node* ident;
	ast_node* value;
};

struct ast_declaration_node {
	string node_type;
	ast_datatype_node* datatype;
	ast_ident_node* name;
};

struct ast_conditional_node {
	string node_type;
	cond_op op;
	ast_node* left;
	ast_node* right;
};

struct ast_equality_node {
	string node_type;
	eq_op op;
	ast_node* left;
	ast_node* right;
};

//for function/class calls/declarations
struct ast_fc_node {
	string node_type;
	ast_ident_node* name;
	ast_declaration_node* params;
};

//for identifier references
struct ast_ident_reference_node {
	string node_type;
	ast_ident_node* name;
};

struct ast_if_node {
	string node_type;
	ast_node* cond;
	ast_node* if_branch;
	ast_node* unless_branch;
	ast_node* otherwise_branch;
};

struct ast_choice_node {
	string node_type;
	ast_ident_node* ident;
	ast_node* choice_expr;
	ast_node* choice_otherwise;
};

struct ast_package_node {
	string node_type;
	ast_ident_node* package;
};

struct ast_default_loop_node {
	string node_type;
	ast_node* def_branch;
	ast_node* def_unless;
	ast_node* condition;
};

struct ast_for_loop_node {
	string node_type;
	ast_ident_node* ident;
	ast_declaration_node* start;
	ast_int_node* finish;
};

struct ast_print_node {
	string node_type;
	ast_node* write_expr;
};

struct ast_prompt_node {
	string node_type;
	ast_string_node* str;
	ast_ident_node* ident;
};

struct ast_input_node {
	string node_type;
	ast_ident_node* ident;
	ast_node* inputs;
};

#endif
