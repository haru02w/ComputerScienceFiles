/*
 * 4. Apresente o resultado para cada expressão.
 */
#include <math.h>
#include <stdio.h>
int main(int argc, char *argv[]) {
  int expression;

  expression = 2 * 4 == 24 / 3;
  printf("a. 2*4=24/3  ==> %d\n", expression);

  expression = 5 % 4 < 19 % 6;
  printf("b. 5mod4<19mod6  ==> %d\n", expression);

  expression = (float)3 * 5 / 4 <= pow(3, 2) / 0.5;
  printf("c. 3*5div4<=pot(3,2)/0.5  ==> %d\n", expression);

  expression = 2 + 8 % 7 >= 3 * 6 - 15;
  printf("d. 2+8mod7>=3*6-15  ==> %d\n", expression);

  return 0;
}
