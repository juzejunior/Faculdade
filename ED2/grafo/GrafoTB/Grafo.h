/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Grafo.h
 *
 * Created on November 7, 2016, 9:29 AM
 */
#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <queue>
#include <list>
#include "Rua.h"

#define INFINITO 10000000

using namespace std;

class Grafo {

private:
    int V;//numero de vertices
    //ponteiro para array da lista de adjascencia
    list<pair<int, int> > *adj;
    //exemplo adj[0].push_back(pair<int, int> )	
public:
    //construtor
    Grafo(int V);//passando numero de vertices
    //adiciona uma aresta ao grafo de v1 à v2
    void addAresta(Rua rua1, Rua rua2, int custo);
    //algoritmo de Dijkstra - retorna o caminho mínimo
    int dijkstra(Rua orig, Rua dest);
};

#endif /* GRAFO_H */

