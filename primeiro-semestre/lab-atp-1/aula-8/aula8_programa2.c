#include <stdlib.h>
#include <stdio.h>
#include <string.h> //Para manipular strings (char)

#define n 3

//Definicao da struct 'aluno'
typedef struct
{
   char nome[100];
   int matricula;
   float cr;
} aluno;

//Programa principal
int main()
{    
   //Variáveis
   int i;
   aluno vetoraluno[n];  //Declaracao do vetor de alunos
   aluno aluno_aux;
   
   //Preenchendo o vetor de alunos
   for (i = 0; i < n; i++)
   {  
      //Carrega os dados para uma struct auxiliar 'aluno'   
      printf("Nome aluno (%d): ", i+1);  
      scanf(" %[^\n]s",aluno_aux.nome);
      printf("Matricula aluno (%d): ", i+1);
      scanf("%d", &aluno_aux.matricula);
      printf("CF do aluno (%d): ", i+1);
      scanf("%f", &aluno_aux.cr);
      printf("\n");
      
	  //fflush(stdin); //Limpeza do buffer em Windows
      
      //Transfere toda variavel heterogenea 'aluno' para o vetor de alunos
      vetoraluno[i] = aluno_aux;
   }
   
   //Impressao do vetor de aluno
   printf("-------------------------------\n");
   for (i = 0; i < n; i++)
   {
      printf("Nome aluno (%d): %s\n",    i+1, vetoraluno[i].nome);
      printf("Matricula  (%d): %d\n",    i+1, vetoraluno[i].matricula);
      printf("Coef. rend (%d): %4.2f\n", i+1, vetoraluno[i].cr);  
      printf("\n");
   }
   
   system("pause");
   return 0;          
}
