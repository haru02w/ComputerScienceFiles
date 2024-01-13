#include <stdio.h>
#include <string.h>
#include "./menus.h"

static void inner_menu_redirection(int highlight)
{
	if (highlight < 0 || highlight > 6)
		return;
	void (*const functions[])() = {
		insert_movie_menu,	    remove_movie_menu,
		change_score_menu,	    search_by_id_menu,
		search_by_title_menu,	    list_movies_menu,
		clean_deleted_entries_menu,
	};
	functions[highlight]();
}

void main_menu()
{
	for (;;) {
		reset_terminal();

		// header
		printf("\t\tMenu Principal\n"
		       "Selecione uma das opções a seguir:\n");

		// options
		printf("\t1) Inserir novo filme\n"
		       "\t2) Remover um filme\n"
		       "\t3) Alterar nota do filme pela chave\n"
		       "\t4) Buscar filmes pela chave\n"
		       "\t5) Buscar filmes pelo título\n"
		       "\t6) Listar todos os filmes\n"
		       "\t7) Deletar todos os filmes removidos\n"
		       "\t0) Sair\n"
		       "R: ");

		int ch = getchar();
		clear_input_buffer();

		switch (ch) {
		case '1' ... '7':
			inner_menu_redirection(ch - '1');
			break;

		case '0':
			return;
		}
	}
}
