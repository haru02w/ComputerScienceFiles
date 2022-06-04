//Diretivas de Pré-processamento (Obrigatórias)
#include <stdio.h>
#include <stdlib.h>
//Obrigatório. Função principal: indica o início da execução do programa
int main ()
{	
	//Declaração de Variáveis Locais. 
	float sal_func, sal_reajuste;
 	//Obrigatório. Comandos para resolução do problema
 	printf("Digite o salário do funcionário: ");
 	scanf("%f",sal_func);
 	
	if (sal_func<500)
 	 	sal_reajuste+=sal_func*0.15;
	else if (sal_func>=500 && sal_func<=1000)
	 	sal_reajuste+=sal_func*0.10;
	else 
		sal_reajuste+=sal_func*0.05;
	
	printf("\nO salário do funcionário é: %.2f", sal_func);
 	printf("\nO salário com reajuste é: %.2f", sal_func+sal_reajuste);
 	//Opcional. Comando para interromper momentaneamente o programa
  //	printf("\n");
  //	system("PAUSE");	
  	//Retorno ao SO o status do programa
  	return 0;
}//Indica o final do programa.
