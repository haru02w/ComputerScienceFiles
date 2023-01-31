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
void quicksort(bigint_t *arr, int start, int end);
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
	quicksort(arr, 0, size - 1);

	//grava no arquivo
	fp = fopen("quick.dat", "w");
	for (int i = 0; i < size; i++)
		fprintf(fp, "%d %d\n", arr[i].high, arr[i].low);
	fclose(fp);
	return 0;
}

void quicksort(bigint_t *arr, int low, int high)
{
	//se os ponteiros se crusarem, termina a recursão
	if (low >= high)
		return;

	//seleciona um pivot
	int pivot = high, j = low;
	//se o pivot for menor que os elementos ordenados a partir dele, então pula pra proxima execução
	for (int i = low; i < high; i++) {
		if (arr[i].high > arr[pivot].high ||
		    (arr[i].high == arr[pivot].high &&
		     (arr[i].high >= 0 ? arr[i].low >= arr[pivot].low :
					 arr[i].low <= arr[pivot].low)))
			continue;
		//senão, troca o maior elementos dos ordenados com o atual
		SWAP(arr[i], arr[j]);
		//anda um elemento no vetor elemento atual
		j++;
	}
	// coloca o pivot no lugar ordenado
	SWAP(arr[j], arr[pivot]);
	//chama as proximos pivot para os subarrays
	quicksort(arr, low, j - 1);
	quicksort(arr, j + 1, high);
}
