#include <ctype.h>
#include <stdio.h>
#include "../movie.h"
#include "menus.h"
void remove_movie_menu()
{
	char input_id[6];
	for (;;) {
		reset_terminal();
		printf("\t\tRemover filmes\n");
		printf("Digite o codigo do filme a remover: ");
		scanf("%5[^\n]s", input_id);
		clear_input_buffer();

		printf("Tem certeza que deseja remover o filme %s? (s/N)\nR: ",
		       input_id);
		int ch = getchar();
		clear_input_buffer();
		if (toupper(ch) == 'S' && remove_movie(input_id))
			printf("Filme removido com sucesso. "
			       "Remover outro filme? (s/N)\nR: ");
		else
			printf("Filme não removido."
			       " Tentar novamente? (s/N)\nR: ");
		ch = getchar();
		clear_input_buffer();
		if (toupper(ch) == 'S')
			continue;
		break;
	}
}
