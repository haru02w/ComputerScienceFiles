#include "headers.h"
#include <stdio.h>
int main(int argc, char *argv[])
{
	verify_user();
	FILE *storage_p = fopen(STORAGE_FILE, "rb");

	if (storage_p == NULL)
		storage_p = fopen(STORAGE_FILE, "wb");
	fclose(storage_p);

	menu_subjects();
	return 0;
}

void integer_detect_input_error(int begin, int end, int *target)
{
	while (*target < begin || *target > end) {
		printf("Valor inválido, digite outro: ");
		scanf("%d", target);
	}
}

void floating_detect_input_error(int begin, int end, float *target)
{
	while (*target < begin || *target > end) {
		printf("Valor inválido, digite outro: ");
		scanf("%f", target);
	}
}

// Verifica se a letra digitada é inválida ou se o usuário quer aplicar exame sem ter concluído as provas.
void check_activity_input_error(char *target, int test_concluded,
				int test_amount)
{
	while ((*target != 'P' && *target != 'T' && *target != 'E') ||
	       (*target == 'E' && test_concluded < test_amount)) {
		printf("Dado inválido! Digite novamente: ");
		scanf(" %c", target);
	}
}

void grade_perc_input_error(int current_perc, float *target)
{
	while (*target < 0 || *target > 100 || *target + current_perc > 100) {
		printf("Valor inválido! Digite outro: ");
		scanf("%f", target);
	}
}
int check_yes_or_no(int def)
{
	char target;
	scanf(" %c", &target);
	switch (target) {
	case 'S':
	case 's':
		return 1;
	case 'n':
	case 'N':
		return 0;

	default:
		if (def != 0)
			return 1;
		else
			return 0;
	}
}
