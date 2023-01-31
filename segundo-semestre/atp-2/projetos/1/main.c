/* 
 * Autor: João Victor Millane
 * Exercicio: Texto Misturado
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define WORD 50
#define PREV 5

//Funções definidas durante programa
int inicialize();
void verify(FILE *pfiler1, FILE *pfiler2, FILE *pfilew);
void core(FILE *pfiler1, FILE *pfiler2, FILE *pfilew);

/*
 * pfiler1 - ponteiro para o arquivo 1 de leitura = "codigos.dat"
 * pfiler2 - ponteiro para o arquivo 2 de leitura = "palavras.dat"
 * pfilew - ponteiro para o arquivo unico de escrita= "linhas.dat"
 */
int main()
{
	FILE *pfiler1, *pfiler2, *pfilew;
	//Verifica a existencia dos arquivos de entrada
	if (inicialize())
		return 0;
	//abre os arquivos
	pfiler1 = fopen("codigos.dat", "r");
	pfiler2 = fopen("palavras.dat", "r");
	pfilew = fopen("linhas.dat", "w");

	//faz o processamento do problema por completo
	core(pfiler1, pfiler2, pfilew);
	//verifica se algum dos arquivos terminaram antes do previsto
	verify(pfiler1, pfiler2, pfilew);

	//fecha os arquivos
	fclose(pfiler1);
	fclose(pfiler2);
	fclose(pfilew);
	//encerra o programa
	return 0;
}
/* 
 * inicialize - Verifica a existencia dos arquivos necessarios para execução
 * e lança um erro caso não exista
 */
int inicialize()
{
	FILE *pfile1, *pfile2;
	//tenta os arquivos como leitura
	pfile1 = fopen("codigos.dat", "r");
	pfile2 = fopen("palavras.dat", "r");
	//verifica se os arquivos foram abertos corretamente
	if (!pfile1 || !pfile2) {
		printf("Os arquivos de entrada não estão presentes.\n");
		return 1;
	}
	//fecha os arquivos após a verificação
	fclose(pfile1);
	fclose(pfile2);
	return 0;
}

/*
 * core - onde maior toda a logica do programa é implementada
 * @cod - pega os codigos do arquivo "codigos.dat"
 * @counter - salva a posição de @prev no momento atual
 * @word - pega as palavras do arquivo "palavras.dat"
 * --a maior palavra do Portugues possui 46 letras
 * @prev - salva as posicões das palavras anteriores
 */
void core(FILE *pfiler1, FILE *pfiler2, FILE *pfilew)
{
	int cod, counter = 0;
	char word[WORD];
	long prev[PREV + 1]; // +1 para guardar a posição atual
	prev[0] = ftell(pfiler2);
	while (!feof(pfiler2)) {
		//verifica se o arquivo de codigos já chegou ao fim
		// e lê o codigo do arquivo
		if (fscanf(pfiler1, "%d", &cod) == EOF)
			return;

		if (cod > 0) { //se o codigo é maior que 0
			//passa pela quantidade de palavras requisitada ou
			// até o fim do arquivo
			for (int i = 0; i < cod && !feof(pfiler2); i++) {
				//verifica se chegou ao fim do arquivo
				// e lê a palavra do arquivo
				if (fscanf(pfiler2, "%s ", word) == EOF)
					return;
				//guarda a ultima posição da palavra num array circular
				counter = (counter + 1) % (PREV + 1);
				prev[counter] = ftell(pfiler2);

				//escreve em linhas.dat
				if (i != 0)
					fprintf(pfilew, " ");
				fprintf(pfilew, "%s", word);
			}

		} else if (cod < 0) { //se o codigo é maior que 0
			//volta @cod palavras para trás
			fseek(pfiler2,
			      prev[(counter + PREV + cod + 1) % (PREV + 1)],
			      SEEK_SET);
			//até que a posição anterior volte a atual
			for (int i = 0; ftell(pfiler2) <= prev[counter - 1];
			     i++) {
				//leia a palavra do arquivo
				fscanf(pfiler2, "%s ", word);
				//e escreve no outro
				if (i != 0)
					fprintf(pfilew, " ");
				fprintf(pfilew, "%s", word);
			}
		} else
			fprintf(pfilew, "0");
		fprintf(pfilew, "\n");
	}
	return;
}
/*
 * verify - Verifica se algum dos arquivos terminou
 * antes do esperado e escreve o restante dos valores
 * @cod - pega os codigos do arquivo "codigos.dat"
 * @counter - conta o numero de palavras para limitar 
 * a quantidade 5 por linha
 * @word - pega as palavras do arquivo "palavras.dat"
*/
void verify(FILE *pfiler1, FILE *pfiler2, FILE *pfilew)
{
	int cod, counter = 0;
	char word[WORD];
	//verifica se somente o arquivo de codigos terminou
	if (feof(pfiler2)) {
		//enquanto os codigos não terminarem
		for (int i = 0; fscanf(pfiler1, "%d", &cod) != EOF; i++) {
			if (i != 0)
				fprintf(pfilew, " ");
			fprintf(pfilew, "%d", cod);
		}

		//verifica se somente o arquivo de palavras terminou
	} else if (feof(pfiler1)) {
		//enquanto as palavras não terminarem
		for (int i = 0; fscanf(pfiler2, "%s ", word) != EOF; i++) {
			//printem elas, separando de 5 em 5 sem pular linha logo no começo
			if (counter % PREV == 0 && counter != 0) {
				fprintf(pfilew, "\n");
				i = 0;
			}
			counter++;
			if (i != 0)
				fprintf(pfilew, " ");
			fprintf(pfilew, "%s", word);
		}
	}
}
