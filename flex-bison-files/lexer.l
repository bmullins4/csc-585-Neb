
%{
	#include <iostream>
	#include <cmath>
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

"and"			{ cout << "KW_AND: " << yytext << endl; return KW_AND; }
"boolean"		{ cout << "KW_BOOLEAN: " << yytext << endl; return KW_BOOLEAN; }
"break"			{ cout << "KW_BREAK: " << yytext << endl; return KW_BREAK; }
"choice"		{ cout << "KW_CHOICE: " << yytext << endl; return KW_CHOICE; }
"class"			{ cout << "KW_CLASS: " << yytext << endl; return KW_CLASS; }
"double"		{ cout << "KW_DOUBLE: " << yytext << endl; return KW_DOUBLE; }
"for"			{ cout << "KW_FOR: " << yytext << endl; return KW_FOR; }
"function"		{ cout << "KW_FUNCTION: " << yytext << endl; return KW_FUNCTION; }
"if"			{ cout << "KW_IF: " << yytext << endl; return KW_IF; }
"import"		{ cout << "KW_IMPORT: " << yytext << endl; return KW_IMPORT; }
"input"			{ cout << "KW_INPUT: " << yytext << endl; return KW_INPUT; }
"int"			{ cout << "KW_INT: " << yytext << endl; return KW_INT; }
"loop"			{ cout << "KW_LOOP: " << yytext << endl; return KW_LOOP; }
"new"			{ cout << "KW_NEW: " << yytext << endl; return KW_NEW; }
"not"			{ cout << "KW_NOT: " << yytext << endl; return KW_NOT; }
"null"			{ cout << "KW_NULL: " << yytext << endl; return KW_NULL; }
"or"			{ cout << "KW_OR: " << yytext << endl; return KW_OR; }
"otherwise"		{ cout << "KW_OTHERWISE: " << yytext << endl; return KW_OTHERWISE; }
"prompt"		{ cout << "KW_PROMPT: " << yytext << endl; return KW_PROMPT; }
"return"		{ cout << "KW_RETURN: " << yytext << endl; return KW_RETURN; }
"string"		{ cout << "KW_STRING: " << yytext << endl; return KW_STRING; }
"this"			{ cout << "KW_THIS: " << yytext << endl; return KW_THIS; }
"to"			{ cout << "KW_TO: " << yytext << endl; return KW_TO; }
"unless"		{ cout << "KW_UNLESS: " << yytext << endl; return KW_UNLESS; }
"until"			{ cout << "KW_UNTIL: " << yytext << endl; return KW_UNTIL; }
"write"			{ cout << "KW_WRITE: " << yytext << endl; return KW_WRITE; }
"writeline"		{ cout << "KW_WRITELINE: " << yytext << endl; return KW_WRITELINE; }

"+="	{ cout << "ADD_EQ: " << yytext << endl; return ADD_EQ; }
"-="	{ cout << "SUB_EQ: " << yytext << endl; return SUB_EQ; }
"*="	{ cout << "MUL_EQ: " << yytext << endl; return MUL_EQ; }
"/="	{ cout << "DIV_EQ: " << yytext << endl; return DIV_EQ; }
"%="	{ cout << "MOD_EQ: " << yytext << endl; return MOD_EQ; }
"^="	{ cout << "EXP_EQ: " << yytext << endl; return EXP_EQ; }
"++"	{ cout << "INCREMENT: " << yytext << endl; return INCREMENT; }
"--"	{ cout << "DECREMENT: " << yytext << endl; return DECREMENT; }
"=="	{ cout << "IS_EQ_TO: " << yytext << endl; return IS_EQ_TO; }
"<"		{ cout << "LESSTHAN: " << yytext << endl; return yytext[0]; }
">"		{ cout << "GREATERTHAN: " << yytext << endl; return yytext[0]; }
"<="	{ cout << "LTorEQ: " << yytext << endl; return LTorEQ; }
">="	{ cout << "GTorEQ: " << yytext << endl; return GTorEQ; }
"!="	{ cout << "NOT_EQ: " << yytext << endl; return NOT_EQ; }

"."		{ cout << "MEMBER: " << yytext << endl; return yytext[0]; }
","		{ cout << "SEPARATOR: " << yytext << endl; return yytext[0]; }
";"		{ cout << "SEMI_COLON: " << yytext << endl; return yytext[0]; }

{INTEGER}		{ 
					yylval.intVal = atoi(yytext); 
					cout << "INTEGER: " << yytext << endl; 
					return INTEGER; 
				}
{DECIMAL}		{  
					yylval.dblVal = atof(yytext); 
					cout << "DECIMAL: " << yytext << endl;
					return DECIMAL; 
				}
{STRING}		{
					yylval.strVal = yytext; 
					cout << "STRING: " << yytext << endl; 
					return STRING; 
				}
{BOOLEAN}		{
					if(yytext == "true") yylval.boolVal = true;
					if(yytext == "false") yylval.boolVal = false;
					cout << "BOOLEAN: " << yytext << endl;
					return BOOLEAN; 
				}
{IDENTIFIER}	{ cout << "IDENTIFIER: " << yytext << endl; return IDENTIFIER; }
{COMMENT}		{ cout << "COMMENT: " << yytext << endl; }

[\[({]			{ cout << "OPEN_BRACKET: " << yytext << endl; return yytext[0]; }
[\])}]			{ cout << "CLOSE_BRACKET: " << yytext << endl; return yytext[0]; }

[+*/%\^=-]		{ cout << "OPERATOR: " << yytext << endl; return yytext[0]; }

[ \t\n]+		{ }
.				{ cout << "Unkown Token: " << yytext << endl; }
