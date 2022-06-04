#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n1;
    printf("Digite um numero inteiro: ");
    scanf("%d",&n1);
    if(n1 >= 10 && n1 <= 20)
        printf("O numero está entre 10 e 20\n");
    else
        printf("O numero não está entre 10 e 20\n");
    return 0;
}
