#include <stdio.h>
#include <stdlib.h>
long binary_search(long *arr, long start, long end, long search)
{
	for (long mid; start <= end;) {
		mid = start + (end - start) / 2;
		if (arr[mid] > search)
			end = mid - 1;
		else if (arr[mid] < search)
			start = mid + 1;
		else
			return mid;
	}
	return -1;
}

long binary_search_reverse(long *arr, long start, long end, long search)
{
	for (long mid; start <= end;) {
		mid = start + (end - start) / 2;
		if (arr[mid] > search)
			start = mid + 1;
		else if (arr[mid] < search)
			end = mid - 1;
		else
			return mid;
	}
	return -1;
}

int main(int argc, char *argv[])
{
	int size, terms;
	scanf("%d", &size);
	long *arr = malloc(size * sizeof(long));

	for (int i = 0; i < size; i++)
		scanf("%ld", &arr[i]);

	scanf("%d", &terms);
	for (int i = 0; i < terms; i++) {
		long search, ret1, ret2;
		scanf("%ld", &search);
		ret1 = binary_search(arr, 0, (size - 1) / 2, search);
		ret2 = binary_search_reverse(arr, ((size - 1) / 2) + 1,
					     size - 1, search);
		if (ret1 != -1)
			printf("%ld", ret1);
		else
			printf("%ld", ret2);
		printf(" ");
	}
	printf("\n");

	return 0;
}
