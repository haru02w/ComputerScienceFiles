#include <stdio.h>
#include <stdlib.h>

int main() 
{
	//Vari�veis
	float Fahrenheit, Celsius;
	
	//Programa principal
	printf("Digite o valor da temperatura em Fahrenheit: ");
	scanf("%f", &Fahrenheit);
	
	//Convers�o da temperatura
	Celsius = (5*Fahrenheit - 160) / 9;
	
	//Impress�o do resultado
	printf("Valor da temperatura em Celsius: %f", Celsius);
	
	return 0;
}
