#include <stdlib.h>
#include <stdio.h>
#include "../include/arquivo.h"
#include "../include/funcoesBusca.h"

int main(int argc, char **argv)
{
	//ler a quantidade de linhas e colunas que a matriz terá
	dimensaoMatriz(&linhas,&colunas);
	//aloca o espaço na matriz
	matriz = alocaMatriz(linhas, colunas);
	//atribui o diagrama a matriz
	lerDiagrama(matriz);
	//função que pega as palavras a serem buscadas
	lerPalavra(totalPalavras,todasPalavras);
	//procure pelas palavras *ADICIONAR A BUSCA COM THREAD**
	resolver();		//resolvendo por thread
	//exibe a matriz modificada no console
	imprimirConsole(matriz, linhas, colunas);
	//salva a matriz modificada no arquivo resultado
	imprimirArquivo(matriz,linhas,colunas);

	return 0;
}
