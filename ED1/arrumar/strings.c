#include<string.h>
#include<stdio.h>

long int strtam(char *palavra){
		
		int i;
		
		for(i = 0; palavra[i] != '\0'; i++);

		return i;
} 

int main(){
	
		char palavra[] = "amem";
	
		printf("%ld",strtam(palavra));
	
		return 0;
}
