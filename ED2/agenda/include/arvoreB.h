#ifndef ARVORE_B_H
#define ARVORE_B_H

/* Autores: José Diôgo e Fernando Maia
 * 
 * 
 **/
#include <string.h>
#include "contato.h"
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define ORDEM 4//ordem da arvoreB
#define FALSE 0
#define TRUE  1
#define namefile "_arquivo.dat"


int cont = -1, count = 0;

typedef struct pagina *Apontador;//definicao dos ponteiros para as proximas paginas
typedef struct pagina//ou nó
{
  int numChaves;//Total de chaves na página
  Contato contato[ORDEM*2];//chaves
  int pageNum;//numero da pagina
  int num;
  Apontador apontador[(ORDEM*2)+1];//total de ponteiros
} Pagina;


void ins(Contato contato, Apontador apontador, int *cresceu, Contato *contatoRetorno, Apontador *apontadorRetorno);
void saveAux(Apontador p, int Nivel);
void insereNaPagina(Apontador apontador, Contato contato,  Apontador apDir);
void insere(Contato contato, Apontador *apontador);
void salvar(Apontador page, Contato Reg[]);
int file_exists(const char *filename);

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
/*Insere na árvore B*/
void insere(Contato contato, Apontador *apontador)
{
	int cresceu;
	Contato contatoRetorno;
	Apontador apontadorRetorno;
	Apontador apontadorTemp;
	//insere na arvore
	ins(contato, *apontador, &cresceu, &contatoRetorno, &apontadorRetorno);
	//se a arvore cresceu na altura pela raiz
	if(cresceu)
	{
		apontadorTemp = (Apontador) malloc(sizeof(Pagina));
		apontadorTemp->numChaves = 1;
		apontadorTemp->contato[0] = contatoRetorno;
		apontadorTemp->apontador[1] = apontadorRetorno;
		cont++; 
		apontadorTemp->pageNum = cont;
		apontadorTemp->apontador[0] = *apontador;
		*apontador = apontadorTemp;
	}
    //salva no arquivo
	saveAux(*apontador, 2*ORDEM);
}

//aux para insercao
void ins(Contato contato, Apontador apontador, int *cresceu, Contato *contatoRetorno, Apontador *apontadorRetorno)
{
	Apontador apontadorTemp;
	Contato aux;
	int i, j;
	
	if(apontador == NULL)
	{
		*cresceu = 1;//a arvore cresceu da raiz
		*contatoRetorno = contato;
		*apontadorRetorno = NULL;
		return;
	}
	i = 1;
	while(i < apontador->numChaves && strcmp(contato.nome, apontador->contato[i-1].nome) > 0) i++; 

	//se as chaves forem iguais
	if(strcmp(contato.nome, apontador->contato[i-1].nome) == 0)
	{
		printf("Este contato já se encontra na lista: %s \n", contato.nome);
		return;
	}
	//se a letra for menor
	if(strcmp(contato.nome, apontador->contato[i-1].nome) < 0) ins(contato, apontador->apontador[i-1], cresceu, contatoRetorno, apontadorRetorno);
	else ins(contato, apontador->apontador[i], cresceu, contatoRetorno, apontadorRetorno);
	
	//caso nao cresca
	if(!*cresceu) return;
	
	//verificando a ordem
	if(apontador->numChaves < 2*ORDEM)
	{
		//verifica se a pagina tem espaco
		insereNaPagina(apontador, *contatoRetorno, *apontadorRetorno);
		*cresceu = 0;
		return;
	}
	
	//repartir *split - Pagina tem que ser dividida
	apontadorTemp = (Apontador) malloc(sizeof(Apontador));
	apontadorTemp->numChaves = 0;
	apontadorTemp->apontador[0] = NULL;
	cont++;
	apontadorTemp->pageNum = cont;
	
	if(i <= ORDEM + 1)
	{
		insereNaPagina(apontadorTemp, apontador->contato[2*ORDEM -1], apontador->apontador[2*ORDEM]);
		apontador->numChaves--;
		insereNaPagina(apontador, *contatoRetorno, *apontadorRetorno);
	}
	else
	{
		insereNaPagina(apontadorTemp, *contatoRetorno, *apontadorRetorno);
	}
	
	for(j = ORDEM + 2; j <= 2*ORDEM; j++) insereNaPagina(apontadorTemp, apontador->contato[j - 1], apontador->apontador[j]);

	apontador->numChaves = ORDEM;
	apontadorTemp->apontador[0] = apontador->apontador[ORDEM + 1]; 
	*contatoRetorno = apontador->contato[ORDEM];
	*apontadorRetorno = apontadorTemp;
	
	for(j = ORDEM; j < apontador->numChaves+2; j++){
		strcpy(aux.nome, "a");
		aux.rank = 0;
		apontador->contato[j] = aux;
	}
}

int file_exists(const char *filename)
{
  FILE *arquivo;

  if((arquivo = fopen(filename, "rb")))
  {
    fclose(arquivo);
    return 1;
  }
  return 0;
}


void salvar(Apontador page, Contato Reg[])
{
    FILE* arq;
    if (!file_exists(namefile)){
        arq = fopen(namefile,"wb");
        if (arq == NULL)
            exit(1);
        fseek(arq, page->pageNum*(2*ORDEM*sizeof(Contato)), SEEK_SET);
        fwrite(Reg,(2*ORDEM*sizeof(Contato)),1,arq);
        fclose(arq);
    }

    else{
        arq = fopen(namefile,"r+b");
        if (arq == NULL)
            exit(1);
        fseek(arq, page->pageNum*(2*ORDEM*sizeof(Contato)), SEEK_SET);
        fwrite(Reg, 2*ORDEM*sizeof(Contato),1,arq);
        fclose(arq);
    }
}

void saveAux(Apontador p, int Nivel)
{
  int i,j;

  if (p == NULL)
    return;
  for (i = 0; i < p->numChaves; i++)
    salvar(p, p->contato);
  for (j = 0; j <= p->numChaves; j++)
    saveAux(p->apontador[j], Nivel + 1);
}


#endif


