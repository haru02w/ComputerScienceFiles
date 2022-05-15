#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>  //Biblioteca interna contendo f�rmulas e fun��es matem�ticas
 
int main(void)
{
    setlocale(LC_ALL,"");
    
    //Vari�veis
    float a, b, c, delta, x1, x2;    //entrada
 
    //Programa principal
    printf("Digite os coeficientes a, b e c da express�o ax^2 + bx + c = 0\n");
    printf("a: "); scanf("%f", &a);
    printf("b: "); scanf("%f", &b);
    printf("c: "); scanf("%f", &c);
 
    system("cls");                                     //Limpa a tela
    printf("\n%8.2fx^2 + %8.2fx + %8.2f\n", a, b, c);  //Imprime a equa��o do segundo grau na tela
 
    delta = b*b - 4*a*c;                           //Calcula o discriminante
 
    //Estrutura Condicional: Encadeada Homog�nea (se-senao-se)
	if(delta < 0) //Ra�zes complexas
    {
        printf("\nDELTA = %8.2f\nN�o possui ra�zes reais!\n", delta);
    }
    else
    {
        if(delta == 0) //Ra�z real �nica, com duplicidade
        {
            x1 = -b / (2 * a);
            printf("\nDELTA = %8.2f \nx'   = %8.2f\n\n", delta, x1);
        }
        else  //Caso n�o seja um par complexo, ou ainda n�o seja ra�z real �nica, a �nica op��o restante � ter duas ra�zes reais distintas
        {
            x1 = (-b - sqrt(delta)) / (2 * a);
            x2 = (-b + sqrt(delta)) / (2 * a);
            printf("\nDELTA = %8.2f \nx1 = %8.2f\nx2 = %8.2f\n\n", delta, x1, x2);
        }
    }
 
    system("pause");
 
    return 0;
}
