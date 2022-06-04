#include <stdio.h>

int main() {

	int n1,n2,n3;

	printf("Digite 3 valores inteiros e diferentes entre si: ");
	
	scanf("%d %d %d", &n1,&n2,&n3);

	if (n1<n2 && n1<n3) {
		printf("O menor numero e: %d", n1);
	} else if (n2<n1 && n2<n3) {
		printf("O menor numero e: %d", n2);
	} else {
		printf("O menor numero e: %d", n3);
	}

	\\printf("\n");
	\\system("PAUSE");

	return 0;
}