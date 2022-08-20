//Diretivas de Pré-processamento (Obrigatórias)
#include <stdio.h>
#include <i:\bibli\divisivel.h>
#define n 4

/*int divisivel(int num_1, int num_2)
{
	if ((num_1/num_2) * num_2 == num_1)
	   return 1;
	else
	   return 0;  
	 	
}
*/
int main ()
{	
	//Declaração de Variáveis Locais. 
	int num;
	//Obrigatório. Comandos para resolução do problema
	//Possíveis mensagens para indicar as entradas
 	printf("\nDigite um número:");
	scanf("%d",&num);
	
	//Processamento e saída
	if (divisivel(num,n))
		printf("\n Número digitado %d é divisível por %d!", num,n);
	else
		printf("\n Número digitado %d NÃO é divisível por %d!", num,n);

  //	system("PAUSE");
  	//Retorno ao SO o status do programa
  	return 0;
}//Indica o final do programa.

