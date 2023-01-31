#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
	char frase[1000];
	int minusculas = 0, maiusculas = 0, vogal;
	printf("Digite uma frase: ");
	scanf("%[^\n]s", frase);
	for (int i = 0; i < strlen(frase); i++) {
		switch (frase[i]) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
			vogal = 1;
			break;
		default:
			vogal = 0;
		}
		if (frase[i] >= 'a' && !vogal)
			minusculas++;
		else if (frase[i] >= 'A' && !vogal)
			maiusculas++;
	}
	printf("Consoantes totais: %d\nConsoantes maiusculas: %d\nConsoantes minusculas: %d\n",
	       minusculas + maiusculas, maiusculas, minusculas);
	return 0;
}
