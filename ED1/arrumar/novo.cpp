#include<iostream>
#include <vector>

using namespace std;

int main(){

	int i,n,numero,proximo_sitio = 0, estrela,quant_carneiros=0,total_carneiros=0;
	vector <int> estrelas;

	cin >> n;

	/*lendo e guardando o valor dos lugares*/
	for(i = 0; i < n; i++){

		cin >> numero;
		estrelas.push_back(numero);
		total_carneiros+=numero;
	}

	i = 0;

	while(proximo_sitio != -1 || proximo_sitio != n-1){
	
		/*percorrendo o vector,se for par*/
		if(estrelas.at(proximo_sitio) % 2 == 0){
			 if(estrelas.at(proximo_sitio) > 0){
				quant_carneiros+=1;
				estrelas.at(proximo_sitio) = estrelas.at(proximo_sitio) - 1;
		         }	
			 proximo_sitio = proximo_sitio - 1; 
		}else{//se for impar
			proximo_sitio = proximo_sitio - 1; 
		}

	}



	return 0;
}

