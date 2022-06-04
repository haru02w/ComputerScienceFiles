//Diretivas de Pré-processamento (Obrigatórias)
#include <stdio.h>

//Obrigatório. Função principal: indica o início da execução do programa

int main ()
{	
	//Declaração de Variáveis Locais. 
	int fat, n, n1;
	//Obrigatório. Comandos para resolução do problema
	//Possíveis mensagens para indicar as entradas

	printf("Fatorial de um número - digite um valor: ");
  	scanf("%d", &n);
    n1=n;
  	fat = 1;

  	while (n > 0) 
	{
    	fat = fat *  n;
    	n--;  
  	}

  	printf("%d! = %d \n", n1, fat);

  	//system("PAUSE");
	return 0;
	
}
