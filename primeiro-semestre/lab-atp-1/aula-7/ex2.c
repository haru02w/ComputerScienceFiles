#include <stdio.h>
int main(int argc, char const *argv[])
{
    char scpf[12],c;
    int cpf[11], flag, soma = 0, resto, i;
    printf("Digite um CPF (somente numeros): ");
    scanf("%s", scpf);
    for ( i = 0; i < 11; i++)
    {
        c = scpf[i];
        cpf[i] = c - '0';
    }
    
    for ( i = 0; i < 10; i++)
    {
        if(cpf[i] !=cpf[i+1])
            flag = 1;
    }
    if(flag == 0)
        printf("Elementos Iguais - CPF Invalido.\n");
    else{
        for ( i = 0; i < 9; i++)
            soma = soma + cpf[i] * (10 - i);
        resto = (10 * soma) % 11;
        if(resto == 10)
            resto = 0;
        if(resto != cpf[9]){
            printf("CPF Invalido.\n");
            return 0;
        }
        soma = 0;
        for ( i = 0; i < 10; i++)
            soma += cpf[i] * (11 - i);
        resto = (10 * soma) % 11;
        if(resto == 10)
            resto = 0;
        if(resto != cpf[10]){
            printf("CPF Invalido.\n");
            return 0;
        }
        printf("CPF valido.\n");
    }
    return 0;
}
