
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
     KW_AND = 262,
     KW_BOOLEAN = 263,
     KW_BREAK = 264,
     KW_CHOICE = 265,
     KW_CLASS = 266,
     KW_DOUBLE = 267,
     KW_FOR = 268,
     KW_FUNCTION = 269,
     KW_IF = 270,
     KW_IMPORT = 271,
     KW_INPUT = 272,
     KW_INT = 273,
     KW_LOOP = 274,
     KW_NEW = 275,
     KW_NOT = 276,
     KW_NULL = 277,
     KW_OR = 278,
     KW_OTHERWISE = 279,
     KW_PROMPT = 280,
     KW_RETURN = 281,
     KW_STRING = 282,
     KW_THIS = 283,
     KW_TO = 284,
     KW_UNLESS = 285,
     KW_UNTIL = 286,
     KW_WRITE = 287,
     KW_WRITELINE = 288,
     ADD = 289,
     SUB = 290,
     MUL = 291,
     DIV = 292,
     MOD = 293,
     EXP = 294,
     EQUALS = 295,
     ADD_EQ = 296,
     SUB_EQ = 297,
     MUL_EQ = 298,
     DIV_EQ = 299,
     MOD_EQ = 300,
     EXP_EQ = 301,
     INCREMENT = 302,
     DECREMENT = 303,
     IS_EQ_TO = 304,
     LESSTHAN = 305,
     GREATERTHAN = 306,
     LTorEQ = 307,
     GTorEQ = 308,
     NOT_EQ = 309,
     IDENTIFIER = 310,
     OPEN_PAREN = 311,
     CLOSE_PAREN = 312,
     OPEN_BRACE = 313,
     CLOSE_BRACE = 314,
     OPEN_BRACKET = 315,
     CLOSE_BRACKET = 316,
     MEMBER = 317,
     SEPARATOR = 318,
     END_STMT = 319,
     COMMENT = 320
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 16 "parser.y"

	int intVal;
	double dblVal;
	char *strVal;
	bool boolVal;



/* Line 1676 of yacc.c  */
#line 126 "parser.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


