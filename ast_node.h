
#ifndef AST_NODE_H
#define AST_NODE_H

//#include <string>

enum class op_equal {
	ADD_EQ, SUB_EQ,
	MUL_EQ, DIV_EQ,
	MOD_EQ, EXP_EQ
};

enum class small_op {
	INCREMENT, DECREMENT
};

enum class cond_op {
	LESSTHAN, GREATERTHAN,
	IS_EQ_TO, LTorEQ, GTorEQ,
	EQUAL, NOT_EQ
};


//data types
struct ast_int_node {
	char* node_type;
	int value;
};

struct ast_decimal_node {
	char* node_type;
	double value;
};

struct ast_string_node {
	char* node_type;
	char* value;
};

struct ast_boolean_node {
	char* node_type;
	bool value;
};

struct ast_datatype_node {
	char* node_type;
	ast_int_node* i_value;
	ast_decimal_node* d_value;
	ast_string_node* s_value;
	ast_boolean_node* b_value;
};

//identifier
struct ast_ident_node {
	char* node_type;
	char* name;
};


//for operations/expressions/parameters
struct ast_node {
	char* node_type;
	ast_node* left;
	ast_node* right;
};

struct ast_assignment_node {
	char* node_type;
	ast_node* ident;
	ast_node* value;
};

struct ast_small_assign_node {
	char* node_type;
	ast_node* ident;
	small_op* op;
};

struct ast_opeq_assign_node {
	char* node_type;
	ast_node* ident;
	op_equal* op;
	ast_node* value;
};

struct ast_declaration_node {
	char* node_type;
	ast_node* datatype;
	ast_node* name;
};

struct ast_conditional_node {
	char* node_type;
	cond_op* op;
	ast_node* left;
	ast_node* right;
};

//for function/class calls/declarations
struct ast_fc_node {
	char* node_type;
	ast_node* name;
	ast_node* params;
};

//for identifier references
struct ast_ident_reference_node {
	char* node_type;
	ast_ident_node* name;
};

struct ast_if_node {
	char* node_type;
	ast_node* cond;
	ast_node* if_branch;
	ast_node* unless_branch;
};

struct ast_choice_node {
	char* node_type;
	ast_node* ident;
	ast_node* choice_expr;
	ast_node* choice_otherwise;
};

struct ast_unless_node {
	char* node_type;
	ast_node* cond;
	ast_node* unless_branch;
	ast_node* otherwise_branch;
};

struct ast_package_node {
	char* node_type;
	ast_node* package;
};

struct ast_default_loop_node {
	char* node_type;
	ast_node* def_branch;
	ast_node* def_unless;
	ast_node* cond1;
	ast_node* cond2;
};

struct ast_for_loop_node {
	char* node_type;
	ast_node* ident;
	ast_node* start;
	ast_node* finish;
};

struct ast_print_node {
	char* node_type;
	ast_node* write_expr;
};

struct ast_prompt_node {
	char* node_type;
	ast_node* str;
	ast_node* ident;
};

struct ast_input_node {
	char* node_type;
	ast_node* ident;
};

struct ast_return_node {
	char* node_type;
	ast_node* list;
};

#endif
