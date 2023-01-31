#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 1000

void shellSort(int n, char array[n][MAX_SIZE]);

int main(int argc, char *argv[])
{
	int size;
	scanf("%d", &size);
	char word[size][MAX_SIZE];

	for (int i = 0; i < size; i++)
		scanf("%s", word[i]);
	shellSort(size, word);

	return 0;
}

void shellSort(int n, char array[n][MAX_SIZE])
{
	//strcmp - 1-2 ou seja, se > 0 ent 1 > 2
	int init = 1;
	while (!(init > n / 8 && init <= n / 4))
		init *= 2;

	for (int interval = init; interval > 0; interval /= 2) {
		for (int i = interval; i < n; i += 1) {
			int j;
			char temp[MAX_SIZE];
			strcpy(temp, array[i]);
			for (j = i; j >= interval &&
				    /* array[j - interval] > temp */
				    strcmp(array[j - interval], temp) > 0;
			     j -= interval) {
				strcpy(array[j], array[j - interval]);
			}
			strcpy(array[j], temp);
		}
		for (int i = 0; i < n; i++)
			printf("%s ", array[i]);
		printf("\n");
	}
}
