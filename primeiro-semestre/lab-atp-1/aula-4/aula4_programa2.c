#include <stdio.h>
#include <stdlib.h>
#include <math.h>  //Biblioteca interna contendo fórmulas e funções matemáticas
 
int main(void)
{
    
    //Variáveis
    int N, count, soma;
	 
    //Programa principal
    printf("Digite N um número inteiro positivo: ");
    scanf("%d", &N);
    
    
    //Calcula a soma dos N primeiros números, isto é, 1 + 2 + 3 + ... + N-1 + N
    soma = 0;  //Inicializa a variável acumuladora 'soma' ANTES de entrar no laço de repetição
    count = 1; //Inicializa a variável contadora 'count' ANTES de começar a iterar (entrar no laço)
	do
    {
      soma = soma + count; //Soma os N primeiros números, elemento a elemento dentro do laço de repetição
	  count = count + 1;   //Incrementa ('anda') com a variável contadora 'count'  	
	} while (count <= N);  //Vai repetir as instruções que estão dentro das chaves ENQUANTO a variável 'count' for < ou = à 'N'
 
    //Imprime o resultado da soma dos N primeiros números inteiros positivos
    printf("Soma: %d", soma);
    
    //system("pause"); para pausar (usar no Dev-C)
 
    return 0;
}
