#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char *argv[], char *envp[]){
	
	/*replicacao do processo atual*/
	pid_t id = fork();
	
	if(id < 0){ 
		printf("Erro durante a replicação\n");
		exit(-1);
	}else if(id > 0){//eh o processo pai
		wait(0);//aguarda o filho responder
	}else{
		execve ("/bin/date", argv, envp) ;//execute algo
		perror("Erro: ");
	}
	
	printf("Bye!");
	
	return 0;
}
