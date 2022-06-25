/*25. Compile o programa abaixo e explique as saídas obtidas com as instruções
 * escritas na linha 15.
 */
#include <stdio.h>
int main(int argc, char *argv[]) {
  char nome[40];
  int idade;

  printf("Digite o seu nome: ");
  scanf("%s", nome);

  printf("Digite sua idade: ");
  scanf("%d", &idade);

  printf("%p\n%p\n%lu\n%lu\n", &nome, &idade, sizeof(nome), sizeof(idade));
  return 0;
}
/* Explicação:
 * %p é o formatador para ponteiros
 *
 * No caso desse programa está apresentando os endereços de memoria das
 * variaveis "nome" e "idade"
 *
 * %lu é o formatador para "unsigned long int"
 * %lu funciona bem para "sizeof()" porem
 * o correto é utilizar o formatador especifico para o tipo de dado
 * retornado do "sizeof", "size_t", implementado desde a revisão C99 de 1999:
 * %zu
 *
 * No caso, o %lu está apresentando o tamanho em bytes ocupado pelas variaveis
 * "nome" e "idade"
 */
