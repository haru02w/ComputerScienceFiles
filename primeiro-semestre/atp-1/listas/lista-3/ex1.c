#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n1;
    printf("Digite um numero: ");
    scanf("%d",&n1);
    if(n1 >= 20 && n1 <= 100)
        printf("Numero entre 20 e 100\n");
    else
        printf("Numero não está entre 20 e 100\n");
    return 0;
}
