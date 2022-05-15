/* 16. Calcular o salário líquido do funcionário sabendo que este é constituído
 * pelo salário bruto mais o valor das horas extras subtraindo 8% de INSS do
 * total. Serão lidos nesse problema o salário bruto, o valor das horas extras e
 * o numero de horas extras. Apresentar ao final o salário líquido.
 */
#include <stdio.h>
int main(int argc, char *argv[]) {
  float salario, valor_hrs_extra, hrs_extra;
  printf("Digite o salario bruto: ");
  scanf("%f", &salario);
  printf("Digite o valor das horas extras: ");
  scanf("%f", &valor_hrs_extra);
  printf("Digite a quantidade de horas extras: ");
  scanf("%f", &hrs_extra);
  // *0.92 é o mesmo que subtrair 8%
  salario = (valor_hrs_extra * hrs_extra + salario) * 0.92;
  printf("O salario liquido é de R$%.2f\n", salario);

  return 0;
}
