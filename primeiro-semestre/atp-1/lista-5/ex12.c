#include <stdio.h>
//errado
int main ()
{
  int vin[10],vai[30];

  for (int i = 0; i < 10; i++) {
    scanf(" %d", &vin[i]);
  }
  for (int i = 0; i < 10; i++) {
    vai[3*i] = vin[i];
    vai[3*i+1] = vin[i];
    vai[3*i+2] = vin[i];
  }
  for (int i = 0; i < 30; i++) {
    printf("%d\n", vai[i]);
  }
  return 0;
}
