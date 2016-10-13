#ifndef _MTS_H
#define _MTS_H

#include <stdio.h>
#include <stdlib.h>

void printMatrix(int *matrix, int order);

int *alocaEIncrementa(int ld){
   int x=0,y=0,aux=0;
   int *matriz;
   
   //Alocando matriz e preenchendo com zeros.
    matriz =  (int*) calloc(ld*ld, sizeof(int));
   
	for(y = 0; y < ld; y++){
		matriz[y*ld+y] = (1+rand()%100);
	}
	
	y=0;
	for(x = 0; x < ld; x++){
		aux =(1+rand()%100);
		if(y <= x-1){
			matriz[x*ld+y] = aux;
			matriz[y*ld+x] = aux;
			y++;
		}
	}
	
   return matriz;	
}

void multiplicarMatriz(int *a, int *b, int *c, int ld)
{
	int x, y, z;
	
	for(x = 0; x < ld; x++) {
     for( y = 0; y < ld; y++)
     {   for( z = 0; z < ld; z++) 
			c[x*ld+y] += a[x*ld+z] * b[z*ld+y];
	 }
	}
}

// Função auxiliar que imprime a matriz na tela
void printMatrix(int *matrix, int order) {
	// impressão da matriz toda
	int i, j;
	
	for (i = 0; i < order; i++) {
		printf (" | ");
		for (j = 0; j < order; j++) {
			printf (" %d|", matrix[i * order + j]);
		}
		printf ("\n");
	}
}

#endif
