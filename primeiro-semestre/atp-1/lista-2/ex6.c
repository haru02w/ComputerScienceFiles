/*
 * 6. Determine os resultados das expressões abaixo, considerando os valores 2,
 * 7 e 3.5 para as variáveis a, b e c, respectivamente. considere também uma
 * variável lógica l, cujo valor é falso (F). Reescreva as instruções em
 * linguagem c.
 */
#include <math.h>
#include <stdio.h>
// Utilizei 0 como F e 1 como V para traduzir as expressões dos exercicios
// e não depender da biblioteca <stdbool.h>
int main(int argc, char *argv[]) {
  int expression, a = 2, b = 7, l = 0;
  float c = 3.5;

  expression = 2 < 5 && 15 / 3 == 5;
  printf("a) 2<5 e 15/3=5  ==> %d\n", expression);

  expression = 2 < 5 || 15 / 3 == 5;
  printf("b) 2<5 ou 15/3=5  ==> %d\n", expression);

  expression = 0 || 20 / (18 / 3) != (21 / 3) / 2;
  printf("c) F ou 20 div(18/3) <> (21/3) div 2  ==> %d\n", expression);

  expression = !0 || pow(3, 2) / 3 < 15 - 35 % 7;
  printf("d) não V ou pot (3,2)/3 <15 -35 mod 7  ==> %d\n", expression);

  expression = !((5 != 10 / 2) || 1 && 2 - 5 > 5 - 2 || 1);
  printf("e) não ((5<> 10/2) ou V e 2 – 5 > 5 – 2 ou V)  ==> %d\n", expression);

  expression = !1 || pow(3, 2) / 3 < 15 - 35 % 7;
  printf("f) pot (2,4) <> 4 + 2 ou 2 + 3 * 5/3 mod 5 > 0  ==> %d\n",
         expression);

  expression = b == a * c && (l || 1);
  printf("g) b = a * c e (l ou V)  ==> %d\n", expression);

  expression = b > a || b == pow(a, a);
  printf("h) b > a ou b= pot(a,a)  ==> %d\n", expression);

  expression = l && (float)b / a >= c || (!a) <= c;
  printf("i) l e b div a >=c ou não a <= c  ==> %d\n", expression);

  expression = !l || 1 && sqrt(a + b) >= c;
  printf("j) não l ou V e rad(a+b) >=c  ==> %d\n", expression);

  expression = (float)b / a == c || (float)b / a != c;
  printf("k) b/a = c ou b/a <> c  ==> %d\n", expression);

  expression = l || pow(b, a) <= c * 10 + a * b;
  printf("l) l ou pot (b,a) <= c * 10 + a*b   ==> %d\n", expression);

  return 0;
}
