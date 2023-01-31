#include "headers.h"
#include <stdio.h>

void menu_subjects()
{
	int i, useropt;
	files_t storage_subjects;
	FILE *fstorage_p, *fsubject_p;
	subject_t subject;

start:
	fstorage_p = fopen(STORAGE_FILE, "rb");
	printf("\e[1;1H\e[2J"); // limpa o terminal.
	printf("======== Menu Materias ========\n");
	printf("0) Sair do programa\n1) Adicionar diciplina\n");
	for (i = 2;
	     fread(&storage_subjects, sizeof(files_t), 1, fstorage_p) == 1;
	     i++) {
		fsubject_p = fopen(storage_subjects.name, "rb");
		if (fsubject_p == NULL)
			continue;

		//trava se n existe
		if (!fsubjectread(&subject, fsubject_p)) {
			fclose(fsubject_p);
			continue;
		}

		printf("%d) Semestre %d de %d, %s\n", i, subject.semester,
		       subject.year, subject.name);
		fclose(fsubject_p);
	}
	rewind(fstorage_p);

	printf("R: ");
	scanf("%d", &useropt);

	if (useropt == 0) {
		fclose(fstorage_p);
		return;
	}
	if (useropt == 1) {
		add_subject();
		goto end;
	}

	while (useropt >= 2 &&
	       fread(&storage_subjects, sizeof(files_t), 1, fstorage_p) == 1)
		useropt--;

	menu_subject_options(storage_subjects.name);

end:
	fclose(fstorage_p);
	goto start;
}
void menu_subject_options(char filename[MAX_SIZE])
{
	int useropt;
	for (;;) {
		printf("\e[1;1H\e[2J"); // limpa o terminal.
		printf("======== Opções Materia ========\n");
		printf("0) Voltar\n"
		       "1) Aulas\n"
		       "2) Alunos\n"
		       "3) Editar materia\n"
		       "4) Mostrar caracteristicas da materia\n"
		       "R: ");
		scanf("%d", &useropt);
		switch (useropt) {
		case 0:
			return;
		case 1:
			menu_class(filename);
			break;
		case 2:
			// menu_students();
			break;
		case 3:
			if (edit_subject(filename))
				return;
			break;
		case 4:
			show_subject_attributes(filename);
			break;
		default:
			printf("Opção invalida, tente novamente.\n");
		}
	}
}

void menu_class(char filename[MAX_SIZE])
{
	int useropt;
	subject_t subject;
	for (;;) {
		FILE *fp = fopen(filename, "rb");
		fsubjectread(&subject, fp);
		fclose(fp);
		printf("\e[1;1H\e[2J"); // limpa o terminal.
		printf("======== Opções Aulas ========\n");
		printf("0) Voltar\n"
		       "1) Adicionar aulas\n");
		for (int i = 0; i < subject.given_class; i++) {
			printf("%d) Aula %d/%d/%d, %s\n", i + 2,
			       subject.classes[i].day, subject.classes[i].month,
			       subject.classes[i].year,
			       (subject.classes[i].control ?
					(subject.classes[i].activity.type ==
							 'P' ?
						 "Prova" :
						 (subject.classes[i].activity
									  .type ==
								  'E' ?
							  "Exame" :
							  "Trabalho")) :
					" "));
		}
		printf("R: ");
		scanf("%d", &useropt);

		if (useropt == 0)
			return;
		else if (useropt == 1)
			add_class(filename);
		else if (useropt > subject.given_class || useropt < 2)
			printf("Opção invalida. Tente novamente");
		else
			menu_class_options(filename, useropt - 1);
	}
}
void menu_class_options(char filename[MAX_SIZE], int id)
{
	int useropt;
	for (;;) {
		printf("\e[1;1H\e[2J"); // limpa o terminal.
		printf("======== Opções Aula ========\n");
		printf("0) Voltar\n"
		       "1) Editar aula\n"
		       "2) Mostrar caracteristicas da aula\n"
		       "R: ");
		scanf("%d", &useropt);
		switch (useropt) {
		case 0:
			return;
		case 1:
			// if (edit_class(filename,id))
			// 	return;
			break;
		case 2:
			show_class_attributes(filename, id);
			break;
		default:
			printf("Opção invalida, tente novamente.\n");
		}
	}
}

void verify_user()
{
	user_t user;
	FILE *user_p = fopen("user.dat", "rb");

	printf("\e[1;1H\e[2J"); // limpa o terminal.
	if (user_p == NULL) {
		printf("======== Bem Vindo! ========\n");
		printf("Atenção! Usuário inexistente, realize seu cadastro!\nDigite seu nome de usuário: ");
		scanf("%s", user.name);

		user_p = fopen("user.dat", "wb");
		fwrite(&user, sizeof(user_t), 1, user_p);
	} else {
		fread(&user, sizeof(user_t), 1, user_p);
		printf("====|Bem Vindo, %s!|====\n", user.name);
		printf("Pressione Enter para continuar...\n");
		getchar();
	}
	printf("\n\n");

	fclose(user_p);
}
