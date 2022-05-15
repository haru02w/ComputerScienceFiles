/*
 * 31. Elabore um código em linguagem C para solicitar a idade do usuário. Em
 * seguida, o programa deve analisar e informar: se ele pode dirigir, caso tenha
 * 18 anos ou mais; e se ele pode usufruir de aposentadoria, caso tenha 70 anos
 * ou mais. O programa deve ser escrito usando const. Em seguida, reescreva o
 * código usando #define
 */
#include <stdio.h>
#define I18 18
#define I70 70
void using_const() {
  const int i18 = 18, i70 = 70;
  unsigned int idade;
  printf("Digite sua idade: ");
  scanf("%ud", &idade);
  if (idade >= i18)
    printf("Você pode dirigir\n");
  if (idade >= i70)
    printf("e tambem pode usufruir de aposentadoria.\n");
}
void using_define() {
  unsigned int idade;
  printf("Digite sua idade: ");
  scanf("%ud", &idade);
  if (idade >= I18)
    printf("Você pode dirigir\n");
  if (idade >= I70)
    printf("e tambem pode usufruir de aposentadoria.\n");
}
int main(int argc, char *argv[]) {
  using_const();
  return 0;
}
