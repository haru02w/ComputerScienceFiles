#include <stdio.h>
#include <stdlib.h>

#define MAX 6

int main() 
{
    //Vari�veis
    int v[MAX];
    int i, j, aux;
    
    //Leitura do vetor (dados fornecidos pelo usu�rio) 
    for (i = 0; i < MAX; i++)
	{
	    printf("Digite v[%d]: \n", i); 
		scanf("%d", &v[i]);	
	}
	
	//Ordena��o do vetor (via m�todo da bolha)
	for (i = 0; i < MAX; i++)
	{
		for (j = i+1; j < MAX; j++)
    	{
      		if (v[j] < v[i])
      		{
         		aux = v[i];
         		v[i] = v[j];
         		v[j] = aux;
      		}
		}
	}
	
    //Impress�o do vetor ordenado 
    for (i = 0; i < MAX; i++)
	    printf("v[%d]: %d \n", i, v[i]); 

	return 0;
}
