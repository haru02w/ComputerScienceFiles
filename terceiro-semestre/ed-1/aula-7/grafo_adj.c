#include <stdio.h>
#include <stdlib.h>

//EDs para nó e grafo
//----------------------------------
struct no {
	int id;
	int val;
	struct no *prox;
};

typedef struct no *No;

struct grafo {
	int nNo;     //número de nós
	No vertices; //array de vértices
};

typedef struct grafo *Grafo;
//----------------------------------

//Implementação das funções/operações
//----------------------------------
//Cria um nó do grafo
No criaNo (int id, int val) {
	No n = (No) malloc(sizeof(struct no));
	n->id = id;
	n->prox = NULL;
	n->val = val;
	return n;
}

//Adiciona um nó no grafo
void addNo (No n, int id, int val) {
	No novo = criaNo(id, val);
	if(n == NULL){
		return;
	}
	//Encontra a última posição na lista de adj. ref. nó n
	while(n->prox != NULL){ 
		n = n->prox;
	}
	n->prox = novo;
}

//Imprime a lista de todos os nós adjacentes ao nó corrente n
void imprimeNo(No n){
	while(n != NULL){
		printf("-> (%d, val: %d)", n->id, n->val);
		n = n->prox;
	}
}

//Define um grafo vazio
Grafo criaGrafo(){
	Grafo G = (Grafo) malloc(sizeof(struct grafo));
	G->vertices = NULL;
	G->nNo = 0;
	return G;
}

//Efetuar a leitura do grafo via arquivo
void readGraph(Grafo G, const char *filename){
//...
}

//Imprime o grafo a partir das listas de adjacencia
void printGraph(Grafo G) {
	int i;
	printf("\nGrafo - Lista de Adjacencia\n\n");
	for(i = 0; i < G->nNo; i++){
		printf("(%d)", (G->vertices + i)->id);
		imprimeNo((G->vertices + i));
		printf("\n");	
	}
}
//----------------------------------


//----------------------------------
int main() {
	Grafo g = criaGrafo();
	
	readGraph(g, "digrafo.txt");
	printGraph(g);
	
	return 0;
}
//----------------------------------


