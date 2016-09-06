#include <stdlib.h>
#include <stdio.h>
#include "../include/arquivo.h"

int main(int argc, char **argv)
{
	int linhas=0,colunas=0,i,j;
	char **matriz;
	//ler a quantidade de linhas e colunas que a matriz terá
	dimensaoMatriz(&linhas,&colunas);
	//aloca o espaço na matriz
	matriz = alocaMatriz(linhas, colunas);
	//atribui o diagrama a matriz
	leitura(matriz);
	
	for(i = 0; i < linhas; i++)
	{
		for(j = 0; j < colunas; j++)
		{
			printf("%c", matriz[i][j]);
		}
	}
	
	return 0;
	
}
