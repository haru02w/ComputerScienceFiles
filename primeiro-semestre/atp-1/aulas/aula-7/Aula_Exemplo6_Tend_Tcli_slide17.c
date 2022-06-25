//Aula Exemplo: Struct (registro) - Prof. Dr. Leandro A. Neves
#include <stdio.h>
#include <stdlib.h>
int main()
{
    //Defini��o do registro e seus respectivos campos
     
   typedef struct endereco{
      char rua[20];
      char numero[4];
      char cep[4];
    }Tend; //Declara��o do tipo struct Tend

   typedef struct cliente{ 
      int codigo;
      Tend end;  //Declara��o da vari�vel end com o tipo endereco
    }Tcli; //Declara��o do tipo struct cliente

   Tcli cli; //Declara��o da vari�vel cli com o tipo (modelo) cliente

   //Entrada dos dados
   printf("\nDigite o codigo.: ");
   scanf("%d",&cli.codigo);
   printf("\nDigite o nome da rua: ");
   scanf(" %[^\n]s",cli.end.rua);
   printf("\nDigite o numero da residencia: ");
   scanf(" %[^\n]s",cli.end.numero);
   printf("\nDigite o cep: ");
   scanf(" %[^\n]s",cli.end.cep);
      
   //Sa�da dos dados Lidos
   printf("\n\nCodigo do cliente ...: %d", cli.codigo);
   printf("\nNome da rua ...: %s", cli.end.rua);
   printf("\nNumero da residencia ...: %s", cli.end.numero);
   printf("\nNumero da residencia ...: %s", cli.end.cep);

   printf("\n");
 //  system("PAUSE");	
   return 0;
}
