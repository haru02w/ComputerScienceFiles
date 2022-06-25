#include <stdio.h>
#include <stdlib.h>
#define N 5   //Quantidade de linhas do triângulo de pascal

int main() 
{	
	int i, j;
	int pascal[N][N];
   
	//Constroi o triângulo de pascal
	for (i=0; i<N; i++) 
      for (j=0; j<=i; j++) 
	  {
        if (j==0 || i==j)
            pascal[i][j] = 1;
        else
            pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
      }
    
	//Imprime o triângulo de pascal   
    for (i=0; i<N; i++) 
	{
    	for (j=0; j<=i; j++)
    	  printf("%d ", pascal[i][j]);
    	
		printf("\n");
	}

	return 0;
}
