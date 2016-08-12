#include<stdio.h>


int main(){
    int n;
    int centena;
    scanf("%d",&n);
    printf("%d\n",n);
    /*verificando acima de 100*/
    if(n>=100){
        centena = n / 100;
        printf("%d nota(s) de R$ 100,00\n",centena);

        printf("%d", n/10);
    }

    return 0;
}
