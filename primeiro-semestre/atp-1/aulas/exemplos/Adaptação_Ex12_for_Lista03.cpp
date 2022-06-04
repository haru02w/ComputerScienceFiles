//Diretivas de Pré-processamento (Obrigatórias)
#include <stdio.h>

//Obrigatório. Função principal: indica o início da execução do programa

int main ()
{	
	//Declaração de Variáveis Locais. 
	int num, maior, menor;
	//Obrigatório. Comandos para resolução do problema
	//Possíveis mensagens para indicar as entradas
 	printf("\nDigite cinco números:");
	
	for (int i=0;i<5;i++)
	{
		printf("\nDigite um número (%d): ", i);
		scanf("%d",&num);
		
		if (i==0) //inicialização para comparação
		{ 
			maior=num;
			menor=num;
		}
		else if (num>maior)//Identificação do maior número e a saída
		{
			maior=num;
		}
		else if (num<menor)//Identificação do menor número e a saída
		{
			menor=num;
		}
	}
	printf("\n O maior numero é: %d", maior);
	printf("\n O menor numero é: %d", menor);
	
  	printf("\n");
  //	system("PAUSE");
  	//Retorno ao SO o status do programa
  	return 0;
}//Indica o final do programa.

