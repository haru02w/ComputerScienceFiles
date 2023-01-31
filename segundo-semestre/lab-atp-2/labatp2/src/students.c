#include "headers.h"
void add_students(subject_t *subject)
{
	subject->students = calloc(subject->student_amount, sizeof(student_t));
	printf("\e[1;1H\e[2J"); // limpa o terminal.
	printf("======== Adicionar Estudantes ========\n");
	printf("Informe caracteristicas dos alunos: \n");
	for (int i = 0; i < subject->student_amount; i++) {
		printf("----Aluno %d----\n", i + 1);
		printf("Número: ");
		scanf("%d", &subject->students[i].id);
		integer_detect_input_error(1, 50, &subject->students->id);
		printf("Nome: ");
		scanf("%s", subject->students[i].name);

		//zera as notas inicialmente
		for (int j = 0; j < 3; j++)
			subject->students[i].test_grade[j] = 0;

		//zera os trabalhos inicialmente
		for (int j = 0; j < 10; j++)
			subject->students[i].task_grade[j] = 0;
	}
}
