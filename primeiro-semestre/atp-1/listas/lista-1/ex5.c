/*Escreva um programa em linguagem C para ler dois números (tipo real),
 * realizar a soma e apresentar o resultado.
*/
#include <stdio.h>
int main() {
  float n1, n2;
  printf("Digite dois numeros: ");
  scanf("%f%f", &n1, &n2);
  printf("%.2f + %.2f = %.2f\n", n1, n2, n1 + n2);
  return 0;
}
