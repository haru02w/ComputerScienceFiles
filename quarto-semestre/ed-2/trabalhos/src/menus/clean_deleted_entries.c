#include "../movie.h"
#include "menus.h"
#include <stdio.h>
void clean_deleted_entries_menu()
{
	if (clean_deleted_entries())
		printf("Filmes removidos apagados com sucesso\n");
	else
		printf("Não foi possivel apagar os filmes removidos\n");
}
