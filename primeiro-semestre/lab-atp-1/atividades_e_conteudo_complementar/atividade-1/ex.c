#include <stdio.h>
int main(int argc, char const *argv[])
{
    char string[100];
    float preco,total;
    unsigned int qtd_comprada;

    printf("Digite o nome do produto: ");
    scanf("%s",&string);
    printf("Digite o preço do produto: ");
    scanf("%f",&preco);
    printf("Digite a quantidade comprada: ");
    scanf("%u",&qtd_comprada);
    printf("O nome do produto é: %s\n",string);

    total = preco * qtd_comprada;

    if(qtd_comprada >= 11 && qtd_comprada <= 20)
        total *= 0.9;
    if(qtd_comprada >= 21 && qtd_comprada <= 50)
        total *= 0.8;
    if(qtd_comprada > 50)
        total *= 0.75;

    printf("O valor total a ser pago é: R$%.2f\n",total);

    return 0;
}
