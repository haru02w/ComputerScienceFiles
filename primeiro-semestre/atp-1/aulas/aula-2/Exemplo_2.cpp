#include <stdio.h>

int main() {
  char a='l';
  const float pi=3.1415;
  int n=-1;
  
  printf("\n%i", n);
  printf("\n%.4f", pi);
  printf("\n%c", a);
  printf("\nExemplo de operação %.4f", pi*n);
  
  return 0;
}
