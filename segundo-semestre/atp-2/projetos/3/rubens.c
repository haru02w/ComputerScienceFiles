#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int id;
	int saltos;
	int O; //operação
	struct No *prox;
} no;

typedef struct {
	no *inicio;
	no *fim;
} lista_circ;

void criar_no(int Id, int Saltos, int OP, lista_circ *lista);
void insere_ordenado(lista_circ *lista, no *novo_no);
void insere_inicio(lista_circ *lista, no *novo_no);
void insere_fim(lista_circ *lista, no *novo_no);
no *remover(lista_circ *lista, no *elemento);

int main()
{
	//Criando a lista
	lista_circ lista;
	lista.inicio = NULL;
	lista.fim = NULL;
	lista.fim = 0;

	int N, i, Saltos, OP;
	no *ultimoRemovido = NULL, *aux, *elemento;

	scanf("%i", &N);
	//Laço que cria os N elementos
	//uso esta condição inicial, pois assim posso usar o i para identificar o elemento
	for (i = 1; i <= N; i++) {
		scanf("%i%i", &Saltos, &OP);
		criar_no(i, Saltos, OP, &lista);
	}
	//Processamento
	aux = elemento =
		lista.inicio; //passando pra aux e elemento, o inicio da lista
	Saltos =
		lista.inicio
			->saltos; // passando a qtd de saltos do primeiro elemento
	while (lista.inicio) {
		for (i = 1; i < Saltos; i++) { //ando na lista
			aux = aux->prox;
		}
		elemento = aux;
		aux = aux->prox; //andando mais um elemento na lista, o próximo processamento tem que partir do prox
		if (elemento->O == 1) { //testo se o elemento pede reinserção
			ultimoRemovido->O =
				0; //atualizando o campo "operação" do elemento
			insere_ordenado(&lista, ultimoRemovido);
		} else {
			free(ultimoRemovido);
		}
		Saltos = elemento->saltos; //Atualizando Saltos
		ultimoRemovido = remover(&lista, elemento);
		//Final - todos os elementos foram removidos da lista
		if (lista.inicio == NULL && elemento->O == 0) {
			printf("%i\n", elemento->id);
		}
	}
	free(ultimoRemovido); //Liberando a memoria pro do ultimo elemento

	return 0;
}
void criar_no(int Id, int Saltos, int OP, lista_circ *lista)
{
	no *novo_no = malloc(sizeof(no)); //Aloca memoria
	//Testa se a alocação deu certo
	if (novo_no) {
		//preenchendo os campos da estrutura
		novo_no->id = Id;
		novo_no->saltos = Saltos;
		novo_no->O = OP;
		insere_ordenado(lista, novo_no);
	}
}
void insere_ordenado(lista_circ *lista, no *novo_no)
{
	no *aux;

	if (lista->inicio == NULL) //Quando a lista está vazia
	{
		insere_inicio(lista, novo_no);
		return;
	}
	//Quando o elemento a ser inserido é menor elemento da nossa lista
	else if (novo_no->id < lista->inicio->id) {
		insere_inicio(lista, novo_no);
		return;
	} else {
		aux = lista->inicio;
		//ando na lista procurando a posição de inserção do elemento
		while (aux->prox != lista->inicio &&
		       novo_no->id > aux->prox->id)
			aux = aux->prox;
		//Se prox aponta do inicio é uma inserção no fim
		if (aux->prox == lista->inicio) {
			insere_fim(lista, novo_no);
			return;
		} else { //Senao é uma inserção no meio
			novo_no->prox = aux->prox;
			aux->prox = novo_no;
			return;
		}
	}
}
void insere_inicio(lista_circ *lista, no *novo_no)
{
	novo_no->prox = lista->inicio;
	lista->inicio = novo_no;
	if (lista->fim ==
	    NULL) //Se o fim da lista estiver nulo então essa é a primeira inserção
		lista->fim = novo_no;
	lista->fim->prox = lista->inicio;
}
void insere_fim(lista_circ *lista, no *novo_no)
{ //é o primeiro no?
	if (lista->inicio ==
	    NULL) { //Nesse caso também estamos inserindo o primeiro elemento da lista
		lista->inicio = novo_no;
		lista->fim = novo_no;
		lista->fim->prox = lista->inicio;
	} else {
		lista->fim->prox = novo_no;
		lista->fim = novo_no;
		novo_no->prox = lista->inicio;
	}
}
no *remover(lista_circ *lista, no *elemento)
{
	no *aux = lista->inicio;
	// A lista tem apenas UM elemento?
	if (lista->inicio == lista->fim) {
		lista->inicio = lista->fim = NULL;
		return elemento;
	}
	//O elemento a ser removido é o primeiro da lista?
	else if (lista->fim->prox == elemento) {
		lista->fim->prox = lista->inicio->prox;
		lista->inicio =
			elemento->prox; //Outra forma seria lista->inicio = lista->fim->prox
		return elemento;
	}
	//O elemento a ser removido é o ultimo da lista?
	else if (elemento->prox == lista->inicio) {
		//Procuro o penultimo elemento da lista
		while (aux->prox != elemento) {
			aux = aux->prox;
		}
		lista->fim = aux; // O fim recebe o penultimo
		aux->prox = lista->inicio;
		return elemento;
	}
	// O elemento a ser removido esta no meio da lista!
	else {
		//Procurando o nó anterior
		while (aux->prox != elemento)
			aux = aux->prox;
		aux->prox = elemento->prox;
		return elemento;
	}
}
