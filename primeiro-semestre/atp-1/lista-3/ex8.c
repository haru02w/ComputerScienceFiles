#include <stdio.h>
//incompleto
int main(int argc, char const *argv[])
{
    int a,b,c;
    printf("Digite 3 numeros: ");
    scanf("%d %d %d",&a,&b,&c);
    if(!(a < b + c && b < a + c && c < a + b)){
        printf("Não é um triangulo\n");
        return 0;
    }
    if(a == b && b == c){
        printf("É um triangulo equilátero\n");
        return 0;
    }
    if(a == b || b == c || a == c){
        printf("É um triangulo isósceles\n");
        return 0;
    }
    printf("É um triangulo escaleno\n");
    return 0;
}
