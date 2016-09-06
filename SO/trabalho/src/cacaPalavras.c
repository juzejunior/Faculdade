#include <stdlib.h>
#include <stdio.h>
#include "../include/arquivo.h"

int main(int argc, char **argv)
{
	int linhas=0,colunas=0;
	char **matriz;
	//ler a quantidade de linhas e colunas que a matriz terá
	dimensaoMatriz(&linhas,&colunas);
	//aloca o espaço na matriz
	matriz = alocaMatriz(linhas, colunas);
	//atribui o diagrama a matriz
	lerDiagrama(matriz);
	//função que pega as palavras
	lerPalavra(totalPalavras,todasPalavras);
	//cria threads e chama a função de busca
	organizarThreads();
	
	return 0;
	
}
