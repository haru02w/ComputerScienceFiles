//Diretivas de Pré-processamento (Obrigatórias)
#include <stdio.h>
#define n 4
//#include <stdlib.h>
//Obrigatório. Função principal: indica o início da execução do programa

int main ()
{	
	//Declaração de Variáveis Locais. 
	int num;
	//Obrigatório. Comandos para resolução do problema
	//Possíveis mensagens para indicar as entradas
 	printf("\nDigite um número:");
	scanf("%d",&num);
	
	//Processamento e saída
	if ((num/n) * n == num)
		printf("\n Número digitado %d é divisível por %d!", num,n);
	else
		printf("\n Número inválido!");

  //	system("PAUSE");
  	//Retorno ao SO o status do programa
  	return 0;
}//Indica o final do programa.

