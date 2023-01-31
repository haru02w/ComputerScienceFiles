#include <stdio.h>
int main(int argc, char *argv[])
{
	int votos[6] = { 0 }, voto, total = 0, maior = 0, ind_vencedor = -1;
	for (;;) {
		scanf("%d", &voto);
		if (voto >= 1 && voto <= 6) {
			votos[voto - 1]++;
			total++;
		} else
			break;
	}
	for (int i = 0; i < 6; i++) {
		float tmp = (float)votos[i] * 100 / total;
		if (i == 5)
			printf("Total de votos nulos %d, %f%%\n", votos[i],
			       tmp);
		else if (i == 6)
			printf("Total de votos brancos %d, %.0f%%\n", votos[i],
			       tmp);
		else {
			if (maior < votos[i]) {
				maior = votos[i];
				ind_vencedor = i;
			}
			printf("Total de votos do candidato %d: %d, %0.f%%\n",
			       i + 1, votos[i], tmp);
		};
	}
	printf("O candidato vencedor é %d\n", ind_vencedor + 1);

	return 0;
}
