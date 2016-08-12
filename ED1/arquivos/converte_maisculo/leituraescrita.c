/*
* Sistemas de Informação - UNEB 2015.2 - ED I
* Authors: José Diôgo, Wellington Correia, Mateus Nascimento e Paulo Anselmo
*/

#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>

/*Transforma o texto em maiusculo*/
void mudar_texto(FILE *leitura, FILE *escrita){

	char caractere;

	while((caractere  = fgetc(leitura)) != EOF){
		caractere = toupper(caractere);
		fputc(caractere, escrita);
	}
}


int main(int argc, char *argv[]){
	
		/*arquivos para leitura e escrita*/
		FILE *leitura;
		FILE *escrita;
		
		/*inicialização dos arquivos*/
		leitura = fopen("texto.txt", "r");
		escrita = fopen("modificado.txt","w");
		
		if(leitura == NULL) printf("Arquivo não encontrado.");
		else mudar_texto(leitura, escrita);
	
		return 0;
}
