#include <stdio.h>

int main()
{
  int i=0, aux;
  
  printf("\nApresenta��o de --i");
  printf("\n valor de i: %d",i);
  aux=i++;
  printf("\n valor retornado por i++ via aux: %d",aux);
  printf("\n i depois i++: %d \n", i);
  
  printf("\n-------------------------------------------");
  printf("\nApresenta��o de --i");  
  i=0;
  printf("\n valor de i: %d",i);
  aux=++i;
  
  printf("\n valor retornado por ++i via aux: %d",aux);
  printf("\n i depois ++i: %d \n", i);
  
  return 0;  
}
