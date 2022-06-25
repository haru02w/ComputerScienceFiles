//Diretivas de Pré-processamento (Obrigatórias)
#include <stdio.h>
#include <stdlib.h>
/*Opcional. 
Declarações de Variáveis Globais. 
Declarações de Funções. Importante, não vamos estudar em ATPI*/
//Obrigatório. Função principal: indica o início da execução do programa
int main ()
{	
	//Opcional. Declaração de Variáveis Locais. Estudado em ATPI
	char nome[40];
 	int idade; 
 	
 	//Obrigatório. Comandos para resolução do problema
 	printf("Digite o seu nome: ");
 	scanf("%s",&nome);
 	printf("\nDigite sua idade: ");
 	scanf("%d",&idade);
 	printf("\nOlá %s, sua idade é %d ",nome,idade);
 	
 	//Opcional. Comando para interromper momentaneamente o programa
  	system("PAUSE");	
  	//Retorno ao SO o status do programa
  	return 0;
}//Indica o final do programa.
