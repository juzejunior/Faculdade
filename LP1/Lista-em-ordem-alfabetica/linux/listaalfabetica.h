#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct List{
	char name[30];
	struct List *next;
}List;

/*Essa função insere um nome na lista em ordem alfabética*/
bool insert(List **init_List, char name[])
{
	/*se não houver elementos na lista*/
	if(*init_List == NULL)
	{
		*init_List = (List*) malloc(sizeof(List));//inicializando
		if(*init_List != NULL)//se conseguiu alocar
		{
			strcpy((*init_List)->name, name);//guarde o nome na primeira posição da lista
			(*init_List)->next = NULL;//sete o proximo elemento como nulo
			return true;	
		}
	}else//se ja houver elementos na lista
	{
		List *p = *(init_List);
		List *anterior = p;
		List *new_node = (List*) malloc(sizeof(List));
		if(new_node != NULL)
		{	
			strcpy(new_node->name,name);	
				
			if(strcmp(new_node->name, p->name) <= 0 && p == *(init_List))
			{
			    //se for menor do que o primeiro elemento insira no inicio da lista	
				new_node->next = p;
				(*init_List) = new_node;
				return true;
			}
			//se for maior que o primeiro elemento continue procurando na lista	
			while(p != NULL){						
					if(strcmp(new_node->name, p->name) <= 0)//se o elemento é menor ou igual
					{
						anterior->next = new_node;
						new_node->next = p;
						return true;
					}
					
				anterior = p;//guardando a posição anterior
				p = p->next;
		    }
		    //se não houver elemento maior então insira no fim
		    new_node->next = p;
		    anterior->next = new_node;
		}
	} 
	return false;
}

/*Essa função exclui um elemento na lista a partir do nome informado*/
bool delete(List **init_List, char name[])
{
	if(*init_List == NULL){
		printf("	A lista está vazia :(\n");
		return false;//se a lista estiver vazia retorne falso
	} 
	
	List *p = *(init_List);
	List *trash;
	List *anterior;
	
	while(p != NULL)
	{
		if(strcmp(p->name, name) == 0)//se achou o nome a ser excluido
		{
			if(p == *(init_List))//se for o primeiro elemento
			{
				trash = p;
				(*init_List) = p->next;
				free(trash);
			}else
			{
				trash = p;
				anterior->next = p->next;
				free(trash);
			}
			return true;
		}
		anterior = p;
		p = p->next;
	}
	
	printf("	Esta pessoa não se encontra na lista :(\n");
	return false;
}

/*Essa função mostra todos os elementos dentro da lista se houver elementos*/
bool show(List *list)
{
	int i = 1;
	List *p = list;
	if(p == NULL) {
		printf("	Ops!  A lista está vazia :(\n\n");
		return false;
	}
	while(p != NULL)
	{
		printf("	%dº: %s\n", i, p->name);
		p = p->next;
		i++;
	}
	return true;
}

bool freeAlocate(List **initList)
{
	if(*(initList) == NULL) return false;
	
	List *p = *(initList);
	List *trash = p;
	
	while(p != NULL)
	{
		trash = p;
		p = p->next;
		free(trash);
	}
	
	return true;
}

