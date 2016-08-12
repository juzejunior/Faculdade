#include<stdio.h>
#define n 3

int indice(int i, int j){
	
	if(i < j)
		return i*n+j-i;
		
	return j*n+i-j;
}


int main()
{
		int v[6] = {1,2,3,4,7,5};
	
		int i, j,index;
		
		scanf("%d %d", &i, &j);
		
		index = indice(i,j);
		
		printf("%d ", v[index]);
	
		return 0;
}
