#include <stdio.h>
#include <stdlib.h>
#include <math.h>   //sqrt

#define n 10

int main() 
{
	//Vari�veis
	float v[n], soma = 0, media, desv_pad;
	int i;
	
	//Rotina principal
	//--------------------------------------------
	//Leitura do vetor e c�lculo da soma dos n elementos
	for (i=0; i<n; i++){
		printf("Digite v[%d]: ", i+1);
		scanf("%f", &v[i]);
		soma = soma + v[i];   //Acumula a soma dos n elementos
	}
	
	//C�lculo m�dia
	media = soma / n;
	soma = 0;
	
	//C�lculo da soma interna do desvio padr�o
	for (i=0; i<n; i++)
		soma = (v[i] - media)*(v[i] - media);
    
    //C�lculo do desvio padr�o
    desv_pad = sqrt(soma / (n-1));
    
    //Sa�da
    printf("M�dia: %f\n", media);
    printf("Desvio Padrao: %f\n", desv_pad);
	
	//--------------------------------------------	
	return 0;
}
