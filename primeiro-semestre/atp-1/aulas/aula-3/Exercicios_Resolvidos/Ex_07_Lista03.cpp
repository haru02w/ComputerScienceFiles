//Diretivas de Pr�-processamento (Obrigat�rias)
#include <stdio.h>
#include <stdlib.h>
//Obrigat�rio. Fun��o principal: indica o in�cio da execu��o do programa
int main ()
{	int prod;
	printf ("\nDigite o c�digo do produto: \n");
	scanf("%d",&prod);
	switch(prod)
    	{	
		case 1: printf("\nSul"); break;
		case 2: printf("\nNorte"); break;
		case 3: printf("\nLeste"); break;
		case 4: printf("\nOeste"); break;
		case 5: 
		case 6: 
		case 12 ... 15: printf("\nNordeste"); break;
		case 7 ... 9: printf("\nSudeste"); break;
		case 10:
		case 11: printf("\nCentro-Oeste"); break;
		default: printf("Importado"); break;
	
	}
	//Opcional. Comando para interromper momentaneamente o programa
    	//system("PAUSE");	
  	//Retorno ao SO o status do programa
  	return 0;
}//Indica o final do programa.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             sEDUsEDU                                                                                                                                                                                                                                                                                                                                      
