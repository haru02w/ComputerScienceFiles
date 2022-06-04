#include <stdio.h>
int main(int argc, char const *argv[])
{
    int j = 0, aux,vetor[6];
    printf("Digite: \n");
    for (int i = 0; i < 6; i++){
        printf("v[%d]: ",i+1);
        scanf("%d",&vetor[i]);
    }
    for (int i = 0; i < 6; i++)
    {
        for ( j = i+1; j < 6; j++)
        {
            if(vetor[j] < vetor[i]){
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
    printf("\nOs numeros ordenados são: \n");
    for (int i = 0; i < 6; i++)
    {
        printf(" %d\t",vetor[i]);
    }
    printf("\n");
    
    return 0;
}
