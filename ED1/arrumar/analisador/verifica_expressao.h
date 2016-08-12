#include<stdbool.h>
#include<stdio.h>

void verificaExpressao(char *expressao)
{
	char caractere_anterior;
	int contParenteses = 0,contChaves = 0,contColchetes = 0,lugar_erro = 0,i;
	bool validador = true;
	
	while(*expressao)
	{
		//verifica se há invalidade
		switch(*expressao)
		{
		  case '{': 
			   if(caractere_anterior == '[' || caractere_anterior == '(') validador = false;
			   else contChaves++;
			   break;
		  case '[':
				if(caractere_anterior == '(') validador = false;
				else contColchetes++;
				break;
		  case '(':
				contParenteses++;
				break;
		  case '}':
				if(lugar_erro == 0)
					validador = false;
				contChaves--;
				
				break;
		  case ']':
				if(lugar_erro == 0)
					validador = false;
				if(caractere_anterior == '}') validador = false;
				else contColchetes--;
				break;
		  case ')':
				if(lugar_erro == 0)
					validador = false;
			    if(caractere_anterior == ']' || caractere_anterior == '}') validador = false;
			    else contParenteses--;
		}
		
		if(validador == true){
			lugar_erro++;
		}
		caractere_anterior = *expressao;//guarda o caractere atual
		expressao++;//vai para o próximo caractere
	}
	
	/*retorna verdade se for válida*/
	if(contParenteses == 0 && contChaves == 0 && contColchetes == 0 && validador == true){
		printf("Expressão Válida!");
	} 
	else{
		printf("%s", expressao);
		for(i = 0; i < lugar_erro;i++){
			printf(" ");
		}
		printf("^\n");
	}
}
