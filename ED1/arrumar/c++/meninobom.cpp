#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<cstring>

using namespace std;

int alfabetica(string a, string b){

	return a < b;

}


int main(){

    string nome;
    string ultimo_nome;
    vector<string> criancas;
    vector<string> auxiliar;
    vector<string> ajuda;
    int cont = 0;

   while(getline(cin,nome)){
        if(nome.compare("EOF") != 0){
	    auxiliar.push_back(nome);
	    std::transform(nome.begin(), nome.end(), nome.begin(), ::tolower);		    	
            ajuda.push_back(nome);
	    criancas.push_back(nome);			
            cont++;
        }else{
            break;
        }
   }

   sort(criancas.begin(),criancas.end(),alfabetica);
 

   for(int i = 0; i <= auxiliar.size()-1;i++){
       if(criancas.at(cont-1).compare(ajuda.at(i)) == 0){
		
		cout<<auxiliar.at(i)<<endl;
       }		
       //cout << criancas.at(cont-1)endl;
   }
       
   return 0;
}
