#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

void *multiplicacao(void *num){
	int a;
	a = (int)num;
	printf("a: %d\n multiplica a: %d\n", a, a*2);
}

int main(){
	pthread_t thread;
	int criar;
	int a = 1;
	criar = pthread_create(&thread, NULL, multiplicacao, (void *)a);
	if(criar != 0) printf("Nao criou");
	pthread_exit(NULL);
	return 0;
}
