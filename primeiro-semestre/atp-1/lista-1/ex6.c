/*
 * Escreva um programa em linguagem C para ler duas notas (tipo real),
 * calcular a média e informar se a média obtida é maior ou igual a 5,0.
*/
#include <stdio.h>
int main() {
  float n1, n2;
  printf("Digite as notas: ");
  scanf("%f %f", &n1, &n2);

  if (((n1 + n2) / 2) >= 5)
    printf("A média é maior ou igual a 5!");
  else
    printf("A média é menor que 5!");
  printf("\n");
  return 0;
}
