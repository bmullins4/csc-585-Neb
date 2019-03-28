
%defines "parser.h"

%{
	#include <cmath>
	#include <cstdio>
	#include <iostream>
	#include "ast_node.h"
	#include "ast_node_functions.h"

	extern int yylex(); //will be generated by flex
	extern void yyerror(const char*); //code this

	using namespace std;
%}

%error-verbose

%union {
	struct ast_node* ast;
	struct ast_datatype_node* dt;
	struct ast_int_node* ival;
	struct ast_decimal_node* dval;
	struct ast_string_node* sval;
	struct ast_boolean_node* bval;
	struct ast_ident_node* ident;
	struct ast_assignment_node* assign;
	struct ast_small_assign_node* s_assign;
	struct ast_opeq_assign_node* o_assign;
	struct ast_declaration_node* decl;
	struct ast_conditional_node* conditional;
	struct ast_equality_node* equality;
	struct ast_fc_node* fc;
	struct ast_if_node* ifs;
	struct ast_choice_node* choices;
	struct ast_package_node* pkg;
	struct ast_default_loop_node* dl;
	struct ast_for_loop_node* fl;
	struct ast_print_node* prnt;
	struct ast_prompt_node* prmpt;
	struct ast_input_node* inpt;
	struct ast_return_node* rtn;

	int integer;
	double decimal;
	char* str;
	bool boolean;
}

%token <integer> INTEGER
%token <decimal> DECIMAL
%token <str> STRING
%token <boolean> BOOLEAN
%token <ident> IDENTIFIER

%token <ival> KW_INT
%token <dval> KW_DOUBLE
%token <sval> KW_STRING
%token <bval> KW_BOOLEAN

%token <conditional> KW_AND KW_OR KW_NOT

%token KW_BREAK KW_CHOICE KW_CLASS
%token KW_FOR KW_FUNCTION KW_IF KW_IMPORT
%token KW_INPUT KW_LOOP KW_NEW
%token KW_NULL KW_OTHERWISE KW_PROMPT KW_RETURN
%token KW_THIS KW_TO KW_UNLESS KW_UNTIL
%token KW_WRITE KW_WRITELINE

%token ADD_EQ SUB_EQ MUL_EQ DIV_EQ MOD_EQ EXP_EQ
%token INCREMENT DECREMENT
%token IS_EQ_TO LTorEQ GTorEQ NOT_EQ

%nonassoc NO_UNLESS NO_OTHERWISE
%right '='
%left '+' '-'
%left '*' '/' '%'
%right '^'

%type <ast> statements arr_content expression conditions choice_expr var
%type <ast> parameters package write_expr input_list unless_stmt return_list
%type <ast> statement file program number non_number literal
%type <dt> data_type
%type <assign> assignment var_assign arr_assign ident_assign obj_assign
%type <s_assign> small_op
%type <o_assign> op_equal
%type <decl> declaration
%type <conditional> condition cond_op
%type <fc> function class
%type <ifs> if_stmt
%type <choices> choice_stmt
%type <pkg> import
%type <dl> default
%type <fl> forloop
%type <prnt> print
%type <prmpt> prompt
%type <inpt> input
%type <rtn> return

%%

program
	: file	{ $$ = $1; }
	;

file
	: /* empty */	{ /* do nothing */ }
	| statements	{ $$ = $1; }
	;

statements
	: statement
	| statements statement	{ $$ = new_node("L", $1, $2); }
	;

statement
	: assignment
	| branch
	| break
	| class
	| declaration
	| function
	| import
	| loop
	| print
	| prompt
	| return
	;

assignment
	: var_assign
	| arr_assign { /* currently no array support */ }
	| ident_assign
	| obj_assign
	;

var_assign
	: var '=' expression ';'	{ $$ = (ast_assignment_node*)new_assignment_node($1, $3); }
	| var '=' IDENTIFIER '[' INTEGER ']' ';'
	;

arr_assign
	: var '=' '[' ']' ';'
	| var '=' '[' arr_content ']' ';'
	| IDENTIFIER '=' '[' ']' ';'
	| IDENTIFIER '=' '[' arr_content ']' ';'
	;

arr_content
	: literal
	| IDENTIFIER					{ $$ = new_ident_reference_node($1); }
	| arr_content ',' literal		{ $$ = new_node("L", $1, $3); }
	| arr_content ',' IDENTIFIER	{ $$ = new_node("L", $1, (ast_node*)$3); }
	;

ident_assign
	: IDENTIFIER small_op ';'								{ $$ = (ast_assignment_node*)new_small_assign_node((ast_node*)$1, (small_op*)$2); }
	| IDENTIFIER '=' expression ';'							{ $$ = (ast_assignment_node*)new_assignment_node((ast_node*)$1, $3); }
	| IDENTIFIER '=' IDENTIFIER '[' INTEGER ']' ';'
	| IDENTIFIER op_equal expression ';'					{ $$ = (ast_assignment_node*)new_opeq_assign_node((ast_node*)$1, (op_equal*)$2, $3); }
	| IDENTIFIER op_equal IDENTIFIER '[' INTEGER ']' ';'
	| KW_THIS '.' IDENTIFIER '=' IDENTIFIER ';'				{ /* come back to this */ }
	;

obj_assign
	: var '=' KW_NEW IDENTIFIER '(' ')' ';'					{ $$ = (ast_assignment_node*)new_assignment_node($1, (ast_node*)$4); }
	| var '=' KW_NEW IDENTIFIER '(' parameters ')' ';'		{ $$ = (ast_assignment_node*)new_assignment_node($1, (ast_node*)$4); }
	| var '=' KW_NULL ';'									{ $$ = (ast_assignment_node*)new_assignment_node($1, NULL); }
	;

var
	: data_type IDENTIFIER		{ $$ = new_declaration_node((ast_node*)$1, (ast_node*)$2); }
	| data_type '[' ']' IDENTIFIER
	| data_type '[' INTEGER ']' IDENTIFIER
	;

data_type
	: KW_INT		{ $$ = (ast_datatype_node*)$1; }
	| KW_DOUBLE		{ $$ = (ast_datatype_node*)$1; }
	| KW_STRING		{ $$ = (ast_datatype_node*)$1; }
	| KW_BOOLEAN	{ $$ = (ast_datatype_node*)$1; }
	| IDENTIFIER	{ $$ = (ast_datatype_node*)$1; }
	;

expression
	: expression '+' expression		{ $$ = new_node("+", $1, $3); }
	| expression '-' expression		{ $$ = new_node("-", $1, $3); }
	| expression '*' expression		{ $$ = new_node("*", $1, $3); }
	| expression '/' expression		{ $$ = new_node("/", $1, $3); }
	| expression '%' expression		{ $$ = new_node("%", $1, $3); }
	| expression '^' expression		{ $$ = new_node("^", $1, $3); }
	| '(' expression ')'			{ $$ = $2; }
	| literal
	;

op_equal
	: ADD_EQ
	| SUB_EQ
	| MUL_EQ
	| DIV_EQ
	| MOD_EQ
	| EXP_EQ
	;

small_op
	: INCREMENT		
	| DECREMENT		
	;

branch
	: if_stmt
	| choice_stmt
	;

if_stmt
	: KW_IF '(' conditions ')' '[' statements ']' %prec NO_UNLESS		{ $$ = (ast_if_node*)new_if_node($3, $6, NULL); }
	| KW_IF '(' conditions ')' '[' statements ']' unless_stmt			{ $$ = (ast_if_node*)new_if_node($3, $6, $8); }
	;

unless_stmt
	: KW_UNLESS '(' conditions ')' '[' statements ']' %prec NO_OTHERWISE				{ $$ = (ast_node*)new_unless_node($3, $6, NULL); }
	| KW_UNLESS '(' conditions ')' '[' statements ']' KW_OTHERWISE '[' statements ']'	{ $$ = (ast_node*)new_unless_node($3, $6, $10); }
	;

conditions
	: condition
	| conditions condition	{ $$ = new_node("L", $1, (ast_node*)$2); }
	;

condition
	: expression cond_op expression		{ $$ = (ast_conditional_node*)new_conditional_node((cond_op*)$2, $1, $3); }
	| expression KW_AND expression		{ $$ = (ast_conditional_node*)new_conditional_node((cond_op*)$2, $1, $3); }
	| expression KW_OR expression		{ $$ = (ast_conditional_node*)new_conditional_node((cond_op*)$2, $1, $3); }
	| KW_NOT condition					{ $$ = (ast_conditional_node*)new_node("L", (ast_node*)$2, (ast_node*)$1); }
	;

cond_op
	: '<'
	| '>'
	| IS_EQ_TO
	| LTorEQ
	| GTorEQ
	| NOT_EQ
	;

choice_stmt
	: KW_CHOICE '(' IDENTIFIER ')' '[' choice_expr ']' ';'	{ /* not currently supported */ }
	;

choice_expr
	: literal '{' statements '}'					{  }
	| choice_expr literal '{' statements '}'		{  }
	| choice_expr KW_OTHERWISE '{' statements '}'	{  }
	;

break
	: KW_BREAK ';'
	;

class
	: KW_CLASS IDENTIFIER '(' ')' '[' statements ']'				{ $$ = (ast_fc_node*)new_fc_node((ast_node*)$2, NULL); }
	| KW_CLASS IDENTIFIER '(' parameters ')' '[' statements ']'		{ $$ = (ast_fc_node*)new_fc_node((ast_node*)$2, (ast_node*)$4); }
	;

function
	: KW_FUNCTION IDENTIFIER '(' ')' '[' statements ']'				{ $$ = (ast_fc_node*)new_fc_node((ast_node*)$2, NULL); }
	| KW_FUNCTION IDENTIFIER '(' parameters ')' '[' statements ']'	{ $$ = (ast_fc_node*)new_fc_node((ast_node*)$2, (ast_node*)$4); }
	;

parameters
	: var
	| IDENTIFIER
	| parameters ',' var			{ $$ = new_node("L", $1, $3); }
	| parameters ',' IDENTIFIER		{ $$ = new_node("L", $1, (ast_node*)$3); }
	;

declaration
	: var ';'

import
	: KW_IMPORT package ';'	{ $$ = (ast_package_node*)new_package_node((ast_node*)$2); }
	;

package
	: IDENTIFIER
	| package '.' IDENTIFIER	{ $$ = new_node("L", $1, (ast_node*)$3); }
	;

loop
	: default
	| forloop
	;

default
	: KW_LOOP '[' statements ']' KW_UNTIL '(' conditions ')' ';' %prec NO_UNLESS
		{ $$ = (ast_default_loop_node*)new_default_loop_node((ast_node*)$7, NULL, (ast_node*)$3, NULL); }
	| KW_LOOP '[' statements ']' KW_UNTIL '(' conditions ')' KW_UNLESS '(' conditions ')' '[' statements ']' ';'
		{ $$ = (ast_default_loop_node*)new_default_loop_node((ast_node*)$7, (ast_node*)$11, (ast_node*)$3, NULL); }
	;

forloop
	: KW_FOR '(' IDENTIFIER KW_TO INTEGER ')' '[' statements ']'	{ $$ = (ast_for_loop_node*)new_for_loop_node((ast_node*)$3, NULL, (ast_node*)$5); }
	| KW_FOR '(' var KW_TO INTEGER ')' '[' statements ']'			{ $$ = (ast_for_loop_node*)new_for_loop_node(NULL, (ast_node*)$3, (ast_node*)$5); }
	;

print
	: KW_WRITE '(' write_expr ')' ';'		{ $$ = (ast_print_node*)new_print_node((ast_node*)$3); }
	| KW_WRITELINE '(' write_expr ')' ';'	{ $$ = (ast_print_node*)new_print_node((ast_node*)$3); }
	;

write_expr
	: expression
	| write_expr ',' expression		{ $$ = new_node("L", $1, (ast_node*)$3); }
	;

prompt
	: KW_PROMPT '(' STRING ')' input ';'		{ $$ = (ast_prompt_node*)new_prompt_node((ast_node*)$3, NULL); }
	| KW_PROMPT '(' IDENTIFIER ')' input ';'	{ $$ = (ast_prompt_node*)new_prompt_node(NULL, (ast_node*)$3); }
	;

input
	: KW_INPUT '[' input_list ']'	{ $$ = (ast_input_node*)new_input_node((ast_node*)$3) }
	;

input_list
	: IDENTIFIER
	| input_list ',' IDENTIFIER		{ $$ = new_node("L", $1, (ast_node*)$3); }
	;

return
	: KW_RETURN literal ';'
	| KW_RETURN IDENTIFIER ';'
	| KW_RETURN KW_NULL ';'
	| KW_RETURN '[' return_list ']' ';'		{ $$ = (ast_return_node*)new_return_node((ast_node*)$3); }
	;

return_list
	: literal
	| IDENTIFIER
	| KW_NULL
	| return_list ',' literal		{ $$ = new_node("L", $1, (ast_node*)$3); }
	| return_list ',' IDENTIFIER	{ $$ = new_node("L", $1, (ast_node*)$3); }
	| return_list ',' KW_NULL		{ $$ = new_node("L", $1, NULL); }
	;

literal
	: number
	| non_number
	;
	
number	
	: INTEGER
	| DECIMAL
	; 
	
non_number	
	: STRING
	| BOOLEAN
	;
