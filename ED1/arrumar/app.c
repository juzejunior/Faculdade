#include<stdio.h>

int main(){

  double i,j,cont=1;


  for(i =0; i <=2;){

    if(i%2.0 == 0){
        printf("I=%d\n",(i*10)*10);
    }

    if(cont == 3){
         printf("I=%.1lf\n",i);
         i = i+0.2;
         cont= 1;
    }else{
          printf("I=%.1lf\n",i);
          cont++;
    }
  }

    return 0;
}
