#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MIN(x, y) (x < y ? x : y)

int maze_shortest_path(int **arr, int arr_size, int i, int j, int end_col,
		       int dist);
int main(int argc, char *argv[])
{
	int **arr, arr_size, start_col, end_col;
	int tmp;
	scanf("%d %d %d", &arr_size, &start_col, &end_col);

	arr = malloc(arr_size * sizeof(int *));
	for (int i = 0; i < arr_size; i++) {
		arr[i] = malloc(arr_size * sizeof(int));
		for (int j = 0; j < arr_size; j++) {
			scanf("%d", &tmp);
			arr[i][j] = tmp;
		}
	}

	tmp = maze_shortest_path(arr, arr_size, 0, start_col, end_col, 0);
	tmp = tmp == INT_MAX ? -1 : tmp;
	printf("%d", tmp);

	for (int i = 0; i < arr_size; i++)
		free(arr[i]);
	free(arr);
	return 0;
}

int maze_shortest_path(int **arr, int arr_size, int i, int j, int end_col,
		       int dist)
{
	static int min_dist = INT_MAX;
	if (!(i >= 0 && i < arr_size && j >= 0 && j < arr_size &&
	      arr[i][j] == 0))
		return -1;

	if (i == arr_size - 1 && j == end_col)
		return (min_dist = MIN(min_dist, dist));

	arr[i][j] = dist + 1;

	maze_shortest_path(arr, arr_size, i + 1, j, end_col, dist + 1);
	maze_shortest_path(arr, arr_size, i, j + 1, end_col, dist + 1);
	maze_shortest_path(arr, arr_size, i, j - 1, end_col, dist + 1);
	maze_shortest_path(arr, arr_size, i - 1, j, end_col, dist + 1);

	arr[i][j] = 0;

	return min_dist;
}
