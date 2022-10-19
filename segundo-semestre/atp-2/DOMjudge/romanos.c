#include <stdio.h>
#include <string.h>
#define MAX 100

#define M 1000
#define D 500
#define C 100
#define L 50
#define X 10
#define V 5
#define I 1

void convert_rtoi(int *integer, char *roman);
void convert_itor(char *roman, int *integer);
void str_clear(char *roman);

int main(int argc, char *argv[])
{
	int lines, switcher, i, j, integer, sum = 0;
	char roman[MAX];
	scanf("%d", &lines);
	for (i = 0; i < lines; i++) {
		scanf("%d", &switcher);
		if (switcher == 1) {
			scanf("%s", roman);
			convert_rtoi(&integer, roman);
			sum += integer;
			printf("%d\n", integer);
		} else if (switcher == 2) {
			str_clear(roman);
			scanf("%d", &integer);
			convert_itor(roman, &integer);
			printf("%s\n", roman);
		} else
			return 0;
		integer = 0;
	}
	printf("%d\n", sum);
	return 0;
}

void str_clear(char *roman)
{
	int i;
	for (i = 0; i < MAX; i++) {
		roman[i] = '\0';
	}
}

void convert_itor(char *roman, int *integer)
{
	int i, j, lastn, iarr[4];
	char *str[4][4] = { { "M" },
			    { "C", "CD", "D", "CM" },
			    { "X", "XL", "L", "XC" },
			    { "I", "IV", "V", "IX" } };

	iarr[0] = *integer / M;
	iarr[1] = (*integer % M) / C;
	iarr[2] = (*integer % C) / X;
	iarr[3] = (*integer % X) / I;

	for (i = 0; i < 4; i++) {
		while (iarr[i] != 0) {
			switch (iarr[i]) {
			case 1 ... 3:
				strcat(roman, str[i][0]);
				iarr[i] -= 1;
				break;
			case 4:
				strcat(roman, str[i][1]);
				iarr[i] -= 4;
				break;
			case 5 ... 8:
				strcat(roman, str[i][2]);
				iarr[i] -= 5;
				break;
			case 9:
				strcat(roman, str[i][3]);
				iarr[i] -= 9;
				break;
			}
		}
	}
}

void convert_rtoi(int *integer, char *roman)
{
	int lastn = 0x7FFFFFFF;
	int i, change;
	for (i = 0; i < strlen(roman); i++) {
		switch (roman[i]) {
		case 'M':
			change = M;
			break;
		case 'D':
			change = D;
			break;

		case 'C':
			change = C;
			break;

		case 'L':
			change = L;
			break;

		case 'X':
			change = X;
			break;

		case 'V':
			change = V;
			break;

		case 'I':
			change = I;
			break;
		}
		if (lastn < change)
			*integer -= 2 * lastn;
		*integer += change;
		lastn = change;
	}
	return;
}
