#include <stdio.h>
int main(int argc, char const *argv[])
{
    float peso,altura,imc;
    printf("Digite o seu peso em kilogramas: ");
    scanf("%f",&peso);
    printf("Digite sua altura em metros: ");
    scanf("%f",&altura);
    
    imc = peso / (altura * altura); 

    printf("De acordo com a tabela de IMC, você tem: ");
    if(imc < 18.5)
        printf("Desnutrição");
    else if(imc >= 18.5 && imc <= 24.5)
        printf("Peso normal");
    else if(imc >= 25.0 && imc <= 29.9)
        printf("Sobrepeso");
    else if(imc >= 30.0 && imc <= 39.9)
        printf("Obesidade");
    else if(imc >= 40.0)
        printf("Obesidade Mórbida");
    printf("\n");

    return 0;
}
