#include <stdio.h>
#include <stdlib.h>
typedef struct list {
	int id, steps, op, status;
	struct list *next;
} list_t;

list_t *add2end(list_t **list, int id, int steps, int op);
void reinsert(list_t **list, list_t *last);
void removefromlist(list_t **list, list_t *elem);

void debug(list_t **list);

int main(int argc, char *argv[])
{
	int people, steps, op;
	list_t *list = NULL, *tmp, *last;

	scanf("%d", &people);

	for (int i = 1; i <= people; i++) {
		scanf("%d %d", &steps, &op);
		last = add2end(&list, i, steps, op);
	}
	tmp = last;
	steps = list->steps;
	last = NULL;

	for (; list != list->next; steps = tmp->steps, last = tmp) {
		for (int i = 0; i < steps; i++)
			tmp = tmp->next;

		if (tmp->op)
			reinsert(&list, last);
		else if (last)
			free(last);
		removefromlist(&list, tmp);
		debug(&list);
	}
	printf("%d\n", list->id);
	free(list);
	free(last);

	return 0;
}
list_t *add2end(list_t **list, int id, int steps, int op)
{
	static list_t *last = NULL;
	list_t *new = malloc(sizeof(list_t));

	new->id = id;
	new->steps = steps;
	new->op = op;
	new->status = 1;

	if (!*list) {
		new->next = new;
		*list = new;
	} else {
		last->next = new;
		new->next = *list;
	}
	last = new;
	return last;
}
void reinsert(list_t **list, list_t *last)
{
	list_t *tmp = *list, *tmp2 = *list;
	int run = 1;

	last->op = 0;

	if (last->id < (*list)->id)
		*list = last, run = 0;

	while (tmp->next != tmp2 && (last->id > tmp->next->id || !run))
		tmp = tmp->next;

	tmp2 = tmp->next;
	tmp->next = last;
	last->next = tmp2;
}

void removefromlist(list_t **list, list_t *elem)
{
	list_t *tmp = elem;
	do
		tmp = tmp->next;
	while (tmp->next != elem);
	tmp->next = elem->next;

	if (*list == elem)
		*list = (*list)->next;
	return;
}

void debug(list_t **list)
{
	list_t *tmp = *list;
	printf("(");

	do {
		printf("%d ", tmp->id);
		tmp = tmp->next;
	} while (tmp != *list);
	printf(")\n");
}
