#include <stdio.h>
#define max 3
int main()
{
	char nome[30], end[60], cid[40], cep[9], sexo;
  	//Exemplo entrada de Dados
  
  	for (int i=0; i<max; i++)
    {
  		printf("\nDigite o nome: ");
  		scanf(" %[^\n]s",nome);
	  		
	  	printf("\nDigite o endereço: ");
	  	scanf(" %[^\n]s",end);	
	  		
	  	printf("\nDigite a cidade: ");
  		scanf(" %[^\n]s",cid);
  		  	
	  	printf("\nDigite o cep: ");
  		scanf(" %[^\n]s",cep);
  		  	
  		printf("\nSexo : ");
  		scanf(" %c",&sexo);
    	
  		printf("\nNome: %s",nome);
    	printf("\nEndereço: %s",end);
		printf("\nCidade: %s",cid);
   		printf("\nCep: %s",cep);
   		printf("\nSexo: %c",sexo);
  	}
  	
 	//system("PAUSE"); 
	return 0;
 }
