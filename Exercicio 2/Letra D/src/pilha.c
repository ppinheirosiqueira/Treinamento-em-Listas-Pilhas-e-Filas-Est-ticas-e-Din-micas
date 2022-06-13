#include "pilha.h"

void FPVazia(Pilha *p){
	p->base = (Block*) malloc (sizeof(Block));
	p->top  = p->base;
	p->base->prox = NULL;
}

void Push(Pilha *p, Item d){
	Block *aux = (Block*) malloc (sizeof(Block));
	aux->data = d;
	aux->prox = p->top;
	p->top = aux;
}

void Pop(Pilha *p, Item *d){
	Block *aux;

	if(p->base == p->top || p == NULL){
		printf("PILHA VAZIA!\n");
		return;
	}
	
	aux = p->top;
	p->top = aux->prox;
	*d = aux->data;
	free(aux);
}


void PImprime(Pilha *p){
	Block *aux;

	aux = p->top;
	while(aux != p->base){
		printf("%d\n", aux->data.val);
		aux = aux->prox;
	}
}

int fibonacci(int n){
	if (n == 1)
		return (1);

	if (n == 2)
		return (1);

	return (fibonacci(n-1) + fibonacci(n-2));
}

int procuraSequencia(Pilha *p, int n){
	Pilha p2;
	Item d;
	int aux;
	FPVazia(&p2);
	while (p->top->data.n != n){
		Pop(p, &d);
		Push(&p2, d);
	}
	
	aux = p->top->data.val;

	while (p2.base != p2.top){
		Pop(&p2, &d);
		Push(p, d);
	}

	return aux;
}