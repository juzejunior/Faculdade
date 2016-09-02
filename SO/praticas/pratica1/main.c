#include <stdio.h>

int main(){
	printf("Informacoes da CPU:");
	system("cat /proc/cpuinfo");

	printf("Informacoes da Memoria:");
	system("cat /proc/meminfo");

	printf("Informacoes da Rede:");
	system("ifconfig");
	return 0;
}
