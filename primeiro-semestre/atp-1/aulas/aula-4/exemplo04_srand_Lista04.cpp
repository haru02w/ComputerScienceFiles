#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define n 6000
int main()
{	int f1=0,f2=0,f3=0,f4=0,f5=0,f6=0,k,i;
	setlocale(LC_ALL,"portuguese");
		
	printf("\nAplica��o de srand() com escala - uso de seed \n");

	srand(time(NULL));
	
	printf("\nGerador de %d n�meros no intervalo de 1 a 6\n",n);
	
	for (i=0; i<n;i++)
	{ 	
		k=1+rand()%6;
		switch(k)
    	{
			case 1:f1++;break;
			case 2:f2++;break;
			case 3:f3++;break;
			case 4:f4++;break;
			case 5:f5++;break;
			default:f6++;break;
    	}
	}
		
	printf("\nTotal de n�meros sorteados: %d",i);
	printf("\n n�mero 1, %d vezes;",f1);
	printf("\n n�mero 2, %d vezes;",f2);
	printf("\n n�mero 3, %d vezes;",f3);
	printf("\n n�mero 4, %d vezes;",f4);
	printf("\n n�mero 5, %d vezes;",f5);
	printf("\n n�mero 6, %d vezes.",f6);
	
			
	return 0;
}
