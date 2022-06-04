#include <stdio.h>
#include <string.h>

int main()
{
  char str1[]="Algoritmos e ", str2[]="Técnicas de Prog.";
  
  puts("\n\t - Manipulação de String -");

  printf("\nstr 1: %s", str1);  
  printf("\nstr 2: %s", str2);  
  
  printf("\nTamanho de str1: %lu",strlen(str1));
  printf("\nTamanho de str2: %lu",strlen(str2));

  return 0;
}
  
