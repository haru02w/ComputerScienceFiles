#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void gera_12x4(int qtd_mensal[][4])
{
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 4; j++) {
			qtd_mensal[i][j] = rand() % 100;
		}
	}
}
void gera_4x2(int custo_lucro[][2])
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			custo_lucro[i][j] = rand() % 100;
		}
	}
}

int main(int argc, char *argv[])
{
	int qtd_mensal[12][4], custo_lucro[4][2];
	int total_ano = 0, lucro_ano = 0, custo_ano = 0;
	//gera valores do ano todo
	srand(time(NULL));
	gera_12x4(qtd_mensal);
	//printa os valores
	for (int i = 0, total_mes = 0, custo_mes = 0, lucro_mes = 0; i < 12;
	     i++, total_mes = 0, total_mes = 0, custo_mes = 0, lucro_mes = 0) {
		//gera os valores de cada produto, pra cada mes
		gera_4x2(custo_lucro);

		for (int j = 0; j < 4; j++) {
			total_mes += qtd_mensal[i][j];
			custo_mes += custo_lucro[j][0];
			lucro_mes += custo_lucro[j][1];
		}
		custo_ano += custo_mes;
		lucro_ano += lucro_mes;
		printf("A quantidade total de produtos fabricados no mês %d é: %d\n"
		       "O custo total no mês %d é: %d\n"
		       "O lucro total no mês %d é: %d\n",
		       i + 1, total_mes, i + 1, custo_mes, i + 1, lucro_mes);
		total_ano += total_mes;
	}
	printf("A quantidade total no ano fabricada de cada produto é: %d\n"
	       "O custo total no ano é: %d\n"
	       "O lucro total no ano é: %d\n",
	       total_ano, custo_ano, lucro_ano);
	return 0;
}
