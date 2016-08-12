#include<iostream>

using namespace std;

int main(){

    int cont=0;
    double i;

    for(i=0;i<=2;){

        if(i == 0.0){
            printf("%.0lf",i);
        }

        if(cont==3){
            printf("%.1lf\n",i);
            cont = 0;
        }else{
            printf("%.1lf\n",i);
            cont++;
            i+=0.2;
        }

    }

    return 0;
}
