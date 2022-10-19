#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
typedef struct planetas {
	char nome[21];
	double peso;
	struct {
		double x, y, z;
	} cords;
} planetas_t;

void input(planetas_t *planetas, int qtd)
{
	int i;
	for (i = 0; i < qtd; i++) {
		scanf(" %s %lf %lf %lf %lf", planetas[i].nome,
		      &planetas[i].peso, &planetas[i].cords.x,
		      &planetas[i].cords.y, &planetas[i].cords.z);
	}
}
double distancia(planetas_t *planetas, int sres1, int sres2)
{
	double x1, y1, z1, x2, y2, z2;
	x1 = planetas[sres1].cords.x;
	y1 = planetas[sres1].cords.y;
	z1 = planetas[sres1].cords.z;
	x2 = planetas[sres2].cords.x;
	y2 = planetas[sres2].cords.y;
	z2 = planetas[sres2].cords.z;

	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) +
		    (z2 - z1) * (z2 - z1));
}
int search(planetas_t *planetas, char *tmp)
{
	int i = 0;
	while (strcmp(planetas[i].nome, tmp))
		i++;
	return i;
}
void output(planetas_t *planetas, int info)
{
	int i, op, sres1, sres2;
	char tmp[2][20];
	for (i = 0; i < info; i++) {
		scanf("%d ", &op);
		switch (op) {
		case 1: //calcula distancia
			scanf(" %s %s", tmp[0], tmp[1]);
			sres1 = search(planetas, tmp[0]);
			sres2 = search(planetas, tmp[1]);
			printf("%.2lf\n", distancia(planetas, sres1, sres2));
			break;
		case 2: //mostrar coordenadas
			scanf(" %s", tmp[0]);
			sres1 = search(planetas, tmp[0]);
			printf("%.0lf %.0lf %.0lf\n", planetas[sres1].cords.x,
			       planetas[sres1].cords.y,
			       planetas[sres1].cords.z);
			break;
		case 3: //mostrar peso
			scanf(" %s", tmp[0]);
			sres1 = search(planetas, tmp[0]);
			printf("%.2lf\n", planetas[sres1].peso);
		}
	}
}

int main(int argc, char *argv[])
{
	int qtd, info;
	planetas_t *planetas;
	char tmp[2][20];
	scanf("%d %d", &qtd, &info);
	planetas = malloc(qtd * sizeof(planetas_t));
	input(planetas, qtd);
	output(planetas, info);
	free(planetas);
	return 0;
}
