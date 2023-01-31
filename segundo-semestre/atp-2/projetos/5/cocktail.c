#include <stdio.h>
//define a quantidade de elementos a ler
#define MAX 200000
//faz a troca dos elementos
#define SWAP(x, y)                \
	{                         \
		bigint_t tmp = x; \
		x = y;            \
		y = tmp;          \
	}
#define CONDITION(x, y)                          \
	(x.high > y.high || (x.high == y.high && \
			     (x.high >= 0 ? x.low >= y.low : x.low <= y.low)))

//define a struct
typedef struct {
	int high, low;
} bigint_t;
//implementação do insertionsort
void cocktail(bigint_t *arr, int start, int end);
int main(int argc, char *argv[])
{
	// @size = variavel do tamanho do vetor
	// @arr = vetor que guarda os elementos a serem ordenados
	int size = MAX;
	bigint_t arr[size];
	//abre o arquivo
	FILE *fp = fopen("bigint.dat", "r");
	//se não conseguiu abrir, fecha o programa
	if (!fp)
		return 0;
	//le @size elementos
	for (int i = 0; i < size; i++)
		fscanf(fp, "%d %d", &arr[i].high, &arr[i].low);
	fclose(fp);
	//faz a ordenação
	cocktail(arr, 0, size - 1);

	//grava no arquivo
	fp = fopen("cocktail.dat", "w");
	for (int i = 0; i < size; i++)
		fprintf(fp, "%d %d\n", arr[i].high, arr[i].low);
	fclose(fp);
	return 0;
}
void cocktail(bigint_t *list, int start, int end)
{
	int length, bottom, top, swapped, i;
	bigint_t aux;
	length = end;
	bottom = start;
	top = length - 1;
	swapped = 0;
	while (swapped == 0 &&
	       bottom < top) //Se não houver troca de posições ou o ponteiro que
	{ //sobe ultrapassar o que desce, o vetor esta ordenado
		swapped = 1;
		//Este for é a “ida” para a direita
		for (i = bottom; i < top; i = i + 1) {
			if (CONDITION(
				    list[i],
				    list[i +
					 1])) //indo pra direita:testa se o próximo é maior
			{ //indo pra direita:se o proximo é maior que o atual,
				//troca as posições
				aux = list[i];
				list[i] = list[i + 1];
				list[i + 1] = aux;
				swapped = 0;
			}
		} //fecha for
		// diminui o  `top` porque o elemento com o maior valor
		// já está na direita (atual posição top)
		top = top - 1;
		//Este for é a “ida” para a esquerda
		for (i = top; i > bottom; i = i - 1) {
			if (CONDITION(list[i - 1], list[i])) {
				aux = list[i];
				list[i] = list[i - 1];
				list[i - 1] = aux;
				swapped = 0;
			}
		}
		//aumenta o `bottom` porque o menor valor já está
		//na posição inicial (bottom)
		bottom = bottom + 1;
	} //fecha while
} // fim da funçao
