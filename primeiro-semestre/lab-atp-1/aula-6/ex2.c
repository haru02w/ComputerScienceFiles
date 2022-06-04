#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int A[3][4], maior, menor, i, j, S[3] = {0, 0, 0};
    for (i = 0; i < 3; i++)
        for (j = 0; j < 4; j++)
        {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
    printf("\n\n");
    maior = A[0][0];
    menor = A[0][0];
    for (i = 0; i < 3; i++){
        for (j = 0; j < 4; j++)
        {
            if (A[i][j] < menor)
                menor = A[i][j];
            if (A[i][j] > maior)
                maior = A[i][j];
                S[i] += A[i][j];
        }
        printf("Soma[%d] = %d \n",i ,S[i]);
    }
    printf("Maior: %d Menor: %d\n",maior,menor);
    return 0;
}
