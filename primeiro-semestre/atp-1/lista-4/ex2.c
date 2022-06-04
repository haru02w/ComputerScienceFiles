#include <stdio.h>
int main(int argc, char const *argv[])
{
    int loop = 1;
    float kwh, total;
    char aposentado;
    while (loop)
    {
        printf("Digite a quantidade de kWh da conta de energia eletrica(-1 para sair): ");
        scanf("%f", &kwh);
        if (kwh >= 0)
        {
            printf("Voce é aposentado? S/N: ");
            scanf(" %c", &aposentado);
            if (aposentado == 'S')
                total = (kwh * 0.1) * 0.85;
            else
                total = kwh * 0.1;
            printf("O preço da conta de energia eletrica é: R$%.2f", total);
        }
        else
        {
            printf("Numero invalido. Saindo... ");
            loop = 0;
        }
        printf("\n");
    }

    return 0;
}