#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
	char letras_usadas[128];
	char frase[1000];
	int qtd = 1;

	printf("Digite uma frase: ");
	scanf("%[^\n]s", frase);
	for (int i = 0; i < strlen(frase); i++)
		qtd += frase[i] == ' ' ? 1 : 0;
	printf("%d\n", qtd);

	return 0;
}
