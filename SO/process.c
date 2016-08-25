#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

int sum  = 0;

void soma(pid_t pid);

int main(int argc, char **argv)
{
	pid_t filho, filho2, neto1, neto2, bisneto;
	static int vida;
	
	filho = fork();
	
	switch(filho)
	{
		case 0://first child
			 printf("Sou o primeiro filho(pid=%d) e minha soma é %d\n", getpid(), getpid() % 10);
		break;	  	
		default://dad
		    soma(wait(&filho));//sum
		    sleep(2);
		    //create the second child
		    filho2 = fork();
		    switch(filho2)
		    {
			  case 0://second child
					neto1 = fork();
					switch(neto1)
					{
					  case 0://first grandson
					 	printf("Sou o primeiro neto(pid=%d) e minha soma é %d\n", getpid(), getpid() % 10);
					  break;
					  default:
					    soma(wait(&neto1));
						sleep(2);
						//create the scond grandson
						neto2 = fork();
						switch(neto2)
						{
							case 0://neto 2
								bisneto = fork();
								switch(bisneto)
								{
									case 0://bisneto
										printf("Sou o bisneto(pid=%d) e minha soma é %d\n", getpid(), getpid() % 10);
									break;
									default:
									   soma(wait(&bisneto));
									   printf("Sou o segundo filho(pid=%d) e minha soma é %d\n", getppid(), getppid() % 10);
									   printf("Sou o segundo neto(pid=%d) e minha soma é %d\n", getpid(), getpid() % 10);		
									   //vida = sum+getppid() % 10 + getpid()%10;	
									break;
								}
							break;
							default://second child
							    soma(wait(&neto2));
							break;
						}
					  break;
					}
			  break;
			  default://dad
				soma(wait(&filho2));
				printf("Sou o pai(pid=%d) e minha soma é ", getpid());
			  break;	
			}
		break;
	}
	
	return 0;
}

void soma(pid_t pid)
{
	sum += pid % 10;
}
