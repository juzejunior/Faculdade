#ifndef REGISTRO_H
#define REGISTRO_H
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*registro com dois campos(chave - id, valor)*/
typedef struct reg{
	int chave;
	float valor;
} reg;

/*Responsável por carregar os 1000 registros no vetor*/
void carregarReg(FILE *f, reg r[], int n)
{
	int i = 0;
	while(fscanf(f,"%d %f", &r[i].chave, &r[i].valor) != EOF && i < n)
	{
		i++;
	}
}

/*Gera um arquivo com a chave ordenada e valores aleatórios para o segundo campo*/
void gerarOrdenado(FILE *f, int TAM)
{
	int i;
	float valor;
	srand((unsigned) time(NULL));
	
	for(i = 1; i <= TAM; i++)
	{
		valor  = 100.00 + rand() % 1500;
		fprintf(f,"%d  %.2f\n", i, valor);//o segundo valor esta entre 100 e 1500
	}
}

/*Gera um arquivo com a chave ordenada inversamente e valores aleatórios para o segundo campo*/
void gerarInverso(FILE *f, int TAM)
{
	int i;
	float valor;
	srand((unsigned) time(NULL));
	
	for(i = TAM; i >= 1; i--)
	{
		valor  = 100.00 +rand() % 1500;
		fprintf(f,"%d  %.2f\n", i, valor);//o segundo valor esta entre 100 e 1500
	}
}

/*Esta funcao verifica se um determinado numero já existe no vetor*/
int existeNoVec(int *v, int tam,int num)
{
	int i;
	for(i = 0; i < tam; i++){
		if(v[i] == num) return 1;//true
	}
	return 0;//false
}

/*Gera um arquivo com as chaves aleatórias e valores aleatórios para o segundo campo*/
void gerarAleatorio(FILE *f, int n){
	srand((unsigned)time(NULL));	
	int v[n], i, j;
	float valor;

	for (i=0; i<n+1; i++){
		v[i] = 1 + (rand() % 10);
	}

	for (i=0; i<n+1; i++){
		for (j=0; j<i; j++){
			if (v[i] == v[j]){
				v[i] = 1 + (rand() % 10);
				j = 0;
			}
		}
	}

	for (i=0; i<n; i++){
		for (j=0; j<i; j++){
			if (v[i] == v[j]){
				printf("REPETIU\n");
			}
		}
		valor = 100.00 + (rand() % 1500);
		fprintf(f,"%d  %.2f\n", v[i], valor);
	}
}

/*Exibe os resultados do total de iterações e o tempo de máquina demorado para ordenar*/
void exibir(reg r[], int arquivo, int iteracoes, double tempo)
{
	int i = 0;
	//FILE *f = fopen("num_ordenado.txt","a");
	
	printf("\n\n");
	
	while(i < 1000)
	{
		/*caso o arquivo desejado seja o aleatório, imprima linear*/
		if(arquivo == 3) printf("	 %dº %.2f\n", r[i].chave, r[i].valor);
		else{//caso nao, imprima em par
			if(i % 2 == 0) printf("	 %dº %.2f", r[i].chave, r[i].valor);
			else printf("	%dº %.2f\n\n", r[i].chave, r[i].valor);
		}
		i++;
	}
	//exibe o total de iteracoes e o tempo em milisegundos para ordenar
	printf(" Total de iterações: %d Tempo: %.2lf ms\n", iteracoes, tempo);
	//fprintf(f,"%d  %.3lf\n", iteracoes,tempo);
	//fclose(f);
}

#endif
