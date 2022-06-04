//Diretivas de Pré-processamento (Obrigatórias)
#include <stdio.h>
//#include <stdlib.h>
//Obrigatório. Função principal: indica o início da execução do programa
int main ()
{	int voto;
	printf ("\nDigite seu voto: \n");
	scanf("%d",&voto);
	switch(voto)
    {	case 1: printf("Candidato 1"); break;
		case 2: printf("Candidato 2"); break;
		case 3: printf("Candidato 3"); break;
		case 4: printf("Candidato 4"); break;
		default: printf("Inválido"); break;
	}
	//Opcional. Comando para interromper momentaneamente o programa
  	printf("\n");
  	system("PAUSE");	
  	//Retorno ao SO o status do programa
  	return 0;
}//Indica o final do programa.
