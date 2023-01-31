#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MIN(x, y) (x < y ? x : y)
#define SIZE 25

void maze_shortest_path(int arr_size, int arr[arr_size][arr_size], int i, int j,
			int end_col, int dist);
int main(int argc, char *argv[])
{
	int arr_size, start_col, end_col;
	int tmp;
	scanf("%d %d %d", &arr_size, &start_col, &end_col);
	int arr[arr_size][arr_size];
	for (int i = 0; i < arr_size; i++) {
		for (int j = 0; j < arr_size; j++) {
			scanf("%d", &tmp);
			arr[i][j] = tmp;
		}
	}

	maze_shortest_path(arr_size, arr, 0, start_col, end_col, 0);
	printf("-1\n");
	return 0;
}

void maze_shortest_path(int arr_size, int arr[arr_size][arr_size], int i, int j,
			int end_col, int dist)
{
	if (!(i >= 0 && i < arr_size && j >= 0 && j < arr_size &&
	      arr[i][j] == 0))
		return;

	if (i == arr_size - 1 && j == end_col) {
		printf("%d\n", dist);
		exit(0);
	}

	arr[i][j] = dist + 1;

	maze_shortest_path(arr_size, arr, i + 1, j, end_col, dist + 1);
	maze_shortest_path(arr_size, arr, i, j + 1, end_col, dist + 1);
	maze_shortest_path(arr_size, arr, i, j - 1, end_col, dist + 1);

	arr[i][j] = 0;

	return;
}
