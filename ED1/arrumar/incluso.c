#include<stdio.h>
#include<stdlib.h>
#define tamanhoB 5

int main(){
	
	int i,j,n,contador;
	int *a;
	int b[tamanhoB] = {4,1,2,3,7};
	contador = 0;
	
	scanf("%d",&n);
	
	a = (int *) calloc(n,sizeof(int));
	
	for(i = 0; i < n; i++){
		scanf("%d", a+i);
		for(j = 0; j < tamanhoB; j++){
			if(a[i] == b[j]){
				contador++;
				j = tamanhoB;//saindo do loop
			} 	
		}
	}
	
	if(contador == n) printf("O conjunto A está contido em B.");
	else printf("O conjunto A não está contido em B.");
	
	return 0;
}
