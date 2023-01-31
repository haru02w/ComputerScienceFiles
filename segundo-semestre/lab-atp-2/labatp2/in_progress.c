#include "src/headers.h"
//IMPLEMENTEM NESSE ARQUIVO SOMENTE FUNÇÕES Q N EXISTEM NOS ARQUIVOS DA PASTA "src"

//FAÇAM O PROTOTIPO AQUI SOMENTE DE FUNÇÕES Q N TEM PROTOTIPO NA HEADERS.H
void add_class(subject_t *);
void add_activity(subject_t *);

//função que le o ttipo de atividade que foi feita (WIP)
// void add_activity(subject_t *temp_subject){
  
// }

/* store: struct pra armazenamento.
 * current: quantidade de aulas dadas até o momento da inserção. */
void add_class(char file_name[MAX_SIZE])
{
	subject_t store;
	int i, aux, cur_id = store.given_class;

	// Quantidade de aulas dadas * hora de cada aula.
	if(store.given_class * store.class_workload == store.total_workload) {
		printf("Não é possível adicionar aula, limite de horas atingido!\n");
		return;
	}

	// Recebe o índice crescentemente (de 1 até N).
	store.classes[cur_id].id = cur_id + 1;

	printf("Dia: ");
	scanf("%d", &store.classes[cur_id].day);
	integer_detect_input_error(1, 30, &store.classes[cur_id].day);
	
	printf("Mês: ");
	scanf("%d", &store.classes[cur_id].month);
	integer_detect_input_error(1, 12, &store.classes[current].month);
	store.classes[cur_id].year = store.year; // recebe ano da disciplina.
	
	printf("Conteúdo do dia: ");
	scanf(" %[^\n]s", store.classes[cur_id].content);
	
	printf("Houve atividade? (0 ou 1): ");
	scanf("%d", &store.classes[cur_id].control);
        integer_detect_input_error(0, 1, &store.classes[cur_id].control);

	// Aplica presença para todos os alunos.
	for(i = 0; i < store.student_amount; i++) {
		printf("%s estava presente? (0 ou 1): ", store.students[i].name);
		scanf("%d", &aux);
		integer_detect_input_error(0, 1, &aux);
		store.students[i].presence_amount += aux;
	}

	// Se control == 1, houve atividade na aula.
	if(store.classes[cur_id].control) {
		printf("Nome da atividade: ");
		scanf("%s", store.classes[cur_id].activity.name);
		printf("Tipo da atividade ('P' para prova, 'T' para trabalho, 'E' para exame): ");
		scanf(" %c", &store.classes[cur_id].activity.type);
		printf("Peso da atividade: ");
		scanf("%f", &store.classes[cur_id].activity.grade_perc);
		for(i = 0; i < store.student_amount; i++) {
			if(store.classes[cur_id].activity.type != 'E') {
				printf("Nota de %s: ", store.students[i].name);
			        if(store.classes[cur_id].activity.type == 'P')
				        scanf("%f", &store.students[i].test_grade[store.test_did]);
			        else if(store.classes[cur_id].activity.type == 'T')
				        scanf("%f", &store.students[i].test_grade[store.task_did]);
				calculate_average_grade(file_name);
			}
			else if(store.classes[cur_id].activity.type == 'E' && store.task_did == store.task_amount) {
				printf("Nota de %s: ", store.students[i].name);
				scanf("%f", &store.students[i].exam_grade);
			}
		}

		// Atualiza quantidade de atividades aplicadas.
		switch(store.classes[cur_id].activity.type) {
			case 'P': store.test_did++; break;
			case 'T': store.task_did++;
		}
	}

	// Atualiza quantidade de aulas realizadas.
	store.given_class++;
}

void show_class_attributes(subject_t temp, int chosen_id)
{
	printf("Código: %d\n"
	       "Data: %d / %d / %d\n"
	       "Conteúdo: %s\n"
	       temp.classes[chosen_id].id, temp.classes[chosen_id].day, 
	       temp.classes[chosen_id].month, temp.classes[chosen_id].year, 
	       temp.classes[chosen_id].content);

	if(temp.classes[chosen_id].control) {
		printf("Essa aula possui uma avaliação.\n");
		show_activity_attribute(temp, chosen_id);
	}
}

void show_activity_attribute(subject_t temp, int current_id)
{
	printf("Nome: %s\n", temp.classes[current_id].activity.name);
	printf("Tipo de atividade: ");
	
	switch(temp.classes[current_id].activity.type) {
		case 'P': puts("Prova"); break;
		case 'T': puts("Trabalho"); break;
		default: puts("Exame");
	}

	printf("Peso na média final: %.2f\n", temp.classes[current_id].activity.grade_perc);
}

void show_all_activity_grade(subject_t temp)
{
	int i, j;

	for(i = 0; i < temp.student_amount; i++) {
		printf("===| %s |===\n", temp.students[i].name);
		printf("Provas: ");
		for(j = 0; j < temp.test_amount; j++)
			printf("%d) %.2f ", j+1, temp.students[i].test_grade[j]);
		printf("\nTrabalhos: ");
		for(j = 0; j < temp.task_amount; j++)
			printf("%d) %.2f ", j+1, temp.students[i].task_grade[j]);
	}
}

//função que mostra as informações dos alunos
void show_student_info(char file_name[]){
  FILE *subject_file = fopen(file_name, "rb");
  int i, j, op, control = 0;
  subject_t subject;
  fsubjectread(&subject, subject_file);
  fclose(subject_file);

  menu_alun:
  printf("%d alunos estão rregistrados nessa matéria, informe sobre qual aluno a informação deve ser mostrada:\n 1) voltar.\n", subject.student_amount);
  if(control == 0) printf(" 2) anterior (indisponivel)\n");
  else printf(" 2) anterior.\n");
  if(control + 5 > subject.student_amount) printf(" 3) proximo (indisponivel).\n");
  else printf(" 3) proximo.\n");
  i=0;
  while(i<5 && control + i < subject.student_amount){
    printf(" %d) ID: %d, NOME: %s.\n", i+3, subject.students[control+i].id, subject.students[control+i].name);
    i++;
  }
  scanf("%d", &op);
  switch(op){
    case 1: return;
    case 2:{
      if(control == 0) printf("opção indisponivel\n");
      else control -= 5;
      goto menu_alun;
    }
    case 3:{
      if(control + 5 > subject.student_amount) printf("opção indisponivel\n");
      else control += 5;
      goto menu_alun;
    }
    case 4 ... 8:{ 
      printf("ID: %d, NOME: %s \n Presenças: %d/%d - %d%%\n Média: %.2f \n ", subject.students[control + (op - 4)].id, subject.students[control + (op - 4)].name, subject.students[control + (op - 4)].presence_amount, subject.class_amount, (subject.students[control + (op - 4)].presence_amount * 100) / subject.class_amount, subject.students[control + (op - 4)].average_grade);
      printf("Deseja ver as informações de mais alguem? S/N\n");
      scanf("%d", &op);
      if(op == 'S' || op == 's') goto menu_alun;
      else return;
    } 
    default: printf("Opção invalida!"); goto menu_alun;
  }
}

// Calcula a média final de cada aluno.
void calculate_average_grade(char file_name[MAX_SIZE])
{
	FILE *storage_pointer = fopen(file_name, "rb");
	subject_t subject;
	int i, j;
	fsubjectread(&subject, storage_pointer);
	fclose(storage_pointer);

	for(i = 0; i < subject.student_amount; i++) {
		for(j = 0; j < subject.test_amount; j++)
			subject.students[i].average_grade += subject.students[i].test_grade[j];
		for(j = 0; j < subject.task_amount; j++)
			subject.students[i].average_grade += subject.students[i].task_grade[j];
	}

	storage_pointer = fopen(file_name, "wb");
	fsubjectwrite(&subject, storage_pointer);
	fclose(storage_pointer);
}

//função que verifica se oi aluno foi aprovado ou não
void verify_approval(char file_name[]){
  int i;
  FILE *subject_file = fopen(file_name, "rb");
  subject_t subject;
  fsubjectread(&subject, subject_file);
  fclose(subject_file);

  for(i=0; i< subject.student_amount; i++){
    if(subject.students[i].average_grade > subject.minimal_grade && (100 * subject.students[i].presence_amount)/subject.class_amount > subject.minimal_freq)
      subject.students[i].approve = 1;
    else subject.students[i].approve = 0;
  }
  subject_file = fopen(file_name, "wb");
  fsubjectwrite(&subject, subject_file);
  fclose(subject_file);
  
}