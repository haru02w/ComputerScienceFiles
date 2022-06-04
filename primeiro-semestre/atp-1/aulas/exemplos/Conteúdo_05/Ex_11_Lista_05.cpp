#include <stdio.h>
#include <locale.h> 
	
#define N 5

int main()
{  setlocale(LC_ALL, "Portuguese");
	
	int resp, v[N], maior, menor, aux, inter_1, inter_2;
	
	printf("\n\t\t\t - Exercício 11 - Lista 05 -");
	
	printf("\n Digite %d números\n", N);
	
	for (int i=0;i<N;i++)
		scanf("%d", &v[i]);
		
	do{
		do{
			printf("\t\t\n\n--- MENU ---\n");
			printf("\n1.Ordenar elementos em ordem crescente");
			printf("\n2.Ordenar elementos em ordem decrescente");
			printf("\n3.Imprimir todo o vetor");	
			printf("\n4.Imprimir as posicoes de um intervalo especificado pelo usuario");
			printf("\n0.Sair  ");
		  	scanf("%d", &resp);	
		  	if (resp<0 || resp>4)
		  		printf ("\nEntrada inválida!");
		  	
		}while(resp<0 || resp>4);
		
		if (resp==0)
			printf("\n Programa encerrado!");
		else if ((resp>=1) && (resp<=3))
		{
			if (resp==1)
			{
				printf("\nElementos em ordem crescente: ");
				for (int i=0; i<N; i++)
				{
					menor=i;
					for (int j=i; j<N; j++)
					{
						if (v[j] < v[menor])
							menor = j;
					}
			
					aux = v[i];
					v[i] = v[menor];
					v[menor] = aux;	
				}
			}
			else if (resp==2)
			{
				printf("\nElementos em ordem decrescente: ");
				for (int i=0;i<N;i++)
				{	
					maior = i;
					for (int j=i;j<N;j++)
					{
						if (v[j] > v[maior])
							maior = j;
					}	
					aux = v[i];
					v[i] = v[maior];
					v[maior] = aux;
				}
			}
			else 
				printf("\nImprimir todo o vetor: ");
			
			for(int i=0;i<N;i++)
				printf("[%d]", v[i]);
			
		} 
		else if (resp == 4) 
		{
			do{
				
				printf("\n Digite o primeiro numero do intervalo (0 < %d): \n", N);
				scanf("%d", &inter_1);
				if(inter_1<0 || inter_1>=N)
					printf("\nIntervalo inválido!");	
			}while(inter_1 < 0 || inter_1>=N);
				
			do{
			
				printf("\n Digite o segundo numero do intervalo (%d < %d): \n", inter_1, N);
				scanf("%d", &inter_2);
				if(inter_2<inter_1 || inter_2>=N)
					printf("\nIntervalo inválido!");	
			}while(inter_2<inter_1 || inter_2>=N);
				
									
			if(inter_1==inter_2)
				printf("\n Valor no intervalo (%d-%d): %d", inter_1, inter_2, v[inter_1]);
			else 
			{
				for(int intervalo=inter_1; intervalo<=inter_2; intervalo++)
					printf("Resultado: [%d]\n", v[intervalo]);
			}
		}
		
	}while (resp!=0);

	return 0;
} 
