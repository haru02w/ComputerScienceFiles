#include <stdio.h>
#include <string.h>
#define size 41
int main()
{
  char str1[]="Algoritmos e ", str2[]="T�cnicas de Prog.";
  char str3[size];
  
  puts("\n\t - Manipula��o de String -");

  printf("\nstr 1: %s", str1);  
  printf("\nstr 2: %s", str2);  
  
  printf("\nTamanho de str1: %lu",strlen(str1));
  printf("\nTamanho de str2: %lu",strlen(str2));
  strcpy(str3,str1);
  printf("\n%s",str3);
  return 0;
}  
