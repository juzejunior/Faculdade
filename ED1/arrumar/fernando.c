#include<stdio.h>
#include<ctype.h>
int main(){
long long int A=0, D=0,contador=0,contador2=0,C=0;
 scanf("%lld",&A);
   long long int vet[A];
 for(contador=0;contador<A;contador++){
  scanf("%lld",&vet[contador]);D=D+vet[contador];
 }
 contador=0;
 while(contador<A&&contador>=0){
   if(vet[contador]%2!=0){
   vet[contador]--;contador++;C++;D--;
  }else if(vet[contador]%2==0&&vet[contador]!=0){
   if(contador2==0){C++;contador2=6;}vet[contador]--;contador--;D--;
  }else if(vet[contador]==0){
   contador--;
  } 
 }
 if(contador==A-1&&contador2==0){
   printf("%lld %lld\n",C-1,D);
    }else{
   printf("%lld %lld\n",C,D);
 }
}
