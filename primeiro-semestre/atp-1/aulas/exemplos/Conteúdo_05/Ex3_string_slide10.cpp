#include <stdio.h>
#define size 21
int main()
{
  char str1[size];
  puts("\nDigite uma palavra: ");
  
  fgets(str1, size, stdin);
  puts(str1);
  return 0;
}
