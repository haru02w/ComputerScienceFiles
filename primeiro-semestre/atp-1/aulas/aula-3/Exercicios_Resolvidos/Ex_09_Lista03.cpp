//Diretivas de Pr�-processamento (Obrigat�rias)
#include <stdio.h>
//#include <stdlib.h>
//Obrigat�rio. Fun��o principal: indica o in�cio da execu��o do programa

int main ()
{	
	//Declara��o de Vari�veis Locais. 
	int num;
	//Obrigat�rio. Comandos para resolu��o do problema
	//Poss�veis mensagens para indicar as entradas
 	printf("\nDigite um n�mero:");
	scanf("%d",&num);
	
	//Processamento e sa�da
	if (num%4 == 0)
		printf("\n N�mero digitado %d � divis�vel por 4!", num);
	else
		printf("\n N�mero inv�lido!");

  //	system("PAUSE");
  	//Retorno ao SO o status do programa
  	return 0;
}//Indica o final do programa.

