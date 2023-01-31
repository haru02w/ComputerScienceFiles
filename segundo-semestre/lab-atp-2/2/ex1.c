#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int numero, nota1, nota2;
	char nome[40], curso[40];
} alunos_t;
int main(int argc, char *argv[])
{
	int op, num, stop;
	unsigned locate;
	alunos_t aluno;
	FILE *pfile = fopen("ALUNOS.DAT", "w");
	fclose(pfile);
	for (;;) {
		stop = 0;
		printf("Para escrever digite 1, para editar digite 2: ");
		scanf("%d", &op);

		if (op == 1) {
			pfile = fopen("ALUNOS.DAT", "a+");
			printf("Digite:\n");
			printf("Numero: ");
			scanf("%d", &aluno.numero);

			locate = ftell(pfile);

			fseek(pfile, 0, SEEK_SET);

			while (fscanf(pfile, "%d", &num) != EOF && !stop) {
				if (num == aluno.numero) {
					printf("Aluno já existe\n");
					stop = 1;
				}
			}
			if (stop)
				continue;

			fseek(pfile, locate, SEEK_SET);

			printf("Nome: ");
			scanf("%s", aluno.nome);
			printf("Curso: ");
			scanf("%s", aluno.curso);
			printf("Nota1: ");
			scanf("%d", &aluno.nota1);
			printf("Nota2: ");
			scanf("%d", &aluno.nota2);
			fprintf(pfile, "%d %s %s %d %d\n", aluno.numero,
				aluno.nome, aluno.curso, aluno.nota1,
				aluno.nota2);
			fclose(pfile);
		} else if (op == 2) {
			pfile = fopen("ALUNOS.DAT", "r+");
			printf("Numero do aluno pra alterar: ");
			scanf("%d", &num);
			do {
				locate = ftell(pfile);
				fscanf(pfile, "%d %s %s %d %d\n", &aluno.numero,
				       aluno.nome, aluno.curso, &aluno.nota1,
				       &aluno.nota2);
				if (num == aluno.numero) {
					stop = 1;
					break;
				}

			} while (!feof(pfile) && !stop);
			if (!stop) {
				printf("Aluno não existe");
				fclose(pfile);
				continue;
			}

			printf("Numero atual: %d\nAlterar para: ",
			       aluno.numero);
			scanf("%d", &aluno.numero);

			fseek(pfile, 0, SEEK_SET);

			do {
				fscanf(pfile, "%d", &num);
				if (num == aluno.numero) {
					printf("Aluno já existe\n");
					stop = 1;
				}

			} while (!feof(pfile) && !stop);
			if (stop) {
				fclose(pfile);
				continue;
			}

			fseek(pfile, locate, SEEK_SET);

			printf("Nome atual: %s\nAlterar para: ", aluno.nome);
			scanf("%s", aluno.nome);
			printf("Curso atual: %s\nAlterar para: ", aluno.curso);
			scanf("%s", aluno.curso);
			printf("Nota1 atual: %d\nAlterar para: ", aluno.nota1);
			scanf("%d", &aluno.nota1);
			printf("Nota2 atual: %d\nAlterar para: ", aluno.nota2);
			scanf("%d", &aluno.nota2);
			fclose(pfile);
		} else {
			printf("Operação invalida. Fechando...");
			return 0;
		}
	}
	return 0;
}
