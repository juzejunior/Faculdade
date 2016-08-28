#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>


int main(int argc, char **argv){
	pid_t filho, filho2, neto1, neto2, bisneto;
	int val, value, value2, value3;
	//creating pipe
	int fd[2], sf[2], st[2], fc[2];
	pipe(fd);
	pipe(sf);
	pipe(st);
	pipe(fc);
	
	filho = fork();

	switch(filho){
		case 0://first child
			 val = getpid() % 10;
			 write(fc[1], &val, sizeof(val));
			 printf("Sou o primeiro filho(pid=%d) e minha soma é %d\n", getpid(), getpid() % 10);
		break;	  	
		default://dad
		    wait(&filho);//sum
		    sleep(2);
		    //create the second child
		    filho2 = fork();
		    switch(filho2){
			  case 0://second child
					neto1 = fork();
					switch(neto1){
					  case 0://first grandson
					    val = getpid() % 10;
					    write(st[1], &val, sizeof(val));
					 	printf("Sou o primeiro neto(pid=%d) e minha soma é %d\n", getpid(), getpid() % 10);
					  break;
					  default:
					    wait(&neto1);
						sleep(2);
						//create the second grandson
						neto2 = fork();
						switch(neto2){
							case 0://neto 2
								bisneto = fork();
								switch(bisneto){
									case 0://bisneto
										printf("Sou o bisneto(pid=%d) e minha soma é %d\n", getpid(), getpid() % 10);
										val = getpid() % 10;
										write(fd[1], &val, sizeof(val));
									break;
									default:
									   sleep(2);//review
									   wait(&bisneto);
									   val = getpid() % 10 + getppid() % 10;
									   write(sf[1], &val, sizeof(val));
									   printf("Sou o segundo filho(pid=%d) e minha soma é %d\n", getppid(), getppid() % 10);
									   printf("Sou o segundo neto(pid=%d) e minha soma é %d\n", getpid(), getpid() % 10);		
									break;
								}
							break;
							default://second child
							    sleep(2);//works
							    wait(&neto2);
							break;
						}
					  break;
					}
			  break;
			  default://dad
			    sleep(2);
				wait(&filho2);
				
				close(fd[1]);
				close(sf[1]);
				close(st[1]);
				// now read the data (will block)
				read(fd[0], &val, sizeof(val));
				read(sf[0], &value, sizeof(value));
				read(st[0], &value2, sizeof(value2));
				read(fc[0], &value3, sizeof(value3));
				printf("Sou o pai(pid=%d) e minha soma é %d", getpid(), val+value+value2+value3);
				// close the read-descriptor
				close(fd[0]);
			  break;	
			}
		break;
	}
	return 0;
}

