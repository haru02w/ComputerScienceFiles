/* 

Construir o analizador lexico usando o gerador FLEX
Aceitar nome de variavel, numeros, sinal de atribuição, operadores matematicos, separadores:

,;(){}[]
*/

%{
%}

variavel [a-zA-Z_][a-zA-Z0-9_]*
numeros [0-9]*
sinais "+"|"-"|"*"|"/"
separador "("|")"|"["|"]"|"{"|"}"

%%
{numeros}    printf("Numero: %s\n", yytext);
{variavel}   printf("Variavel: %s\n", yytext);
{sinais}     printf( "Operador: %s\n", yytext );
"="          printf("Sinal de Atribuição: %s\n", yytext);
{separador}  printf("Separador: %s\n", yytext);
%%

int yywrap();

int main( int argc, char **argv )
{
    ++argv, --argc;  /* skip over program name */
    if ( argc > 0 )
        yyin = fopen( argv[0], "r" );
    else
        yyin = stdin;
    yylex();
}

int yywrap() {
    return 1;
}
