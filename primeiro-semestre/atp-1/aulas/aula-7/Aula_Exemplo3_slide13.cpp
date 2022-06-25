//Aula - Struct (registro) - Prof. Dr. Leandro A. Neves
#include <stdio.h>
#include <stdlib.h>
int main()
{
   //Definição do registro e seus respectivos campos
   struct cliente {
            int codigo;
            char end[20];
          }cli, cli2; 
  //Declaração de cli e cli2 do tipo struct
  // ou
  //struct cliente cli, cli2;
  
   //Entrada dos dados
   printf("\nDigite o codigo.: ");
   scanf("%d",&cli.codigo);
   printf("\nDigite o endereco: ");
   scanf(" %[^\n]s",cli.end);

   //Saída dos dados Lidos
   printf("\n\nCodigo do cliente ...: %d",   cli.codigo);
   printf("\nEndereco ...: %s",  cli.end);
   printf("\n");
   //system("PAUSE");	
   return 0;
}
