#include <stdio.h>
#include "arvoreB2.h"
#include "arvoreB.h"
#include "contato.h"
int main(){
Apontador *A;
Contato B;
inicializa2(&A);	
char x;
char x2[20]; 
	while(1){
		printf("Escolha o tipo de telefone para as operações\n\n[1]Celular [2]Comercial [3]Residencial");
		scanf(" %d",&flag);
		printf("[1] Inserir [2] Buscar [3]Remover");
		scanf(" %c",&x);
		system("clear");
		if(x == '1'){
			//Colocar um cadastro
			insere2(B,&A,flag);
		}else if(x == '2'){
			//colocar pelo menos o]
			printf("Digite o numero a ser buscado, caso nao haja resultado nehum sera mostrado"); 
			if(flag == 1){scanf(" %s",B.telCelular);}else if(flag == 2){scanf(" %s",B.telComercial);}else{scanf(" %s",B.telResidencial);}
			Busca2(B,A,flag);	
		}else{
			printf("Digite o numero a ser removido"); 
			scanf(" %s",x2);
			if(flag == 1){
				Retira2(x2,&A);
				
			}else if(flag == 2){
				Retira2(x2,&A);
				
			}else{
				Retira2(x2,&A);
				
			}
		}
	}
}
