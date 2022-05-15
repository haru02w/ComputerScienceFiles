/*
 * 29. Explique o resultado obtido com:
 */
#include <stdio.h>
int main(int argc, char *argv[]) {
  char c;
  for (c = 0; c < 128; ++c)
    printf(".");
  return 0;
}
/*
 * O numero maximo positivo de uma variavel tipo "char" é de 127, portanto, para
 * qualquer valor de "c" a condição sera verdadeira, criando um loop infinito
 */
