/*
 * 22. Considerando o exercício anterior, escreva e teste um programa que tente
 * exibir na tela os caracteres representados pelos bytes cujo primeiro bit é 1.
 */
#include <stdio.h>
int main(int argc, char *argv[]) {
  int count = 0;
  for (char i = 32; i < 127; i++) {
    if (i % 2) {
      if (!(count % 10))
        printf("\n");
      printf("%c\t", i);
      count++;
    }
  }
  printf("\n");
  return 0;
}
