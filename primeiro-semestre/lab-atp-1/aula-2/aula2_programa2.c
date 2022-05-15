#include <stdio.h>
#include <stdlib.h>

int main() 
{
	//Variáveis
	float Fahrenheit, Celsius;
	
	//Programa principal
	printf("Digite o valor da temperatura em Fahrenheit: ");
	scanf("%f", &Fahrenheit);
	
	//Conversão da temperatura
	Celsius = (5*Fahrenheit - 160) / 9;
	
	//Impressão do resultado
	printf("Valor da temperatura em Celsius: %f", Celsius);
	
	return 0;
}
