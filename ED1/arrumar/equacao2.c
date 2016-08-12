#include<stdio.h>
#include<math.h>

int main(){

    double a,b,c,delta,raiz1,raiz2;
    scanf("%lf %lf %lf",&a,&b,&c);
    delta = pow(b,2) - 4*a*c;//calculo do delta

    raiz1 = -b+(sqrt(delta));
    printf("%.5lf",raiz1);

    return 0;
}
