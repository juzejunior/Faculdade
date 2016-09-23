#include "../include/arvoreB.h"

int main(int argc, char **argv){
	
	Apontador dicionario;
	inicializa(&dicionario);
	Contato new;
	strcpy(new.nome,"Welligtinho is gay");
	strcpy(new.cpf,"1222432");
	strcpy(new.profissao,"transexual");
	//strcpy(new.telcelular,"242424");
	insere(new, &dicionario);
	
	
	return 0;
}
