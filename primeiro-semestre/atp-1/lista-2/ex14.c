/*
 * 14. Calcular o aumento que será dado a um funcionário, obtendo do usuário o
 * salário atual e a porcentagem de aumento. Apresentar o novo valor do salário
 * e o valor do aumento.
 */
#include <stdio.h>
int main(int argc, char *argv[]) {
  float salario_atual, aumento;
  printf("Digite o salario atual do funcionário: ");
  scanf("%f", &salario_atual);
  printf("Digite o valor de aumento em porcentagem: ");
  scanf("%f", &aumento);
  printf("Seu aumento foi de %d%%\n", (int)aumento);
  aumento = (aumento / 100) + 1;
  printf("O novo salario do funcionário é: R$%.2f\n", salario_atual * aumento);
  return 0;
}
