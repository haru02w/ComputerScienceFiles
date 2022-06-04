#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
    float a,b,c,delta,x1,x2;
    printf("Digite os coeficientes de uma equação quadratica: \n");
    printf("a: ");
    scanf(" %f",&a);
    printf("b: ");
    scanf(" %f",&b);
    printf("c: ");
    scanf(" %f",&c);

    delta = b * b - 4 * a * c;

    if(delta == 0.0)
        printf("Há somente uma raiz para a equação: %f", -b / (2 * a));
    else if(delta < 0.0)
        printf("Não há raizes reais para equação.\n");
    else{
        printf("Há duas raizes para a equação: \n");
        printf("x1: %.2f\n",(-b + sqrt(delta)) / (2 * a));
        printf("x2: %.2f\n",(-b - sqrt(delta)) / (2 * a));
    }
    return 0;
}
