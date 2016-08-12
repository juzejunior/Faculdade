#include<stdio.h>
#define TAM 10

char pilha[TAM];

int topo = -1;

int is_full()
{
	if(topo >= TAM){
		return 1;		
	}else{
		return 0;
	}
}

int total()
{
	return topo+1;
}

int is_empty()
{
	if(topo < 0)
	{
		return 1;
	}else{
		return 0;
	}
}

int push(char letra)
{
	if(!is_full())
	{
		topo++;
		pilha[topo] = letra;
		return 1;
	}else{
		return 0;
	}
}

char pop()
{
	if(!is_empty())
	{
		int retorno = pilha[topo];
		topo--;
		return retorno;
	}else{
		return 0;
	}
}

char top()
{
	if(!is_empty())
	{
		return pilha[topo];
	}else{
		return '0';
	}
}

int troca(int n)
{
	char guarda_topo, valor_troca, aux[TAM];
	int i = 0, cont = 1;
	/*se a pilha tiver menos que n elementos*/
	if(topo+1 < n) return 0;

	/*guardando o valor do topo*/
	guarda_topo = pop();
	
	while(cont < n)
	{
		if(cont == n-1){
			valor_troca = pop();
		}else{
			aux[i] = pop();
			i++;
		}
		cont++;
	}
	
	while(cont >= 1)
	{
		if(cont == n){
			push(guarda_topo);
		}else if(cont == 1)
		{
			push(valor_troca);
		}else{
			push(aux[i]);
		} 
		i--;
		cont--;
	}
	
	while(topo >= 0) printf("%c \n", pop());
	return 1;
}


int main()
{
	push('E');
	push('K');
	push('H');
	push('R');
	push('Y');
	push('D');
		
	troca(5);	
		
	return 0;
}
