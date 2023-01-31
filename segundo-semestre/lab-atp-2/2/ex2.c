#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
	char frase[1000];
	int minusculas = 0, maiusculas = 0;
	printf("Digite uma frase: ");
	scanf("%[^\n]s", frase);
	for (int i = 0; i < strlen(frase); i++) {
		switch (frase[i]) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			minusculas++;
			break;
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
			maiusculas++;
			break;
		}
	}
	printf("Vogais totais: %d\nVogais maiusculas: %d\nVogais minusculas: %d\n",
	       minusculas + maiusculas, maiusculas, minusculas);
	return 0;
}
