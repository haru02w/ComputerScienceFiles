#include <stdint.h>
#include <stdlib.h>
#include <curses.h>

#include "file_management/file_management.h"
#include "menus/menus.h"

int main(int argc, char *argv[])
{
	if (argc == 2)
		set_path(argv[1]);
	init_files();
	main_menu();
	end_files();
	return EXIT_SUCCESS;
}
