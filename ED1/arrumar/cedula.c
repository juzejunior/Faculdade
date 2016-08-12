#include<stdio.h>

int main(){

    int dinheiro,dezena;

    scanf("%d",&dinheiro);

    if(dinheiro >= 100){
        printf("%d Nota(s) de R$ 100,00\n",dinheiro/100);
        dezena = dinheiro%100;
        if(dezena == 50){
            printf("%d Nota(s) de R$ 50,00\n",(dinheiro%100)/50);
        }else if(dezena > 50){

        }

    }

    return 0;
}
