//Diretivas de Pr�-processamento (Obrigat�rias)
#include <stdio.h>
#include <stdlib.h>
/*Opcional. 
Declara��es de Vari�veis Globais. 
Declara��es de Fun��es. Importante, n�o vamos estudar em ATPI*/
//Obrigat�rio. Fun��o principal: indica o in�cio da execu��o do programa
int main ()
{	
	//Opcional. Declara��o de Vari�veis Locais. Estudado em ATPI
	char nome[40];
 	int idade; 
 	
 	//Obrigat�rio. Comandos para resolu��o do problema
 	printf("Digite o seu nome: ");
 	scanf("%s",&nome);
 	printf("\nDigite sua idade: ");
 	scanf("%d",&idade);
 	printf("\nOl� %s, sua idade � %d ",nome,idade);
 	
 	//Opcional. Comando para interromper momentaneamente o programa
  	system("PAUSE");	
  	//Retorno ao SO o status do programa
  	return 0;
}//Indica o final do programa.
