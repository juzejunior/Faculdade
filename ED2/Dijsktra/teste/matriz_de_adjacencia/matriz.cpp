//#ifndef MATRIZ_H
//#define MATRIZ_H

#include<iostream>
#include<fstream>
#include<vector>
#include<stdio.h>

using namespace std;

string total[20][20];
vector<string>ruas;

void
build_Matriz_de_Adjacencia(){ //Criar a matriz
	
	
	string aux;
	int j = 0; int i = 0, cont = 0; 
	string rua1; 	
	
	for( i = 0; i < 20 ; i++){
			for(j = 0; j < 20; j++){
				total[i][j] = "0";
			}
	}
	total[0][0] =  "x";
	ifstream myfile ("Ruas.txt");
	if(myfile.is_open()){
		while (!myfile.eof()){
			getline (myfile,rua1); 		
			ruas.push_back(rua1);
		}
	}
	myfile.close();
	for( i = 1 ; i <= 19 ; i++){
		total[i][0] = ruas[cont];
		total[0][i] = ruas[cont];
		cont++;
	
	}
	
	for( i = 1 ; i <= 19 ; i++)
		for( j = 1; j < (int)ruas.size(); j++)
				total[i][j] = "0";	
	//fclose(arq);
}

void
adicionar_Botao(){ 
	string aux, aux2;
	string rua1;
	vector<string>R2;
	
	ifstream myfile ("Grafos.txt");
	if(myfile.is_open()){
		while (!myfile.eof()){
			getline (myfile,rua1); 		
			R2.push_back(rua1);
		}
	}
	myfile.close();
	for(int cont = 0,cont2 = 1; cont < 61;cont2++,cont++){
		if(cont % 2 == 0){
					
			for(int i = 1 ; i <=19 ; i++){
				if(R2[cont] == total[i][0] ){
					for(int j = 1 ; j <= 19 ; j++){
						if( R2[cont2] == total[0][j]){
							total[i][j] = "1";
						}	
					}
				}
			}
		}	
	}
	
}

void
show_Matriz(){ //Mostra a matriz (Função chamada na hora de )
	build_Matriz_de_Adjacencia();
	adicionar_Botao();
	for(int i = 0; i <= 19 ; i++){
		for(int j = 0 ; j <= 19; j++){
			cout<<total[i][j]<<"  "; //Adicionar elemento da matriz no painel
		}
		cout<<endl; // pula linha para adicionar os próximos elementos a cada 19 loops do segundo iterador
	}
}

int main(){
 show_Matriz();	
}

//#endif
