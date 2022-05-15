#include <stdio.h>
#include <stdlib.h>

//Programa para inverter n�meros usando resto de divis�es
int main() 
{
	//Vari�veis
	int N, M, aux; 
	int C, D, U; //C: Centena, D: Dezena, U: Unidade
	
	//Programa principal
	printf("Digite um n�mero com tr�s algarismos: ");
	scanf("%d", &N);
	
	//Convers�es e manipula��o dos d�gitos
	aux = (N % 100); //Capturando os dois �ltimos d�gitos com o resto da divis�o inteira
	
	D = aux / 10;    //Capturando a dezena com a divis�o inteira
	U = aux % 10;    //Capturando a unidade com o resto da divis�o inteira
	C = N / 100;     //Capturando a centena com a divis�o inteira
	
	M = 100*U + 10*D + C;//Constru�ndo o n�mero invertido a partir de seus algar�smos
	
	printf("N�mero invertido: %d", M);
	
	return 0;
}
