#ifndef FILA_H 
#define FILA_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

typedef struct Item Item;
typedef struct Block Block;
typedef struct Fila Fila;
typedef struct FilaIndexada FilaIndexada;

struct Item{
	int val;
};

struct Block{
	Item data;
	Block *prox;
};

struct Fila{
	Block *first;
	Block *last;
};

struct FilaIndexada{
    Fila fila;
    int Indexador;
};

void FFVazia(Fila *f);
void Enfileira(Fila *f, Item d);
void Desenfileira(Fila *f, Item *d);
void FImprime(Fila *f);
void separaFila(Fila *f, Fila *f2, int n);
int Indexador(Fila *f);

#endif