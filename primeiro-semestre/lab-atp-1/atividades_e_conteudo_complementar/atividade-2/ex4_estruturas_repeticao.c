#include <stdio.h>
int main(int argc, char const *argv[])
{
    unsigned int n;
    printf("Digite um numero natural: ");
    scanf("%u",&n);
    printf("Todos os numeros até esse numero é: ");
    for (int i = 1; i <= n; i++)
        printf("%u\t",n);
    return 0;
}
