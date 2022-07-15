#include <stdio.h>
typedef struct
{
    float real;
    float im;
} complexo;

int main(int argc, char const *argv[])
{
    complexo z, w;
    complexo soma, produto,aux;
    int n;

    printf("Digite a parte real e imaginaria: ");
    scanf("%f %f", &z.real, &z.im);
    printf("Digite a parte real e imaginaria: ");
    scanf("%f %f", &w.real, &w.im);

    // soma
    soma.real = z.real + w.real;
    soma.im = z.im + w.im;
    printf("Soma: %.2f + %.2fi\n", soma.real, soma.im);

    // exponenciação
    printf("Digite o valor do expoente: ");
    scanf("%d",&n);


    produto.real = (z.real * z.real) - (z.im * z.im);
    produto.im = (z.real * z.im) + (z.im * z.real);

    for (int i = 2; i < n; i++)
    {
        aux.real = (z.real * produto.real) - (z.im * produto.im);
        aux.im = (z.real * produto.im) + (z.im * produto.real);
        produto = aux;
    }
    printf("exponenciação: %.2f + %.2fi\n", produto.real, produto.im);

    return 0;
}
