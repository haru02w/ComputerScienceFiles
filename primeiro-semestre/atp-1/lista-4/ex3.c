#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n;
    for (int i = 0; i < 10; i++)
    {
        printf("Digite o numero do produto %d: ",i);
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Sul\n");
            break;
        case 2:
            printf("Norte\n");
            break;
        case 3:
            printf("Leste\n");
            break;
        case 4:
            printf("Oeste\n");
            break;
        case 5:
        case 6:
            printf("Nordeste\n");
            break;
        case 7 ... 9:
            printf("Sudeste\n");
            break;
        case 10:
        case 11:
            printf("Centro-Oeste\n");
            break;
        case 12 ... 15:
            printf("Nordeste\n");
            break;
        default:
            printf("Importado\n");
        }
    }
    return 0;
}
