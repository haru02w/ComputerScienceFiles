#include <stdio.h>
int main(int argc, char const *argv[])
{
    int j = 0,vetor[6],negativos[6],soma = 0;
    printf("Digite: \n");
    for (int i = 0; i < 6; i++)
    {
        printf("v[%d]: ",i+1);
        scanf("%d",&vetor[i]);
        if(vetor[i] < 0){
            negativos[j] = vetor[i];
            j++;
            soma += vetor[i];
        }
    }
    printf("Os numeros negativos são: \n");
    for (int i = 0; i < j; i++)
        printf("%d\n",negativos[i]);
    printf("A media dos numeros negativos é: %f\n",(float)soma/j);
    return 0;
}
