/*
 *8. As variáveis A, B e C são variáveis do tipo inteiro, com valores 5, 10 e
 * -8, respectivamente. Existe uma variável D que armazena o valor 1,5.
 * Reescreva as instruções em Linguagem C. Apresente os resultados para:
 */
#include <math.h>
#include <stdio.h>
// Utilizei 0 como F e 1 como V para traduzir as expressões dos exercicios
// e não depender da biblioteca <stdbool.h>
int main(int argc, char *argv[]) {
  int expression, a = 5, b = 10, c = -8;
  float d = 1.5;

  expression = 2 * a % 3 - c;
  printf("a. 2 * A mod 3 – C  ==> %d\n", expression);

  expression = sqrt(-2 * c) / 4;
  printf("b. sqrt(–2 * C) div 4  ==> %d\n", expression);

  expression = (30 % 4 * pow(3, 3)) * -1;
  printf("c. (30 %% 4 * pot (3,3)) * –1  ==> %d\n", expression);

  expression = pow(-c, 2) + (d * 10) / a;
  printf("d. pot (–C,2) + (D * 10) / A  ==> %d\n", expression);

  expression = sqrt(pow(a, (float)b / a)) + c * d;
  printf("e. rad (pot (A, B/A)) + C * D  ==> %d\n", expression);

  return 0;
}
