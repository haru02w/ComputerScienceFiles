#include <stdio.h>
#include <stdlib.h>

//Programa para inverter números usando resto de divisões
int main() 
{
	//Variáveis
	int N, M, aux; 
	int C, D, U; //C: Centena, D: Dezena, U: Unidade
	
	//Programa principal
	printf("Digite um número com três algarismos: ");
	scanf("%d", &N);
	
	//Conversões e manipulação dos dígitos
	aux = (N % 100); //Capturando os dois últimos dígitos com o resto da divisão inteira
	
	D = aux / 10;    //Capturando a dezena com a divisão inteira
	U = aux % 10;    //Capturando a unidade com o resto da divisão inteira
	C = N / 100;     //Capturando a centena com a divisão inteira
	
	M = 100*U + 10*D + C;//Construíndo o número invertido a partir de seus algarísmos
	
	printf("Número invertido: %d", M);
	
	return 0;
}
