#include<stdio.h>
#include<string.h>
#include "verifica_expressao.h"


int main()
{
	char expressao[80];
	
	fgets(expressao,80,stdin);
	
	verificaExpressao(expressao);
	
	return 0;
}
