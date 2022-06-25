/* 10. Faça um algoritmo para ler dois números. O primeiro valor deve ser
 * armazenado em uma variável de nome A e o segundo na variável B. Realize a
 * troca, tal que B armazena o valor de A e A o valor de B. Após a troca,
 * imprima os resuldos.
 */
#include <stdio.h>
int main(int argc, char *argv[]) {
  int a, b, aux;
  scanf("%d %d", &a, &b);
  aux = a;
  b = a;
  a = aux;
  printf("O segundo numero digitado foi: %d\nO primeiro foi: %d", a, b);

  return 0;
}
