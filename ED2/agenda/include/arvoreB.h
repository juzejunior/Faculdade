#ifndef ARVORE_B_H
#define ARVORE_B_H

#include "contato.h"

const t = 2;

typedef struct ArvoreB {  
   int numChaves;  
   Contato c;
   arvoreB *filhos[2 * t];  
   bool folha; 
}noArvoreB;

#endif


