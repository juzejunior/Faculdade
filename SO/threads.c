#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


#define NUM_THREADS 3

/*Cada thread executa esta funçao*/
void *PrintHello(void *threadid)
{
	printf("#%ld: Hello World!\n", threadid);
	pthread_exit(NULL);
}

/*cria as proximas threads*/
int main(int argc, char **argv)
{
	pthread_t threads[NUM_THREADS];//definindo threads
	int i, status;
	
	/*criando threads*/
	for(i = 0; i < NUM_THREADS; i++)
	{
		printf("Thread %d criada!\n", i+1);
		status = pthread_create(&threads[i], NULL, PrintHello, (void *) i);
		
		/*Se algo saiu errado*/
		if(status){
			perror("pthread_create");
			exit(-1);
		}
	}

	return 0;
}
