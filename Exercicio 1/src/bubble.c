#include "bubble.h"

void InterativeBubbleSort(float **f, int n) {

    float aux0;
    float aux1;

    for(int i=1; i<n; i++){ 
        for(int j=0; j<n-i; j++){
            if(f[j][1] > f[j+1][1]){
                aux0 = f[j][0];
                aux1 = f[j][1];
	            f[j][0] = f[j+1][0];
                f[j][1] = f[j+1][1];
	            f[j+1][0] = aux0;
                f[j+1][1] = aux1;
			}
        }
	}
}