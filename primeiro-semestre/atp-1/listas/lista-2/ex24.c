/*
 * 24. Considere o fragmento de código listado abaixo. Escreva um código em
 * linguagem para realizar uma adição com os valores armazenados nas variáveis n
 * e m. O resultado deve ser armazenado em x. Apresente o resultado. Explique o
 * que ocorreu a partir do significado de overflow. Reescreva o código para
 * evitar o erro.
 */
// codigo já reescrito.
// trocado do tipo "unsigned int" para "unsigned long int"
#include <stdio.h>
int main(int argc, char *argv[]) {
  unsigned long int n, m, x;
  n = 4000000000;
  m = 300000000;
  x = n + m;
  printf("A soma de %lu + %lu = %lu\n", n, m, x);
  return 0;
}
