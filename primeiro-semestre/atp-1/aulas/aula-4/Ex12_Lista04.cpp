#include <stdio.h>

#define total 4 //alterar para 50
int main()
{
	char sexo;
	int num_h=0, num_m=0, i;
	float altura, maior_h, menor_h, maior_m, menor_m, total_h, total_m, diferenca;
	
	for(i=0; i<total; i++)
	{  
		do
		{
			printf("Digite o Sexo <m>asculino ou <f>eminino:\n");
			//fflush(stdin);
			scanf(" %c",&sexo);
			
						
		}while(sexo!='m' && sexo!='f');// valida a entrada	

		printf("\nDigite a altura em metros: ");
		scanf("%f", &altura);
		
		if(sexo=='m')
		{
			if (num_h==0) //inicialização para comparação
			{ 
				maior_h=altura;menor_h=altura;
				total_h=altura; 
			}
			else
			{
				if(altura>maior_h)
				{
					maior_h=altura; //armazena maior altura para mulher
				}
				else if(altura<menor_h)
				{
					menor_h=altura; //armazena maior altura para mulher
				}
				total_h=total_h+altura; //calcula total de homens para cada entrada
			}
			num_h++; //incrementa variável para ter o total de homens
		}
		else
		{
			if (num_m==0) //inicialização para comparação
			{ 
				maior_m=altura;menor_m=altura;
				total_m=altura;
			}
			else
			{
				if(altura>maior_m)
				{
					maior_m=altura; //armazena maior altura para mulher
				}
				else if(altura<menor_m)
				{
					menor_m=altura; //armazena maior altura para mulher
				}
				total_m=total_m+altura; //calcula total de mulheres para cada entrada
			}
			num_m++; //incrementa variável para ter o total de mulheres
		}
	}
	//item (a)
	printf("\n\n\t Maior altura - homem: %.2f",maior_h);
	printf("\n\n\t Menor altura - homem: %.2f",menor_h);
	printf("\n\n\t Maior altura - mulher: %.2f",maior_m);
	printf("\n\n\t Menor altura - mulher: %.2f",menor_m);
	//item (b)
	printf("\n\n\t Altura média - mulheres: %.3f",total_m/num_m);
	printf("\n\n\t Altura média - homens: %.3f",total_h/num_h);
	//item (c)
	printf("\n\n\t Número de homens: %d",num_h);
	diferenca=total_h-total_m;
	
	if (diferenca!=0)
		diferenca=(diferenca/(total_h+total_m))*100;
				
	printf("\n\n\t Diferença de altura entre homens e mulheres: %.2f%%",diferenca);
	
	//system("PAUSE");
	return 0;
}	
