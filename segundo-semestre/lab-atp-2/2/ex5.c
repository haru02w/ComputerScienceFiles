#include <stdio.h>
int main(int argc, char *argv[])
{
	char letrasr[128] = { 0 };
	char frase[1000];
	int existe = 0;
	printf("Digite uma frase: ");
	scanf("%[^\n]s", frase);
	for (int i = 0; frase[i] != '\0'; i++)
		letrasr[frase[i]]++;

	printf("As letras que se repetem são: \n");

	for (int i = 0; i < 128; i++) {
		if (letrasr[i] > 1)
			printf("%c com %d repetições\n", i, letrasr[i]);
	}
	return 0;
}
