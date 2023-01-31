#include <stdio.h>
#include <stdlib.h>
//estrutura
typedef struct list {
	int id, steps, op;
	struct list *next;
} list_t;
//adiciona e retorna o elemento adicionado
list_t *add2end(list_t **list, int id, int steps, int op);
//reinsere o ultimo elemento
void reinsert(list_t **list, list_t **tail, list_t *last);
//remove da lista
void removefromlist(list_t **list, list_t **tail, list_t *elem);

int main(int argc, char *argv[])
{
	/*
        * @people - quantidade de pessoas na lista circular
        * @steps - guarda os passos de cada um dos elementos da lista
        * @op - guarda operação dos elementos da lista
        */
	int people, steps, op;
	/*
	 * @list - lista circular
	 * @tmp - ponteiro temporario usado em loops
	 * @last - elemento anteriormente removido
	 * @tail - ultimo elemento da lista
	 */
	list_t *list = NULL, *tmp, *last = NULL, *tail;

	scanf("%d", &people);
	if (!people)
		return 0;

	//adiciona todos os elementos na lista
	for (int i = 1; i <= people; i++) {
		scanf("%d %d", &steps, &op);
		//salva o elemento adicionado pra usar o ultimo elemento
		tail = add2end(&list, i, steps, op);
	}
	//define @tmp como o ultimo elemento
	tmp = tail;
	//atualiza os passos a ser andado pelo primeiro elemento
	steps = list->steps;

	while (list != list->next) {
		//anda @steps elementos
		for (int i = 0; i < steps; i++)
			tmp = tmp->next;

		//salva os proximos passos
		steps = tmp->steps;

		//se a operação é 1, então reinsere o anterior
		if (tmp->op)
			reinsert(&list, &tail, last);
		//se não inserir, limpa o elemento da memoria
		else if (last)
			free(last);
		//
		//tira o elemento atual da lista
		removefromlist(&list, &tail, tmp);

		//salva o atual como anterior para proxima execução
		last = tmp;
	}

	//mostra o elementos que sobrou
	printf("%d\n", list->id);

	//limpa os elementos restantes
	free(list);
	free(last);
	return 0;
}

list_t *add2end(list_t **list, int id, int steps, int op)
{
	//salva o ultimo elemento adicionado
	static list_t *last = NULL;
	//cria o novo elemento
	list_t *new = malloc(sizeof(list_t));
	//adiciona os elementos na lista
	new->id = id;
	new->steps = steps;
	new->op = op;

	//se for nulo, atualiza a cabeça da lista
	if (!*list) {
		new->next = new;
		*list = new;
		//senão coloca depois do final
	} else {
		last->next = new;
		new->next = *list;
	}
	//salva o atual como o ultimo
	last = new;
	//retorna o novo elemento
	return last;
}
void reinsert(list_t **list, list_t **tail, list_t *last)
{
	list_t *tmp = *list, *tmp2;
	//se o elemento anterior for nulo (não existir)
	if (!last)
		//só sai
		return;

	//reinsere sempre com a operação 0
	last->op = 0;

	//enquanto não chegar no final da lista e enquanto o elemento a adicionar for maior que o atual
	while (tmp->next != *list && last->id > tmp->next->id)
		//ande pro proximo elemento
		tmp = tmp->next;

	//se o id do elemento a reinserir é menor que o id dá cabeça
	if (last->id < (*list)->id) {
		last->next = *list;
		//a cabeça vira o elemento reinserido
		*list = last;
		//altera o proximo elemento do ultimo elemento (aponta para a nova cabeça)
		(*tail)->next = *list;
		return;
	}

	//salva o proximo atual
	tmp2 = tmp->next;
	//o proximo elemento se torna o @last
	tmp->next = last;
	//e o proximo do @last se torna o que antes era proximo do tmp
	last->next = tmp2;
}

void removefromlist(list_t **list, list_t **tail, list_t *elem)
{
	list_t *tmp = elem;
	//anda até encontrar o elemento
	do
		tmp = tmp->next;
	while (tmp->next != elem);
	//altera o proximo pro proximo do elemento
	tmp->next = elem->next;

	//se o elemento for a cabeça
	if (*list == elem)
		//passa a cabeça pra frente
		*list = (*list)->next;
	//se o proximo do elemento for a cabeça (for o ultimo elemento)
	if (elem->next == *list)
		//altera o ponteiro pro novo valor
		*tail = tmp;

	return;
}
