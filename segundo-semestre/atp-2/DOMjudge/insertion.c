#include <stdio.h>
#include <stdlib.h>

void insertionPiramid(double arr[], int size, int separator);
int main(int argc, char *argv[])
{
	int size, separator;
	scanf("%d %d", &size, &separator);
	double arr[size];

	for (int i = 0; i < size; i++)
		scanf("%lf", &arr[i]);

	insertionPiramid(arr, size, separator);

	for (int i = 0; i < size; i++)
		printf("%.3lf ", arr[i]);
	printf("\n");

	return 0;
}

void insertionPiramid(double arr[], int size, int separator)
{
	int init = 1;
	for (int i = init; i < separator + 1; i++) {
		double tmp = arr[i];
		int j = i - 1;

		while (tmp < arr[j] && j >= 0) {
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = tmp;
	}

	for (int i = separator + 2; i < size; i++) {
		double tmp = arr[i];
		int j = i - 1;

		while (tmp > arr[j] && j >= 0) {
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = tmp;
	}
}
