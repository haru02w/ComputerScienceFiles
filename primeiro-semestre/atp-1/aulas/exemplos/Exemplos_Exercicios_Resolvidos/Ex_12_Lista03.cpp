//Diretivas de Pré-processamento (Obrigatórias)
#include <stdio.h>
//#include <stdlib.h>
//Obrigatório. Função principal: indica o início da execução do programa

int main ()
{	
	//Declaração de Variáveis Locais. 
	int num_1, num_2, num_3, num_4, num_5;
	//Obrigatório. Comandos para resolução do problema
	//Possíveis mensagens para indicar as entradas
 	printf("\nDigite cinco números:");
	printf("\nPrimeiro valor:");
	scanf("%d",&num_1);
	printf("\nSegundo valor:");
	scanf("%d",&num_2);
	printf("\nTerceiro valor:");
	scanf("%d",&num_3);
	printf("\nQuarto valor:");
	scanf("%d",&num_4);
	printf("\nQuinto valor:");
	scanf("%d",&num_5);
	//Identificação do maior número e a saída
	if (num_1>num_2 && num_1>num_3 && num_1>num_4 && num_1>num_5)
		printf("\n numero maior é: %d", num_1);
	else if (num_2>num_3 && num_2>num_4 && num_2>num_5)
		printf("\n numero maior é: %d", num_2);
	else if (num_3>num_4 && num_3>num_5)
		printf("\n numero maior é: %d", num_3);
	else if (num_4>num_5)
		printf("\n numero maior é: %d", num_4);
	else
		printf("\n numero maior é: %d", num_5);

	//Identificação do menor número e a saída
	if (num_1<num_2 && num_1<num_3 && num_1<num_4 && num_1<num_5)
		printf("\n numero menor é: %d", num_1);
	else if (num_2<num_3 && num_2<num_4 && num_2<num_5)
		printf("\n numero menor é: %d", num_2);
	else if (num_3<num_4 && num_3<num_5)
		printf("\n numero menor é: %d", num_3);
	else if (num_4<num_5)
		printf("\n numero menor é: %d", num_4);
	else
		printf("\n numero menor é: %d", num_5);

  	
  //	system("PAUSE");
  	//Retorno ao SO o status do programa
  	return 0;
}//Indica o final do programa.

