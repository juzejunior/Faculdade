#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *somatorio(void *num){
	clock_t tempoInicial, tempoFinal;
	tempoInicial = clock();
	double tempoGasto = 0;
    long int soma=1, aux;
    for(aux = 2; aux <= 10000000; aux++){
        soma +=aux;
    }
    tempoFinal = clock();
    
    tempoGasto = ((tempoFinal-tempoInicial)/(double)CLOCKS_PER_SEC);
    
    printf("Milissegundos: %lf\n", tempoGasto);
}

int main(int argc, char **argv){
    int numThread = atoi(argv[1]);  
    int x, criar=0;
    pthread_t threads[numThread];
    
    for(x = 0; x < numThread; x++){
        criar = pthread_create(&threads[x], NULL, somatorio, NULL);
		
        if(criar != 0){
            printf("Tread Nao Criada!");
            exit(1);
        } 
    }
    for(x = 0; x < numThread; x++){
		pthread_join(threads[x], NULL);
	}

    pthread_exit(NULL);
    
}
