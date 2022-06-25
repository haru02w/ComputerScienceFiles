#include <stdio.h>
#include <stdlib.h>
#include <math.h>   //sqrt

#define n 10

int main() 
{
	//Variáveis
	float v[n], soma = 0, media, desv_pad;
	int i;
	
	//Rotina principal
	//--------------------------------------------
	//Leitura do vetor e cálculo da soma dos n elementos
	for (i=0; i<n; i++){
		printf("Digite v[%d]: ", i+1);
		scanf("%f", &v[i]);
		soma = soma + v[i];   //Acumula a soma dos n elementos
	}
	
	//Cálculo média
	media = soma / n;
	soma = 0;
	
	//Cálculo da soma interna do desvio padrão
	for (i=0; i<n; i++)
		soma = (v[i] - media)*(v[i] - media);
    
    //Cálculo do desvio padrão
    desv_pad = sqrt(soma / (n-1));
    
    //Saída
    printf("Média: %f\n", media);
    printf("Desvio Padrao: %f\n", desv_pad);
	
	//--------------------------------------------	
	return 0;
}
