#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define n 6
int main()
{
	setlocale(LC_ALL,"portuguese");
		
	printf("\nAplica��o de srand() com escala - uso de seed \n");

	//printf("\nDigite um valor inteiro como semente: ");
	//scanf("%d",&seed); 
	
    srand(time(NULL));
	printf("\nGerador de %d n�meros no intervalo de 1 a 6\n",n);
	for (int i=0; i<n;i++)
		printf("\n%do. n�mero aleat�rio: %d", i+1, rand()%6);
			
	return 0;
}
