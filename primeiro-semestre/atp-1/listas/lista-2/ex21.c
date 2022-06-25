/*
 * 21. Escreva e teste um programa que exiba na tela os caracteres representados
 * pelos chars 32 a 127. Exiba dez caracteres por linha.
 */
#include <stdio.h>
int main(int argc, char *argv[]) {
  int count = 0;
  for (char i = 32; i < 127; i++, count++) {
    if (count % 10 == 0)
      printf("\n");
    printf("%c\t", i);
  }
  printf("\n");
  return 0;
}
