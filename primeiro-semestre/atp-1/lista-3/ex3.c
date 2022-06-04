#include <stdio.h>
int main(int argc, char const *argv[])
{
    char sexo;
    printf("Digite 'M' para masculino e 'F' para feminino: ");
    scanf("%c",&sexo);
    if(sexo == 'M' || sexo == 'F') 
        printf("Entrada valida. ");
    else
        printf("Entrada Invalida.");
    return 0;
}
