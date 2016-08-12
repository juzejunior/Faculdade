#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct NO{
	char chave[20];
	struct NO *prox;
} NO; 

typedef enum {DIREITA = 0, ESQUERDA} Enum;

/*Essa função insere uma palavra na lista*/
int insert(NO *node, char word[]);
int walk(NO *node, int direcao,char chave[], int n);

int main(int argc, char *argv[])
{
	NO *f = (NO*) malloc(sizeof(NO));
	f->prox = NULL;
	insert(f,"BAT");
	insert(f,"CAT");
	insert(f,"EAT");
	
	walk(f,ESQUERDA,"EAT", 2);
	
	return 0;
}

int insert(NO *node, char word[])
{
	NO *p = node;
	
	if(p != NULL)
	{	
		NO *new_node = (NO*) malloc(sizeof(NO));
		if(new_node != NULL)
		{
			while(p->prox != NULL) p = p->prox;
			strcpy(new_node->chave, word);
			new_node->prox = p->prox;
			p->prox = new_node;
			return 1;
		}
	}
	
	return 0;
}

int walk(NO *node, int direcao,char chave[], int n)
{
	NO *p = node->prox;
	NO *inicio = node;
	int cont = 0, cont2 = 0;
	
	while(strcmp(p->chave, chave) && p->prox != NULL){
		p = p->prox;
		cont++;
	} 
	/*se a palavra procurada nao estiver no ultimo elemento quer dizer que não existe a palavra*/
	if(strcmp(p->chave, chave) != 0) return 0;
	
	switch(direcao)
	{
		case DIREITA:
				while(p->prox != NULL && cont2 < n)
				{
					p = p->prox;
					cont2++; 
				}
				
				if(cont2 == n){
					printf("O elemento a %d posição(ões) a direita da palavra %s é %s.\n",n,chave,p->chave);
					 return 1;
				}else{
					printf("Não consegui andar");
					return 0;
				}
		break;
		case ESQUERDA: 
				
			cont = cont - n;	
			
			if(cont < 0)
			{
				printf("Não foi possivel percorrer!");
				return 0;
			}else{
				while(cont >= 0)
				{
					cont--;
					inicio = inicio->prox;
				}
					
				printf("O elemento a %d posição(ões) a esquerda da palavra %s é %s.\n",n,chave,inicio->chave);
			}	
		
		break;
	}
	
	return 0;
}
