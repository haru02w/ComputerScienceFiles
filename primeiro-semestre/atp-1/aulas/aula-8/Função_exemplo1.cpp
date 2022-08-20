//Aula Funções - Prof. Dr. Leandro A. Neves
#include <stdio.h>

//Protótipo
int soma(int n, int n1);

int main()
{
   int num_1, num_2;
   
   //Entrada dos dados
   printf("\nDigite o primeiro número.: ");
   scanf("%d",&num_1);
   printf("\nDigite o segundo número.: ");
   scanf("%d",&num_2);
   
   printf ("\n A soma dos números é: %d", soma(num_1, num_2));
   printf("\n");
   
   //system("PAUSE");	
   
   return 0;  
}

int soma(int n, int n1)
{
   return (n + n1);
}

