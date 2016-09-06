#ifndef _ARQUIVO_H
#define _ARQUIVO_H

#include <stdio.h>
#include <stdlib.h>

void dimensaoMatriz(int *linhas, int *colunas){
	FILE *arquivo;
	arquivo = fopen("../src/data/diagrama.txt","r");
	fscanf(arquivo,"%d %d",linhas,colunas);
	fclose(arquivo);
}

char **alocaMatriz(int linhas, int  colunas)
{
   int x;
   char **v;
   v =  (char**) malloc((linhas) * sizeof(char*));
   // percorre as linhas alocadas na matriz
   for (x = 0 ; x < linhas; x++) {
      v[x] = (char*) malloc(colunas+1 * sizeof (char));
   }
   // retorna o ponteiro de ponteiros(matriz).
   return v;	
}

void lerDiagrama(char **matriz)
{
	char ch;
	FILE *arquivo;
	int linhas,colunas;
	int i,j;
	
	arquivo = fopen("../src/data/diagrama.txt","r");
	fscanf(arquivo,"%d %d",&linhas,&colunas);
	fscanf(arquivo,"%c", &ch);
	fscanf(arquivo,"%c", &ch);
	
	for(i = 0; i < linhas; i++)
	{
		for(j = 0; j < colunas+1; j++)
		{
			ch = fgetc(arquivo);
			if(ch != '\n') matriz[i][j] = ch;
		}
	}
	fclose(arquivo);	
}

void lerPalavra(int totalPalavras, char palavras[][100]){
	FILE *arquivo;
	int x = 0;
	char a[100];
	arquivo = fopen("../src/data/diagrama.txt","r");
	//Ler até onde começa as palavras
	while (x<19)
	{
		fgets(a, 100, arquivo);	
		x++;
	}
	
	//Atribui as palavras a matriz "palavras"
	x=0;
	while (x<totalPalavras)
	{
		fgets(palavras[x], 100, arquivo);	
		x++;
	}
	
	fclose(arquivo);
	
}
#endif
