#include<stdio.h>
#include "encrypt.h"
#include "checksum.h"

int main(int argc, char argv[]){

	char nome[] = "José Diôgo";
	encrypt(nome);
	printf("Meu nome encriptado: %s\n", nome);
	printf("Checksum vale: %d\n", checksum(nome));
	encrypt(nome);
	printf("Meu nome descriptografado: %s\n", nome);
	printf("Checksum vale: %d\n", checksum(nome));

	return 0;
}