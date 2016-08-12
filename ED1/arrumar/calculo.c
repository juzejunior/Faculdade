#include<stdio.h>

/*Parametros void para que qsort receba um ponteiro para qualquer tipo de dado*/
int ordem_crescente(const void* num1, const void* num2){
	
	int a = * (int*) num1;/*Converte para inteiro*/
	int b = * (int*) num2;/*Converte para inteiro*/
	
	return a - b;
}

int main(){
		int numeros[] = {50,12,9,100,200,400,1000};//cria um vetor de inteiros
		int i;

		qsort(numeros,7,sizeof(int),ordem_crescente);//Aqui a função qsort ordena os numeros dentro do vetor
													 //em ordem crescente
		/*Exibe o vetor já arrumado*/
		for(i = 0; i < 7;i++){
			printf("%d ",numeros[i]);
		}
		
		return 0;
}



















/*int main(){
	double a,b,c,delta,r1,r2;
	scanf("%lf %lf %lf",&a,&b,&c);
	delta = pow(b,2) - 4*a*c;
	printf("Delta = %lf\n",delta);
	delta = sqrt(delta);
	
	if(a != 0 && delta >= 0){
		r1 = (-b + delta) / 2*a;
		r2 = (-b - delta) / 2*a;
		printf("R1 = %.5lf\n",r1);
		printf("R2 = %.5lf\n",r2);
	}else{
		printf("Impossivel calcular\n");
	}
	return 0;	
}*/


