#include <stdio.h>
int main(int argc, char const *argv[])
{
    float salario,salario_final;
    printf("Digite o valor do salario: ");
    scanf("%f",&salario);
    if(salario < 500)
        salario_final = salario * 1.15;
    if(salario >= 500 && salario <= 1000)
        salario_final = salario * 1.10;
    if(salario > 1000)
        salario_final = salario * 1.05;
    printf("O salario com reajuste é: %f",salario_final);
    return 0;
}