#include <iostream>
#include <list>
#include <queue>
#define INFINITO 10000000

using namespace std;

class Grafo
{
private:
	int V; //numero de vertices
	//ponteiro para array da lista de adjascencia
	list<pair<int, int> > * adj;
	//exemplo adj[0].push_back(pair<int, int> )	
public:
	//construtor
	Grafo(int V)//passando numero de vertices
	{
		this->V = V; //atribui o nº de vertices
		/*
		  cria as listas onde cada lista é uma lista de pair, onde cada pair informa o destino e o custo
		*/
		adj = new list<pair<string, int> >[V];
	}
	//adiciona uma aresta ao grafo de v1 à v2
	void addAresta(int v1, int v2, int custo)
	{
		adj[v1].push_back(make_pair(v2, custo));//insira neste vertice uma aresta ate v2 com o custo
	}
	//algoritmo de Dijkstra - retorna o caminho mínimo
	int dijkstra(int orig, int dest)
	{
		//vetor de distancias
		int dist[V];
		/*visitados- caso o vertice ja tenha sido expandido n expanda de novo*/
		int visitados[V];
		//fila de prioridades - Qual vertice será escolhido da fila para ser expandido?
		priority_queue < pair<int, int>, 
						vector<pair<int, int> >, greater<pair<int, int> > > pq;

		//inicia o vetor de distancia e visitados
		for (int i = 0; i < V; i++)
		{
			/* code */
			dist[i] = INFINITO;
			visitados[i] = false;
		}
		//a distancia de orig para orig e 0
		dist[orig] = 0;
		//inserier na fila
		pq.push(make_pair(dist[orig], orig));
		
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
		return dist[dest];
	}
};

int main(int argc, char const *argv[])
{
	/* code */
	Grafo g(5);
	//inserindo as arestas
	g.addAresta(0, 4, 10);
	g.addAresta(0, 1, 1);
	g.addAresta(1, 2, 5);
	g.addAresta(2, 4, 1);
	g.addAresta(3, 2, 1);
	g.addAresta(0, 3, 3);
	g.addAresta(3, 4, 6);
	

	cout << "O caminho mínimo de 0 para 4 é: " << g.dijkstra(0, 4) << endl;

	return 0;
}