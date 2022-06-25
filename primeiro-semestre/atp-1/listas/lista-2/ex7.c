/*
 * 7. Determine o resultado de cada expressão, considerando X=1, A=3, B=5, C=8 e
 * D=7. Reescreva as instruções em Linguagem C.
 */
#include <math.h>
#include <stdio.h>
#define X 1
#define A 3
#define B 5
#define C 8
#define D 7
// Utilizei 0 como F e 1 como V para traduzir as expressões dos exercicios
// e não depender da biblioteca <stdbool.h>
int main(int argc, char *argv[]) {
  int expression;

  expression = !(X > 3);
  printf("a) não (X>3)  ==> %d\n", expression);

  expression = (X < 1) && !(B > D);
  printf("b) (X<1) e não(B>D)  ==> %d\n", expression);

  expression = !(D < 0) && (C > 5);
  printf("c) não (D<0) e (C>5)  ==> %d\n", expression);

  expression = !(X > 3) || (C < 7);
  printf("d) não (X>3) ou (C<7)  ==> %d\n", expression);

  expression = (A > B) || (C > B);
  printf("e) (A>B) ou (C>B)  ==> %d\n", expression);

  expression = (X >= 2);
  printf("f) (X>=2)  ==> %d\n", expression);

  expression = (X < 1) && (B >= D);
  printf("g) (X<1) e (B>=D)  ==> %d\n", expression);

  expression = (D < 0) || (C > 5);
  printf("h) (D<0) ou (C>5)  ==> %d\n", expression);

  expression = !(D > 3) || !(B < 7);
  printf("i) não (D>3) ou não(B<7)  ==> %d\n", expression);

  expression = (A > B) || !(C > B);
  printf("j) (A>B) ou não (C>B)  ==> %d\n", expression);

  return 0;
}
