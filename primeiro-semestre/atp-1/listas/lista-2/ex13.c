/*13. Faça um algoritmo para ler os valores a, b, c, d, e, f e determinar o
 * valor de x, a partir da equação:
 * x = ((a + (b / c)) / (d - 2 * (e / f))) + 4 * a;
 */
#include <stdio.h>
int main(int argc, char *argv[]) {
  float x, arr[6];
  /*
    traduzindo um pouco mais pra simbologia humana:
    arr[0] = a , arr[1] = b, arr[2] = c, e assim por diante
    utilizei arrays por que acho menos maçante que escrever as variaveis na mão
  */
  for (char i = 'a'; i <= 'f'; i++) {
    printf("Digite o valor de %c: ", i);
    scanf("%f", &arr[i - 'a']);
  }
  x = ((arr[0] + (arr[1] / arr[2])) / (arr[3] - 2 * (arr[4] / arr[5]))) +
      4 * arr[0];
  return 0;
}
