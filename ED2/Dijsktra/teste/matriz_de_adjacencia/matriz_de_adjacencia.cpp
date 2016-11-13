#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;

string total[18][18];
vector<string>ruas;

void
build_Matriz_de_Adjacencia(){ //Criar a matriz
	
	FILE * arq = fopen("Ruas.txt","r");
	string aux;
	int j = 0,i = 0; 
	char rua1[50]; 	
	
	while ( fscanf ( arq, " %[^\n]s" , rua1) != EOF ){ 		
		ruas.push_back(rua1);
	}
	
	for(int i = 0 ; i < (int)ruas.size() ; i++){
		total[i][0] = ruas[i];
		total[0][i] = ruas[i];
	}
	
	for( i = 1 ; i < (int)ruas.size() ; i++)
		for( j = 1; j < (int)ruas.size(); j++)
				total[i][j] = "0";	
}

void
show_Matriz(){ //Mostra a matriz
	for(int i = 0; i < (int)ruas.size() ; i++){
		for(int j = 0 ; j < (int)ruas.size() ; j++){
			cout<<total[i][j]<<"  ";
		}
		cout<<endl;
	}
}


void
adicionar_Ligacao(string first, string second){ //Adiciona ligação entre o ponto first e second
	for(int i = 1 ; i < (int)ruas.size() ; i++){
		if(first == total[0][i] ){
			for(int j = 1 ; j < (int)ruas.size() ; j++){
				if( second == total[j][0])
					total[i][j] = "X";
			}
		}
	}
}

int main(){

}

	
	

