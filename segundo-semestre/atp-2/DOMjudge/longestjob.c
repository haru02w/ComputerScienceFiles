#include <stdio.h>
#include <stdlib.h>
typedef struct list {
	int instant, cost;
	struct list *next;
} list_t;

void add2list(list_t **head, int instant, int cost);
void rm2list(list_t **head, list_t *node);
void printl(list_t **head);
void debug(list_t *head);
list_t *nextjob(list_t *head, int time);

int main(int argc, char *argv[])
{
	list_t *head = NULL;
	int programs, instant, cost;
	scanf("%d", &programs);
	for (int i = 0; i < programs; i++) {
		scanf("%d %d", &instant, &cost);
		add2list(&head, instant, cost);
	}
	printl(&head);

	if (!head)
		return 0;
	while (head != NULL) {
		list_t *tmp = head;
		head = head->next;
		free(tmp);
	}

	return 0;
}

void add2list(list_t **head, int instant, int cost)
{
	list_t *prev = NULL, *new = malloc(sizeof(list_t));
	new->instant = instant;
	new->cost = cost;
	if (!*head) {
		new->next = NULL, *head = new;
		return;
	}

	if (instant < (*head)->instant) {
		new->next = *head, *head = new;
		return;
	}

	for (list_t *tmp = *head; tmp != NULL; prev = tmp, tmp = tmp->next) {
		if (instant < tmp->instant) {
			prev->next = new;
			new->next = tmp;
			return;
		}
	}
	prev->next = new;
	new->next = NULL;
	return;
}
void rm2list(list_t **head, list_t *node)
{
	list_t *prev = NULL;
	if (*head == node) {
		*head = (*head)->next;
		free(node);
	}

	for (list_t *tmp = *head; tmp != NULL; prev = tmp, tmp = tmp->next) {
		if (tmp == node) {
			prev->next = tmp->next;
			free(tmp);
			return;
		}
	}
	return;
}

void printl(list_t **head)
{
	int time = 0;
	list_t *execution = *head;
	time = execution->instant;
	while (execution != NULL) {
		if (execution->instant > time)
			time = execution->instant;
		time += execution->cost;
		printf("%d ", execution->cost);
		rm2list(head, execution);

		execution = nextjob(*head, time);
	}
	printf("\n");

	return;
}

void debug(list_t *head)
{
	for (; head != NULL; head = head->next)
		printf("%d ", head->instant);
	printf("\n");
	return;
}
list_t *nextjob(list_t *head, int time)
{
	list_t *lower = head;
	for (list_t *tmp = head; tmp != NULL; tmp = tmp->next)
		if (tmp->instant <= time && tmp->cost > lower->cost)
			lower = tmp;

	return lower;
}
