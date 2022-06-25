#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
    float v[10], soma = 0, media, devpad;
    int i;

    for(i = 0; i < 10; i++){
        printf("v[%d]: ", i);
        scanf("%f",&v[i]);
        soma += v[i];
    }
    media = soma / 10;
    soma = 0;
    for ( i = 0; i < 10; i++)
        soma = soma + pow(v[i] - media, 2);
    devpad = sqrt(soma / 9);
    printf("Média: %f\n",media);
    printf("Desvio Padrão: %f\n",devpad);
    return 0;
}
