#include <stdio.h>
#include <stdlib.h>
#include <locale.h>   //Biblioteca que cont�m a fun��o 'setlocale' (para gerenciar acentos em portugu�s)

int main()
{
   
   setlocale(LC_ALL, "");  //Comando para poder usar acentos em portugu�s
   
   //Declaracao de variaveis
   int faltas;         //entrada
   float P1, P2, T;    //entrada
   float MF;           //sa�da
   
   //Rotina principal
   printf("Digite as notas P1, P2 e T: \n");  //Escreva na tela. Obs: \n pula p/ a pr�xima linha
   scanf("%f %f %f", &P1, &P2, &T);           //Leia as notas: P1, P2 e T
   
   printf("Digite o total de faltas \n");     //Escreve na tela
   scanf("%d", &faltas);                      //Leia o n�mero de faltas: faltas
   
   //C�lculos
   MF = (P1 + P2 + T)/3;
   
   //Estrutura condicionar composta (para checar se o aluno est� aprovado ou reprovado)
   if (MF >= 5.0 && faltas <=9)
   {
   	  printf("Aprovado com m�dia final: %.2f", MF);
   }
   else
   {
   	  printf("Reprovado com m�dia final: %.2f", MF);

   } 

}
