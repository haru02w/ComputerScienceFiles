#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n1;
    printf("Digite um numero inteiro: ");
    scanf("%d",&n1);
    if(n1 % 4 != 0)
        printf("Numero Invalido!.");
    return 0;
}
/*
int main(int argc, char const *argv[])
{
    int n1;
    printf("Digite um numero inteiro: ");
    scanf("%d",&n1);
    if((n1 / 4)*4 != n1)
        printf("Numero Invalido!.");
    return 0;
}
*/