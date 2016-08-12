#include "listaalfabetica.h"
#include <ctype.h>

int main(int argc, char *argv[])
{
	List *list;
	char name[30], escolha;
	int i = 0;
	bool alfabetico;
	
	list = NULL;
	escolha = 'a';
	
	printf("---------------- Crie sua Lista em ordem alfabética! ------------\n\n                            Bem-Vindo!\n");
	
	while(escolha != 's')
	{
		do{
			printf("\n	i - inserir | e - excluir | l - Listar | s - Sair: ");
			scanf("%c",&escolha);
			tolower(escolha);
			 __fpurge(stdin);
		}while(escolha != 'i' && escolha != 'e' && escolha != 'l' && escolha != 's');
			
		switch(escolha)
		{
			case 'i': 
					printf("	Digite um nome: ");
					fgets(name,30,stdin);	
					 insert(&list,name);  
			break;
			case 'e':
					printf("	Quem você deseja excluir: ");
					fgets(name,30,stdin);
					delete(&list,name);
			break;
			case 'l': 
					show(list);
			break;
			case 's':
				   printf("\n	Volte sempre!\n");	
			break;
		}	
	}

	//liberando a memória
	freeAlocate(&list);
	
	return 0;
}
