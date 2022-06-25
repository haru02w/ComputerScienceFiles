//Aula Exemplo: Struct (registro) - Prof. Dr. Leandro A. Neves
#include <stdio.h>
#include <stdlib.h>
int main()
{
    //Definição do registro e seus respectivos campos
     
   typedef struct endereco{
      char rua[20];
      char numero[4];
      char cep[4];
    }Tend; //Declaração do tipo struct Tend

   typedef struct cliente{ 
      int codigo;
      Tend end;  //Declaração da variável end com o tipo endereco
    }Tcli; //Declaração do tipo struct cliente

   Tcli cli; //Declaração da variável cli com o tipo (modelo) cliente

   //Entrada dos dados
   printf("\nDigite o codigo.: ");
   scanf("%d",&cli.codigo);
   printf("\nDigite o nome da rua: ");
   scanf(" %[^\n]s",cli.end.rua);
   printf("\nDigite o numero da residencia: ");
   scanf(" %[^\n]s",cli.end.numero);
   printf("\nDigite o cep: ");
   scanf(" %[^\n]s",cli.end.cep);
      
   //Saída dos dados Lidos
   printf("\n\nCodigo do cliente ...: %d", cli.codigo);
   printf("\nNome da rua ...: %s", cli.end.rua);
   printf("\nNumero da residencia ...: %s", cli.end.numero);
   printf("\nNumero da residencia ...: %s", cli.end.cep);

   printf("\n");
 //  system("PAUSE");	
   return 0;
}
