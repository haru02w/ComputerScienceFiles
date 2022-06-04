//Diretivas de Pré-processamento (Obrigatórias)
#include <stdio.h>
#include <stdlib.h>
#define n 10
//Obrigatório. Função principal: indica o início da execução do programa
int main ()
{	
	//Declaração de Variáveis Locais. 
	int cod_func[n];
	float sal_func[n], sal_reajuste[n], total_sal_base=0, total_sal_reaj=0;
	char nome_func[n][40];

	printf("\n\n\t\t - Programa Reajuste de Salário -");	
	for (int i=0; i<n; i++)
	{
		
		printf("\n\n\tDigite o código do funcionário: ");
 		scanf("%d",&cod_func[i]);
		//Obrigatório. Comandos para resolução do problema
 		printf("\n\tDigite o salário do funcionário: ");
 		scanf("%f",&sal_func[i]);
 		printf("\n\tDigite o nome do funcionário: ");
		scanf(" %[^\n]s",nome_func[i]);
		//setbuf(stdin,NULL);
		//Acumula salário base
		total_sal_base+=sal_func[i];			
		
		if (sal_func[i]<500)
 			sal_reajuste[i]=sal_func[i]*1.15;
		else if (sal_func[i]>=500 && sal_func[i]<=1000)
			sal_reajuste[i]=sal_func[i]*1.10;
		else 
			sal_reajuste[i]=sal_func[i]*1.05;
		//Acumula salário reajustado
		total_sal_reaj+=sal_reajuste[i];			
					
	}
	printf("\n\n\t__________________________________________________________________________________");
	printf("\n\t\t\tLista de Salários dos Funcionários da Empresa AB");
	printf("\n\t__________________________________________________________________________________");
	printf("\n\t\tCodigo\tNome\t\t\t\tSal. Base\tSalario Reajustado");
	printf("\n\t__________________________________________________________________________________");

	for (int i=0; i<n; i++)
	{
		printf("\n\t\t%d\t%s\t\t\t\t%.2f\t\t\t%.2f", cod_func[i],nome_func[i], sal_func[i],sal_reajuste[i]) ;
 	}
  		
	printf("\n\n\t__________________________________________________________________________________");
	printf("\n\n\t\t\t\t\t\tTotal:|%.2f\t\t\t|%.2f",total_sal_base,total_sal_reaj);
	printf("\n\n\t__________________________________________________________________________________\n");
  	//Opcional. Comando para interromper momentaneamente o programa
	// system("PAUSE");	
  	//Retorno ao SO o status do programa
  	return 0;
}//Indica o final do programa.


