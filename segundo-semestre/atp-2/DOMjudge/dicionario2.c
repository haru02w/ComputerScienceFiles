#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXWORD 100
typedef struct words {
	char word[MAXWORD];
	struct words *next;
} list_t;

void add2list(list_t **head, char *word);
void rm2list(list_t **head, char *word);
void printl(list_t **head, char *word);

int main(int argc, char *argv[])
{
	int numwords, nops;
	list_t *dictionary = NULL;
	scanf("%d %d", &numwords, &nops);

	for (int i = 0; i < numwords; i++) {
		char word[MAXWORD];
		scanf(" %s", word);
		add2list(&dictionary, word);
	}

	for (int i = 0, op; i < nops; i++) {
		char word[MAXWORD];
		scanf("%d %s", &op, word);
		switch (op) {
		case 0:
			rm2list(&dictionary, word);
			break;
		case 1:
			add2list(&dictionary, word);
			break;
		case 2:
			printl(&dictionary, word);
			break;
		}
	}
	while (dictionary != NULL) {
		list_t *prev = dictionary;
		dictionary = dictionary->next;
		free(prev);
	}
	return 0;
}

void add2list(list_t **head, char *word)
{
	list_t *tmp = *head, *prev = NULL, *new = malloc(sizeof(list_t));
	int res = 0;
	strcpy(new->word, word);
	if (!*head) {
		new->next = NULL, *head = new;
		return;
	}

	while (tmp != NULL) {
		res = strcmp(tmp->word, word);
		if (res > 0)
			break;
		if (res == 0) {
			free(new);
			return;
		}
		prev = tmp, tmp = tmp->next;
	}

	if (res > 0) {
		if (*head == tmp)
			new->next = *head, *head = new;
		else
			new->next = prev->next, prev->next = new;
	} else
		prev->next = new, new->next = NULL;
	return;
}
void rm2list(list_t **head, char *word)
{
	list_t *tmp = *head, *prev = NULL;
	int res = 1;
	if (!*head)
		return;
	while (tmp != NULL && (res = strcmp(tmp->word, word)))
		prev = tmp, tmp = tmp->next;
	if (res)
		return;

	if (!prev) {
		tmp = *head;
		*head = (*head)->next;
		free(tmp);

	} else if (tmp != NULL) {
		prev->next = tmp->next;
		free(tmp);
	} else {
		prev->next = NULL;
		free(tmp);
	}
	return;
}
void printl(list_t **head, char *word)
{
	list_t *tmp = *head;
	while (tmp != NULL && strcmp(tmp->word, word) < 0)
		tmp = tmp->next;
	if (tmp == NULL) {
		printf("NULL\n");
		return;
	}
	while (tmp != NULL) {
		printf("%s ", tmp->word);
		tmp = tmp->next;
	}
	printf("\n");

	return;
}
