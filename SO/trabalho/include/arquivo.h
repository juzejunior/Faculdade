#ifndef _ARQUIVO_H
#define _ARQUIVO_H

#include "funcoesBusca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void lerPalavra(int totalPalavra, char palavras[][100]){
  	FILE *arquivo;
  	int x = 0;
 	int i;
  	char a[100];
 	char ch;
 	char palavra[50];
  	arquivo = fopen("../src/data/diagrama.txt","r");
  	//Ler até onde começa as palavras
  	while (x<18)
  	{
  		fgets(a, 100, arquivo);	
  		x++;
  	}	
  	//Atribui as palavras a matriz "palavras"
  	x=0;
 	while (x < totalPalavra)
  	{
 		fgets(palavras[x], 100, arquivo);	
 		fscanf(arquivo,"%s", palavras[x]);
  		x++;
  	}
 	fclose(arquivo);	
}

void imprimirArquivo(char **matriz, int linhas, int colunas){
 	FILE *arquivo;
 	int x,y;
 	arquivo = fopen("data/resultado.txt","w");
 	fprintf(arquivo,"%d %d\n\n", linhas, colunas);
 	for(x = 0; x < linhas; x++){
 		for(y = 0; y < colunas; y++){
 			fputc(matriz[x][y],arquivo);		
 		}
 		fputc('\n',arquivo);	
 	}
	fclose(arquivo);
}

void imprimirConsole(char **matriz, int linhas, int colunas)
{
	int i,j;
	printf("%d %d\n\n", linhas, colunas);
	for(i = 0; i < linhas; i++)
	{
		for(j = 0; j < colunas; j++)
		{
			if(isupper(matriz[i][j]))
			{
				printf("%c", matriz[i][j]);
			}else{
				printf("%c", matriz[i][j]);
			}
			if(j % 59 == 0 && j != 0) printf("\n");
		}
	}
}
#endif
