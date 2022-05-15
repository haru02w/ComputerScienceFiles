/*
 * 30. Escreva um código em linguagem C para apresentar as quantidades de bytes
 * para as variáveis char, int, float e double. Em seguida, aplique os
 * modificadores unsigned e long. Os resultados obtidos são maiores ou menores
 * que os disponíveis na tabela abaixo? Explique!
 */
#include <stdio.h>
int main(int argc, char *argv[]) {
  printf("char\t\t\t%zu\n", sizeof(char));
  printf("unsigned char\t\t%zu\n", sizeof(unsigned char));
  printf("signed char\t\t%zu\n", sizeof(signed char));
  printf("int\t\t\t%zu\n", sizeof(int));
  printf("unsigned int\t\t%zu\n", sizeof(unsigned int));
  printf("signed int\t\t%zu\n", sizeof(signed int));
  printf("long int\t\t%zu\n", sizeof(long int));
  printf("signed long int\t\t%zu\n", sizeof(signed long int));
  printf("unsigned long int\t%zu\n", sizeof(unsigned long int));
  printf("float\t\t\t%zu\n", sizeof(float));
  printf("double\t\t\t%zu\n", sizeof(double));
  printf("long double\t\t%zu\n", sizeof(long double));
  return 0;
}
/*
 * No meu computador, varios valores estavam diferentes da tabela.
 * Cada arquitetura e sistema operacional define tamanhos de variaveis de forma
 * diferentes, portanto é recomendado utilizar a biblioteca <stdint.h>, que
 * define tipos de variaveis com tamanhos estaticos, indiferentes ao
 * sistema operacional ou arquitetura, para determinadas aplicações
 */
