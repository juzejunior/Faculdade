#include<stdio.h>

void modifica(int *y){
	
	*y = *y+1;
}

int main(){
	

	int x;
	x = 13;
	
	
	
	printf("%d\n",x);
	modifica(&x);
	printf("%d\n",x);

	return 0;
	
}
