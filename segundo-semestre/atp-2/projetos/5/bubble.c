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

//define a struct
typedef struct {
	int high, low;
} bigint_t;
//implementação do insertionsort
void insertionsort(bigint_t *arr, int start, int end);
void bubblesort(bigint_t *arr, int start, int end);
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
	bubblesort(arr, 0, size - 1);

	//grava no arquivo
	fp = fopen("bubble.dat", "w");
	for (int i = 0; i < size; i++)
		fprintf(fp, "%d %d\n", arr[i].high, arr[i].low);
	fclose(fp);
	return 0;
}
void insertionsort(bigint_t *arr, int start, int end)
{
	//guarda o valor do elemento a ser movido
	bigint_t key;
	//começa do segundo elemento
	for (int i = start + 1, j; i <= end; i++) {
		//passa o elemento pra tras se ele for menor
		for (key = arr[i], j = i - 1;
		     j >= 0 && (arr[j].high > key.high ||
				(arr[j].high == key.high &&
				 (arr[j].high >= 0 ? arr[j].low >= key.low :
						     arr[j].low <= key.low)));
		     //passa o elemento da frente pra tras
		     arr[j + 1] = arr[j],
		    j--)
			;
		//reinsere o elemento que foi retirado anteriormente em seu devido lugar
		arr[j + 1] = key;
	}
}

void bubblesort(bigint_t *arr, int start, int end)
{
	for (int i = end; i >= 0; i--)
		for (int j = 0; j <= i; j++)
			if (arr[j].high > arr[j + 1].high ||
			    (arr[j].high == arr[j + 1].high &&
			     (arr[j].high >= 0 ? arr[j].low >= arr[j + 1].low :
						 arr[j].low <= arr[j + 1].low)))
				SWAP(arr[j], arr[j + 1]);
}
