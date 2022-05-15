/*
 * 5. Considere a sequência apresentada abaixo e responda qual o valor
 * armazenado na variável segurado
 */
#include <stdio.h>
int main(int argc, char *argv[]) {
  int idade = 28;
  float valor = 1000.00, fator = 0.05;
  int segurado = idade < 30 && valor * fator <= 500.00;
  printf("idade = 28\nvalor = 1000.00\nfator = 0.05\nsegurado = idade < 30 e "
         "valor*fator <= 500.00  ==> %d\n",
         segurado);
  return 0;
}
