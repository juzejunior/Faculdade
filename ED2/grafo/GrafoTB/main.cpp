/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: bill-01
 *
 * Created on November 7, 2016, 9:27 AM
 */

#include <cstdlib>
#include "Grafo.h"
#include "Rua.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Rua rua;
    rua.setNome("Paripe");
    rua.setId(0);
    Rua rua2;
    rua2.setNome("Coutos");
    rua2.setId(1);
    Rua rua3;
    rua3.setNome("Periperi");
    rua3.setId(2);
    Rua rua4;
    rua4.setNome("Calçada");
    rua4.setId(3);
    //4 cidades
    Grafo g(4);
    g.addAresta(rua, rua2, 5);
    g.addAresta(rua, rua4, 2);
    g.addAresta(rua2, rua3, 2);
    g.addAresta(rua4, rua3, 1);
    
    std::cout << "O caminho mais curto de Paripe até Periperi é: " << g.dijkstra(rua, rua4) <<" Km"<<endl;
    
    return 0;
}

