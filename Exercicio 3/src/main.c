#include "letras.h"
#include <ctype.h>

int main()
{
    char opcao;

    do{
	    printf("O exercício 3 (Filas) possui 3 opções:\n");
	    printf("Qual opção você deseja executar?(a,b,c)\n");
	    printf("Digite 's' para sair\n");
	    scanf(" %c", &opcao);
	    printf("\n");
	    opcao = tolower(opcao);
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

	    	case 's':
	    	    printf("Aparentemente está tudo funcionando, grato pela paciência.\n\n");
	    	    break;
	    	    
	    	default:
	    	    printf("Eu te dei 4 opções, por favor digite uma opção válida\n\n");
	    	    break;

	    } 
    }while(opcao!='s');
               
    return 0;
}
