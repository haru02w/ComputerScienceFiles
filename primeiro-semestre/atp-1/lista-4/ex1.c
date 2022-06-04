#include <stdio.h>
int main(int argc, char const *argv[])
{
    int loop = 1;
    float salario;
    while (loop)
    {
        printf("Digite o salario do funcionario ou -1 para fechar: ");
        scanf("%f",&salario);
        if (salario >= 0)
        {
            if (salario < 500)
                salario *= 1.15;
            else if (salario >= 500 && salario <= 1000)
                salario *= 1.10;
            else
                salario *= 1.05;
            printf("O novo salario é de %f",salario);
        }
        else{
            printf("Valor invalido. Saindo...");
            loop = 0;
        }
        printf("\n");
    }
    
    return 0;
}
