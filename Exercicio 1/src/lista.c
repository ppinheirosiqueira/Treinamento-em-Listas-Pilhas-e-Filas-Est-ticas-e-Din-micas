#include "lista.h"

void Swap(Block *a, Block *b){
	Item aux;
	aux = a->data;
	a->data = b->data;
	b->data = aux;
	
}

void FLVazia(Lista *l){
	l->first = (Block*) malloc (sizeof(Block));
	l->last  = l->first;
	l->first->prox = NULL;
}

void LInsert(Lista *l, Item d){
	l->last->prox = (Block*) malloc (sizeof(Block));
	l->last = l->last->prox;
	l->last->data = d;
	l->last->prox = NULL;
}

void LRemove(Lista *l, Item d){
	Block *aux, *tmp;

	if(l->first == l->last || l == NULL || l->first->prox == NULL){
		printf("LISTA VAZIA!\n");
		return;
	}
	
	aux = l->first;
	while(aux->prox != NULL){
		if (aux->prox->data.val == d.val){
			tmp = aux;
			aux = aux->prox;
			tmp->prox = aux->prox;
			if (aux == l->last)
				l->last = tmp;
			free(aux);
			aux->prox = NULL;
		}
		else
			aux = aux->prox;
	}
}


void LImprime(Lista *l){
	Block *aux;

	aux = l->first->prox;
	while(aux != NULL){
		printf("%d \t", aux->data.val);
		aux = aux->prox;
	}
    printf("\n");
}

bool verificaPar(Item d){

    if (d.val % 2 == 0)
        return true;
    else
        return false;
}

void verificaParRecursivo(int *numPares, int *numImpares, Block *BAtual){
    if(BAtual->prox == NULL){
        if (verificaPar(BAtual->data))
            *numPares = 1;
        else
            *numImpares = 1;
        return;
    }
    else{
        verificaParRecursivo(numPares, numImpares, BAtual->prox);
        if (verificaPar(BAtual->data))
            *numPares = *numPares + 1;
        else
            *numImpares = *numImpares + 1;
        return;
    }
}

Lista inverteLista(Lista *l, int n){
	Block *aux;
	Lista laux;
	FLVazia(&laux);

	for (int i = 0; i < n; i++){
		aux = l->first->prox;
		while(aux != NULL){
			if(aux->prox == NULL){
				LInsert(&laux, aux->data);
				LRemove(l, aux->data);
			}
			aux = aux->prox;
		}
	}

	return laux;
}

void multiplicaPares(Lista *l, Lista *l2, int n, int m){
	Lista l3;
	FLVazia(&l3);
	Item itemAux;
	Block *blocoL;
	int vetL[n], vetL2[m];

	blocoL = l->first->prox;

	for(int i = 0; i < n; i++){
		vetL[i] = blocoL->data.val;
		blocoL = blocoL->prox;
	}

	blocoL = l2->first->prox;

	for(int j = 0; j < m; j++){
		vetL2[j] = blocoL->data.val;
		blocoL = blocoL->prox;
	}

	if (n > m){
		for(int i = 0; i < n; i++){
			if (i < m){
				itemAux.val = vetL[i] * vetL2[i];
				LInsert(&l3, itemAux);	
			}else{
				itemAux.val = vetL[i];
				LInsert(&l3, itemAux);	
			}
		}
	}else{
		for(int i = 0; i < m; i++){
			if (i < n){
				itemAux.val = vetL[i] * vetL2[i];
				LInsert(&l3, itemAux);	
			}else{
				itemAux.val = vetL2[i];
				LInsert(&l3, itemAux);	
			}
		}
	}

	LImprime(&l3);
}