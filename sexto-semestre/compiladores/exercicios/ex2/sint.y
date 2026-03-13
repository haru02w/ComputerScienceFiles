%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern int yyparse();
extern char *yytext;
extern FILE *yyin;
extern int line_number;
extern int error_count;
void yyerror(const char *s);
%}

%define parse.error detailed

%token IDENTIFIER NUMBER STRING_LITERAL
%token OP_ADD OP_SUB OP_MUL OP_DIV OP_ASSIGN
%token OP_EQUAL OP_NEQUAL OP_LESS OP_GREATER OP_ELESS OP_EGREATER
%token OP_AND OP_OR OP_NOT
%token IF ELSE WHILE DO FOR BREAK CONTINUE RETURN
%token LPAREN RPAREN LBRACKET RBRACKET LBRACE RBRACE SEMICOLON COMMA
%token VOID CHAR INT FLOAT DOUBLE

%left OP_OR
%left OP_AND
%nonassoc OP_EQUAL OP_NEQUAL OP_LESS OP_GREATER OP_ELESS OP_EGREATER
%left OP_ADD OP_SUB
%left OP_MUL OP_DIV
%right OP_ASSIGN
%right OP_NOT
%right RPAREN ELSE

%%

program:
    | program function_definition
	| program declaration SEMICOLON
    ;

statement_list:
	| statement_list statement

statement:
    LBRACE statement_list RBRACE
    | SEMICOLON
    | declaration SEMICOLON
    | assignment SEMICOLON
    | conditional
    | loop
    | expression SEMICOLON
    | RETURN expression SEMICOLON
    ;

declaration:
    type declaration_list
    ;

declaration_list:
	IDENTIFIER
    | assignment
    | declaration_list COMMA assignment
	| declaration_list COMMA IDENTIFIER
    ;

assignment:
    IDENTIFIER OP_ASSIGN assignment_expression
    ;

conditional:
    IF LPAREN expression RPAREN statement ELSE statement
    | IF LPAREN expression RPAREN statement
    ;

loop:
    WHILE LPAREN expression RPAREN statement
    | FOR LPAREN declaration SEMICOLON expression SEMICOLON assignment RPAREN statement 
    | DO statement WHILE LPAREN expression RPAREN SEMICOLON
    ;

function_definition:
    type IDENTIFIER LPAREN parameter_list RPAREN LBRACE statement_list RBRACE
    | type IDENTIFIER LPAREN parameter_list RPAREN SEMICOLON
    ;

parameter_list:
    | type IDENTIFIER
    | parameter_list COMMA type IDENTIFIER
    ;

expression:
    logical_or_expression    
    ;

assignment_expression:
    logical_or_expression
    | IDENTIFIER OP_ASSIGN expression

logical_or_expression:
    logical_and_expression
    | logical_or_expression OP_OR logical_and_expression 
    ;

logical_and_expression:
    equality_expression
    | logical_and_expression OP_AND equality_expression 
    ;

equality_expression:
    relational_expression
    | equality_expression OP_EQUAL relational_expression 
    | equality_expression OP_NEQUAL relational_expression    
    ;

relational_expression:
    additive_expression
    | relational_expression OP_GREATER additive_expression
    | relational_expression OP_LESS additive_expression
    | relational_expression OP_EGREATER additive_expression 
    | relational_expression OP_ELESS additive_expression
    ;

additive_expression:
    multiplicative_expression
    | additive_expression OP_ADD multiplicative_expression
    | additive_expression OP_SUB multiplicative_expression    
    ;

multiplicative_expression:
    unary_expression
    | multiplicative_expression OP_MUL unary_expression
    | multiplicative_expression OP_DIV unary_expression
    ;

unary_expression:
    OP_NOT unary_expression
    | LPAREN expression RPAREN
    | function_call
    | NUMBER
    | IDENTIFIER
    | STRING_LITERAL
    ;

function_call:
    IDENTIFIER LPAREN argument_list RPAREN
    | IDENTIFIER LPAREN RPAREN
    ;

argument_list:
    expression
    | argument_list COMMA expression
    ;

type:
    INT
    | FLOAT
    | DOUBLE
    | CHAR
    | VOID
    ;

%%

void yyerror(const char *s) 
{
    fprintf(stderr, "Erro [Linha %d], %s\n token não identificado: %s\n", line_number, s, yytext);
    error_count++;
}

int main(int argc, char **argv) 
{
    ++argv, --argc;
    if (argc > 0) {
        yyin = fopen(argv[0], "r");
        if (!yyin) {
            perror(argv[0]);
            return 1;
        }
    } else {
        yyin = stdin;
    }

    yyparse();

    if(error_count == 0) {
        printf("Nenhum erro detectado nas análises!\n");
    }

    return 0;
}
