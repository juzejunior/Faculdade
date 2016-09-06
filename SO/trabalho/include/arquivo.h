#ifndef _ARQUIVO_H
#define _ARQUIVO_H

#include <stdio.h>
#include <stdlib.h>

void domencao(int *linhas, int *colunas){
	FILE *arquivo;
	int cont,x=0,y=0;
	arquivo = fopen("diagrama.txt","r");
	fscanf(arquivo,"%d %d",linhas,colunas);
	fclose(arquivo);
}


void leitura(char vet[][]){
	char ch;
	FILE *arquivo;
	int cont,x=0,y=0,linhas,colunas;
	arquivo = fopen("diagrama.txt","r");
	fscanf(arquivo,"%d %d",&linhas,&colunas);
	//char vet[linhas+2][colunas];
	//printf("%d %d", linhas, colunas);
	while((	ch = fgetc(arquivo)) != EOF ){
		if(ch != '\n'){
			vet[x][y] = ch;
				y++;
		}else{ 
			x++;
			y = 0;
		}if(x == linhas+3){
			break;
		}
	}	
	fclose(arquivo);	
	
}

#endif
