#include<stdio.h>
#include<stdbool.h>


typedef struct{
	
	union{
		int inteiro;
		float dupla;
		char *nome;
	};
	
}Fila;


#define TAM 5

int fila[TAM];
int topo;
int primeiro; 
int cont = 0;



/*inicia a fila*/
void start()
{
	primeiro = 0;
	topo = -1;	
}

/*Verifica se a fila esta vazia*/
bool isEmpty()
{
	return topo < primeiro;
}

/*Verifica se a fila esta vazia*/
bool isFull()
{
	return topo == TAM;
}

/**/
int delete()
{
	if(!isEmpty())
	{
		int valor = fila[primeiro];
		primeiro++;
		return valor;
	} else{
		return 0;
	}
}

/*Inserir*/
void insert(int valor)
{
	if(!isFull())
	{
		topo++;
		fila[topo] = valor;
		cont++;
	}
}

int quant()
{
		return cont;
}

int main()
{
	start();
	insert(15);
	
	
	printf("%d ", delete());
	
	return 0;
}
