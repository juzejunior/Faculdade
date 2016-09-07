#include <stdlib.h>
#include <stdio.h>
#include "../include/arquivo.h"
#include "../include/funcoesBusca.h"

int main(int argc, char **argv)
{
	int linhas=0,colunas=0, posIni, posFinal;
	char **matriz;
	char direcao[5];
	int found;
	//ler a quantidade de linhas e colunas que a matriz terá
	dimensaoMatriz(&linhas,&colunas);
	//aloca o espaço na matriz
	matriz = alocaMatriz(linhas, colunas);
	//atribui o diagrama a matriz
	lerDiagrama(matriz);
	//função que pega as palavras a serem buscadas
	lerPalavra(totalPalavras,todasPalavras);
	//procure pelas palavras *ADICIONAR A BUSCA COM THREAD**
	//organizarThreads();
	buscaPalavra(matriz,"processos", &posIni, &posFinal, direcao, linhas, colunas);

	return 0;
}
