
%{
	#include <iostream>
	#include <string>
	#include "parser.h"

	using namespace std;
%}

%option noyywrap

/* Literals */
INTEGER			-?[0-9]+
DECIMAL			-?[0-9]+\.[0-9]+
STRING			\"[^"]*\"
BOOLEAN			"true"|"false"

/* Identifier */
IDENTIFIER		[a-zA-Z][a-zA-Z_0-9]*

/* Comment */
COMMENT			"//".*

%%

"and"			{ return KW_AND; }
"boolean"		{ return KW_BOOLEAN; }
"break"			{ return KW_BREAK; }
"choice"		{ return KW_CHOICE; }
"class"			{ return KW_CLASS; }
"double"		{ return KW_DOUBLE; }
"for"			{ return KW_FOR; }
"function"		{ return KW_FUNCTION; }
"if"			{ return KW_IF; }
"import"		{ return KW_IMPORT; }
"input"			{ return KW_INPUT; }
"int"			{ return KW_INT; }
"loop"			{ return KW_LOOP; }
"new"			{ return KW_NEW; }
"not"			{ return KW_NOT; }
"null"			{ return KW_NULL; }
"or"			{ return KW_OR; }
"otherwise"		{ return KW_OTHERWISE; }
"prompt"		{ return KW_PROMPT; }
"return"		{ return KW_RETURN; }
"string"		{ return KW_STRING; }
"this"			{ return KW_THIS; }
"to"			{ return KW_TO; }
"unless"		{ return KW_UNLESS; }
"until"			{ return KW_UNTIL; }
"write"			{ return KW_WRITE; }
"writeline"		{ return KW_WRITELINE; }

"+="	{ return ADD_EQ; }
"-="	{ return SUB_EQ; }
"*="	{ return MUL_EQ; }
"/="	{ return DIV_EQ; }
"%="	{ return MOD_EQ; }
"^="	{ return EXP_EQ; }
"++"	{ return INCREMENT; }
"--"	{ return DECREMENT; }
"=="	{ return IS_EQ_TO; }
"<"		{ return yytext[0]; }
">"		{ return yytext[0]; }
"<="	{ return LTorEQ; }
">="	{ return GTorEQ; }
"!="	{ return NOT_EQ; }

"."		{ return yytext[0]; }
","		{ return yytext[0]; }
";"		{ return yytext[0]; }

{INTEGER}		{ yylval.integer = atoi(yytext); return INTEGER; }
{DECIMAL}		{ yylval.decimal = atof(yytext); return DECIMAL; }
{STRING}		{ yylval.str = yytext; return STRING; }
{BOOLEAN}		{
					if(yytext == "true") yylval.boolean = true;
					if(yytext == "false") yylval.boolean = false;
					return BOOLEAN; 
				}
{IDENTIFIER}	{ return IDENTIFIER; }
{COMMENT}		{ }

[\[({]			{ return yytext[0]; }
[\])}]			{ return yytext[0]; }

[+*/%\^=-]		{ return yytext[0]; }

[ \t\n]+		{ }
.				{ yyterminate(); }
<<EOF>>			{ yyterminate(); }
