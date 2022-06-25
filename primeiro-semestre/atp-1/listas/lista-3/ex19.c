#include <stdio.h>
int main(int argc, char const *argv[])
{
    float consumo,preco,total;
    int tipo;
    unsigned int distancia;

    printf("1 - Gasolina\t2 - Álcool\t3 - Diesel\nDigite o tipo de combustivel do veiculo: ");
    scanf("%d",&tipo);

    switch (tipo)
    {
    case 1:
        preco = 4.79;
        break;
    case 2:
        preco = 2.68;
        break;
    case 3:
        preco = 2.64;
    }

    printf("Digite a distancia à percorrer em km: ");
    scanf("%u",&distancia);

    printf("Digite o consumo medio do veiculo em km/l : ");
    scanf("%f",&consumo);

    total = (distancia / consumo) * preco;

    printf("O custo em reais de combustivel dessa viajem é de: %f\n",total);
    return 0;
}
