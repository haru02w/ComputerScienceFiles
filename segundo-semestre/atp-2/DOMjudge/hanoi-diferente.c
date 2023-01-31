#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ndisks;
int count = 0;
int movs;
int towers[3][21] = { 0 };

void iff()
{
	if (count != movs)
		return;
	int zeros;
	for (int i = 0; i < 3; i++) {
		zeros = 0;
		for (int j = ndisks; j >= 0; j--) {
			if (!towers[i][j]) {
				zeros++;
			} else {
				printf("%d ", towers[i][j]);
			}
		}
		if (zeros == ndisks + 1)
			printf("0 ");
		printf("\n");
	}
	exit(0);
}
void hanoi(int ndisks, int o, int a, int d, int oo, int aa, int dd)
{
	iff();
	if (ndisks == 1) {
		towers[d][dd] = towers[o][oo];
		towers[o][oo] = 0;
		//		towers[o]--;
		//		towers[d]++;
		count++;
	} else {
		hanoi(ndisks - 1, o, d, a, oo + 1, dd, aa);
		iff();
		towers[d][dd] = towers[o][oo];
		towers[o][oo] = 0;
		//		towers[o]--;
		//		towers[d]++;
		count++;
		hanoi(ndisks - 1, a, o, d, aa, oo, dd + 1);
	}
}
int main()
{
	scanf("%d %d", &ndisks, &movs);
	for (int i = 0; i < ndisks; i++)
		towers[0][i] = ndisks - i;
	hanoi(ndisks, 0, 1, 2, 0, 0, 0);
	count = movs;
	iff();
	return 0;
}
