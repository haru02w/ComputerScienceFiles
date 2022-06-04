//Diretivas de Pré-processamento (Obrigatórias)
#include <stdio.h>
#include <stdlib.h>
//Obrigatório. Função principal: indica o início da execução do programa
int main ()
{	
	float n1, n2, n3, media;
  	printf ("\nDigite três notas:\n");
	scanf("%f  %f  %f", &n1, &n2, &n3);
 	media= (n1+n2+n3)/3;
 	printf ("Média: %f", media);
 	if (media >= 5)
	   	printf ("\nAprovado");
    else
    	printf ("\nUhhh, não deu");
 	//Opcional. Comando para interromper momentaneamente o programa
  	//printf("\n");
  	//system("PAUSE");	
  	//Retorno ao SO o status do programa
  	return 0;
}//Indica o final do programa.
