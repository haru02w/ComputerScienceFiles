#include <stdio.h>

void troca (int *endn1, int *endn2)
{
   int aux;
   aux = *endn1;
   *endn1 = *endn2;
   *endn2 = aux;            
       
}            

int main()
{
   int n1, n2;     
   printf("\nDigite valor 1:");
   scanf("%d",&n1);
   printf("\nDigite valor 2:");
   scanf("%d",&n2);
   printf("\nValor 1: %d; Valor 2: %d", n1, n2);
   troca(&n1,&n2);
   printf("\nApós troca -> Valor 1: %d; Valor 2: %d", n1, n2);
   printf("\n");
//   system("PAUSE");	
   return 0;  
}
