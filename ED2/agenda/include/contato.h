#ifndef CONTATO_H
#define CONTATO_H

#include <stdio.h>
#include <stdlib.h>
#include "data.h"

typedef struct Contato{
	char nome[30];
	Data dataNascimento;
	char cpf[12];
	char profissao[30];
	char email[15];
	char telCelular[15];
	char telComercial[15];
	char telResidencial[15];
}Contato;

#endif
