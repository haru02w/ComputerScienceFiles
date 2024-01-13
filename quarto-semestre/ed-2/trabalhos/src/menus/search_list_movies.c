#include "../movie.h"
#include "menus.h"
#include "../file_management/file_globals.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void search_by_id_menu()
{
	char input_id[6];
	for (;;) {
		reset_terminal();
		printf("\t\tBuscar Filmes por codigo\n");
		printf("Digite o codigo do filme a buscar: ");
		scanf("%5[^\n]s", input_id);
		clear_input_buffer();

		char *out = search_by_id(input_id);
		if (out != NULL) {
			char *arr[7];
			char *rest = out;
			char *token;

			for (int i = 0;
			     (token = strtok_r(rest, "@", &rest)) && i < 7; i++)
				arr[i] = token;

			printf("\nCodigo: %s\n"
			       "Titulo em Português: %s\n"
			       "Titulo Original: %s\n"
			       "Diretor: %s\n"
			       "Ano de lançamento: %s\n"
			       "País: %s\n"
			       "Nota: %s\n",
			       arr[0], arr[1], arr[2], arr[3], arr[4], arr[5],
			       arr[6]);
		} else
			printf("Não foi possivel encontrar o registro solicitado\n");

		printf("Pressione Enter para continuar\n");
		clear_input_buffer();

		break;
	}
}

void search_by_title_menu()
{
	char input_title[256];
	for (;;) {
		reset_terminal();
		printf("\t\tBuscar Filmes por Titulo\n");
		printf("Digite o título do filme a buscar: ");
		scanf("%255[^\n]s", input_title);
		clear_input_buffer();

		int arr_length;
		char **out = search_by_title(input_title, &arr_length);
		if (out != NULL) {
			for (int i = 0; i < arr_length; i++) {
				char *arr[7];
				char *rest = out[i];
				char *token;

				for (int j = 0;
				     (token = strtok_r(rest, "@", &rest)) &&
				     j < 7;
				     j++)
					arr[j] = token;

				printf("\nCodigo: %s\n"
				       "Titulo em Português: %s\n"
				       "Titulo Original: %s\n"
				       "Diretor: %s\n"
				       "Ano de lançamento: %s\n"
				       "País: %s\n"
				       "Nota: %s\n",
				       arr[0], arr[1], arr[2], arr[3], arr[4],
				       arr[5], arr[6]);
			}
			for (int i = 0; i < arr_length; i++)
				free(out[i]);
			free(out);
		} else
			printf("Não foi possivel encontrar o registro solicitado\n");

		printf("Pressione Enter para continuar\n");
		clear_input_buffer();

		break;
	}
}

void list_movies_menu()
{
	if (Giprimary_bptree->root_offset == -1) {
		printf("Não há nenhum filme salvo. Pressione enter para continuar\n");
		clear_input_buffer();
		return;
	}
	char *out;
	int i = 0;
	bp_node temp;
	ibp_node_read(&temp, Giprimary_bptree, Giprimary_bptree->root_offset);
	while ((out = search_next(&temp, &i)) != NULL) {
		char *arr[7];
		char *rest = out;
		char *token;
		for (int j = 0; (token = strtok_r(rest, "@", &rest)) && j < 7;
		     j++)
			arr[j] = token;

		printf("\nCodigo: %s\n"
		       "Titulo em Português: %s\n"
		       "Titulo Original: %s\n"
		       "Diretor: %s\n"
		       "Ano de lançamento: %s\n"
		       "País: %s\n"
		       "Nota: %s\n",
		       arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6]);

		printf("Pressione Enter mostrar proximo filme\n");
		clear_input_buffer();
	}
	printf("Todos os filmes cadastrados foram listados. "
	       "Pressione Enter para continuar\n");
	clear_input_buffer();
}
