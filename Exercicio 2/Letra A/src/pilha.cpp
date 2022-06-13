#include "pilha.hpp"

void FPVazia(Pilha *p)
{
	p->base = new Block;
	p->top = p->base;
	p->base->prox = NULL;
}

void Push(Pilha *p, Item d)
{
	Block *aux = new Block;
	aux->data = d;
	aux->prox = p->top;
	p->top = aux;
}

void Pop(Pilha *p, Item *d)
{
	Block *aux;

	if (p->base == p->top || p == NULL)
	{
		cout << "LISTA VAZIA!\n";
		return;
	}

	aux = p->top;
	p->top = aux->prox;
	*d = aux->data;
	free(aux);
}

string Converte(int caracter)
{
	string num_convertido;

	num_convertido = caracter;

	return num_convertido;
}

Item ZeraVetor(Item aux)
{

	int i = 0;
	for (i = 0; i < TAM; i++)
	{
		aux.vet_valores[i] = 0;
	}
	return aux;
}

void PImprime(Pilha *p)
{
	Block *aux;
	int i = 0;
	aux = p->top;
	while (aux != p->base)
	{
		for (i = 0; i < TAM; i++)
		{
			if (aux->data.vet_valores[i] == 0)
			{
				break;
			}
			cout << Converte(aux->data.vet_valores[i]);
		}
		cout << "\n";
		aux = aux->prox;
	}
}

void PImprimeOperadores(Pilha *p)
{
	Block *aux;
	aux = p->top;
	int i = 0;
	for (i = 0; i < TAM; i++)
	{
		if (aux->data.vet_valores[i] == 0)
		{
			break;
		}
		cout << Converte(aux->data.vet_valores[i]) << "\n";
	}
}

void RecebeEquacao(string equacao, Pilha *operandos, Pilha *operadores)
{
	Item aux;
	int cont = 0, cont2 = 0;
	vector<int> vet_operandos[equacao.size()];
	vector<int> vet_operadores;
	for (size_t i = 0; i < equacao.size(); i++)
	{
		if ((equacao[i] >= 48 && equacao[i] <= 57))
		{
			vet_operandos[cont2].push_back(equacao[i]);
			cont++;
		}
		else
		{
			cont2++;
			vet_operadores.push_back(equacao[i]);
		}
	}
	aux = ZeraVetor(aux);

	for (int i = cont; i >= 0; i--)
	{
		for (size_t j = 0; j < vet_operandos[i].size(); j++)
		{
			
			aux.vet_valores[j] = vet_operandos[i][j];
		}
		if (vet_operandos[i].capacity() != 0)
			Push(operandos, aux);
		aux = ZeraVetor(aux);
	}

	for (size_t i = 0; i < (vet_operadores.size()); i++)
	{
		aux.vet_valores[i] = vet_operadores.at(i);
		Push(operadores, aux);
	}
	
	cout << "\nPilha contendo os operandos presentes na equação '" << equacao << "': " << endl;
	PImprime(operandos);
	cout << "\n";

	cout << "\nPilha contendo os operadores presentes na equação '" << equacao << "': " << endl;
	PImprimeOperadores(operadores);
	cout << "\n";
}