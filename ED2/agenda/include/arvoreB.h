#ifndef ARVORE_B_H
#define ARVORE_B_H

#include "contato.h"

#define ORDEM = 4//ordem da arvoreB
#define MAXIMODECHAVES ORDEM-1
#define MINIMODECHAVES 2


typedef struct ArvoreB {  
   int numeroChaves;//quantidade de chaves em x  
   Contato c[MAXIMODECHAVES];//chaves de contato
   ArvoreB *filhos[ORDEM];//numero de apontadores
   //int folha;//verdadeiro se x é folha e falso, caso contrario
}noArvoreB;

//insere na arvore
void inserir(Contato c, ArvoreB **arvore)
{
	int cresceu;
	Contato cRetorno;
	//criando filho direito
	noArvoreB *filhoDir;
	noArvoreB *novaRaiz;
	//insere na auxiliar
	//TO-DO consertar isso e outra funcoes
	inserirAux(Contato);
}

#endif


