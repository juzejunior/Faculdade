#ifndef ORDENACAO_H
#define ORDENACAO_H
#include <sys/time.h>
#include "registro.h"

/*Ordenacao por inserção*/
int ordInsercao(int n, reg r[])
{	
	int i,j;
	reg x;
	int inte = 0;
	
	for(j = 1; j < n; j++)
	{
		x = r[j];
		for(i = j-1; i >= 0 && r[i].chave > x.chave; i--)
		{
			r[i+1] = r[i];
			inte++;
		}
		r[i+1] = x;
	}
	
	return inte;
}

int ordSelecao(int tam, reg r[]){
	
	int i, j, min;
	reg aux;
	int inte = 0;
	
	for (i = 0; i < (tam-1); i++){
	    min = i;
	    for (j = (i+1); j < tam; j++) {
	    	if(r[j].chave < r[min].chave) 
	        min = j;
	        inte++;
	    }
	    if (i != min) {
	    	aux = r[i];
	    	r[i] = r[min];
	    	r[min] = aux;
	    	inte++;
	    }
	}
	return inte;
}

/*Ordenacao com heap*/
void ordHeap(int n, reg r[], int *cont)
{
	int i = n/2;
	int pai, filho;
	reg t;
	
	for(;;)
	{
		if( i > 0){
			i--;
			t = r[i];
		}else{
			n--;
			if(n == 0) return;
			t = r[n];
			r[n] = r[0];
		}
		pai = i;
		filho = i * 2 + 1;
		
		while(filho < n)
		{
			if((filho + 1 < n) && (r[filho + 1].chave > r[filho].chave))
			{
				filho++;
			}
			if(r[filho].chave > t.chave){
				r[pai] = r[filho];
				pai = filho;
				filho = pai *2+1;
				*cont = *cont + 1;
			}else{
				break;
			}
		}
		r[pai] = t;
	}
}

/*Ordenação por ShellSort*/
int ordShell(int tam, reg r[]) 
{
	int inte = 0;
    int i , j;
    reg valor;
    int gap = 1;
    while(gap < tam) {
        gap = 3*gap+1;
    }
    while ( gap > 1) {
        gap /= 3;
        for(i = gap; i < tam; i++) {
            valor = r[i];
            j = i - gap;
            while (j >= 0 && valor.chave < r[j].chave) {
                r[j + gap] = r[j];
                j -= gap;
                inte++;
            }
            r[j + gap] = valor;
        }
    }
    
    return inte;
}

/*Ordenação por QuickSort*/
int quickSort(int inicio, int fim, int inte, reg r[])
{
   int pivo, i, j, meio;
   reg aux;
   
   i = inicio;
   j = fim;
   
   meio = (int) ((i + j) / 2);
   pivo = r[meio].chave;
   inte = 0;
   do{
      while (r[i].chave < pivo) i = i + 1;
      while (r[j].chave > pivo) j = j - 1;
      
      if(i <= j){
         aux = r[i];
         r[i] = r[j];
         r[j] = aux;
         i = i + 1;
         j = j - 1;
         inte++;
      }
   }while(j > i);
   
   if(inicio < j) inte += quickSort(inicio, j, inte, r);

   if(i < fim) inte += quickSort(i, fim, inte, r); 
   return inte;
}

int ordQuick(int tam, reg r[]){
	int inte;
	inte = quickSort(0, tam+1, 0, r);
	return inte;
}

#endif
