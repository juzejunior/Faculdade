#include <stdio.h>
#include <unistd.h>


int main()
{
	FILE *file = fopen("fork.c","r+");
	int descriptor = fileno(file);
	
	printf("%d", descriptor);
	//duplicando em outra posiçao do descritor de arquivos
	dup2(descriptor, 4);
	
	
	return 0;
}

void error(char *msg){
	
	fprintf(stderr,"%s: %s",msg, strerror(errno));
	exit(1);
}

