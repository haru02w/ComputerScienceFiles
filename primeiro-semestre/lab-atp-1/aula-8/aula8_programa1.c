#include <stdlib.h>
#include <stdio.h>
#include <string.h> //Para manipular strings (char)

//Definicao da struct 'aluno'
//----------------------------------------
typedef struct  //O typedef serve para "apelidar" uma struct que foi criada
{
	char nome[100];
	int matricula;
	float cr;
} aluno;
//----------------------------------------


//----------------------------------------
//Programa principal
int main()
{          
	//Declaracao de uma "super-variavel" do tipo aluno, chamada aluno1
	aluno aluno1; //aqui, note que não foi necessário usar "struct aluno aluno1" por conta do apelido do typedef
	  
	//Carrega os dados para uma "super-variavel" struct que definimos, do tipo'aluno'   
    printf("Nome aluno: ");  
    scanf(" %[^\n]s",aluno1.nome);
      
	printf("Matricula aluno: ");
    scanf("%d", &aluno1.matricula);
      
	printf("CR do aluno: ");
    scanf("%f", &aluno1.cr);
      
   	//Impressao dos dados do aluno
    printf("\n-------------------------------\n");
    
	printf("Nome do aluno: %s\n", aluno1.nome);
	printf("Matricula do aluno: %d\n", aluno1.matricula);
	printf("CR do aluno: %f\n", aluno1.cr);
    
    system("pause");
    return 0;          
}
//----------------------------------------
