#include<stdio.h>

#define rendabaixa 1000*0.08
#define rendamedia 2.00*0.18

int main(){

    double salario;
    scanf("%lf",&salario);

    if(salario <= 2000.00){
       printf("Isento\n");
    }else if(salario <= 3000.00){
        printf("R$ %.2lf\n",rendabaixa);
    }else if(salario <= 4500.00){
        printf("R$ %.2lf\n",rendabaixa+rendamedia);
    }else if(salario > 4500.00){
         printf("R$ %.2lf\n",rendabaixa+rendamedia+275.24);
    }

    return 0;
}
