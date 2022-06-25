#include <stdio.h>
int main(int argc, char const *argv[])
{
    float kwh,total;
    char aposentado;
    printf("Digite a quantidade de kWh da conta de energia eletrica: ");
    scanf("%f",&kwh);
    printf("Voce é aposentado? S/N: ");
    scanf(" %c",&aposentado);

    if(aposentado == 'S')
        total = (kwh * 0.1) * 0.85; 
    else
        total = kwh * 0.1; 
    printf("O preço da conta de energia eletrica é: R$%.2f",total);
    return 0;
}