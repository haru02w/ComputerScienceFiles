/*
 * 27. Explique o resultado fragmento de código:
 */
#include <stdio.h>
int main(int argc, char *argv[]) {
  unsigned char u, v, w;
  u = 255;
  v = 2;
  printf("%d", u + v);
  w = u + v;
  printf("%d", w);
  return 0;
}
/*
 * No primeiro "printf", por meio de casting, o valor da soma dos characteres
 * foram transformados em "int" e imprimidos na tela. No outro "printf", o valor
 * da soma de "u" com "v" foi atribuido a uma variavel do tipo "char" e, por
 * esse tipo de variavel armazenar somente valores até 255, ocorre um overflow
 * onde o bit mais significativo é ignorado e o valor volta a ser 0 novamente.
 */
