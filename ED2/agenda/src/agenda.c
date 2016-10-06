#include "../include/arvoreB.h"
#include "../include/contato.h"
#include <string.h>
#include <time.h>

#define ARVORE_POR_NOME 1
#define ARVORE_POR_TELEFONE 2 

void menu();
void header();
void pause();
void limparBuffer();
char* now();
void limparTela();
int checkSO();
void opcaoArquivo(int opcao, int tipoArvore);
void inserirMenu(Contato contato);
void inserirMenu2(Contato contato);


Apontador dicionario;

int main()
{	
	int tipoArvore = -1;
	
	header();
	while(tipoArvore != ARVORE_POR_NOME && tipoArvore != ARVORE_POR_TELEFONE)
	{
	  printf("Qual árvore deseja utilizar? (1 - Por nome 2 - Por Telefone): ");
	  scanf("%d", &tipoArvore); 
	}
	limparTela();
	menu(tipoArvore);
	
	return 0;
}

void menu(int tipoArvore)
{
	int opcao = 0;
	
	inicializa(&dicionario);
	
	while(opcao < 1 || opcao > 8)
	{
		header();
		printf(" 	1 - Inserir\n");
		printf(" 	2 - Buscar\n");
		printf(" 	3 - Listar Todos\n");
		printf(" 	4 - Buscar Inteligente\n");
		printf(" 	5 - Listar por contato de trabalho\n");
		printf(" 	6 - Listar por email\n");
		printf("	7 - Excluir\n");
		printf(" 	8 - Sair\n\n");
		printf(" 	Opção: ");
		scanf("%d", &opcao);
		limparTela();
	}
	
	if(opcao == 8)
	{
		printf(" Até mais!\n\n");	
		exit(1);
    }else{
		opcaoArquivo(opcao, tipoArvore);
	} 	
}

void opcaoArquivo(int opcao, int tipoArvore)
{
    Contato contato;
    
    header();
    //choice
    switch(opcao)
    {
		case 1: 
			   if(tipoArvore == ARVORE_POR_NOME)//insere em arvore por nome
				{inserirMenu(contato);
					printf("entrei aqui!");
			    }
			   else inserirMenu2(contato);//insere na arvore por telefon
			   break;
	   case 2:
			 printf("  Buscar: ");
			 if(tipoArvore == ARVORE_POR_NOME)
			 {
			   scanf(" %[^\n]s", contato.nome);
			   Busca(contato, dicionario);
			 }else{
			   scanf(" %[^\n]s", contato.telCelular);
			   Busca(contato, dicionario);
			 }
			 break;
	   case 3:
	        if(tipoArvore == ARVORE_POR_NOME)
				em_ordem(dicionario);
			else em_ordem2(dicionario);  
			 break;
	   case 4:
			 printf("  Buscar: ");
			  if(tipoArvore == ARVORE_POR_NOME)
			 {
			   scanf(" %[^\n]s", contato.nome);
			   buscaInteligente(contato, dicionario);
			 }else{
			   scanf(" %[^\n]s", contato.telCelular);
			   buscaInteligente2(contato, dicionario);
			 }
			break;
	   case 5:
	        if(tipoArvore == ARVORE_POR_NOME)
				listarTodosComTelTrabalho(dicionario);
			else listarTodosComTelTrabalho2(dicionario);
			break;
	   case 6:
	        printf("  E-mail:  ");
	        scanf(" %[^\n]s", contato.email);
	        if(tipoArvore == ARVORE_POR_NOME) buscaEmail(contato, dicionario);
		    else buscaEmail2(contato, dicionario);
		    break;
	   case 7:
			printf("Excluir: ");
			if(tipoArvore == ARVORE_POR_NOME) 
			{
				scanf(" %[^\n]s", contato.nome);
				Retira(contato.nome, &dicionario);
			}
			else {
			  scanf(" %[^\n]s", contato.telCelular);
			  Retira2(contato.telCelular, &dicionario);	
			}
			break;
	}
	printf("\n");
	pause();
    limparTela();
    menu(tipoArvore);
}

void inserirMenu(Contato contato)
{
	 printf("  Nome: ");
	 scanf(" %[^\n]s", contato.nome);
	 printf("  CPF: ");
	 scanf(" %s", contato.cpf);
	 printf("  Data de nascimento(0/0/0): ");
	 scanf("%d/%d/%d", &contato.dataNascimento.dia, &contato.dataNascimento.mes, &contato.dataNascimento.ano);
	 printf("  Profissão: ");
	 scanf(" %[^\n]s", contato.profissao);
	 printf("  E-mail: ");
	 scanf(" %s", contato.email);
	 printf("  Celular: ");
	 scanf(" %[^\n]s", contato.telCelular);
	 printf("  Tel Comercial: ");
	 scanf(" %[^\n]s", contato.telComercial);
	 printf("  Tel Residencial: ");
	 scanf(" %[^\n]s", contato.telResidencial);
	 //cadastre o novo contato
	 insere(contato, &dicionario, 1);
}

void inserirMenu2(Contato contato)
{
	 printf("  Nome: ");
	 scanf(" %[^\n]s", contato.nome);
	 printf("  CPF: ");
	 scanf(" %s", contato.cpf);
	 printf("  Data de nascimento(0/0/0): ");
	 scanf("%d/%d/%d", &contato.dataNascimento.dia, &contato.dataNascimento.mes, &contato.dataNascimento.ano);
	 printf("  Profissão: ");
	 scanf(" %[^\n]s", contato.profissao);
	 printf("  E-mail: ");
	 scanf(" %s", contato.email);
	 printf("  Celular: ");
	 scanf(" %[^\n]s", contato.telCelular);
	 printf("  Tel Comercial: ");
	 scanf(" %[^\n]s", contato.telComercial);
	 printf("  Tel Residencial: ");
	 scanf(" %[^\n]s", contato.telResidencial);
	 //cadastre o novo contato
	 insere2(contato, &dicionario, 1);
}

void header()
{
	printf("\n                    Agenda   \n\n");	
}

int checkSO()
{
	#ifdef __unix__
		return 0;
	#elif defined(_WIN32) || defined(WIN32)
		return 1;
	#endif
}

void limparTela()
{
	int SO;
	SO = checkSO();
	if(SO==0) system("clear");
	else system("cls");
	return;
}

/*Retorna data e hora atual*/
char* now()
{
	time_t t;
	time(&t);
	return asctime(localtime(&t));
}

void limparBuffer()
{
	if (checkSO())
	{
		fflush(stdin);
	}else{
		getchar();
	}
}

void pause()
{
	if(checkSO())
		system("pause");
	else
		system("read -p \" Pressione <ENTER> para continuar\" saindo");
}
