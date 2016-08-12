#include<stdio.h>
#include<stdlib.h>
#include "ponto.h"

int main(){
	
	float distancia;
	Ponto *p,*p2;

	p = cria_ponto(10,21);
	p2 = cria_ponto(7,25);

	distancia = distancia_ponto(p,p2);
	
	printf("A distância entre os dois pontos criados: %.2f/n", distancia);
	
	libera_ponto(p);
	libera_ponto(p2);

	return 0;
}
