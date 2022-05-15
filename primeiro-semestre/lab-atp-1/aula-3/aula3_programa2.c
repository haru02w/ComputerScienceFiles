#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>  //Biblioteca interna contendo fórmulas e funções matemáticas
 
int main(void)
{
    setlocale(LC_ALL,"");
    
    //Variáveis
    float a, b, c, delta, x1, x2;    //entrada
 
    //Programa principal
    printf("Digite os coeficientes a, b e c da expressão ax^2 + bx + c = 0\n");
    printf("a: "); scanf("%f", &a);
    printf("b: "); scanf("%f", &b);
    printf("c: "); scanf("%f", &c);
 
    system("cls");                                     //Limpa a tela
    printf("\n%8.2fx^2 + %8.2fx + %8.2f\n", a, b, c);  //Imprime a equação do segundo grau na tela
 
    delta = b*b - 4*a*c;                           //Calcula o discriminante
 
    //Estrutura Condicional: Encadeada Homogênea (se-senao-se)
	if(delta < 0) //Raízes complexas
    {
        printf("\nDELTA = %8.2f\nNão possui raízes reais!\n", delta);
    }
    else
    {
        if(delta == 0) //Raíz real única, com duplicidade
        {
            x1 = -b / (2 * a);
            printf("\nDELTA = %8.2f \nx'   = %8.2f\n\n", delta, x1);
        }
        else  //Caso não seja um par complexo, ou ainda não seja raíz real única, a única opção restante é ter duas raízes reais distintas
        {
            x1 = (-b - sqrt(delta)) / (2 * a);
            x2 = (-b + sqrt(delta)) / (2 * a);
            printf("\nDELTA = %8.2f \nx1 = %8.2f\nx2 = %8.2f\n\n", delta, x1, x2);
        }
    }
 
    system("pause");
 
    return 0;
}
