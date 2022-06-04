#include <stdio.h>
#include <stdlib.h>
#include <math.h>  //Para usar o fabs (m�dulo de um n�mero)

int main() 
{	
	//Vari�veis
	int i, N, sinal;
	float epsilon; //Valor limite dos termos da s�rie num�rica
	float soma, T, den;
	
	//Programa principal
	printf("Digite o valor de E: ");
	scanf("%f", &epsilon);
	
	//Inicializa��o de vari�veis
	den = -1;
	sinal = -1;
	soma = 0;
	
	do {
		den = den + 2;  //Avan�a p/ constru�r o pr�ximo termo
		sinal = -sinal; //Inverte o sinal (aqui fica variando entre -1 e 1)
		
		T = sinal/den;  //Calcula o termo geral da soma (-1)^n / (2n + 1)
		//printf("vvv: %f", T);
		
		soma = soma + T;
    }
	while (fabs(T) > epsilon); //Enquanto |T| < epsilon, continua o loop
				
	//Imprime o resultado
	printf("Pi vale: %f", 4*soma);	
		
}


