%{
#include <stdio.h>

int line_number = 1;
int error_count = 0;
%}

letra        [a-zA-Z_]
digito       [0-9]

%%
{letra}({letra}|{digito})*          { printf("Linha %d: Identificador: %s\n", line_number, yytext); }
{digito}+{letra}({letra}|{digito})* { printf("Linha %d: Erro: Identificador inválido: %s\n", line_number, yytext); error_count++; }

{digito}+      	               { printf("Linha %d: Numero inteiro: %s\n", line_number, yytext); }
{digito}+"."{digito}+ 	       { printf("Linha %d: Numero real: %s\n", line_number, yytext); }

"+"             	       { printf("Linha %d: Operador de adição: %s\n", line_number, yytext); }
"-"             	       { printf("Linha %d: Operador de subtração: %s\n", line_number, yytext); }
"*"             	       { printf("Linha %d: Operador de multiplicação: %s\n", line_number, yytext); }
"/"             	       { printf("Linha %d: Operador de divisão: %s\n", line_number, yytext); }

"="             	       { printf("Linha %d: Operador de atribuição: %s\n", line_number, yytext); }

"=="            	       { printf("Linha %d: Operador de igualdade: %s\n", line_number, yytext); }
"!="            	       { printf("Linha %d: Operador de diferença: %s\n", line_number, yytext); }
"<"             	       { printf("Linha %d: Operador menor que: %s\n", line_number, yytext); }
">"             	       { printf("Linha %d: Operador maior que: %s\n", line_number, yytext); }
"<="            	       { printf("Linha %d: Operador menor ou igual: %s\n", line_number, yytext); }
">="            	       { printf("Linha %d: Operador maior ou igual: %s\n", line_number, yytext); }

"&&"            	       { printf("Linha %d: Operador lógico E: %s\n", line_number, yytext); }
"||"            	       { printf("Linha %d: Operador lógico OU: %s\n", line_number, yytext); }
"!"             	       { printf("Linha %d: Operador lógico NÃO: %s\n", line_number, yytext); }

","             	       { printf("Linha %d: Separador vírgula: %s\n", line_number, yytext); }
";"             	       { printf("Linha %d: Separador ponto e vírgula: %s\n", line_number, yytext); }
"("             	       { printf("Linha %d: Separador parêntese esquerdo: %s\n", line_number, yytext); }
")"             	       { printf("Linha %d: Separador parêntese direito: %s\n", line_number, yytext); }
"{"             	       { printf("Linha %d: Separador chave esquerda: %s\n", line_number, yytext); }
"}"             	       { printf("Linha %d: Separador chave direita: %s\n", line_number, yytext); }
"["             	       { printf("Linha %d: Separador colchete esquerdo: %s\n", line_number, yytext); }
"]"             	       { printf("Linha %d: Separador colchete direito: %s\n", line_number, yytext); }

"\'"                       { printf("Linha %d: Aspas simples: %s\n", line_number, yytext); }
"\""                       { printf("Linha %d: Aspas dupla: %s\n", line_number, yytext); }

"//"[^\n]*         { /* Ignorar comentário de uma linha */}

"/*"[^*]*\*+([^/*][^*]*\*+)*"/"   { /* Ignorar comentário de bloco */ }

\n             { line_number++; }  // Incrementar o contador de linhas

[ \t\r]+       /* Ignorar espaços em branco e tabs */

.              {
                  printf("Linha %d: Erro: Caractere desconhecido: %s\n", line_number, yytext);
                  error_count++;
               }
%%

int yywrap();

int main(int argc, char **argv)
{
    ++argv, --argc;  /* Ignorar o nome do programa */
    if (argc > 0)
        yyin = fopen(argv[0], "r");
    else
        yyin = stdin;
    
    yylex();

    if (error_count == 0) {
        printf("Análise léxica concluída com sucesso. Nenhum erro encontrado.\n");
    } else {
        printf("Análise léxica concluída com %d erro(s).\n", error_count);
    }

    return 0;
}

int yywrap() {
    return 1;
}
