#include<stdio.h>
#include<string.h>

void tratarString(char *s[]){

    int i,tamanho;

    for(i = 0; i < 3;i++){
        if(strncmp(s[i],"i",1)){
            printf("%s",s[i]);
        }

    }
}


int main(){

    char *lista[] = {
        "I love you mary.",
        "I love you ana.",
        "I love my girlfriend"
    };

    tratarString(lista);

    return 0;
}
