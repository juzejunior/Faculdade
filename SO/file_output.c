/*
 * Este programa recolhe RSS de sites e redireciona sua saida 
 * */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void error(char *msg){
	
	printf("%s\n",msg);
	exit(1);
}

int main(int argc, char *argv[]){
	
	FILE *f = fopen("stories.txt","w");
	char *feeds[] = {"http://www.cnn.com/rss/celebs.xml", NULL};
	int times = 2;
	char *frase = argv[1];
	int i;
	int pid_status;
	
	if(!f) error("Nao foi possivel criar o arquivo!");
	
	/*clona o processo atual gerando um processo filho*/
	pid_t pid = fork();
	
	if(pid == -1) error("Nao foi possivel criar o processo!");
	
	/*caso seja o processo filho, ou seja, pid = 0*/
	if(!pid){
			char var[255];
			sprintf(var,"RSS_FEED=%s", feeds[0]);	
			char *vars[] = {var, NULL};	
			//alterando a saida padrao do processo
			if(dup2(fileno(f), 1) == -1) error("Impossivel redirecionar a saida padrao");
			
			if(execle("/usr/bin/python", "/usr/bin/python","./rssgossip.py",frase,NULL, vars) == -1){
				error("Cant run script!");
				return 1;
			}		
	}
	
	if(waitpid(pid, &pid_status, 0) == -1) error("Erro esperando pelo processo filho!!");
	
	return 0;
}

