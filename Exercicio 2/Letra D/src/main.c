#include "pilha.h"

int main()
{
	Pilha p;
	Item aux;
	int n, auxN;
	char opcao;
	FPVazia(&p);
	do{
		printf("\nInsira o tamanho da sequência de Fibonacci desejada: ");
		scanf("%d", &n);

		if (n < p.top->data.n && p.top != p.base){
			procuraSequencia(&p, n);
		}else{
			if (p.top->data.n != 0)
				auxN = p.top->data.n + 1;
			else
				auxN = 1;
			for (int i = auxN; i <= n; i++){
				aux.n = i;
				aux.val = fibonacci(i);
				Push(&p, aux);
			}
		}

		printf("%d\n", fibonacci(n));

		printf("\nDeseja verificar outra sequência?(s/n)\n");
		scanf(" %c", &opcao);
	}while(opcao != 'n');
	
	return 0;
}
