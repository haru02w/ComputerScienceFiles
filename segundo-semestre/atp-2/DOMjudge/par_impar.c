#include <stdio.h>
int main(int argc, char *argv[])
{
	int i, n, x, y;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		if ((x + y) % 2)
			printf("B");
		else
			printf("A");
		printf("\n");
	}

	return 0;
}
