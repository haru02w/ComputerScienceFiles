#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define n 6
int main()
{
	setlocale(LC_ALL,"portuguese");
	printf("\nAplica��o de rand() com escala\n");
	
	printf("\nGerador de seis n�meros no intervalo de 1 a 6\n");
	for (int i=0; i<n;i++)
		printf("\n%do. n�mero aleat�rio: %d", i+1, 1 + rand()% 6);
			
	return 0;
}
