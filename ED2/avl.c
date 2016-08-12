/*
 * Este modulo implementa a estrutura de árvore avl, arvores balanceadas na insercao e remocao
 * Author: José Diôgo
 * Considerando esquerda 1, direita -1 no nivel de balanceamento
 * */
 
#include <stdio.h>
#include <stdlib.h>
 
typedef struct tree{
	int value, bf;
	struct tree *left, *right;	
} tree;

tree* rotacaoDuplaEsquerda(tree *root);
tree* rotacaoDuplaDireita(tree *root);
tree* rotacaoEsquerda(tree *root);
tree* rotacaoDireita(tree *root);
tree* balancearEsq(tree *root);


/*Insere os elementos na árvore*/
void add(tree **root, int value)
{
	//caso nao haja elementos, adicione na raiz
	if(*root == NULL)
	{
		*root = (tree*) malloc(sizeof(tree));
		if(root != NULL){
			(*root)->value = value;
			(*root)->left = (*root)->right = NULL;
			(*root)->bf = 0;
		}else exit(-1);
	}
	else if(value < (*root)->value)//se menor, va para esquerda	
	{
		add(&(*root)->left, value);
		//verifica se o nó raiz esta balanceado
		switch((*root)->bf)
		{	
			case 0: (*root)->bf = 1;//caso esteja balanceada fica mais alta a esquerda
					break;
			case 1: (*root)->bf = 0;//caso esteja alta a direita, balanceia
					break;
			case -1:   *root = balancearEsq(*root);//faça a rotação para balancear
					break;
		}
	}
	else if(value > (*root)->value)//se maior, va para direita
	{
		add(&(*root)->right, value);
		//verifica se o nó raiz esta balanceadod
	}
}
/*balancear o lado esquerdo*/
tree* balancearEsq(tree *root)
{
	tree *left = root->left;
	if(left->bf == 1)  return rotacaoDireita(root);
	else if(root->left->bf == -1) return rotacaoDuplaDireita(root);
	return NULL;
}
/*Percurso ERD*/
void erd(tree *root)
{
	if(root != NULL)
	{
		erd(root->left);
		printf("%d ", root->value);
		erd(root->right);
	}
}

/*Busca*/
void busca(tree *root, int value)
{
	int static i = 1;//static, nao reinicia o valor :)

	if(root == NULL) printf("Numero inexistente :(");
	else if(root->value == value){
		printf(" Encontrei! Em: %d\n", i);
		return;
	}else if(value < root->value){
		i++;
		busca(root->left, value);
	}else if(value > root->value){
		i++;
		busca(root->right, value);
	}
}
/*Rotaçao para direita*/
tree* rotacaoDireita(tree *root){
	
	tree *new_root = root->left;
	//se possuir filhos na direita, adicione-os a esquerda da antiga raiz
	if(new_root->right != NULL) root->left = new_root->right;
	else root->left = NULL;
	
	new_root->right = root;
	return new_root;
}
/*Rotaçao para esquerda*/
tree* rotacaoEsquerda(tree *root){
	
	tree *new_root = root->right;	
	//se possuir filhos na esquerda, adicione-os a direita da antiga raiz
	if(new_root->left != NULL) root->right = new_root->left;
	else root->right = NULL;
	
	new_root->left = root;
	return new_root;
}

/*Rotacao dupla para a direita*/
tree* rotacaoDuplaDireita(tree *root){

	tree *root_left = root->left;
	tree *new_root = root_left->right;
	//se tiver filhos a esquerda, deixe que o root_right herde-os
	if(new_root->left != NULL) root_left->right = new_root->left;
	else root_left->right = NULL;
	//o inverso
	if(new_root->right != NULL) root->left = new_root->right;
	else root->left = NULL;
	
	new_root->left = root_left;
	new_root->right = root;
	
	return new_root;
}

/*Rotacao dupla para a esquerda*/
tree* rotacaoDuplaEsquerda(tree *root){

	tree *root_right = root->right;
	tree *new_root = root_right->left;
	//se tiver filhos a esquerda, deixe que o root_right herde-os
	if(new_root->left != NULL) root_right->right = new_root->left;
	else root_right->right = NULL;
	//o inverso
	if(new_root->right != NULL) root->left = new_root->right;
	else root->left = NULL;
	
	new_root->left = root->left;
	new_root->right = root;
	
	return new_root;
}



