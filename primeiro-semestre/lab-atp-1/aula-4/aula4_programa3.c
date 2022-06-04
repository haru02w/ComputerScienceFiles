#include <stdio.h>
#include <stdlib.h>

int main() 
{	
	//Variáveis
	int i, N, fat = 1;
	
	//Programa principal
	printf("Digite o valor de N: ");
	scanf("%d", &N);
	
	//Calcula o fatorial, termo a termo, a partir de um laço de repetição
	for (i=1; i<=N; i++)
		fat = fat * i;
	
	//Imprime o resultado
	printf("Fatorial de %d: %d", N, fat);	
		
}


