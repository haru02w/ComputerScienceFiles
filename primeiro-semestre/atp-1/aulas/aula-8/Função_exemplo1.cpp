//Aula Fun��es - Prof. Dr. Leandro A. Neves
#include <stdio.h>

//Prot�tipo
int soma(int n, int n1);

int main()
{
   int num_1, num_2;
   
   //Entrada dos dados
   printf("\nDigite o primeiro n�mero.: ");
   scanf("%d",&num_1);
   printf("\nDigite o segundo n�mero.: ");
   scanf("%d",&num_2);
   
   printf ("\n A soma dos n�meros �: %d", soma(num_1, num_2));
   printf("\n");
   
   //system("PAUSE");	
   
   return 0;  
}

int soma(int n, int n1)
{
   return (n + n1);
}

