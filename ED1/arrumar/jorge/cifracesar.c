#include<stdio.h>
#include<string.h>

int main()
{
   int n,i,quant_casa,j = 0,k = 0, diferenca;
   char nome[50];
   char alfabeto[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
   scanf("%d", &n);
   for(i = 0; i < n; i++){5
	   
	   scanf("%49s", nome);
	   scanf("%d", &quant_casa);
	   
	   for(j = 0; j <= strlen(nome); j++){
		      
		      for(k = 0; k < 26; k++){
				  if(nome[j] == alfabeto[k]){
					  diferenca = k - quant_casa;
					 if(diferenca >= 0){
						 printf("%c",alfabeto[k - quant_casa]);
					 }else{
						 printf("%c", alfabeto[diferenca+26]);
					 }
				  }
			   }
		}
		printf("\n");  
    }
   
   return 0;
}
