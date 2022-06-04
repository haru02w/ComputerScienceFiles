//Diretivas de Pré-processamento (Obrigatórias)
#include <stdio.h>
//#include <stdlib.h>
//Obrigatório. Função principal: indica o início da execução do programa
int main ()
{	int prod;
	printf ("\nDigite o código do produto: \n");
	scanf("%d",&prod);
	switch(prod)
    {	case 1 ... 5: printf("Produto categoria 1"); break;
		case 6: printf("Produto categoria 2"); break;
		default: printf("Categoria não cadastrada"); break;
	}
	//Opcional. Comando para interromper momentaneamente o programa
  //	printf("\n");
  //	system("PAUSE");	
  	//Retorno ao SO o status do programa
  	return 0;
}//Indica o final do programa.
