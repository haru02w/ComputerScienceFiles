//Programa Ex14
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main()
{ setlocale(LC_ALL,"portuguese");
	//Declaração de Variáveis
	int	c1=0,c2=0,c3=0,c4=0,nulo=0,branco=0,op, total;
		
	
	//Entrada de Dados

	//laço para definir se continua execução
	do{
		//Opções
      	system("clear");
      	printf ("\n\n\t\t---Programa Eleição presidencial---");
		printf("\n\n\t\t <1> Candidato 1");
		printf("\n\t\t <2> Candidato 2");
		printf("\n\t\t <3> Candidato 3");
		printf("\n\t\t <4> Candidato 4");
		printf("\n\t\t <5> Nulo");
		printf("\n\t\t <6> Branco");
		printf("\n\n\t\t <0> Encerrar");
		
		do{
			printf("\n\t Escolha uma opção: ");
      		scanf("%d", &op);
			if (op<0 || op>6)
        		printf ("\n\t\tOpção inválida!");
      	}while (op<0 || op>6);
		//teste para definir se a opção escolhida foi encerrar
		//Isso evita testes no switch e permite o programa encerrar, caso opção seja 0
		if (op!=0)
		{ printf("\n\t\tFique tranquilo, seu voto foi computado!");
			switch(op)
			{	
				case 1: c1++;break;
				case 2: c2++;break;
				case 3: c3++;break;
				case 4: c4++;break;
				case 5: nulo++;break;
				default: branco++;break;
			}
		}
		
	}while (op!=0);
	total=c1+c2+c3+c4+nulo+branco;
 	printf("\n\n\t\t Apuração - eleição presidencial");
	printf("\nTotal de votos para cada candidato:");
	if (c1!=0)
		printf("\nCandidato 1: %d, %.2f%%",c1,((float)c1/(float)total)*100);
	else
		printf("\nCandidato 1: %d, %.2f%%",c1,c1);
	
	if (c2!=0)	
		printf("\nCandidato 2: %d, %.2f%%",c2,((float)c2/(float)total)*100);
	else
		printf("\nCandidato 2: %d, %.2f%%",c2,c2);
		
	if (c3!=0)
		printf("\nCandidato 3: %d, %.2f%%",c3,((float)c3/(float)total)*100);
	else
		printf("\nCandidato 3: %d, %.2f%%",c3,c3);
		
	if (c4!=0)	
		printf("\nCandidato 4: %d, %.2f%%",c4,((float)c4/(float)total)*100);
	else
		printf("\nCandidato 4: %d, %.2f%%",c4,c4);
		
	printf("\n\nTotal de votos: %d",total);

  
 	if (nulo!=0)
	  	printf("\nVotos Nulos: %d, representando %.2f%% dos votos",nulo, ((float)nulo/(float)total)*100);
  	else
    	printf("\nVotos Nulos: %d, representando %.2f%% dos votos", nulo, (float)nulo);
    	
 	if (branco!=0)
	 	printf("\nVotos Branco: %d, representando %.2f%% dos votos",branco, ((float)branco/(float)total)*100);
	else
		printf("\nVotos Branco: %d, representando %.2f%% dos votos",branco, (float)branco);
	
	if (c1+c2+c3+c4!=0)	
	 	printf("\n\nVotos válidos: %d, representando %.2f%% do total de votos",c1+c2+c3+c4, ((float)(c1+c2+c3+c4)/(float)total)*100);
	else
	 	printf("\n\nVotos válidos: %d, representando %.2f%%",c1+c2+c3+c4, (float)c1+c2+c3+c4);
	 	
	if (branco+nulo!=0)
		printf("\n\nVotos Branco e Nulos: %d, representando %.2f%% dos votos",branco+nulo, ((float)(branco+nulo) /(float)total)*100);
	else
		printf("\n\nVotos Branco e Nulos: %d, representando %.2f%% dos votos",branco+nulo, (float)branco+nulo);
	return 0;
}
