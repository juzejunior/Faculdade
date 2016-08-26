#include "ordenacao.h"
#include "registro.h"
#define TAM 1000

void menu();
void header();
void pause();
void limparBuffer();
char* now();
void limparTela();
int checkSO();
void opcaoArquivo(int opcao);

int main(int argc, char **argv)
{
	menu();
	return 0;
}

void menu()
{
	int opcao = 0;
	
	while(opcao < 1 || opcao > 6)
	{
		header();
		printf(" 	1 - Inserção");
		printf(" 	2 - Seleção\n");
		printf(" 	3 - Heap");
		printf(" 	4 - Shell\n");
		printf(" 	5 - Quick");
		printf(" 	6 - Sair\n\n");
		printf(" 	Opção: ");
		scanf("%d", &opcao);
		limparTela();
	}
	
	if(opcao == 6)
	{
		printf(" Até mais!\n\n");	
		exit(1);
    }else{
		opcaoArquivo(opcao);
	} 	
}

void opcaoArquivo(int opcao)
{
	int op, inicial, final, ite;
	double tempo;
	FILE *file;
	reg vetor[TAM];
	ite = 0;
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
	   	
	   	switch(opcao)
	   	{
			case 1: 
					inicial = clock();
					ite = ordInsercao(TAM, vetor);
					ordInsercaoSecond(TAM, vetor);
					final = clock();
			        break;
			case 2: 
					inicial = clock();
					ite = ordSelecao(TAM, vetor);
			        final = clock();
			        break;
			case 3: 
					inicial = clock();
					ordHeap(TAM, vetor, &ite);
			        final = clock();
			        break;
			case 4: 
					inicial = clock();
					ite = ordShell(TAM, vetor);
			        final = clock();
			        break;
			case 5: 
					inicial = clock();
					ite = ordQuick(TAM, vetor);
					final = clock();
					break;
		}
		tempo = (final - inicial) * 1000.0 / (double) CLOCKS_PER_SEC;
		limparTela();
		exibir(vetor, op, ite,tempo);
		pause();
		limparTela();
		menu();
	}
}

void header()
{
	printf("\n           Algoritmos de Ordenação   %s\n\n", now());	
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

