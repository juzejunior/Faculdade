#include<stdio.h>
#include<math.h>

int main(){

    int n,i,cubo,pontencia;

    scanf("%d",&n);

    for(i = 1; i <= 5;i++){
        cubo = pow(i,3);
        pontencia = pow(i,2);
        printf("%d %d %d\n",i,pontencia,cubo);
    }

    return 0;
}
