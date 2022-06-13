#include "letras.h"
#include "bubble.h"

void LetraA(){
    Item aux;
	Lista l;
	FLVazia(&l);
	int numP = 0, numI = 0;
	bool auxP;
	Block *b;

	printf("Exercício 1-a)\nLista utilizada:\n");

    srand(time(NULL));

	for(int i = 0; i < 10; i ++){
		aux.val = rand()%100;
		LInsert(&l, aux);
	}
	b = l.first->prox;
	while(b!=NULL){
		aux = b->data;
		auxP  = verificaPar(aux);
		if (auxP)
			numP++;
		else
			numI++;
    	b = b->prox;
	}

	LImprime(&l);
	printf("\nPelo método não recursivo foram encontrados:\n%d numeros pares nessa lista e %d numeros impares nessa lista\n", numP, numI);
	
	numP = 0;
	numI = 0;

	verificaParRecursivo(&numP, &numI, l.first->prox);
	printf("\nPelo método recursivo foram encontrados:\n%d numeros pares nessa lista e %d numeros impares nessa lista\n\n", numP, numI);

    return;
}

void LetraB(){
    Lista L1, L2;
    Item aux;
	int auxL1 = 0, auxL2 = 0, auxNum;
	printf("Exercício 1-b)\n");
		    
	FLVazia(&L1);
    FLVazia(&L2);

	auxNum = rand() % 13 + 1;

	for(int i = 0; i < 3; i ++){
		aux.val = rand() % 13 + 1;
		LInsert(&L1, aux);
		printf("L1[%d]: %d\n", i, aux.val);
		auxL1 = auxL1 + aux.val - auxNum; 
		aux.val = rand() % 13 + 1;
		LInsert(&L2, aux);
		printf("L2[%d]: %d\n\n", i, aux.val);
		auxL2 = auxL2 + aux.val - auxNum;
	}

	printf("Número sorteado %d\n", auxNum);	

	if(auxL1 > auxL2)
		printf("A lista vencedora foi a 1\n\n");
	else
		printf("A lista vencedora foi a 2\n\n");

    return;
}

void LetraC(){
	printf("Exercício 1-c)\n");
    	Lista l, l2;
	Item aux;
	int n, m;

	FLVazia(&l);
	FLVazia(&l2);
	srand(time(0));

	printf("\nInsira o tamanho das listas desejado: \n");
	printf("Lista 1:");
	scanf("%d", &n);
	printf("Lista 2:");
	scanf("%d", &m);

	for (int i = 0; i < n; i++){
		aux.val = rand() % 100;
		LInsert(&l, aux);
	}

	for (int i = 0; i < m; i++){
		aux.val = rand() % 100;
		LInsert(&l2, aux);
	}

	printf("Lista 1:\n");
	LImprime(&l);
	printf("\n");	
	printf("Lista 2:\n");
	LImprime(&l2);
	printf("\n");
	
	if(n > m){
		l2 = inverteLista(&l2, n);
	}
	else{
		l = inverteLista(&l, n);
	}
	printf("Lista 3:\n");
	multiplicaPares(&l, &l2, n, m);

    return;
}

void LetraD(){
    Lista L1D, L2D;
	Item iaux;
	int aux, contTamanho = 0, nmPares;
	float **matrizPares;
	FILE *file;  	    
	printf("Exercício 1-d)\n");

	FLVazia(&L1D);
    FLVazia(&L2D);	    	    

	file = fopen("Lista1D.txt", "r");

	if (file == NULL){   
		printf("Arquivo não encontrado!\n"); 
	}
	else{
		while(fscanf(file, "%d", &aux) == 1){
			iaux.val = aux;
			LInsert(&L1D,iaux);
			contTamanho++;
		}
	}
    
    fclose(file);

	file = fopen("Lista2D.txt", "r");
	if (file == NULL){   
		printf("Arquivo não encontrado!\n"); 
	}
	else{
		while(fscanf(file, "%d", &aux) == 1){
			iaux.val = aux;
			LInsert(&L2D,iaux);
		}		
	}			

    printf("X:\n");
	LImprime(&L1D);
    printf("Y:\n");
	LImprime(&L2D);
	fclose(file);

	
	printf("\nInsira a quantidade de pares desejados: ");
	scanf("%d", &nmPares);
    printf("\n");
	while(nmPares > contTamanho){
		printf("Insira a quantidade de pares desejados (menor que o tamanho das listas por favor): ");
		scanf("%d", &nmPares);
    	printf("\n");
	}

	matrizPares = malloc (contTamanho * sizeof(float *));

	for (int i = 0; i < contTamanho; i++){
		matrizPares[i] = malloc (2 * sizeof(float *));
	}

	Block *AuxX, *AuxY;
	AuxX = L1D.first->prox;
	AuxY = L2D.first->prox;
	for (int i = 0; i < contTamanho; i++){
		matrizPares[i][0] = i + 1;
		matrizPares[i][1] = sqrt(pow(AuxX->data.val,2) + pow(AuxY->data.val,2));
        AuxX = AuxX->prox;
		AuxY = AuxY->prox;
	}

	InterativeBubbleSort(matrizPares,contTamanho);

	printf("Os %d pares mais próximos são: ", nmPares);
	for (int i = 0; i < nmPares; i++){
		printf("Par %.0f: Distância %f\n", matrizPares[i][0], matrizPares[i][1]);
	}

    return;
}