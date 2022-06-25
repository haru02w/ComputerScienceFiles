#include <stdio.h>
#include <stdlib.h>

int main() 
{
    //Variaveis
    float v[6];
    int i;
    int contagem = 0;
    float soma = 0;

    //Programa principal
	for (i=0; i<6; i=i+1)
	{
	    printf("Digite v[%d]: \n", i); 
		scanf("%f", &v[i]);	
	}
	
	for (i=0; i<6; i++)
	{
		if (v[i] < 0)
		{
		  contagem = contagem + 1;
	      soma = soma + v[i];
		}
	}
	
	//media = soma/contagem;
	
	printf("Qtde de numeros negativos: %d\n" , contagem);
	printf("Media aritmetica negativos: %f", (soma/contagem));

	return 0;
}
