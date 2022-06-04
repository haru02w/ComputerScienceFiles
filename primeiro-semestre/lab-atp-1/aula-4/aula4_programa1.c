#include <stdio.h>
#include <stdlib.h>

int main()
{
      
   //Declaracao de variaveis
   int count;
   
   //Programa principal
   while (count <= 100)
   {
       printf("Número: %d e Quadrado: %d\n", count, count*count);
       count = count + 1; //Incrementa uma unidade no contador
   }
}
