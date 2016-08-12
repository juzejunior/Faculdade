#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


#define tamanho_maximo 50
int primeiro,ultimo;
int Fila[tamanho_maximo];

void criaFila(){
	    /*inicia a fila vazia*/
		primeiro = 0;
		ultimo = -1;
}

bool filaVazia(){
	
	return primeiro > ultimo;
	
}

bool filaCheia(){
	
	return ultimo == (tamanho_maximo-1);	
}

bool inserir(int valor){
		/*se a fila n estiver cheia*/
		if(!filaCheia()){
			ultimo++;
			Fila[ultimo] = valor;
			return true;
		}else{
				return false;
		}
}

void remover(){
		
		int valor;	
		valor = Fila[primeiro];
		primeiro++;
}

int primeiroElemento(){
	
	int valor;
			valor = Fila[primeiro];
			return valor;
}
/*verifica o tamanho da fila*/
int tamanho(){
	
	return (ultimo - primeiro)+1;
	
}

int main(){
	
		int n,i;
		
		scanf("%d", &n);
		
		int tiradas[n-1];
		
		criaFila();
		
		for(i = 1; i <= n; i++){
			//se a fila n esta cheia, insira n elementos na fila
			if(!filaCheia()){
				inserir(i);	
		    }		
		}
		
		/*for(i = 0; i < n; i++){
			printf("Fila %dº: %d\n",i+1,Fila[i]);
		}*/
		i = 0;
		while(tamanho() >= 2){				
			
			if(i > 0){
				tiradas[i] = Fila[primeiro+1]; 	
				remover();
			}else{
				tiradas[i] = Fila[primeiro];
				remover(); 	
			}
			
			i++;
		}
	
		for(i = 0; i < 3; i++){
			
		}
		
		return 0;
}
