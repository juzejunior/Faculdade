#include <stdio.h>
#include <stdlib.h>

#define TAM 5



int main()
{
    int **p;
    int cont2,cont=1,linha=0,conferidor=1,coluna=0,coluna2=0;
    p=(int**)malloc(cont*sizeof(int*));//alocando linha
    p[cont-1] = (int*)malloc(TAM*sizeof(int));//alocando colunas 

    while(conferidor){  //Aloca valores

        if(coluna == 5)
        {
		   cont++;//aumentando o contador de linhas
		   p= (int**)realloc(p,cont*sizeof(int*));  //incrementa linha	
		   p[cont-1]=  (int*)malloc(TAM*sizeof(int)); //atribui espaço para as colunas
		   coluna = 0;
		}
      
        scanf("%d",&p[cont-1][coluna]);

         if(p[cont-1][coluna]==0){
            conferidor=0;  //condicao de parada do loop
         }
          
        coluna++;      
    }

	/*while(coluna2<=coluna){  //loop de escrita


		while(cont2<=TAM){  //
			printf("qq\n");

			printf("%d ",p[linha][coluna2]);
			coluna2++;
			cont2++;
			if(coluna2==coluna){
				cont2=TAM;  //chegando a quantidade maxima de elementos ele paara
			}
		}
		cont2=0;
		linha++;

	}*/
	
	return 0;
}

