#include <stdio.h>

#define max 10
int main()
{
	int A[max], B[max];
	
	printf("\nDigite %d valores: ",max);

	
	//La�o para armazenar os valores
	for (int i=0;i<max; i++)
	{	
		printf("\n%do. valor: ", i+1);
		scanf("%d", &A[i]);
		if (A[i]>=0)
			B[i]=A[i];
	}
  //La�o para apresenta��o
	for (int i=0;i<max; i++)
		printf("\n Valores de A[%d]->%d e B[%d]->%d",i,A[i],i,B[i]);
	
  
	return 0;
}
