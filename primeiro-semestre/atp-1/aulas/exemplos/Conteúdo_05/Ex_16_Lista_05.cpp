#include <stdio.h>
#include <stdlib.h>
#define max 11
int main()
{
	int mc, res[max];
	
	printf("\nDigite um multiplicando: ");
	scanf("%d", &mc);
	
	//La�o para realizar a multiplica��o. Armazenar em um vetor o resultado
	for (int i=0;i<max; i++)
		res[i]=mc*i;
	
  //La�o para apresenta��o
	for (int i=0;i<max; i++)
		printf("\n %d x %d = %d", mc, i, res[i]);
  
	return 0;
}

