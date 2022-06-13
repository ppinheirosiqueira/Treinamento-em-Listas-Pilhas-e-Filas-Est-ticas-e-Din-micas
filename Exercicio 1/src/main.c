#include "letras.h"
#include <ctype.h>

int main()
{
    char opcao;

    do{
	    printf("O exercício 1 de Listas possui 4 opções:\n");
	    printf("Qual opção você deseja executar?(a,b,c,d)\n");
	    printf("Digite 's' para sair\n");
	    scanf(" %c", &opcao);
		opcao = tolower(opcao);
	    printf("\n");
	    
	    switch(opcao){
	    
	    	case 'a':
				LetraA();
				break;
	    	    
	    	case 'b':
	    	    LetraB();
	    	    break;
	    	
	    	case 'c':
				LetraC();
	    	    break;
	    	
	    	case 'd':
	    	    LetraD();
	    	    break;

	    	case 's':
	    	    printf("Aparentemente está tudo funcionando, grato pela paciência.\n\n");
	    	    break;
	    	    
	    	default:
	    	    printf("Eu te dei 5 opções, por favor digite uma opção válida\n\n");
	    	    break;

	    } 
    }while(opcao!='s');
               
    return 0;
}
