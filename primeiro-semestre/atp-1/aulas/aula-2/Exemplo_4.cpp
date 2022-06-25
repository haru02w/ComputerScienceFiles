#include <math.h>
/*Opcional. 
Declarações de Variáveis Globais, por exemplo. 
Declarações de Funções. Importante, não vamos estudar em ATPI 
*/ 
//=-=-=-=-=-=-=-=-=-= 
int main () 
{	
    double a, b;
    int n1, n2;  
    printf("\nDigite um número: ");
    scanf("%lf",&a);
    printf("\nDigite um segundo número: ");
    scanf("%lf",&b);

    printf("\n pow(%.3f,%.3f) -> %.3lf", a,b, pow(a,b));
    printf("\n sqrt(%.2lf) -> %.3lf", a, sqrt(a));
    printf("\n sqrt(%.2lf) -> %.3lf", b, sqrt(b));
    
    n1= a;
    n2= b;
    printf("\n %d %% %d -> %d", n1, n2, (n1%n2));
    printf("\n %d / %d -> %d", n1, n2, (n1/n2));
  
  	return 0; 
}//Indica o final do programa.