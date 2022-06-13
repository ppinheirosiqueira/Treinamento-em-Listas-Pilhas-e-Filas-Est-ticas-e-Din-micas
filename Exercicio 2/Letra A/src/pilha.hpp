#ifndef PILHA_HPP
#define PILHA_HPP

#include <stdbool.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#define TAM 10

using namespace std;

typedef struct Item Item;
typedef struct Block Block;
typedef struct Pilha Pilha;

struct Item{
	int vet_valores[TAM];
};

struct Block{
	Item data;
	Block *prox;
};

struct Pilha{
	Block *base;
	Block *top;
};


void FPVazia(Pilha *p);
void Push(Pilha *p, Item d);
void Pop(Pilha *p, Item *d);
string Converte(int caracter);
void PImprime(Pilha *p);
void PImprimeOperadores(Pilha *p);
void RecebeEquacao(string equacao, Pilha *operandos, Pilha *operadores);
Item ZeraVetor(Item aux);

#endif