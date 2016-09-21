#ifndef ARVORE_B_H
#define ARVORE_B_H

/* Autores: José Diôgo e Fernando Maia
 * 
 * 
 **/
#include <string.h>
#include "contato.h"

#define ORDEM 4//ordem da arvoreB
#define FALSE 0
#define TRUE  1

typedef struct pagina *Apontador;//definicao dos ponteiros para as proximas paginas
typedef struct pagina//ou nó
{
  int numChaves;//Total de chaves na página
  Contato contato[ORDEM*2];//chaves
  Apontador apontador[(ORDEM*2)+1];//total de ponteiros
} Pagina;

//inicializa o dicionario
void inicializa(Apontador *dicionario)
{
	*dicionario = NULL;
}
/*insere na página*/
void insereNaPagina(Apontador apontador, Contato contato,  Apontador apDir)
{
	short naoAchouPosicao;
	int k;
	k = apontador->numChaves;//total de chaves 
	naoAchouPosicao = (k > 0);//verifica se já existe chaves 
	//se já existir chaves, procure a melhor posicao para salvar
	while(naoAchouPosicao)
	{
		if(strcmp(contato.nome, apontador->contato[k-1].nome) >= 0)//compara com as chaves pertencentes a pagina, pelo nome caso seja um nome maior ou igual faca a atribuicao posterior
		{
			naoAchouPosicao = FALSE;
			break;
		}
		apontador->contato[k] = apontador->contato[k-1];//se ainda nao encontrou, verifique o proximo contato
		apontador->apontador[k+1] = apontador->apontador[k];
		k--;
		if(k < 1) naoAchouPosicao = FALSE;//se já percorreu todas as posicoes, saia
	}
	apontador->contato[k] = contato;
	apontador->apontador[k+1] = apDir;
	apontador->numChaves++;
}

#endif


