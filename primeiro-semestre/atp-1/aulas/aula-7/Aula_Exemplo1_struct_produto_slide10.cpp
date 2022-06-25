//Aula Exemplo: Struct (vetor de registros) - Prof. Dr. Leandro A. Neves
#include <stdio.h>
#include <stdlib.h>
#define registros 3
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
      Tend end;  //declara��o da vari�vel end com o tipo endereco
   }Tcli; //Declara��o do tipo struct cliente
   Tcli cli[registros]; //declara��o da vari�vel cli com o tipo (modelo) cliente
   
   for(int i=0; i<registros; i++)
   {//Entrada dos dados
      printf("\nDigite o codigo.: ");
      scanf("%d",&cli[i].codigo);
      printf("\nDigite o nome da rua: ");
      scanf(" %[^\n]s",cli[i].end.rua);
      printf("\nDigite o numero da residencia: ");
      scanf(" %[^\n]s",cli[i].end.numero);
      printf("\nDigite o cep: ");
      scanf(" %[^\n]s",cli[i].end.cep);
   }
   for(int i=0; i<registros; i++)
   {//Sa�da dos dados Lidos
      printf("\n\nCodigo do cliente ...: %d", cli[i].codigo);
      printf("\nNome da rua ...: %s", cli[i].end.rua);
      printf("\nNumero da residencia ...: %s", cli[i].end.numero);
      printf("\nNumero da residencia ...: %s", cli[i].end.cep);
      printf("\n");
  }
   //  system("PAUSE");
   return 0;
}
