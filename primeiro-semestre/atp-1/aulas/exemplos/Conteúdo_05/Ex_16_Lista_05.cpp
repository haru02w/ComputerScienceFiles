#include <stdio.h>
#include <stdlib.h>
#define max 11
int main()
{
	int mc, res[max];
	
	printf("\nDigite um multiplicando: ");
	scanf("%d", &mc);
	
	//Laço para realizar a multiplicação. Armazenar em um vetor o resultado
	for (int i=0;i<max; i++)
		res[i]=mc*i;
	
  //Laço para apresentação
	for (int i=0;i<max; i++)
		printf("\n %d x %d = %d", mc, i, res[i]);
  
	return 0;
}

