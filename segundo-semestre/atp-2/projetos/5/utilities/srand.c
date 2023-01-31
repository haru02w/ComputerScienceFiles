#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>
int main(int argc, char *argv[])
{
	srand(time(NULL));
	FILE *fp = fopen("../bigint.dat", "w");
	for (int i = 0; i < 200000; i++)
		fprintf(fp, "%d %d\n",
			(rand() % INT_MAX) * (rand() % 2 ? -1 : 1),
			rand() % INT_MAX);
	fclose(fp);
	return 0;
}
