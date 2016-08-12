#include<stdio.h>

#define TAM 20

typedef struct Operator
{
	char operador;
	int cont;
} Operator;

typedef struct Pilha
{
   Operator operador[TAM];
   int number[TAM];
   int topo;	
} Pilha;

Pilha pOperador, pNumber;

int isFull(Pilha p)
{
	if(p.topo >= TAM) return 1;
	return 0;
}

int inserirOperador(Pilha p, char operando)
{
	if(isFull(p) != 1)
	{
		p.topo++;
		p.operador[topo].operador = operando;
		p.operador[topo].cont += 1;
		return 1;
	}

	return 0;
}

int inserirNumero(Pilha p, char )
{
	
}


int main(int argc, char *argv[])
{
	
	return 0;
}
