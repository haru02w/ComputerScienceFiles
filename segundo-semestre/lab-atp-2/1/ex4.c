#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	int matriz[5][5];
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			scanf("%d", &matriz[i][j]);

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			if (matriz[i][j] != matriz[j][i]) {
				printf("A matriz digitada não é simetrica\n");
				return 0;
			}

	printf("A matriz digitada é simetrica\n");
	return 0;
}
