/*

g++ deadlock.cpp -o deadlock

./deadlock 


Quantidade de recurso: 3
Quantidade de processos: 3
Quandas ligaçoes: 6
6
1°: R2 P1
2°: R2 P2
3°: P1 R1
4°: R1 P2
5°: P2 R3
6°: R3 P3

----------------------------
	R1	R2	R3	P1	P2	P3	
R1	0	0	0	0	1	0	
R2	0	0	0	1	1	0	
R3	0	0	0	0	0	1	
P1	1	0	0	0	0	0	
P2	0	0	1	0	0	0	
P3	0	0	0	0	0	0	
----------------------------
*/
#include <cstdio>
#include <cstring>
#define MAX 100

#define BRANCO 0
#define CINZA 1
#define PRETO 2

void imprimir ( bool grafo[MAX][MAX], int r, int p )
{
	printf("\n----------------------------\n");

	printf("\t");
	for ( int i = 0 ; i < r ; i++ )
		printf("R%d\t", i+1);
	for ( int i = 0 ; i < p ; i++ )
		printf("P%d\t", i+1);
	printf("\n");

	for ( int i = 0 ; i < r+p ; i++ )
	{
		if ( i < r ) printf("R%d\t", i+1);
		else printf("P%d\t", i-r+1);

		for ( int j = 0 ; j < r+p ; j++ )
			printf("%d\t", grafo[i][j] );

		printf("\n");
	}
	printf("----------------------------\n");
}

void DFS ( bool grafo[MAX][MAX], const int r, const int p )
{
	char cor[r+p];
	int pilha[r+p], pos[r+p], t=0;
	int u, i, ini = 0;
	memset( cor, 0, sizeof(cor) );

	pos[t] = 0;
	pilha[t++] = ini;

	while ( t )
	{
		while ( ( u = pilha[t-1] ) == -1 && t >= 0 ) t-- ;
		if ( t < 0 ) break;
		cor[u] = CINZA;

		for ( i = pos[t-1] ; i < r+p ; i++ )
			if ( grafo[u][i] )
			{
				if ( cor[i] != CINZA) // espaco livre para empilhar
				{
					pos[t-1] = i+1;
					pos[t] = 0;
					pilha[t++] = i;
					break;
				}
				else if ( cor[i] == CINZA ) // ciclo ...
				{
					bool imp = false;
					int interrompido;
					printf("Ciclo: ");
					for ( int k = 0 ; k < t ; k++ ) // identificando o ciclo
						if ( pilha[k] == i || imp )
						{
							imp = true;

							if ( pilha[k] < r ) printf("R%d -> ", pilha[k]+1);
							else printf("P%d -> ", pilha[k]-r+1);
						}

					if ( i < r ) printf("R%d\n", i+1);
					else printf("P%d\n", i-r+1);

					printf("Processo(s) critico(s): ");
					imp = false;
					interrompido = -1;
					for ( int k = 0 ; k < t ; k++ ) // identificando o processo critico
						if ( pilha[k] == i || imp )
						{
							if ( pilha[k] >= r )
							{
								printf("P%d ", pilha[k]-r+1);
								if ( interrompido < 0 )
									interrompido = pilha[k];
							}
							imp = true;
						}
					printf("\n");
					printf("Processo interrompido: P%d\n", interrompido-r+1);
					pilha[interrompido] = -1;
					for ( int k = 0 ; k < r+p ; k++ )
						grafo[k][interrompido] = grafo[interrompido][k] = 0;

					printf("\n\n");
				}
			}

		if ( i == r+p )
		{
			cor[u] = PRETO;
			t--;
			if ( !t )
			{
				while ( ++ini < r+p )
					if ( cor[ini] == BRANCO )
					{
						pilha[t++] = ini;
						break;
					}
			}
		}
	}
}

int main (int argc, char **argv)
{
	bool grafo[MAX][MAX];
	int r, p, aux, x, y;
	char cx, cy;

	memset( grafo, 0, sizeof(grafo) );
	printf("Quantidade de recurso: ");
	scanf("%d", &r);
	printf("Quantidade de processos: ");
	scanf("%d", &p);
	printf("Quandas ligaçoes: ");
	scanf("%d", &aux);
	printf("%d\n", aux );

	for ( int i = 0 ; i < aux ; i++ )
	{
		printf("%d°: ", i+1 );
		scanf(" %c%d %c%d", &cx, &x, &cy, &y );

		if ( cx == 'P' ) x += r;
		if ( cy == 'P' ) y += r;

		grafo[x-1][y-1] = true;
	}

	imprimir( grafo, r, p );
	DFS ( grafo, r, p );
	return 0;
}

