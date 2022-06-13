#include "fila.h"

void FFVazia(Fila *f){
	f->first = (Block*) malloc (sizeof(Block));
	f->last  = f->first;
	f->first->prox = NULL;
}

void Enfileira(Fila *f, Item d){
	f->last->prox = (Block*) malloc (sizeof(Block));
	f->last = f->last->prox;
	f->last->data = d;
	f->last->prox = NULL;
}

void Desenfileira(Fila *f, Item *d){
	Block *aux;

	if(f->first == f->last || f == NULL || f->first->prox == NULL){
		printf("FILA VAZIA!\n");
		return;
	}
	
	aux = f->first->prox;
	f->first->prox = aux->prox;
	if (f->first->prox == f->last)
		f->last = f->first;
	d->val   = aux->data.val;
	free(aux);
}


void FImprime(Fila *f){
	Block *aux;

	aux = f->first->prox;
	while(aux != NULL){
		printf("%d\t", aux->data.val);
		aux = aux->prox;
	}
    printf("\n");
}

void separaFila(Fila *f, Fila *f2, int n){
	Fila filaAux;
	Fila filaAux2;
	Block *blockAux;
	Block *blockAux2;
	FFVazia(&filaAux);
	FFVazia(&filaAux2);
	blockAux = f->first->prox;
	blockAux2 = f2->first->prox;
	for(int i = 0; i < n/2; i++){
		Enfileira(&filaAux, blockAux->data);
		Enfileira(&filaAux2, blockAux2->data);
		blockAux = blockAux->prox;
		blockAux2 = blockAux2->prox;
	}

	while(blockAux != NULL){
		Enfileira(&filaAux, blockAux2->data);
		Enfileira(&filaAux2, blockAux->data);
		blockAux = blockAux->prox;
		blockAux2 = blockAux2->prox;
	}

	printf("\nNova fila 1:\n");
	FImprime(&filaAux);
	printf("\nNova fila 2:\n");
	FImprime(&filaAux2);
}

int Indexador(Fila *f){
    int Indexador = 0;
    Block *blockAux;
    blockAux = f->first->prox;
	while(blockAux != NULL){
        Indexador = Indexador + blockAux->data.val;
        blockAux = blockAux->prox;
    }
    return Indexador;
}