/*

28.	Considere a matriz indicada no exercício 3. Construa um programa para ler um eixo de referência, 
sendo x (0), y (1) e z(2), e apresentar os valores dos planos (matrizes) perpendiculares ao eixo dado 
como entrada. Os planos (cortes/fatias) devem ser apresentados de 0 a m com os elementos correspondentes.
Aplicações: Computação Gráfica, imagens tomográficas e modelos de cores (RGB e CIELAB, também conhecido como L*a*b*).

*/

#include <stdio.h>
#include <locale.h>
#include <stdio.h>
#define m 3

int main()
{	
	setlocale(LC_ALL, "Portuguese");
	int A[m][m][m];
  	char eixo;
  	printf("\n\t\t Elementos da matriz A com dimensões %dx%dx%d\n",m,m,m);

  	for (int x=m-1; x>=0; x--)
	{
  		for (int y=m-1; y>=0; y--)
  		{	
      		for (int z=m-1; z>=0; z--)
  				A[x][y][z]=z;
		}
	}
  	
	printf("\n\n\t\t\t -- Visualização - horiz. (z) e vertical (y) -\n");
  	for (int x=0; x<m; x++)
	{
  		for (int y=0; y<m; y++)
  		{	
      		for (int z=0; z<m; z++)
  				printf("%d ", A[x][y][z]);
			printf("\n");
		}
		printf("\n");
	}
  	 
	
	do{
		
		printf("\n\t\t Digite o eixo de referência x (0), y (1) ou z (2):");
		scanf(" %c",&eixo);
		if (eixo!='x' && eixo!='y' && eixo!='z' && eixo!='X' && eixo!='Y' && eixo!='Z')
			printf("\n\t\tEixo inválido!\n");
	}while (eixo!='x' && eixo!='y' && eixo!='z'&& eixo!='X' && eixo!='Y' && eixo!='Z');
	
	printf("\n\n\t\t\t -- Corte perpendicular, ref. eixo %c --\n", eixo);
	if (eixo=='x' || eixo=='X')
	{
		for (int x=m-1; x>=0; x--)
		{
			printf("\n\n\t\t\t -- Corte em %c (fatia %d) - planos y,z - horiz. (z) --\n",eixo,x);
  			for (int y=m-1; y>=0;y--)
  			{	
      			for (int z=0; z<m; z++)
  					printf("\t\t%d ", A[x][y][z]);
				printf("\n");
 			}
 			printf("\n");
		}
	}
	else if (eixo=='y' || eixo=='Y')
	{
		for (int y=m-1; y>=0; y--)
		{
			printf("\n\n\t\t\t -- Corte em %c (fatia %d) - plano x,z - horiz. (z) --\n",eixo,y);
  			for  (int x=m-1; x>=0; x--)
  			{	
      			for (int z=0; z<m; z++)
  					printf("\t\t%d ", A[x][y][z]);
				printf("\n");
 			}
 			printf("\n");
		}
	}
	else
	{
		for (int z=m-1; z>=0; z--)
		{
			printf("\n\n\t\t\t -- Corte em %c (fatia %d) - planos x,y - horiz. (x) --\n",eixo,z);
  			for (int x=m-1; x>=0; x--)
  			{	
      			for (int y=m-1; y>=0; y--)
  					printf("\t\t%d ", A[x][y][z]);
				printf("\n");
 			}
 			printf("\n");
		}
		
	}
	
   	return 0;
}
