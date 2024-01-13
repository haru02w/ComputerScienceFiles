#include <stdio.h>
#include <limits.h>
#include <string.h>
#define MAX 2001

int palindromo(char *string, int i, int j)
{
	if (i > j)
		return 1;
	if (string[i] != string[j])
		return 0;
	return palindromo(string, i + 1, j - 1);
}

int main(int argc, char *argv[])
{
	int len, res = 0;
	char string[MAX];
	char sstr[MAX][MAX]; //why is this here?
	scanf("%s", string);
	len = strlen(string);
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			if (palindromo(string, i, j) != 0 && j - i > res) {
				res = j - i;
			}
		}
	}
	printf("%d\n", res + 1);
	return 0;
}
