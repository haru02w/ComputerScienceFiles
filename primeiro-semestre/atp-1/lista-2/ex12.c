/* 12. O proprietário de uma lanchonete deseja informatizar o seu
 * estabelecimento. Elabore um algoritmo para ler o número da mesa e a
 * quantidade dos itens consumidos, definidos em um cardápio resumido. O
 * algoritmo d;eve calcular 10% sobre a conta, valor este referente aos serviços
 * prestados. O algoritmo deve permitir ler itens contidos no cardápio, que são:
 * Refrigerante→2,50; Cerveja→4,00; Pizza→47,30; Almoço→15,00; Porção→10,50.
 */
#include <stdio.h>
// cardapio:
#define R 2.50
#define C 4.00
#define PI 47.30
#define A 15.00
#define PO 10.50

int main(int argc, char *argv[]) {
  int mesa, qtd, item;
  float valor;
  while (1) {
    valor = 0;
    printf("Digite o numero da mesa (0 para fechar): ");
    scanf("%d", &mesa);
    if (!mesa)
      break;
    while (1) {
      printf("0) Finalizar conta\n1) Refrigerante\n2) Cerveja\n"
             "3) Pizza\n4) Almoço\n5) Porção\n"
             "Digite o numero do item vendido: ");
      scanf("%d", &item);
      if (!item)
        break;
      printf("Digite a quantidade de itens pedidos (0 para cancelar): ");
      scanf("%d", &qtd);
      if (qtd < 0) {
        printf("Erro. Digite uma quantidade valida\n");
        continue;
      }
      if (!qtd)
        continue;
      switch (item) {
      case 1:
        valor += R;
        break;
      case 2:
        valor += C;
        break;
      case 3:
        valor += PI;
        break;
      case 4:
        valor += A;
        break;
      case 5:
        valor += PO;
        break;
      default:
        printf("Erro. Digite um item valido\n");
      }
    }
    printf("Valor total de %.2f reais\n", valor);
  }
  return 0;
}
