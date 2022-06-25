/*
 *Escreva um programa em linguagem C para ler dois valores inteiros,
 * realizar a soma e apresentar o resultado.
*/
#include <stdio.h>
int main(int argc, char *argv[]) {
  int n1, n2;
  printf("Digite dois numeros: ");
  scanf("%d%d", &n1, &n2);
  printf("%d + %d = %d\n", n1, n2, n1 + n2);
  return 0;
}
