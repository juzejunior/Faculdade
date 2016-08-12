#include<stdio.h>

int compare_scores(const void* score_a,const void* score_b){

    //aplicando cast para pegar o valor void e deixa-lo inteiro
    int a = *(int*)score_a;
    int b = *(int*)score_b;

    /*vendo os retornos da funcao*/
    return a-b;
}

int main(){
    int i;
    int inteiros[] = {54,22,11,10,100};
    qsort(inteiros,5,sizeof(int),compare_escores);

    for(i = 0; i < 5; i++){
        printf("%d, ",inteiros[i]);
    }

}
