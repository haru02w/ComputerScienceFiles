#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menus.h"
#include "../movie.h"
void insert_movie_menu()
{
	Tmovie movie;
	size_t chars_counter = 0;
	char buffer[256];

	for (;;) {
		reset_terminal();
		printf("\t\tInserir Filmes\n"
		       "Preencha os campos abaixo\n");

		printf("\tTítulo em Português: ");
		scanf("%255[^\n]s", buffer);
		clear_input_buffer();
		movie.pt_title = malloc(sizeof(char) * strlen(buffer));
		strcpy(movie.pt_title, buffer);
		chars_counter += strlen(movie.pt_title);

		printf("\tTítulo Original: ");
		scanf("%255[^\n]s", buffer);
		clear_input_buffer();
		if (strcmp(movie.pt_title, buffer) == 0)
			sprintf(buffer, "Idem");
		movie.title = malloc(sizeof(char) * strlen(buffer));
		strcpy(movie.title, buffer);
		chars_counter += strlen(movie.title);

		printf("\tDiretor: ");
		scanf("%255[^\n]s", buffer);
		clear_input_buffer();
		movie.director = malloc(sizeof(char) * strlen(buffer));
		strcpy(movie.director, buffer);
		chars_counter += strlen(movie.director);

		for (;;) {
			printf("\tAno de Lançamento: ");
			scanf("%255[^\n]s", buffer);
			clear_input_buffer();
			if (strlen(buffer) != 4 || !strtol(buffer, NULL, 10)) {
				printf("Valores validos entre 1000 e 9999. Pressione Enter para continuar\n");
				clear_input_buffer();
				continue;
			}
			break;
		}

		strcpy(movie.release_year, buffer);

		printf("\tPaís: ");
		scanf("%255[^\n]s", buffer);
		clear_input_buffer();
		movie.country = malloc(sizeof(char) * strlen(buffer));
		strcpy(movie.country, buffer);
		chars_counter += strlen(movie.country);

		for (;;) {
			printf("\tNota: ");
			scanf("%255[^\n]s", buffer);
			clear_input_buffer();
			if (strlen(buffer) != 1 || buffer[0] < '0' ||
			    buffer[0] > '9') {
				printf("Valores validos entre 0 e 9. Pressione Enter para continuar\n");
				clear_input_buffer();
				continue;
			} else {
				movie.score = buffer[0];
			}
			break;
		}

		if (chars_counter > 175) {
			printf("Quantidade maxima de caracteres ultrapassada."
			       " Pressione Enter para tentar novamente.\n");
			clear_input_buffer();
			continue;
		}

		if (insert_movie(movie))
			printf("\tFilme inserido com sucesso. Inserir outro? (s/N) \nR: ");
		else
			printf("Não foi possivel inserir o filme. "
			       "Tentar novamente? (s/N)\nR: ");
		scanf("%255[^\n]s", buffer);
		clear_input_buffer();

		free(movie.pt_title);
		free(movie.title);
		free(movie.director);
		free(movie.country);

		if (strlen(buffer) == 1 && toupper(buffer[0]) == 'S')
			continue;
		break;
	}
}
