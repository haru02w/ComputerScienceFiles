#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n1;
    printf("Digite um numero: ");
    scanf("%d",&n1);
    if(n1 % 2)
        printf("O numero é impar.\n");
    else
        printf("O numero é par.\n");
    return 0;
}
