#include<iostream>
#include<iomanip>

using namespace std;

int main(){

	
	int x,y,i,s=0,cont=0,vezes;
	
	cin >> vezes;

	for(i = 0; i < vezes; i++){
	   cin >> x >> y;
	   while(cont<y){
		if(x%2 != 0){
		    s+=x;
                    cont++;	
		}
		x++;
	   }
	   cout << s<<endl;
	   cont = 0;
	   s = 0;	
	}	

	return 0;
}
