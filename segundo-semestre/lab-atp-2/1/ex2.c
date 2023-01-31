#include <stdio.h>
typedef struct {
	int num_inscricao, idade, sexo, anos_exp;
} pessoa_t;
int main(int argc, char *argv[])
{
	pessoa_t pessoa;
	int idademedia = 0, totalhomens = 0, totalhomensEXP = 0,
	    homens45plus = 0, mulheres35lessEXP = 0, total = 0;
	char stop = 1;
	while (stop) {
		printf("Numero de inscrição do candidato: ");
		scanf("%d", &pessoa.num_inscricao);

		printf("Idade: ");
		scanf("%d", &pessoa.idade);

		printf("sexo (1-masculino, 2-feminino): ");
		scanf("%d", &pessoa.sexo);

		printf("Anos de experiência de serviço: ");
		scanf("%d", &pessoa.anos_exp);

		total++;

		if (pessoa.sexo == 1) {
			totalhomens++;
			if (pessoa.anos_exp > 2) {
				idademedia += pessoa.idade;
				totalhomensEXP++;
			}
			if (pessoa.idade > 45)
				homens45plus++;
		} else {
			if (pessoa.idade < 35 && pessoa.anos_exp > 0)
				mulheres35lessEXP++;
		}

		printf("Deseja continuar? (S - sim,N - não): ");
		scanf(" %c", &stop);
		if (stop == 'N' || stop == 'n')
			stop = 0;
	}
	printf("A media dos homens com mais de 2 anos de experiência no serviço: %d\n"
	       "A porcentagem dos homens com mais de 45 anos entre o total de homens: %d%%\n"
	       "Número de mulheres que têm idade inferior a 35 anos e com experiência no serviço: %d\n",
	       idademedia / totalhomensEXP, homens45plus * 100 / totalhomens,
	       mulheres35lessEXP);
	return 0;
}
