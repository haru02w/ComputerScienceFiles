#include <stdio.h>

int main()
{
  char str1[]="Algoritmos e T�cnicas";
  //inclui automaticamente o '\0'
  char str2[20];
 
  str1=str2; // ERRADO!
  puts(str1);
  return 0;
}

