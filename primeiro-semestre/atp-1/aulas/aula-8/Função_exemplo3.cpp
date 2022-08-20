//Aula  Funções - Prof. Dr. Leandro A. Neves
#include <stdio.h>

int soma(int n, int n1)
{
   return (n+n1);
}

void leitura(int *n, int *n1)
{
   //Entrada dos dados
   printf("\nDigite o primeiro número.: ");
   scanf("%d",&*n);
   printf("\nDigite o segundo número.: ");
   scanf("%d",&*n1);
	
}

int main()
{
   
	//Escopo - Variáveis locais
   int num_1, num_2;
   //Chamada com passagem de parâmetro por referência
   leitura(&num_1, &num_2);
   
   printf ("\n A soma dos números %d e %d é: %d", num_1, num_2, soma(num_1, num_2));
   printf("\n");
  // system("PAUSE");	
   return 0;  
}
