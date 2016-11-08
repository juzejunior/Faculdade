/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Grafo.cpp
 * Author: José Diôgo
 * 
 * Created on November 7, 2016, 9:29 AM
 */
#include "Grafo.h"

Grafo::Grafo(int V) 
{
    this->V = V; //atribui o nº de vertices
    /*cria as listas onde cada lista é uma lista de pair, onde cada pair informa o destino e o custo*/
    adj = new list<pair<int, int> >[V];
}

//adiciona uma aresta ao grafo de v1 à v2
void Grafo::addAresta(Rua rua1, Rua rua2, int custo)
{
        //Esta é a lista de adjascencia
	adj[rua1.getId()].push_back(make_pair(rua2.getId(), custo));//insira neste vertice uma aresta ate a rua 2 com o custo
}
//algoritmo de Dijkstra - retorna o caminho mínimo
int Grafo::dijkstra(Rua orig, Rua dest)
{
    //vetor de distancias
    int dist[V];
    /*visitados- caso o vertice ja tenha sido expandido n expanda de novo*/
    int visitados[V];
    //fila de prioridades - Qual vertice será escolhido da fila para ser expandido?
    priority_queue < pair<int, int>, 
				  vector<pair<int, int> >, greater<pair<int, int> > > pq;
    //inicializa todos os vertices do grafo
    for (int i = 0; i < V; i++)
    {
        /* code*/ 
         dist[i] = INFINITO;
         visitados[i] = false;
    }
    //inicia o vetor de distancia e visitados
    //a distancia de orig para orig e 0 - a distancia inicial da origem para ela mesma é 0
    dist[orig.getId()] = 0;
    //inserier na fila
    pq.push(make_pair(dist[orig.getId()], orig.getId()));

    //loop do algoritmo - Enquanto tiver elementos na fila
    while(!pq.empty())
    {
            pair<int, int> p = pq.top();//extrai o pair do topo
            int u = p.second;//obtem o vertice do pair
            pq.pop();//remove-o da fila
            //verifica se o vertice nao foi expandido
            if(visitados[u] == false)
            {
                    //marca o vertice como visitado
                    visitados[u] = true;
                    list<pair<int , int> >::iterator it;
                    //percorre os vertices "v" adjacentes de "u"
                    for (it = adj[u].begin(); it != adj[u].end(); it++)
                    {
                            //obtem o vertice adjacente e o custo da aresta - Relaxamento
                            int v = it->first;
                            int custo_aresta = it->second;
                            //relaxamento (u, v)
                            if(dist[v] > (dist[u] + custo_aresta))
                            {
                                    //atualiza a distancia de v e insere na fila
                                    dist[v] = dist[u] + custo_aresta;
                                    pq.push(make_pair(dist[v], v));
                            }
                    }
            }
    }
    //retorna a distancia minima até o destino
    return dist[dest.getId()];
}
