//Aula  Fun��es - Prof. Dr. Leandro A. Neves
#include <stdio.h>

int soma(int n, int n1)
{
   return (n+n1);
}

void leitura(int *n, int *n1)
{
   //Entrada dos dados
   printf("\nDigite o primeiro n�mero.: ");
   scanf("%d",&*n);
   printf("\nDigite o segundo n�mero.: ");
   scanf("%d",&*n1);
	
}

int main()
{
   
	//Escopo - Vari�veis locais
   int num_1, num_2;
   //Chamada com passagem de par�metro por refer�ncia
   leitura(&num_1, &num_2);
   
   printf ("\n A soma dos n�meros %d e %d �: %d", num_1, num_2, soma(num_1, num_2));
   printf("\n");
  // system("PAUSE");	
   return 0;  
}
