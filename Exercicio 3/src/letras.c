#include "fila.h"

void LetraA(){
	Fila f, f2;
	Item aux;
	int n = 0;
	FFVazia(&f);
	FFVazia(&f2);
    printf("Letra A)\n");
	printf("Insira o tamanho das filas desejado: ");
	scanf("%d", &n);

	srand(time(0));

	for (int i = 0; i < n; i++){
		aux.val = rand() % 100;
		Enfileira(&f, aux);
	}

	for (int i = 0; i < n; i++){
		aux.val = rand() % 100;
		Enfileira(&f2, aux);
	}
	printf("Fila 1:\n");
	FImprime(&f);
	printf("Fila 2:\n");
	FImprime(&f2);

	separaFila(&f, &f2, n);
    printf("\n\n");
	return;
}

void LetraB(){
    FilaIndexada f;
    Item aux;
	int n = 0;
	FFVazia(&f.fila);
    printf("Letra B)\n");
	printf("Insira o tamanho da fila desejado: ");
	scanf("%d", &n);

	srand(time(0));

	for (int i = 0; i < n; i++){
		aux.val = rand() % 100;
		Enfileira(&f.fila, aux);
	}

	printf("Fila:\n");
	FImprime(&f.fila);

    f.Indexador = Indexador(&f.fila);
    printf("Indexador: %d\n\n", f.Indexador);

    return;
}

void LetraC(){
    int num,n;
    Item aux;
    printf("Letra C)\n");
	printf("Insira quantas filas são desejadas: ");
	scanf("%d", &num);

    printf("Insira o tamanho da fila desejado: ");
	scanf("%d", &n);

    FilaIndexada VetorFilas[num];

	srand(time(0));

    for (int i = 0; i< num; i++){
        FFVazia(&VetorFilas[i].fila);
        
	    for (int j = 0; j < n; j++){
		    aux.val = rand() % 100;
		    Enfileira(&VetorFilas[i].fila, aux);
	    }

        VetorFilas[i].Indexador = Indexador(&VetorFilas[i].fila);
        printf("Fila %d:\n", i+1);
	    FImprime(&VetorFilas[i].fila);
        printf("Indexador: %d\n\n", VetorFilas[i].Indexador);
    }

    InterativeBubbleSort(VetorFilas, num);

    printf("\nFilas ordenadas:\n");

    for (int i = 0; i< num; i++){
        printf("Fila %d:\n", i+1);
	    FImprime(&VetorFilas[i].fila);
        printf("Indexador: %d\n\n", VetorFilas[i].Indexador);
    }

    printf("\n");
    return;
}