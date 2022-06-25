//Diretivas de Pré-processamento (Obrigatórias)
#include <stdio.h>
#include <stdlib.h>
//Obrigatório. Função principal: indica o início da execução do programa
int main ()
{	char mes;
	printf ("\nDigite a primeira letra de mês: \n");
	scanf("%c",&mes);
	switch(mes)
    {
    	case 'J':
    		printf("Janeiro e Julho têm 31 dias. Junho tem 30 dias "); break;
    	case 'M':
    	printf("Março e Maio têm 31 dias "); break;
    	case 'A':
    	case 'O':
    	case 'D':
    		printf("Este mês tem 31 dias"); break;
        case 'F':
            printf("Este mês tem 28 ou 29 dias"); break;
        default:
            printf("Este mês tem 30 dias"); break;
	}
	//Opcional. Comando para interromper momentaneamente o programa
  	
  	//system("PAUSE");	
  	//Retorno ao SO o status do programa
  	return 0;
}//Indica o final do programa.
