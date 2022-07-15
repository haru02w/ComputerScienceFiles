#include <stdio.h>
struct aluno
{
    char nome[100];
    int matricula;
    float cr;
};

int main(int argc, char const *argv[])
{
    struct aluno aluno1;
    printf("Digite um nome: ");
    scanf(" %[^\n]s", aluno1.nome);
    printf("Digite uma matricula: ");
    scanf("%d", &aluno1.matricula);
    printf("Digite um coeficiente de rendimento: ");
    scanf("%f", &aluno1.cr);

    printf("Nome: %s\nMatricula: %d\nCoeficiente de Rendimento: %f", aluno1.nome, aluno1.matricula, aluno1.cr);
    
    return 0;
}
