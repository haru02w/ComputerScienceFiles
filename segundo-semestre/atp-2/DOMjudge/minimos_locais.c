#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int min_local(int **arr, int arr_size, int start_region, int end_region);
int main(int argc, char *argv[])
{
	int **arr, arr_size, regions;
	int start_region, end_region;
	scanf("%d %d", &arr_size, &regions);

	arr = malloc(arr_size * sizeof(int *));
	for (int i = 0; i < arr_size; i++) {
		arr[i] = malloc(arr_size * sizeof(int));
		for (int j = 0; j < arr_size; j++)
			scanf("%d ", &arr[i][j]);
	}

	for (int i = 0; i < regions; i++) {
		scanf("%d %d", &start_region, &end_region);
		printf("%d\n",
		       min_local(arr, arr_size, start_region - 1, end_region));
	}

	return 0;
}

int min_local(int **arr, int arr_size, int start_region, int end_region)
{
	int min = INT_MAX;
	for (int i = start_region; i < end_region; i++)
		for (int j = start_region; j < end_region; j++)
			min = arr[i][j] < min ? arr[i][j] : min;
	return min;
}
