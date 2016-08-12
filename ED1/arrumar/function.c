#include<stdio.h>

/*mensagens a serem enviadas para as pessoas*/
enum tipo_resposta {LIXEIRA,SEGUNDA_CHANCE,CASAMENTO};

typedef struct {

    char *nome;
    enum tipo_resposta tipo;

} resposta;


void lixeira(resposta r){

    printf("Querida %s,\n",r.nome);
    puts("Infelizmente seu ultimo encontro nos contatou");
    puts("Para dizer que não irão se ver novamente.");

}

void segunda_chance(resposta r){

    printf("Querida %s,\n",r.nome);
    puts("Boas notícias: Seu último encontro nos respondeu");
    puts("Organize outro encontro. Por favor ligue o mais rapido possível.");

}

void casamento(resposta r){

    printf("Querida %s,\n",r.nome);
    puts("Parabéns! Seu último encontro entrou em contato");
    puts("Com uma proposta de casamento.");

}


int main(int argc, char *argv[]){

    resposta r[] = {
        {"Mike", LIXEIRA},{"Luis",SEGUNDA_CHANCE},
        {"Matt",SEGUNDA_CHANCE},{"Willian",CASAMENTO}
    };

    int i;

    for(i = 0; i < 4; i++){

        switch(r[i].tipo){
            case LIXEIRA:
                lixeira(r[i]);
            break;
            case SEGUNDA_CHANCE:
                segunda_chance(r[i]);
            break;
            default:
                casamento(r[i]);
            break;
        }

    }

    return 0;
}



