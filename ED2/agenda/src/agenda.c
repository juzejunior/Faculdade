#include "arvoreB.h"
#include "contato.h"
#include <string.h>
#include <time.h>

void menu();
void header();
void pause();
void limparBuffer();
char* now();
void limparTela();
int checkSO();
void opcaoArquivo(int opcao);

Apontador dicionario;

int main()
{	
	inicializa(&dicionario);
	
	menu();
	
	return 0;
}

void menu()
{
	int opcao = 0;
	
	while(opcao < 1 || opcao > 7)
	{
		header();
		printf(" 	1 - Inserir\n");
		printf(" 	2 - Buscar\n");
		printf(" 	3 - Listar Todos\n");
		printf(" 	4 - Buscar por Letra\n");
		printf(" 	5 - Listar por contato de trabalho\n");
		printf(" 	6 - Listar por email\n");
		printf(" 	7 - Sair\n\n");
		printf(" 	Opção: ");
		scanf("%d", &opcao);
		limparTela();
	}
	
	if(opcao == 7)
	{
		printf(" Até mais!\n\n");	
		exit(1);
    }else{
		opcaoArquivo(opcao);
	} 	
}

void opcaoArquivo(int opcao)
{

	/*int op, inicial, final, ite, tipo_ordenacao;
	double tempo;
	FILE *file;
	reg vetor[TAM];
	ite = 0;
	tipo_ordenacao = 0;
	
	while(op < 1 || op > 3)
	{
		header();
		printf(" Qual o tipo de arquivo deseja ordenar: 1- Inverso 2 - Ordenado 3- Aleatório\n\n Opção: ");
		scanf("%d", &op);
		limparTela();
	}
	// abrindo o arquivo 
	if(op == 1)  file = fopen("inverso.txt", "r");
	else if(op == 2) file = fopen("ordenado.txt", "r");
	else if(op == 3) file = fopen("aleatorio.txt", "r");

	if(file == NULL)
	{
		printf(" Arquivo inexistente!\n\n");
		pause();
	}else
	{	
		carregarReg(file, vetor, TAM);//carrega os registros na memória
	   	
	   	limparTela();
	   	header();
		printf(" Deseja testar a estabilidade?(1-sim, 2-nao)\n\n Opção: ");
		scanf("%d", &tipo_ordenacao);		
		   	
	   	switch(opcao)
	   	{
			case 1: 
					inicial = clock();
					ite = ordInsercao(TAM, vetor);
					final = clock();
					if(tipo_ordenacao == 1) ordInsercaoSecond(TAM, vetor); 
					
			        break;
			case 2: 
					inicial = clock();
					ite = ordSelecao(TAM, vetor);
			        final = clock();
			  		if(tipo_ordenacao == 1) ordSelecaoSecond(TAM, vetor); 
			  		
			        break;
			case 3: 
					inicial = clock();
					ordHeap(TAM, vetor, &ite);
			        final = clock();
			        if(tipo_ordenacao == 1) ordHeapSecond(TAM, vetor, &ite);
			        break;
			case 4: 
					inicial = clock();
					ite = ordShell(TAM, vetor);
			        final = clock();
			        if(tipo_ordenacao == 1) ordShellSecond(TAM, vetor);
			        break;
			case 5: 
					inicial = clock();
					ite = ordQuick(TAM, vetor, 1);
					final = clock();
					if(tipo_ordenacao == 1) ordQuick(TAM, vetor, 2);
					break;
		}
		
		tempo = (final - inicial) * 1000.0 / (double) CLOCKS_PER_SEC;
		limparTela();
		exibir(vetor, op, ite,tempo);
		pause();
		limparTela();
		menu();
	}*/
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
