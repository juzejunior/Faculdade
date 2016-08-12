/*
 * Este programa busca uma palavra dada em uma tabela de caça palavras
 * Desenvolvedores: José Diôgo, Fernando Maia
 * Palavras na tabela: UMA, MORAR, AMAR, BAR, CANTA, ANA
 * */
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

/*Tamanho da matriz quadrada*/
#define TAM 5

/*Assinatura da função de busca*/
bool buscaPalavra(char bp[][TAM], char palavra[], int *pI, int *pJ, char *direcao);

int main(int argc, char *argv[])
{
	/*Não foi possivel inicializar na declaração pois matrizes de char são consideradas vetores de strings*/
	char tabela[TAM][TAM];
	int indiceI, indiceJ;
	char direcao[TAM];
	
	/*atribuindo palavras*/
	tabela[0][0] = 'A'; tabela[0][1] = 'M';tabela[0][2] = 'A';tabela[0][3] = 'R'; tabela[0][4] = 'U';
	tabela[1][0] = 'T'; tabela[1][1] = 'O';tabela[1][2] = 'N';tabela[1][3] = 'Y'; tabela[1][4] = 'A';
	tabela[2][0] = 'N'; tabela[2][1] = 'R';tabela[2][2] = 'A';tabela[2][3] = 'M'; tabela[2][4] = 'U';
	tabela[3][0] = 'A'; tabela[3][1] = 'A';tabela[3][2] = 'B';tabela[3][3] = 'A'; tabela[3][4] = 'R';
	tabela[4][0] = 'C'; tabela[4][1] = 'R';tabela[4][2] = 'B';tabela[4][3] = 'A'; tabela[4][4] = 'M';
	
	buscaPalavra(tabela,"CASA", &indiceI, &indiceJ, direcao);
	
	return 0;
}

/*Essa função busca por uma palavra em uma tabela*/
bool buscaPalavra(char bp[][TAM], char palavra[], int *pI, int *pJ, char *direcao)
{
	int i, j,indWord = 0,sizeWord, existWord = 0;
	/*guardando o tamanho da palavra*/	
	sizeWord = strlen(palavra);
	 
	/*BUSCA HORIZONTAL DIRETA*/
	for(i = 0; i < TAM;i++)
	{
		for(j = 0; j < TAM;j++)
		{
			if(bp[i][j] == palavra[indWord])
			{
				//guarda a posição da primeira letra dentro da tabela
				if(indWord == 0){
					*pI = i;
					*pJ = j;
				}
				existWord++;
				indWord++;
			}else{
				if(bp[i][j] != palavra[0]){
					indWord = 0;
					existWord = 0;  
				}else{
				     *pI = i;
					 *pJ = j;
				}
			}
		
			if(sizeWord == existWord){
				i = TAM;
				j = TAM;
				strcpy(direcao,"HD");
				return true;
			}
	    }
	 }
	 /*retorna o indice da palavra para a primeira letra*/
	 indWord = 0;
	 
	 /*HORIZONTAL REVERSA*/
	 for(i = 0; i < TAM;i++)
	 {
		for(j = TAM-1; j >= 0;j--)
	    {
			if(bp[i][j] == palavra[indWord])
			{
				if(indWord == 0){
					*pI = i;
					*pJ = j;
				}
				existWord++;
				indWord++;
			}else{
				/*Se a primeira letra da palavra recebida for diferente da letra da tabela reinicie os parametros*/
				if(bp[i][j] != palavra[0]){
					indWord = 0;
					existWord = 0;  
				}else{
				     *pI = i;
					 *pJ = j;
				}
			}
			/*se encontrou a palavra saia do loop*/	
			if(sizeWord == existWord){
				i = TAM;
				j = -1;
				strcpy(direcao,"HR");
				return true;
			}
		  }
		}
		
		/*BUSCA VERTICAL DIRETA*/
		for(j = 0; j < TAM;j++)
		{
			for(i = 0; i < TAM;i++)
			{
				if(bp[i][j] == palavra[indWord])
				{
					if(indWord == 0){
						*pI = i;
						*pJ = j;
					}
					existWord++;
					indWord++;
				}else{
					if(bp[i][j] != palavra[0]){
						indWord = 0;
						existWord = 0;  
					}else{
						*pI = i;
						*pJ = j;
					}
				}
		
				if(sizeWord == existWord){
					i = TAM;
					j = TAM;
					strcpy(direcao,"VD");
					return true;
				}
			}
		}
		/*retorna o indice da palavra para a primeira letra*/
		indWord = 0;
	     /*Busca Vertical REVERSA*/
	 	 for(j = 0; j < TAM;j++){
	 	
		 for(i = TAM-1; i >= 0;i--){
			
			if(bp[i][j] == palavra[indWord])
			{
				if(indWord == 0){
					*pI = i;
					*pJ = j;
				}
				existWord++;
				indWord++;
			}else{
				if(bp[i][j] != palavra[0]){
					indWord = 0;
					existWord = 0;  
				}else{
				     *pI = i;
					 *pJ = j;
				}
			}
				
			if(sizeWord == existWord){
				i = TAM;
				j = -1;
				strcpy(direcao,"VR");
				return true;
			}
		  }
		}
		/*retorna o indice da palavra para a primeira letra*/
		indWord = 0;
		j = 0;
	    /*Busca DIAGONAL PRINCIPAL DESCENDO*/
		for(i = 0; i < TAM; i++)
		{
			if(bp[i][j] == palavra[indWord])
			{
				if(indWord == 0){
					*pI = i;
					*pJ = j;
				}
				existWord++;
				indWord++;
			}else{
				if(bp[i][j] != palavra[0]){
					indWord = 0;
					existWord = 0;  
				}else{
				     *pI = i;
					 *pJ = j;
				}
			}
				
			if(sizeWord == existWord){
				i = TAM;
				strcpy(direcao,"DPD");
				return true;
			}
			j++;
		}
		/*retorna o indice da palavra para a primeira letra*/
		indWord = 0;
		j = TAM-1;
	    /*Busca DIAGONAL PRINCIPAL SUBINDO*/
		for(i = TAM-1; i >= 0; i--)
		{
			if(bp[i][j] == palavra[indWord])
			{
				if(indWord == 0){
					*pI = i;
					*pJ = j;
				}
				existWord++;
				indWord++;
			}else{
				if(bp[i][j] != palavra[0]){
					indWord = 0;
					existWord = 0;  
				}else{
				     *pI = i;
					 *pJ = j;
				}
			}
				
			if(sizeWord == existWord){
				i = 0;
				strcpy(direcao,"DPS");
				return true;
			}
			j--;
		}
		/*retorna o indice da palavra para a primeira letra*/
		indWord = 0;
		j = TAM-1;
	    /*Busca DIAGONAL PRINCIPAL SUBINDO*/
		for(i = 0; i < TAM; i++)
		{
			if(bp[i][j] == palavra[indWord])
			{
				if(indWord == 0){
					*pI = i;
					*pJ = j;
				}
				existWord++;
				indWord++;
			}else{
				if(bp[i][j] != palavra[0]){
					indWord = 0;
					existWord = 0;  
				}else{
				     *pI = i;
					 *pJ = j;
				}
			}
				
			if(sizeWord == existWord){
				i = TAM;
				strcpy(direcao,"DSD");;
				return true;
			}
			j--;
		}
		
		/*retorna o indice da palavra para a primeira letra*/
		indWord = 0;
		j = 0;
	    /*Busca DIAGONAL SECUNDARIA SUBINDO*/
		for(i = TAM-1; i >= 0; i--)
		{
			if(bp[i][j] == palavra[indWord])
			{
				if(indWord == 0){
					*pI = i;
					*pJ = j;
				}
				existWord++;
				indWord++;
			}else{
				if(bp[i][j] != palavra[0]){
					indWord = 0;
					existWord = 0;  
				}else{
				     *pI = i;
					 *pJ = j;
				}
			}
				
			if(sizeWord == existWord){
				i = 0;
				strcpy(direcao,"DSS");
				return true;
			}
			j++;
		}
		
		
		return false;				
}
