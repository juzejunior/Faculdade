#include<stdio.h>

int main(){
	
		int contador,i,j;
		int a[2] = {3,5};
	    int b[5] = {1,2,3,4,5};
	
		contador = 0;
	
		for(i = 0; i < 2; i++){
			for(j = 0; j < 5; j++){
				if(a[i] == b[j]) contador++;
			}
		}
		
		if(contador == 2) printf("A está contido em B.");
		else printf("A não está contido em B.");

		return 0;
}
