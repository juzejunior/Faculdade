#include<stdio.h>
#include<stdlib.h>

#define aproximacao 0.00001

double rq(double n){
	
	double raiz, raiz_ante;
	raiz = n/2;
	
	do{
		raiz_ante = raiz;
		raiz = (raiz*raiz + n) / (2*raiz);
	}while(abs(raiz-raiz_ante) > aproximacao);
	
	return raiz;
}

int main(){

	double number = 25;
	
	printf("Raiz quadrada = %.2lf\n", rq(number));

	return 0;
}
