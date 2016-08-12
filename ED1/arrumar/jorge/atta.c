#include<stdio.h>
#include<stdlib.h>
#define Alocate 5

int main(int argc, char *argv[])
{
   int *vetor,i,numero,mallocInit;	
   mallocInit = 10, i = 0,numero = 1;
   //aloca o espaco inicial
   vetor = (int*) malloc(mallocInit*sizeof(int));
   if(vetor == NULL) return 1;		
   /*Entrada e realocamento de espaço caso necessário*/
   do{
	   if(i == mallocInit){//se atingiu o nivel maximo de espaco
			vetor = (int*) realloc(vetor, (mallocInit+Alocate)*sizeof(int));//adicione mais 5 espacos livres
			if(vetor == NULL) return 1;
			mallocInit += Alocate;
	   }
	   scanf("%d",&numero);
	   if(numero != 0){
		 vetor[i] = numero;
		 i++;   
	   }
   }while(numero != 0);
   /*Impressão inversa do vetor*/
   for(i = i-1;i >= 0; i--)
	  printf("%d ", *(vetor+i));
   free(vetor);	
   return 0;	
}
