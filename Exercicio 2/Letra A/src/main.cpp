#include "pilha.hpp"

int main()
{
	Pilha operandos, operadores;
	string equacao;

	FPVazia(&operandos);
	FPVazia(&operadores);

	cout << "Informe a equação em que deseja separar seus operando e operadores: ";
	getline(cin, equacao);

	RecebeEquacao(equacao, &operandos, &operadores);

	return 0;
}