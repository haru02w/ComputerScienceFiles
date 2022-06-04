#include <stdio.h>
#include <stdlib.h>
#include <math.h>  //Para usar o fabs (módulo de um número)

int main() 
{	
	//Variáveis
	int i, N, sinal;
	float epsilon; //Valor limite dos termos da série numérica
	float soma, T, den;
	
	//Programa principal
	printf("Digite o valor de E: ");
	scanf("%f", &epsilon);
	
	//Inicialização de variáveis
	den = -1;
	sinal = -1;
	soma = 0;
	
	do {
		den = den + 2;  //Avança p/ construír o próximo termo
		sinal = -sinal; //Inverte o sinal (aqui fica variando entre -1 e 1)
		
		T = sinal/den;  //Calcula o termo geral da soma (-1)^n / (2n + 1)
		//printf("vvv: %f", T);
		
		soma = soma + T;
    }
	while (fabs(T) > epsilon); //Enquanto |T| < epsilon, continua o loop
				
	//Imprime o resultado
	printf("Pi vale: %f", 4*soma);	
		
}


