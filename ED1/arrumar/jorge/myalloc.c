#include<stdio.h>

static unsigned char memoria[1024 * 1024];//Declarando memória de 1 MB
static size_t index = 0;

/*my alloc recebe um inteiro positivo*/
void *my_alloc(size_t tamanho)
{
		void *sua_memoria;
		
		/*verificando se há espaço na memória*/
		if(sizeof( memoria - index) < tamanho)
				return NULL;
			
		sua_memoria = &memoria[index];
		index += tamanho;	
		return sua_memoria;	 
}

int main(){
	
	int *p;
	int n,i;
	
	scanf("%d", &n);
	
	p = (int *) my_alloc(n*sizeof(int));
	
	if(p != NULL)
	{
			for(i = 0; i < n; i++)
				scanf("%d", &p[i]);
		
			for(i = 0; i < n; i++)
				printf("%d ", p[i]);
	
	}	
	
	return 0;
}
