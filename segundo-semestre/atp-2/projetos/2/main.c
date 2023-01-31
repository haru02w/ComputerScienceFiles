#include <stdlib.h>
#include <stdio.h>

/*
* Estrutura estilo lista duplamente encadeada
*/
typedef struct list {
	int num;
	struct list *next;
	struct list *prev;
} list_t;

//         Declação das funções utilizadas

//codigo da recursão
void find_combinations(int *set, int start, int num, int max);
//salva o conjunto achado
void save(list_t **head, list_t **tail);
//coloca um numero na lista
void append(list_t **head, list_t **tail, int num);
//retira o ultimo numero da lista
void pop(list_t **head, list_t **tail);
// utilizarei pra explicar o funcionamento presencialmente.
// somente mostra os elementos da lista temporaria
void debug(list_t **head);

//daclara a lista definitiva (a com maior quantidade de elementos, com os maiores elementos)
list_t *defhead = NULL, *deftail = NULL;

// runs - quantidade de vezes que o algoritmo encontrou um conjunto
// tmpsize - tamanho do vetor temporario
// defsize - tamanho do vetor definitivo
int runs, tmpsize, defsize;
int main(int argc, char *argv[])
{
	//setsize - quantidade de numeros do conjunto
	//numbersize - quantidade de numeros para ser formado
	int setsize, numbersize;

	//set - vetor do conjunto
	//number - o numero atual a ser computado
	int *set, number;
	scanf("%d %d", &numbersize, &setsize);

	//alocação do conjunto.
	set = malloc(setsize * sizeof(int));

	//entrada do conjunto (vetor).
	for (int i = 0; i < setsize; i++)
		scanf("%d", &set[i]);

	for (int i = 0; i < numbersize; i++) {
		scanf("%d", &number);
		//zera as variaveis para cada entrada.
		runs = 0;
		defsize = 0;
		tmpsize = 0;
		//cria a lista definitiva.
		find_combinations(set, 0, number, setsize);
		//se o programa encontrar algum conjunto,
		if (runs)
			//mostra quantos conjuntos encontrou,
			printf("%d ", runs);
		else //senão,
			//mostra 0.
			printf("0");
		//anda por todos os elementos da lista definitiva
		for (list_t *tmp = defhead; tmp != NULL; tmp = tmp->next) {
			//mostrando os numeros.
			printf("%d ", tmp->num);
		}
		printf("\n");

		//limpa a lista definitiva pro proximo uso
		while (deftail != NULL)
			pop(&defhead, &deftail);
	}
	//limpa o conjunto
	free(set);
	return 0;
}

// *set - conjunto
// start - numero de inicio da função
// num - o numero a ser encontrado
// max - o tamanho do conjunto (*set)
void find_combinations(int *set, int start, int num, int max)
{
	//declara a lista temporaria necessaria pro calculo dos subconjuntos
	static list_t *tmphead = NULL, *tmptail = NULL;
	//se a subtração dos elementos ficar negativa
	if (num < 0)
		//volta
		return;
	//se for 0
	if (!num)
		//analisa e salva a lista atual na lista definitiva
		save(&tmphead, &tmptail);
	//percorre todos os elementos do vetor a partir de (start) para testar proximas combinações
	for (int i = start; i < max; i++) {
		//adiciona o numero do conjunto no subconjunto temporario
		append(&tmphead, &tmptail, set[i]);
		tmpsize++; //atualiza o tamanho da lista temporaria
		//debug(&tmphead);

		//passa pro proximo elementos do conjunto
		find_combinations(set, i + 1, num - set[i], max);

		//volta removendo elementos do subconjunto temporario
		pop(&tmphead, &tmptail);
		tmpsize--; //atualiza o tamanho da lista temporaria
		//debug(&tmphead);
	}
}

void save(list_t **head, list_t **tail)
{
	runs++;
	// se o tamanho do vetor temporario for menor que o atual "definitivo"
	if (tmpsize < defsize)
		//sai sem salvar
		return;
	//se o tamanho for igual
	if (tmpsize == defsize) {
		//percorre a lista de tras pra frente procurando o maior elemento
		for (list_t *temp = *tail, *deftemp = deftail;
		     temp != NULL && deftemp != NULL;
		     temp = temp->prev, deftemp = deftemp->prev) {
			//se o maior elemento do vetor temporario for menor que o maior do definitivo
			if (temp->num <= deftemp->num)
				//sai da função sem salvar
				return;
			//senão, para de procurar
			break;
		}
	}

	// retira todos os elementos da lista definitiva atual
	while (deftail != NULL)
		pop(&defhead, &deftail);

	//atualiza a lista definitiva com os elementos da temporaria
	for (list_t *temp = *head; temp != NULL; temp = temp->next)
		append(&defhead, &deftail, temp->num);
	//atualiza o tamanho da lista definitiva
	defsize = tmpsize;

	return;
}
void append(list_t **head, list_t **tail, int num)
{
	//cria uma nova estrutura
	list_t *new = malloc(sizeof(list_t));
	//coloca o numero
	new->num = num;
	//proximo é nulo, já que vai ser adicionado no final
	new->next = NULL;
	//se a cauda for nula
	if (!*tail) {
		//a nova estrutura tem nulo como antecessor
		new->prev = NULL;
		//a cabeça e o rabo apontam pra nova estrutura
		*head = new;
		*tail = new;

	} else { //senão
		//o proximo valor da nova estrutura é a cauda
		new->prev = *tail;
		//o proximo elemento da cauda é o novo elemento
		(*tail)->next = new;
		// a cauda agora é o novo elemento
		*tail = (*tail)->next;
	}
	return;
}
void pop(list_t **head, list_t **tail)
{
	//se o rabo é nulo
	if (!*tail)
		//não faz nada
		return;
	//se o valor anterior ao rabo é nulo
	if (!(*tail)->prev) {
		//limpa o valor da cauda
		free(*tail);
		//coloca nulo em tudo
		*head = NULL;
		*tail = NULL;

	} else { //senão
		// a cauda agora é o valor anterior
		*tail = (*tail)->prev;
		//limpa o ultimo valor
		free((*tail)->next);
		// coloca nulo no final da lista
		(*tail)->next = NULL;
	}
	return;
}

void debug(list_t **head)
{
	printf("(");
	for (list_t *tmp = *head; tmp != NULL; tmp = tmp->next) {
		//mostrando os numeros.
		printf("%d ", tmp->num);
	}
	printf(")\n");
}
