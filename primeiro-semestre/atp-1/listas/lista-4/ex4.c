#include <stdio.h>
int main(int argc, char const *argv[])
{
    float total;
    int kwh, loop = 1;
    while (loop)
    {
        printf("Digite a quantidade de kWh da conta de energia eletrica(-1 para sair): ");
        scanf("%d", &kwh);
        if (kwh >= 0)
        {
            switch (kwh)
            {
            case 0 ... 50:
                total = kwh;
                break;
            case 51 ... 100:
                total = 50 + (kwh - 50) * 1.3;
                break;
            case 101 ... 150:
                total = 50 + 50 * 1.3 + (kwh - 100) * 1.6;
                break;
            default:
                total = 50 + 50 * 1.3 + 50 * 1.6 + (kwh - 150) * 2;
                break;
            }
            printf("O preço da conta de energia eletrica é: R$%.2f\n", total);
        }
        else{
            printf("Numero invalido. Saindo...");
            loop = 0;
        }
        printf("\n");
    }
    return 0;
}