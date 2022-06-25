#include <stdio.h>
#include <stdlib.h>

int main() 
{
	//Variáveis
	float M[3][4];
	int i, j;
	float maior, menor;
	float S[3] = {0, 0, 0};
	
	//Programa principal
	for (i=0; i<3; i++)
	{
	   for (j=0; j<4; j++)
	   {
	   	  printf("Digite M[%d][%d]: ",i,j);
		  scanf("%f",&M[i][j]); 
	   }
	   printf("\n");
    }
	
	//Inicializacao dos valores
	maior = M[0][0];
	menor = M[0][0];
	
	//Encontra o maior e o menor
	for (i=0; i<3; i++)
	{
	   for (j=0; j<4; j++)
	   {
	   	  if (M[i][j] > maior)
			 maior = M[i][j];
			 
		  if (M[i][j] < menor)
		     menor = M[i][j]; 
	      	     
		  S[i] = S[i] + M[i][j];   
	   }
	   
	   printf("Soma da linha: %f\n", S[i]);
    }
	   
	 printf("Maior valor: %f\n", maior);
	 printf("Menor valor: %f", menor);	   
	
	return 0;
}
