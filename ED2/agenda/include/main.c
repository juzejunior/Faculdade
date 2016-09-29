#include <stdio.h>
#include "arvoreB2.h"
#include "contato.h"
int main(){
Apontador *A;
Contato B;
strcpy(B.telCelular,"12345");
 inicializa2(&A);	
 insere2(B,&A,1);
 insere2(B,&A,1);
 Busca2(B,A,1);
 Retira2(B.telCelular,&A,1);
 //Busca2(B,A,1);
}
