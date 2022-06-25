#include <stdio.h>
#include <stdlib.h>

int main() 
{
	//Variávies
	int A[2][2];
	int i, j, det;
	
	//Programa principal
	for (i=0; i<2; i++)
	   for (j=0; j<2; j++)
	   {
	   	   printf("Digite A[%d][%d]:",i,j);
	   	   scanf("%d",&A[i][j]);
	   }
	
	//Calculo do determinante da matriz
	det = A[0][0] * A[1][1] - A[0][1] * A[1][0];
    
	printf("Determinante: %d", det);	
	   
	return 0;
}
