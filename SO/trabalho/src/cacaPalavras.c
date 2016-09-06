#include <stdlib.h>
#include <stdio.h>
#include "../include/arquivo.h"

#define totalPalavras 6

int main(int argc, char **argv)
{
	int linhas=0,colunas=0;
	char **matriz, palavras[totalPalavras][100];
	//ler a quantidade de linhas e colunas que a matriz terá
	dimensaoMatriz(&linhas,&colunas);
	//aloca o espaço na matriz
	matriz = alocaMatriz(linhas, colunas);
	//atribui o diagrama a matriz
	lerDiagrama(matriz);
	//função que pega as palavras
	lerPalavra(totalPalavras,palavras);
	
	return 0;
	
}
