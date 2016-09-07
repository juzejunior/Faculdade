void check ( char * letra, char other){ // Transforma letras maiusculas em minusculas para comparar.
	if (isupper(other))	*letra = tolower(other);
	else *letra = other;
}



//linhaMax e colunaMax são as dimensoes da matriz
bool buscaPalavra(char matriz[][], char palavra[], int *pI, int *pJ, char *direcao, int linhaMax, int colunaMax){
  int i, j, x;
	int sizeWord;
  int found; // S = 1. N = 0.
  // char auxLetra;
  
	sizeWord = strlen(palavra);
  found = 0;
 
  for (i = 0; i < linhaMax; i++){
    for (j = 0; j < colunaMax; j++){
      
      if (palavra[0] == matriz[i][j]){ //Encontrou primeira letra	
        //salvar a posição da primeira letra vai ser necessário?
        *pI = i;
        *pJ = j;
        
        if (palavra[1] == matriz[i - 1][j]){ //Sentido - VR
          found = 1;
				  for (x = 0; x < sizeWord; x++)
            if (palavra[x] != matriz[i - x][j])	found = 0;

          if (found){
  					strcpy(direcao,"VR");
            break;
          }
        }

        if (palavra[1] == matriz[i + 1][j]){ //Sentido - VD
          found = 1;
					for (x = 0; x < sizeWord; x++)
            if (palavra[x] != matriz[i + x][j])	found = 0;

          if (found){
            strcpy(direcao,"VD");
            break;
          }
        }

        if (palavra[1] == matriz[i][j + 1]){ //Sentido - HD
          found = 1;
          for (x = 0; x < sizeWord; x++)
            if (palavra[x] != matriz[i][j + x])	found = 0;

          if (found){
          	strcpy(direcao,"HD");
            break;
          }
        }

        if (palavra[1] == matriz[i][j - 1]){ //Sentido - HR
          found = 1;
          for (x = 0; x < sizeWord; x++)
            if (palavra[x] != matriz[i][j - x])	found = 0;
 
            if (found){
            	strcpy(direcao,"HR");
              break;
            }
        }

        if (palavra[1] == matriz[i - 1][j + 1]){ //Sentido - DAD
          found = 1;
          for (x = 0; x < sizeWord; x++)
            if (palavra[x] != matriz[i - x][j + x])	found = 0;
 
          if (found){
            strcpy(direcao,"DAD");
            break;
          }
        }

        if (palavra[1] == matriz[i - 1][j - 1]){ //Sentido - DAE
          found = 1;
          for (x = 0; x < sizeWord; x++)
            if (palavra[x] != matriz[i - x][j - x])	found = 0;
 
          if (found){
            strcpy(direcao,"DAE");
            break;
          }
        }

        if (palavra[1] == matriz[i + 1][j + 1]){ //Sentido - DaD
          found = 1;
          for (x = 0; x < sizeWord; x++)
            if (palavra[x] != matriz[i + x][j + x])	found = 0;
 
          if (found){
            strcpy(direcao,"DaD");
            break;
          }
        }

        if (palavra[1] == matriz[i + 1][j - 1]){ //Sentido - DaE
          found = 1;
          for (x = 0; x < sizeWord; x++)
            if (palavra[x] != matriz[i + x][j - x])	found = 0;
 
          if (found){
            strcpy(direcao,"DaE");
            break;
          }
        }
      }
    }
    if (found)	break;
  }
  
 	/*TESTE 		
	if (found)	printf("%s - PALAVRA ENCONTRADA\n", palavra);
    else	printf("%s - PALAVRA NAO ENCONTRADA\n", palavra);*/
}
