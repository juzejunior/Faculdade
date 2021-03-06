#include <time.h>
#include "include/MTS.h"

int main (int argc, char **argv)
{
	if (argc != 3) {
		printf ("Erro, uso correto: ./program dimension_a dimension_b \n");
		exit(0);
	}

	int x=0, y=0, aux=0;
	int ld;
	int *matrizA, *matrizB, *matrizC;
	clock_t start,end;  // marcar o tempo de execução
	
	ld = atoi(argv[1]);
	srand(time(NULL));
	
	matrizA = alocaEIncrementa(ld);
	matrizB = alocaEIncrementa(ld);
	srand (1);

	
	matrizC =  (int*) malloc(sizeof(int)*ld*ld);
	start = clock();
	multiplicarMatriz(matrizA, matrizB, matrizC, ld);
	end = clock();
    
    	double timeelapsed = ((double)(end-start))/CLOCKS_PER_SEC;

                                            
	//cout << "["<< a << "]" << " = " << timeelapsed << " sec." <<endl;
    	printf ("%d\t%.4lf\n", ld, timeelapsed);
	
	free(matrizA);
	free(matrizB);
	free(matrizC);
	
	return 0;
}
