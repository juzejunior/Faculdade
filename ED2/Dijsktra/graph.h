#ifndef GRAPH_H
#define GRAPH_H

#include<bits/stdc++.h>
#include <street.h>
#include <algorithm>
#include <QDebug>

using namespace std;
#define INF 0x3f3f3f3f

//Par de distancia e rua
typedef pair<double, int> iPair;

class Graph
{
    std::vector<Street> streets;
    //para cada aresta precisamos guardar o local e sua distancia
    list< pair<double, int> > *adj;//lista de aresta

public:
    Graph();
    void addStreets(std::vector<Street> streets);//construtor
    //funcao para adicionar uma aresta entre dois pontos
    void addEdge(Street orig, Street dest, double dist);
    //imprima os menores caminhos a partir de s
    void shortestPath(string s);
    //retorna o menor caminho utilizando o algoritmo de dijkstra
    double dijkstra(Street orig, Street dest, std::vector<QString> *road);
    //retorna o indice de uma rua
    int streetIndex(Street street);

private:


};

#endif // GRAPH_H
