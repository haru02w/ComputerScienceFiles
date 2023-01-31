#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_SIZE 51
#define STORAGE_FILE "storage.dat"

typedef struct {
	char name[MAX_SIZE];
} user_t;
typedef user_t files_t;

//struct aluno
typedef struct {
	char name[MAX_SIZE]; // Livre.
	int id, presence_amount; // Entre 1 e 50.
	float test_grade[3]; // Entre 0 e 10.
	float task_grade[10]; // Entre 0 e 10.
	float exam_grade; // Entre 0 e 10.
	float average_grade; // Média do aluno.
	int approve; // 1 aprovado, 0 reprovado
} student_t;

typedef struct {
	char name[MAX_SIZE]; // Livre
	char type; // 'P', 'T' ou 'E'.
	float grade_perc; // Entre 0 e 100%.
} activity_t;

//struct aula
typedef struct {
	int id; // Começando em 1.
	int day, month, year; // Data da aula (ano igual ao da disciplina).
	char content[255]; // Livre.
	int control; // Se teve prova (1) ou não (0)
	activity_t activity; //	Se a aula tiver prova, diferente de NULL.
} class_t;

//struct disciplina
typedef struct {
	int id; // Livre.
	char name[MAX_SIZE]; // Livre.
	int semester, semester_status, year; // 1 ou 2 | entre 2013 e 2030.
	int student_amount, test_amount, task_amount; // Máximos: 50 | 4 | 10.
	int task_did,
		test_did; // Para controle de indice. (quando acontece alguma avaliação, ++, até atingir o max da disciplina).
	int total_workload, class_workload; // Livre.
	float minimal_grade, minimal_freq; // Intervalos: [0,10] e [0, 100%].
	int class_amount;
	int given_class; //brunao q fez

	student_t *students;
	class_t *classes;

} subject_t;

// =====|Protótipos|=====

//inicio
void verify_user();

void add_students(subject_t *subject);

void integer_detect_input_error(int, int, int *);
void floating_detect_input_error(int, int, float *);
int check_yes_or_no(int def);

//menus
void menu_subjects();
void menu_subject_options(char filename[MAX_SIZE]);
void menu_class(char filename[MAX_SIZE]);
void menu_class_options(char filename[MAX_SIZE], int id);

//subject.c
void fsubjectwrite(subject_t *subject, FILE *fp);
int fsubjectread(subject_t *subject, FILE *fp);
void add_subject();
void show_subject_attributes(char filename[MAX_SIZE]);
int edit_subject(char filename[MAX_SIZE]);
void delete_subject(char filename[MAX_SIZE]);

//class.c
void show_class_attributes(char file_name[MAX_SIZE], int chosen_id);
void show_activity_attribute(subject_t temp, int current_id);
void add_class(char file_name[MAX_SIZE]);
void check_activity_input_error(char *, int, int);
void grade_perc_input_error(int, float *);
