#ifndef MENUS_H
#define MENUS_H
#include "../file_management/bplus.h"
/* utils */
void reset_terminal();
void clear_input_buffer();

/* menus */
void main_menu();
void insert_movie_menu();
void change_score_menu();
void remove_movie_menu();
void search_by_id_menu();
void search_by_title_menu();
void list_movies_menu();
void clean_deleted_entries_menu();

#endif /* end of include guard: MENUS_H */
