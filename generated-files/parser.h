
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEGER = 258,
     DECIMAL = 259,
     STRING = 260,
     BOOLEAN = 261,
     IDENTIFIER = 262,
     KW_INT = 263,
     KW_DOUBLE = 264,
     KW_STRING = 265,
     KW_BOOLEAN = 266,
     KW_AND = 267,
     KW_OR = 268,
     KW_NOT = 269,
     KW_BREAK = 270,
     KW_CHOICE = 271,
     KW_CLASS = 272,
     KW_FOR = 273,
     KW_FUNCTION = 274,
     KW_IF = 275,
     KW_IMPORT = 276,
     KW_INPUT = 277,
     KW_LOOP = 278,
     KW_NEW = 279,
     KW_NULL = 280,
     KW_OTHERWISE = 281,
     KW_PROMPT = 282,
     KW_RETURN = 283,
     KW_THIS = 284,
     KW_TO = 285,
     KW_UNLESS = 286,
     KW_UNTIL = 287,
     KW_WRITE = 288,
     KW_WRITELINE = 289,
     ADD_EQ = 290,
     SUB_EQ = 291,
     MUL_EQ = 292,
     DIV_EQ = 293,
     MOD_EQ = 294,
     EXP_EQ = 295,
     INCREMENT = 296,
     DECREMENT = 297,
     IS_EQ_TO = 298,
     LTorEQ = 299,
     GTorEQ = 300,
     NOT_EQ = 301,
     NO_OTHERWISE = 302,
     NO_UNLESS = 303
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 19 "parser.y"

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



/* Line 1676 of yacc.c  */
#line 133 "parser.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


