%{
#include <stdio.h>
#include "sint.tab.h"

int line_number = 1;
int error_count = 0;

void multiple_comment();
%}

letra        [a-zA-Z_]
digito       [0-9]

%%
"void"			                    { return(VOID); }
"char"			                    { return(CHAR); }
"int"			                    { return(INT); }
"float"			                    { return(FLOAT); }
"double"		                    { return(DOUBLE); }

"break"                             { return(BREAK); }
"continue"	                        { return(CONTINUE); }
"return"		                    { return(RETURN); }

"do"			                    { return(DO); }
"for"			                    { return(FOR); }
"while"			                    { return(WHILE); }

"if"			                    { return(IF); }
"else"			                    { return(ELSE); }

{letra}({letra}|{digito})*          { return(IDENTIFIER); }
{digito}+{letra}({letra}|{digito})* { error_count++; }

{digito}+      	                    { return(NUMBER); }
{digito}+"."{digito}+ 	            { return(NUMBER); }

{letra}?\"(\\.|[^\\"])*\"	        { return(STRING_LITERAL); }

"+"             	                { return(OP_ADD); }
"-"             	                { return(OP_SUB); }
"*"             	                { return(OP_MUL); }
"/"             	                { return(OP_DIV); }

"="             	                { return(OP_ASSIGN); }

"=="            	                { return(OP_EQUAL); }
"!="            	                { return(OP_NEQUAL); }
"<"             	                { return(OP_LESS); }
">"             	                { return(OP_GREATER); }
"<="            	                { return(OP_ELESS); }
">="            	                { return(OP_EGREATER); }

"&&"            	                { return(OP_AND); }
"||"            	                { return(OP_OR); }
"!"             	                { return(OP_NOT); }

","             	                { return(COMMA); }
";"             	                { return(SEMICOLON); }
"("             	                { return(LPAREN); }
")"             	                { return(RPAREN); }
"["             	                { return(LBRACKET); }
"]"             	                { return(RBRACKET); }
"{"             	                { return(LBRACE); }
"}"             	                { return(RBRACE); }

"//"[^\n]*                          { /* Ignorar comentário de uma linha */}
"/*"                                { multiple_comment(); }

\n                                  { line_number++; }

[ \t\r]+                            /* Ignorar espaços em branco e tabs */

.                                   { error_count++; }

%%

int yywrap();

void multiple_comment() {
	char c, c1;

loop:
	while ((c = input()) != '*' && c != 0) {
	    if(c == '\n') line_number++;
	}

	if ((c1 = input()) != '/' && c != 0)
	{
		goto loop;
	}
}

int yywrap() {
    return 1;
}
