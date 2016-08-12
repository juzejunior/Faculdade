#include<stdio.h>
#include<stdlib.h>

typedef struct arvore
{
	char sigla;
	int value;
	struct arvore *esq,*dir, *prox;
} arvore;

/*utilizada para limpar a tela*/
void limparTela()
{
	system("clear");
}
/*inicializa uma arvore*/
void inicializaArvore(arvore **raiz)
{
	*raiz = NULL;
}
/*verifica se uma arvore ja estive na lista*/
int jaExiste(arvore *raiz, char sigla)
{
	arvore *r = raiz;
	
	while(r != NULL)
	{
		 if(r->sigla == sigla) return 1;
		 r = r->prox;
	}
	
	return 0;
}
/*cria uma nova arvore*/
int criarArvore(arvore **raiz)
{
	int value;
	char sigla;
	arvore *new_node = NULL;
	arvore *r = *raiz;
	arvore *aux = r;
	
	printf("Qual a sigla para a arvore? ");
	scanf(" %c", &sigla);
	printf("Digite um número para a raiz? ");
	scanf("%d", &value);
	new_node = (arvore*) malloc(sizeof(arvore));
	new_node->sigla = sigla;
	new_node->value = value;
	new_node->esq = new_node->dir = new_node->prox = NULL;
	//verificar se a sigla ja existe
	while(aux != NULL)
	{	
		if(aux->sigla == sigla) {
			printf("Essa árvore já existe!\n\n");
			return 0;
		}
		aux = aux->prox;
	}
	//caso nao haja nenhuma arvore criada
	if(r == NULL)
	{
		*raiz = new_node;
		return 1;
	}else{
		while(r->prox != NULL) r = r->prox;
		r->prox = new_node;
		return 1;
	}
}
/*exclui uma arvore*/
int excluirArvore(arvore **raiz)
{
	char sigla;
	arvore *anterior,*trash;
	arvore *r = *raiz;
	anterior = r;
	
	printf("Qual árvore deseja excluir? ");
	scanf(" %c", &sigla);
	
	while(r != NULL)
	{
		if(r->sigla == sigla)
		{
			//se for o primeiro elemento
			if(r == *raiz)
			{
				*raiz = r->prox;
			}else{
				anterior->prox = r->prox; 
			}
			trash = r;
			free(trash);
			printf("Removido com sucesso!\n\n");
			return 1;
		}
		anterior = r;
		r = r->prox;
	}
	printf("Não foi possível remover!\n\n");
	return 0;
}
/*lista todas as arvores*/
void listar(arvore *raiz)
{
	arvore *r = raiz;
	
	if(r == NULL) printf("Não há árvores criadas!");
	
	while(r != NULL)
	{
		printf("  Árvore %c\n", r->sigla);
		r = r->prox;
	}
	printf("\n\n");
}
/*atualizar árvore*/
int atualizarArvore(arvore **raiz)
{
	char sigla, nova_sigla;
	arvore *r = *raiz;
	
	printf("Qual árvore deseja atualizar? ");
	scanf(" %c", &sigla);
	printf("Qual a nova sigla? ");
	scanf(" %c", &nova_sigla);
	
	while(r != NULL)
	{
		if(r->sigla == sigla)
		{
			r->sigla = nova_sigla;
			printf("Atualizado com sucesso!\n\n");
			return 1;
		}
	}
	printf("Não foi possível realizar a atualização!\n\n");
	return 0;
}
/*insere em uma arvore*/
void inserir(arvore **raiz, int value)
{
	if(*raiz == NULL)
	{
		*raiz = (arvore*) malloc(sizeof(arvore));
		(*raiz)->esq = NULL;
		(*raiz)->dir = NULL;
		(*raiz)->value = value;
	}else{
		if(value < (*raiz)->value) inserir(&(*raiz)->esq, value);
		if(value > (*raiz)->value) inserir(&(*raiz)->dir, value);
	}
}


/*remove um determinado dado da arvore*/
int remover(arvore **raiz, int value)
{
	arvore *p,*q;
	/*se a arvore for vazia*/
	if(*raiz == NULL) return 0;
	//caso o valor seja maior va pela direita
	if(value > (*raiz)->value) return remover(&(*raiz)->dir, value);
	//caso seja menor va pela esquerda
	if(value < (*raiz)->value) return remover(&(*raiz)->esq, value);
	//se encontrou o valor
	if(value == (*raiz)->value)
	{
		//se nao tiver filhos desaloque
		if((*raiz)->esq == NULL && (*raiz)->dir == NULL)
		{
			free(*raiz);
			*raiz = NULL;
		}
		else if((*raiz)->esq == NULL)//se nao tiver filhos a esquerda atribua o filho direito no lugar
		{
			p = (*raiz)->dir;
			free(*raiz);
			*raiz = p;
		}
		else if((*raiz)->dir == NULL)//se tiver filhos somente a esquerda atribua o filho esquerdo no lugar
		{
			p = (*raiz)->esq;
			free(*raiz);
			*raiz = p;
		}
		else//tem todos os filhos
		{
			p = (*raiz)->esq;//vamos procurar o maior da arvore esquerda
			q  = NULL;
			while(p->dir != NULL)
			{
				q = p;
				p = p->dir;
			}
			if(q == NULL)//se p e q nao se modificaram
			{
				(*raiz)->esq = p->esq;
				(*raiz)->value = p->value;
				free(p);
			}else{
				q->dir = p->esq;
				(*raiz)->value = p->value;
				free(p);
			}
		}
	}
	
	return 1;
}
//exibe elementos 
/* erd
 * Fixa em ordem
 * */
void exibirEmOrdem(arvore *raiz)
{
	if(raiz != NULL)
	{
		exibirEmOrdem(raiz->esq);
		printf("%d, ", raiz->value);
		exibirEmOrdem(raiz->dir);
	}
}

/*
 * Pre ordem red
 * */
void exibirPreOrdem(arvore *raiz)
{
	if(raiz != NULL)
	{
		printf("%d, ", raiz->value);
		exibirPreOrdem(raiz->esq);
		exibirPreOrdem(raiz->dir);
	}
}
/*
 * Pós fixa edr
 * */
void exibirPosOrdem(arvore *raiz)
{
	if(raiz != NULL)
	{
		exibirPosOrdem(raiz->esq);
		exibirPosOrdem(raiz->dir);
		printf("%d, ", raiz->value);
	}
}
/*exibir parentesada*/
void exibirParentesada(arvore *raiz)
{
	if(raiz != NULL)
	{
		printf("(");
		exibirParentesada(raiz->esq);
		printf("%d", raiz->value);
		exibirParentesada(raiz->dir);
		printf(")");
	}else{
		printf("()");
	}
}
/*utilizada para espelhar uma arvore*/
arvore *espelhar(arvore *raiz)
{
	arvore *nova_arvore;
	
	if(raiz == NULL) return NULL;
	
	nova_arvore = (arvore*) malloc(sizeof(arvore));
	nova_arvore->value = raiz->value;
	
	nova_arvore->esq = espelhar(raiz->dir);
	nova_arvore->dir = espelhar(raiz->esq);
	
	return nova_arvore;
}
/*verifica se uma arvore é simetrica*/
int simetrica(arvore* raiz,arvore* raiz2)
{
  	/*Se ambas forem nulas*/
	if (raiz == NULL && raiz2 == NULL)
		return 1;
	/*se ambas não sao nulas*/
	if (raiz != NULL && raiz2 != NULL)
	{
		return(simetrica(raiz->esq, raiz2->esq) && simetrica(raiz->dir, raiz2->dir));
	}
	return 0;
}
/*contar nós*/
int contarNos(arvore *raiz)
{
	if(raiz == NULL)
		return 0;
	else
		return 1+contarNos(raiz->esq) + contarNos(raiz->dir);
}

/*contar folhas*/
int contarFolhas(arvore *raiz)
{
	if(raiz == NULL)
		return 0;
	if(raiz->esq == NULL && raiz->dir == NULL)
		return 1;
	return contarFolhas(raiz->esq) + contarFolhas(raiz->dir);
}

int maior(int a, int b)
{
   if(a > b) return a;
   return b;	
}

/*calcula o nivel da arvore*/
int altura(arvore *raiz)
{
	if(raiz == NULL || (raiz->esq == NULL && raiz->dir == NULL))
		return 0;
	else 
		return 1 + maior(altura(raiz->esq), altura(raiz->dir));
}

/*libera arvore*/
void liberaArvore(arvore *raiz)
{
	if(raiz != NULL)
	{
		liberaArvore(raiz->esq);
		liberaArvore(raiz->dir);
		free(raiz);
	}
}
/*menu inserir*/
void menuInserir(arvore **raiz)
{
	char sigla;
	int value;
	arvore *r = *raiz;

	printf("  Em qual árvore deseja inserir? ");
	scanf(" %c", &sigla);
	printf("  Qual número deseja inserir? ");
	scanf(" %d", &value);
	
	while(r != NULL)
	{
		if(r->sigla == sigla)
		{
			inserir(&r, value);
			printf("  Inserido com sucesso!\n\n");
			return;
		}
		r = r->prox;
	}
	printf("  Não foi possivel inserir!\n\n");
}
/*menu remover*/
void menuRemover(arvore **raiz)
{
	char sigla;
	int value;
	arvore *r = *raiz;

	printf("  De qual árvore deseja remover? ");
	scanf(" %c", &sigla);
	printf("  Qual elemento deseja remover? ");
	scanf(" %d", &value);
	
	while(r != NULL)
	{
		if(r->sigla == sigla)
		{
			remover(&r, value);
			printf("  Removido com sucesso!\n\n");
			return;
		}
		r = r->prox;
	}
	printf("  Não foi possivel remover!\n\n");
}
/*menu para exibicao infixa*/
void menuInfixa(arvore **raiz)
{
	char sigla;
	arvore *r = *raiz;

	printf("  Qual árvore deseja exibir? ");
	scanf(" %c", &sigla);
	
	while(r != NULL)
	{
		if(r->sigla == sigla)
		{
			exibirEmOrdem(r);
			return;
		}
		r = r->prox;
	}
	printf("  Não foi possivel exibir!\n\n");
}
/*menu para exibicao infixa*/
void menuPrefixa(arvore **raiz)
{
	char sigla;
	arvore *r = *raiz;

	printf("  Qual árvore deseja exibir? ");
	scanf(" %c", &sigla);
	
	while(r != NULL)
	{
		if(r->sigla == sigla)
		{
			exibirPreOrdem(r);
			return;
		}
		r = r->prox;
	}
	printf("  Não foi possivel exibir!\n\n");
}
/*menu para exibicao infixa*/
void menuPosfixa(arvore **raiz)
{
	char sigla;
	arvore *r = *raiz;

	printf("  Qual árvore deseja exibir? ");
	scanf(" %c", &sigla);
	
	while(r != NULL)
	{
		if(r->sigla == sigla)
		{
			exibirPosOrdem(r);
			return;
		}
		r = r->prox;
	}
	printf("  Não foi possivel exibir!\n\n");
}
/*menu para exibicao parentesada*/
void menuParentesada(arvore **raiz)
{
	char sigla;
	arvore *r = *raiz;

	printf("  Qual árvore deseja exibir? ");
	scanf(" %c", &sigla);
	
	while(r != NULL)
	{
		if(r->sigla == sigla)
		{
			exibirParentesada(r);
			return;
		}
		r = r->prox;
	}
	printf("  Não foi possivel exibir!\n\n");
}
/*menu para contar nos de uma arvore*/
void menuContarNos(arvore **raiz)
{
	char sigla;
	arvore *r = *raiz;

	printf("  Em qual árvore? ");
	scanf(" %c", &sigla);

	while(r != NULL)
	{
		if(r->sigla == sigla)
		{
			printf("O total de nós na árvore %c é : %d",sigla,contarNos(r));
			return;
		}
		r = r->prox;
	}
	printf("Não existe nós nesta árvore!");
}
/*menu para contar folhas de uma arvore*/
void menuContarFolhas(arvore **raiz)
{
	char sigla;
	arvore *r = *raiz;

	printf("  Em qual árvore? ");
	scanf(" %c", &sigla);

	while(r != NULL)
	{
		if(r->sigla == sigla)
		{
			printf("O total de folhas na árvore %c é : %d",sigla,contarFolhas(r));
			return;
		}
		r = r->prox;
	}
	printf("  Não existe folhas nesta árvore!");
}
/*menu para contar folhas de uma arvore*/
void menuAltura(arvore **raiz)
{
	char sigla;
	arvore *r = *raiz;

	printf("  Em qual árvore? ");
	scanf(" %c", &sigla);

	while(r != NULL)
	{
		if(r->sigla == sigla)
		{
			printf("A altura da árvore %c é : %d",sigla,altura(r));
			return;
		}
		r = r->prox;
	}
	printf("  Esta árvore não existe!");
}
/*menu para verificar se as arvores são simetricas*/
void menuSimetrica(arvore **raiz)
{
	arvore *r1 = *raiz;
	arvore *r2 = *raiz;
	char sigla;
	
	printf("Qual a primeira árvore? ");
	scanf(" %c", &sigla);
	
	//procurando primeira arvore
	while(r1 != NULL)
	{
		if(r1->sigla == sigla) break;
		r1 = r1->prox;
	}
	printf("Qual a segunda árvore? ");
	scanf(" %c", &sigla);
	//procurando a segunda arvore
	while(r2 != NULL)
	{
		if(r2->sigla == sigla) break;
		r2 = r2->prox;
	}
	
	if(r1 == NULL || r2 == NULL)
	{
		printf("  Uma das árvores não existe!");
		return;
	}else if(simetrica(r1, r2) == 1)
	{
	    printf(" As árvores são simétricas!");
	}else{
		printf(" As árvores não são simétricas!"); 
	}
}
/*menu espelhar*/
void menuEspelhar(arvore **raiz)
{
	arvore *r = *raiz;
	arvore *espelhada = NULL;
	char sigla;
	
	printf("Qual árvore deseja espelhar? ");
	scanf(" %c", &sigla);
	
	while(r != NULL)
	{
		if(r->sigla == sigla)
		{
			espelhada = espelhar(r);
			printf("  Árvore %c: ", sigla);
			exibirParentesada(r);
			printf("\n  Árvore %c espelhada: ",sigla);
			exibirParentesada(espelhada);
			return;
		}
	}
	printf("Essa árvore não existe!");
}
/*barra de navegação*/
void navBar()
{
	printf("  1 - Criar árvore\n  2 - Listar\n  3 - Excluir\n  4 - Atualizar\n");
	printf("  5 - Inserir\n  6 - Remover\n  7 - Exibir infixa \n  8 - Exibir pré-fixa\n  9 - Exibir pós-fixa\n");
	printf(" 10 - Exibir parentesada\n 11 - Contar nós \n 12 - Contar folhas\n 13 - Altura da árvore\n 14 - Simétrica\n 15 - Espelhar\n\n");
}
/*verifica a opcao escolhida*/
void opcoes(arvore **raiz,int opcao)
{	
	switch(opcao)
	{
		case 1:
			criarArvore(raiz);
		break;
		case 2:
			listar(*raiz);
		break;
		case 3:
			excluirArvore(raiz);
		break;
		case 4:
			atualizarArvore(raiz);
		break;
		case 5:
			menuInserir(raiz);
		break;
		case 6:
			menuRemover(raiz);
		break;
		case 7:
			menuInfixa(raiz);
			printf("\n\n");
		break;
		case 8:
			menuPrefixa(raiz);
			printf("\n\n");
		break;
		case 9:
			menuPosfixa(raiz);
			printf("\n\n");
		break;
		case 10:
			menuParentesada(raiz);
			printf("\n\n");
		break;
		case 11:
			menuContarNos(raiz);
			printf("\n\n");
		break;
		case 12:
			menuContarFolhas(raiz);
			printf("\n\n");
		break;
		case 13:
			menuAltura(raiz);
			printf("\n\n");
		break;
		case 14:
			menuSimetrica(raiz);
			printf("\n\n");
		break;
		case 15:
			menuEspelhar(raiz);
			printf("\n\n");
		break;
		case 0:
			printf("  Obrigado por utilizar o sistema!\n\n");
		break;
		default:
			printf("  Opção incorreta!\n\n");
		break;
	}
}
/*menu principal*/
void menuPrincipal(arvore **raiz)
{
	 int opcao = 1;
	 printf("         Arvores\n\n");
	 while(opcao != 0)
	 {
		navBar();
		printf("  Opção: ");
		scanf("%d", &opcao);
		printf("\n");
		opcoes(raiz,opcao);
	 }
}

