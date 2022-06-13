#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "pilha.h"

int gcd(int a, int b);
void phi(int n);

int main(){

	Pilha P1;
	Item Iaux;

	FPVazia(&P1);

    srand(time(0));
	for (int i = 0; i < 20; ++i){
		Iaux.val = rand() % 99 + 1;
		Push(&P1, Iaux);
	}

	for (int i = 0; i < 20; ++i){
		Pop(&P1, &Iaux);
		printf("P1[%d] = %d\n", i, Iaux.val);
		phi(Iaux.val);
		printf("\n");
	}

    return 0;
}

// Function to return gcd of a and b
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
 
// A simple method to evaluate Euler Totient Function
void phi(int n)
{
	printf("Os co-primos de %d são: 1", n);
    for (int i = 2; i < n; i++){
        if (gcd(i, n) == 1){
			printf(", %d", i);
		}
	}
	printf("\n");
}