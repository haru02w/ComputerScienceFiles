#include <stdio.h>
#include <stdlib.h>
#include <math.h>  //Biblioteca interna contendo f�rmulas e fun��es matem�ticas
 
int main(void)
{
    
    //Vari�veis
    int N, count, soma;
	 
    //Programa principal
    printf("Digite N um n�mero inteiro positivo: ");
    scanf("%d", &N);
    
    
    //Calcula a soma dos N primeiros n�meros, isto �, 1 + 2 + 3 + ... + N-1 + N
    soma = 0;  //Inicializa a vari�vel acumuladora 'soma' ANTES de entrar no la�o de repeti��o
    count = 1; //Inicializa a vari�vel contadora 'count' ANTES de come�ar a iterar (entrar no la�o)
	do
    {
      soma = soma + count; //Soma os N primeiros n�meros, elemento a elemento dentro do la�o de repeti��o
	  count = count + 1;   //Incrementa ('anda') com a vari�vel contadora 'count'  	
	} while (count <= N);  //Vai repetir as instru��es que est�o dentro das chaves ENQUANTO a vari�vel 'count' for < ou = � 'N'
 
    //Imprime o resultado da soma dos N primeiros n�meros inteiros positivos
    printf("Soma: %d", soma);
    
    //system("pause"); para pausar (usar no Dev-C)
 
    return 0;
}
