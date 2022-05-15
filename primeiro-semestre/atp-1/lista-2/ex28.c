/*
 * 28. Explique o resultado obtido a partir de:
 */
#include <stdio.h>
int main(int argc, char *argv[]) {
  unsigned char u;
  for (u = 0; u < 256; ++u)
    printf(".");
  return 0;
}
/*
 * O numero maximo de uma variavel tipo "unsigned char" é de 255, portanto, para
 * qualquer valor de "u" a condição sera verdadeira, criando um loop infinito
 */
