//Diretivas de Pr�-processamento (Obrigat�rias)
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
	//Declara��o de Vari�veis Locais. 
	int num;
	//Obrigat�rio. Comandos para resolu��o do problema
	//Poss�veis mensagens para indicar as entradas
 	printf("\nDigite um n�mero:");
	scanf("%d",&num);
	
	//Processamento e sa�da
	if (divisivel(num,n))
		printf("\n N�mero digitado %d � divis�vel por %d!", num,n);
	else
		printf("\n N�mero digitado %d N�O � divis�vel por %d!", num,n);

  //	system("PAUSE");
  	//Retorno ao SO o status do programa
  	return 0;
}//Indica o final do programa.

