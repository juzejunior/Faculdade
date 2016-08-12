#include<stdio.h>

int main(){

    int cont=1;
    double i;
    int aux;

    for(i=0;i<=2;){

        aux = i;

        if(cont == 3){
            if(aux == i){
                  printf("%d\n",aux);
                  cont++;
                  i+=0.2;
            }else{
                 printf("%.1lf\n",i);
                  cont++;
                  i+=0.2;
            }
        }else{
            if(aux == i){
                  printf("%d\n",aux);
                  cont++;
            }else{
                printf("%.1lf\n",i);
                cont++;
            }
        }
    }

    return 0;
}

