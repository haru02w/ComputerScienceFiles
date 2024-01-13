#include <ctype.h>
#include <stdio.h>
#include "menus.h"
#include "../movie.h"
#include <stdlib.h>

void change_score_menu()
{
	char id[6];
	char score;
	for (;;) {
		reset_terminal();
		printf("\t\tAlterar Nota\n");

		printf("Digite o codigo de identificação do filme: ");
		scanf("%5[^\n]s", id);
		clear_input_buffer();

		printf("Digite a nova nota: ");
		score = getchar();
		clear_input_buffer();

		if (!change_score(id, score))
			printf("Filme não encontrado. Tentar novamente? (s/N)\nR: ");
		else
			printf("Alterado com sucesso. Alterar outra nota? (s/N)\nR: ");
		int ch = getchar();
		clear_input_buffer();
		if (toupper(ch) == 'S')
			continue;
		break;
	}
}
