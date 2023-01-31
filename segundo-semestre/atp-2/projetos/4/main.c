#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
//define a estrutura
typedef struct list {
	int id, instant, wait;
	struct list *next;
} list_t;

typedef struct {
	int id, time;
} timetracker_t;

/* adiciona elementos de forma ordenada por @instant 
 * e trata o caso dos @instant's forem iguais porem id for menor 
 */
void add2list(list_t **queue, int id, int instant, int wait);
//remove sempre primeiro elemento (head)
void rm2list(list_t **queue);

int main(int argc, char *argv[])
{
	/*
	 * @elems - quantidade de elementos a ser adicionado
	 * @threads - quantidade de atendentes da fila existe
	 * @busyness - guarda o ocupado do atendente 
	 */
	int elems, threads, *busyness;

	//variaveis temporarias para entrada de dados na lista
	int id, instant, wait;
	/*
	 * @queue - fila
	 * @lowertime - estrutura guarda informações sobre o proximo atendente
	 */
	list_t *queue = NULL;
	timetracker_t lowertime;

	scanf("%d %d", &elems, &threads);
	//aloca dinamicamente, zerando todos os elementos, o vetor @busyness
	busyness = calloc(threads, sizeof(int));

	//adiciona os elementos na fila
	for (int i = 0; i < elems; i++) {
		scanf("%d %d %d", &id, &instant, &wait);
		add2list(&queue, id, instant, wait);
	}

	//enquanto existir algum elemento na lista
	while (queue) {
		//supondo o tempo maximo
		lowertime.time = INT_MAX;
		//anda por todos os atendentes
		for (int i = 0; i < threads; i++) {
			//se encontrar algum atendente com o tempo ocupado menor que @lowertime.time
			if (busyness[i] < lowertime.time) {
				//salva o tempo e o id do atendente
				lowertime.time = busyness[i];
				lowertime.id = i;
			}
		} //no fim, o atendente menos ocupado sempre vai estar no @lowertime

		//se o atendente tiver ocioso quando o cliente chegar
		if (lowertime.time < queue->instant)
			//o tempo ocupado muda pro instante que o cliente chega
			busyness[lowertime.id] = queue->instant;
		//somado com o tempo para atendenter
		busyness[lowertime.id] += queue->wait;
		//logo após, o cliente sai dá fila
		rm2list(&queue);
	}

	//mostra o tempo de serviço dos atendentes
	for (int i = 0; i < threads; i++)
		printf("%d ", busyness[i]);
	printf("\n");

	return 0;
}

void add2list(list_t **queue, int id, int instant, int wait)
{
	//cria o novo elemento, e define um anterior
	list_t *prev = NULL, *new = malloc(sizeof(list_t));

	//coloca os valores em posição
	new->id = id;
	new->instant = instant;
	new->wait = wait;

	//se for vasia,
	if (!*queue) {
		//adiciona como primeiro elemento
		new->next = NULL, *queue = new;
		return;
	}

	//se o instante do @new for menor que o da cabeça
	if (instant <
		    (*queue)->instant || //ou o instante é o mesmo porem o id é menor
	    (instant == (*queue)->instant && id < (*queue)->id)) {
		//o novo vira a cabeça
		new->next = *queue, *queue = new;
		return;
	}

	//anda por toda a lista
	for (list_t *tmp = *queue; tmp != NULL; prev = tmp, tmp = tmp->next) {
		//se o instante do @new for menor que o elemento atual da lista
		if (instant <
			    tmp->instant || //ou o instante é o mesmo porem o id é menor
		    (instant == tmp->instant && id < tmp->id)) {
			//o novo vem antes do atual
			prev->next = new;
			new->next = tmp;
			return;
		}
	}
	//senão, vai no final
	prev->next = new;
	new->next = NULL;
	return;
}
//remove sempre da cabeça
void rm2list(list_t **queue)
{
	//cria um ponteiro pra cabeça lista
	list_t *tmp = *queue;
	//se for nula, não faz nada
	if (!*queue)
		return;

	//senão, passa a cabeça pra frente
	*queue = (*queue)->next;
	//e limpa a cabeça anterior
	free(tmp);
	return;
}
