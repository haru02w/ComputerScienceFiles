#include <stdio.h>
int main(int argc, char const *argv[])
{
    float n;
    printf("Digite um numero: ");
    scanf("%f",&n);
    if(!n)
        printf("Numero nulo.\n");
    if(n > 0)
        printf("Numero positivo.\n");
    if(n < 0)
        printf("Numero negativo.\n");
    return 0;
}