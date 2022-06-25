#include <stdio.h>
int main(int argc, char const *argv[])
{
    int produto;
    printf("Digite o codigo do produto: ");
    scanf("%d",&produto);
    switch (produto)
    {
    case 1:
        printf("Alimento não perecível");
        break;
    case 2 ... 4:
        printf("Alimento perecível");
        break;
    case 5:
    case 6:
        printf("Vestuário");
        break;
    case 7:
        printf("Vestuário");
        break;
    case 8 ... 13:
        printf("Limpeza e utensílios domésticos");
        break;
    default:
        printf("Inválido");
    }
    printf("\n");
    return 0;
}