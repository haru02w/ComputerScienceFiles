//Aula - Struct (registro) - Prof. Dr. Leandro A. Neves
#include <stdio.h>
#include <stdlib.h>
int main()
{
   //Defini��o do registro e seus respectivos campos
    typedef struct cliente{ int codigo;
           char end[20];
          }Tcli; //Declara��o do tipo struct Tcli
   Tcli cli; //declara��o da vari�vel cli com o tipo Tcli 
          
   //Entrada dos dados
   printf("\nDigite o codigo.: ");
   scanf("%d",&cli.codigo);
   printf("\nDigite o endereco: ");
   scanf(" %[^\n]s",cli.end);

   //Sa�da dos dados Lidos
   printf("\n\nCodigo do cliente ...: %d",   cli.codigo);
   printf("\nEndereco ...: %s",  cli.end);
   printf("\n");
  // system("PAUSE");	
   return 0;
}
