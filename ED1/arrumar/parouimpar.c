#include<stdio.h>




int main(){

   int vetor[10],n,i,anterior;
   scanf("%d",&n);
   vetor[0] = n;
   anterior = n;
   printf("N[0] = %d\n",n);
   for(i = 1; i < 10;i++){
        vetor[i] = anterior*2;
        anterior = anterior*2;
        printf("N[%d] = %d\n",i,vetor[i]);
   }
    return 0;
}
