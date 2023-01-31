#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define PREF_AGE 60

//define a estrutura
typedef struct list {
	int age, instant;
	struct list *next;
} list_t;

list_t *add_after(list_t *pos, list_t *new);
list_t *rmfromlist(list_t **head);
void debug(list_t *head);

int main(int argc, char *argv[])
{
	int elems, time = 0;
	list_t *tmplist = NULL, *deflist = NULL;
	scanf("%d", &elems);

	for (int i = 0; i < elems; i++) {
		list_t *new = malloc(sizeof(list_t));

		scanf("%d %d", &new->age, &new->instant);

		if (tmplist == NULL) {
			tmplist = add_after(NULL, new);
		} else {
			list_t *tmp = tmplist;
			if (tmp->instant > new->instant) {
				new->next = tmp;
				tmplist = new;
			} else {
				while (tmp->next != NULL &&
				       tmp->next->instant <= new->instant)
					tmp = tmp->next;
				add_after(tmp, new);
			}
		}
	}
	while (tmplist) {
		static list_t *last = NULL;
		list_t *tmp, *new = rmfromlist(&tmplist);

		while (new->instant >= time) {
			rmfromlist(&deflist);
			time += 3;
		}

		if (new->age < PREF_AGE || deflist == NULL) {
			last = add_after(last, new);
		} else {
			tmp = deflist;
			if (tmp->instant == new->instant &&
			    tmp->age < new->age) {
				new->next = tmp;
				deflist = new;
			} else {
				while (tmp->next != NULL &&
				       new->age < tmp->next->age)
					tmp = tmp->next;
				if (add_after(tmp, new)->next == NULL)
					last = new;
			}
		}

		if (deflist == NULL) {
			time = new->instant + 3;
			deflist = last;
		}

		if (tmplist != NULL && tmplist->instant == new->instant)
			;
		else
			debug(deflist);
	}

	return 0;
}
list_t *add_after(list_t *pos, list_t *new)
{
	if (pos == NULL)
		new->next = NULL;
	else
		new->next = pos->next, pos->next = new;

	return new;
}
list_t *rmfromlist(list_t **head)
{
	if (*head == NULL)
		return NULL;
	list_t *tmp = *head;
	*head = (*head)->next;
	return tmp;
}
void debug(list_t *head)
{
	while (head != NULL) {
		printf("%d ", head->age);
		head = head->next;
	}
	printf("\n");
}
