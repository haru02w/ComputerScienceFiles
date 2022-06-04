#include <stdio.h>

int main ()
{
  int VIN[10], VAI[30];
  
  for (int i=0; i<10; i++)
  {
    printf ("\nDigite o valor de VIN para i igual a %d\n", i);
    scanf ("%d", &VIN[i]);
    VAI[3*i]=VIN[i];
    VAI[3*i+1]=VIN[i];
    VAI[3*i+2]=VIN[i];
  }
  
  for (int i=0; i<30; i++)
  {
    printf ("\nVAI %d tem valor de %d", i, VAI[i]);
  }
  
//  system ("PAUSE");
  return 0;
}

