#include <stdio.h>
#define max 11
int main (int argc, char *argv[])
{
  int n1[max];
  int n2;
  printf("Digite um numero: ");
  scanf("%d",&n2);
  for(int i = 0; i < max; i++){
    n1[i] = n2 * i;
    printf("%d x %d = %d\n", n2, i, n1[i]);
  }
  return 0;
}
