#include <stdio.h>

int main(int argc, char const *argv[])
{
    int matrix[2][2], det;
    int i,j;
    for (i = 0; i < 2; i++){
        for (j = 0; j < 2; j++)
        {
            printf("A[%d][%d] = ",i,j);
            scanf("%d",&matrix[i][j]);
        }
    }
        
    det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];  
    printf("det A: %d\n",det);

    return 0;
}
