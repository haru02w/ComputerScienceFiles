#include <stdio.h>
#define max 15
int main (int argc, char *argv[])
{
  int fib[max] = {0,1}; 
  for (int i = 0; i < max - 2; i++) {
     fib[i+2] = fib[i] + fib[i+1];
  }
  for (int i = 0; i < max; i++) {
    printf("%d\n",fib[i]);
  }
    
  return 0;
}
