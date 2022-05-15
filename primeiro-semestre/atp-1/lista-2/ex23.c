/*
 * 3. Escreva um programa que receba dois caracteres do alfafeto ASCII digitados
 * pelo usuário no terminal e diga se o primeiro vem antes ou depois do segundo
 * na tabela ASCII.
 */
#include <stdio.h>
int main(int argc, char *argv[]) {
  char c1, c2;
  printf("Digite dois caracteres: ");
  scanf("%c %c", &c1, &c2);
  printf("O primeiro vem %s do segundo.\n", c1 < c2 ? "antes" : "depois");
  return 0;
}
