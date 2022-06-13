#include "bubble.h"

void InterativeBubbleSort(FilaIndexada *f, int n) {

    FilaIndexada aux;

    for(int i=1; i<n; i++){ 
        for(int j=0; j<n-i; j++){
            if(f[j].Indexador < f[j+1].Indexador){
                aux = f[j];
	            f[j] = f[j+1];
	            f[j+1] = aux;
			}
        }
	}
}