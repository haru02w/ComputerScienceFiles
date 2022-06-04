#include <stdio.h>
#define max 15

int main()
{ 	int t, fib[max], ant=0, prox=1, aux;
		
	do{
		printf("\n\n Digite o termo (limite) desejado:");
		scanf("%d",&t);
		if (t<=0 || t>15)
			printf("\n Digite um valor no intervalo de 1 a 15!");
	}while(t<=0 || t>max);
	
	printf("\n\n - Série de Fibonacci: ");
	printf("%d", prox);
	
	for (int i=1; i<t; i++) // Início de i em 1, pois o primeiro termo já foi mostrado via variável prox
	{
		aux=ant+prox;
		//printf(" %d", aux);
		fib[i]=aux;
        ant=prox;
		prox=aux;
	}
    for (int i=1; i<t; i++) // Início de i em 1, pois o primeiro termo já foi mostrado via variável prox
	    printf(" %d", fib[i]);
	

	printf("\n");
	//system("PAUSE");
	return 0;
}




