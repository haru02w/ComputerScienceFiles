#include <stdio.h>
#include <stdlib.h>
#include <locale.h>   //Biblioteca que contém a função 'setlocale' (para gerenciar acentos em português)

int main()
{
   
   setlocale(LC_ALL, "");  //Comando para poder usar acentos em português
   
   //Declaracao de variaveis
   int faltas;         //entrada
   float P1, P2, T;    //entrada
   float MF;           //saída
   
   //Rotina principal
   printf("Digite as notas P1, P2 e T: \n");  //Escreva na tela. Obs: \n pula p/ a próxima linha
   scanf("%f %f %f", &P1, &P2, &T);           //Leia as notas: P1, P2 e T
   
   printf("Digite o total de faltas \n");     //Escreve na tela
   scanf("%d", &faltas);                      //Leia o número de faltas: faltas
   
   //Cálculos
   MF = (P1 + P2 + T)/3;
   
   //Estrutura condicionar composta (para checar se o aluno está aprovado ou reprovado)
   if (MF >= 5.0 && faltas <=9)
   {
   	  printf("Aprovado com média final: %.2f", MF);
   }
   else
   {
   	  printf("Reprovado com média final: %.2f", MF);

   } 

}
