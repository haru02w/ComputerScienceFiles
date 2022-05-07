#include <stdio.h>

#define pi2 3.141592

int main() {
  
  const char a= 'l';
  const float pi= 3.1415;
  const int n= -1;
  
  printf("\n%i", n);
  printf("\n%.4f", pi);
  printf("\n%.6f", pi2);
  printf("\n%c", a);
  printf("\nExemplo de operação %.4f", pi*n);
  
  return 0;
}
