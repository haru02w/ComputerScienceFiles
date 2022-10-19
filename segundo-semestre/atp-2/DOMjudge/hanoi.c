#include <stdio.h>
#include <stdlib.h>
int count = 0;
int max, movs;
int towers[3];
void iff()
{
	if (count == movs) {
		printf("%d %d %d\n", towers[0], towers[1], towers[2]);
		exit(0);
	}
}
void hanoi(int ndisks, int o, int a, int d)
{
	iff();
	if (ndisks == 1) {
		towers[o]--;
		towers[d]++;
		count++;
	} else {
		hanoi(ndisks - 1, o, d, a);
		iff();
		towers[o]--;
		towers[d]++;
		count++;
		hanoi(ndisks - 1, a, o, d);
	}
}
int main()
{
	int ndisks;
	scanf("%d %d", &ndisks, &movs);
	max = ndisks;
	towers[0] = ndisks;
	towers[1] = 0;
	towers[2] = 0;
	hanoi(ndisks, 0, 1, 2);
	printf("%d %d %d\n", towers[0], towers[1], towers[2]);
	return 0;
}
