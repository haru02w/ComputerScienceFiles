#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char *argv[])
{
	int vet[18], matriz[3][6];
	srand(time(NULL));
	for (int i = 0; i < 18; i++) {
		vet[i] = rand() % 100;
	}

	for (int i = 0, aux = -1; i < 18; ++i) {
		aux = i % 6 == 0 ? aux + 1 : aux;
		matriz[aux][i % 6] = vet[i];
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 6; j++) {
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
	return 0;
}
