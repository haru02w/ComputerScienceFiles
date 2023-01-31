#include "headers.h"
#include <stdio.h>

/* store: struct pra armazenamento.
 * current: quantidade de aulas dadas até o momento da inserção. */
void add_class(char filename[MAX_SIZE]) //comecei a implementar
{
	subject_t subject;
	FILE *fp = fopen(filename, "rb");
	fsubjectread(&subject, fp);
	fclose(fp);

	int cur_id = subject.given_class;
	float sum = 0;

	// Quantidade de aulas dadas * hora de cada aula.
	if (subject.given_class * subject.class_workload >=
	    subject.total_workload) {
		printf("Não é possível adicionar aula, limite de horas atingido!\n");
		return;
	}

	// Recebe o índice crescentemente (de 1 até N).
	subject.classes[cur_id].id = cur_id + 1;

	printf("Dia: ");
	scanf("%d", &subject.classes[cur_id].day);
	integer_detect_input_error(1, 30, &subject.classes[cur_id].day);

	printf("Mês: ");
	scanf("%d", &subject.classes[cur_id].month);
	integer_detect_input_error(1, 12, &subject.classes[cur_id].month);
	subject.classes[cur_id].year =
		subject.year; // recebe ano da disciplina.

	printf("Conteúdo do dia: ");
	scanf(" %[^\n]s", subject.classes[cur_id].content);

	printf("Houve atividade? (s/N): ");
	subject.classes[cur_id].control = check_yes_or_no(0);

	// Aplica presença para todos os alunos.
	for (int i = 0, aux; i < subject.student_amount; i++) {
		printf("%s estava presente? (S/n): ", subject.students[i].name);
		aux = check_yes_or_no(1);
		subject.students[i].presence_amount += aux;
	}

	for (int i = 0; i < cur_id; i++) {
		if (subject.classes[i].control)
			sum += subject.classes[i].activity.grade_perc;
	}

	// Se control == 1, houve atividade na aula.
	if (subject.classes[cur_id].control && sum < 100) {
		printf("Nome da atividade: ");
		scanf("%s", subject.classes[cur_id].activity.name);

		printf("Tipo da atividade ('P' para prova, 'T' para trabalho, 'E' para exame): ");
		scanf(" %c", &subject.classes[cur_id].activity.type);
		check_activity_input_error(
			&subject.classes[cur_id].activity.type,
			subject.test_did, subject.test_amount);

		printf("Peso da atividade: ");
		scanf("%f", &subject.classes[cur_id].activity.grade_perc);
		grade_perc_input_error(
			sum, &subject.classes[cur_id].activity.grade_perc);

		for (int i = 0; i < subject.student_amount; i++) {
			if (subject.classes[cur_id].activity.type !=
			    'E') { //calcular a media aq
				printf("Nota de %s: ",
				       subject.students[i].name);

				if (subject.classes[cur_id].activity.type ==
				    'P') {
					scanf("%f",
					      &subject.students[i].test_grade
						       [subject.test_did]);
					subject.students[i].average_grade +=
						(subject.students[i].test_grade
							 [subject.test_did] *
						 (subject.classes[cur_id]
							  .activity.grade_perc /
						  100));
				} else if (subject.classes[cur_id]
						   .activity.type == 'T') {
					scanf("%f",
					      &subject.students[i].test_grade
						       [subject.task_did]);
					subject.students[i].average_grade +=
						(subject.students[i].task_grade
							 [subject.task_did] *
						 (subject.classes[cur_id]
							  .activity.grade_perc /
						  100));
				}
			} else if (subject.classes[cur_id].activity.type ==
					   'E' &&
				   subject.task_did == subject.task_amount) {
				printf("Nota de %s: ",
				       subject.students[i].name);
				scanf("%f", &subject.students[i].exam_grade);
			}
		}

		// Atualiza quantidade de atividades aplicadas.
		switch (subject.classes[cur_id].activity.type) {
		case 'P':
			subject.test_did++;
			break;
		case 'T':
			subject.task_did++;
		}

		// Atualiza quantidade de aulas realizadas.
		subject.given_class++;

		fp = fopen(filename, "wb");
		fsubjectwrite(&subject, fp);
		fclose(fp);
		return;
	}
}

void show_class_attributes(char file_name[MAX_SIZE], int chosen_id)
{
	FILE *subject_file = fopen(file_name, "rb");
	subject_t temp;
	fsubjectread(&temp, subject_file);

	printf("Código: %d\n"
	       "Data: %d / %d / %d\n"
	       "Conteúdo: %s\n",
	       temp.classes[chosen_id].id, temp.classes[chosen_id].day,
	       temp.classes[chosen_id].month, temp.classes[chosen_id].year,
	       temp.classes[chosen_id].content);

	if (temp.classes[chosen_id].control) {
		printf("Essa aula possui uma avaliação.\n");
		show_activity_attribute(temp, chosen_id);
	}

	fclose(subject_file);
}

void show_activity_attribute(subject_t temp, int current_id)
{
	printf("Nome: %s\n", temp.classes[current_id].activity.name);
	printf("Tipo de atividade: ");

	switch (temp.classes[current_id].activity.type) {
	case 'P':
		puts("Prova");
		break;
	case 'T':
		puts("Trabalho");
		break;
	default:
		puts("Exame");
	}

	printf("Peso na média final: %.2f\n",
	       temp.classes[current_id].activity.grade_perc);
}
