#include "graph.h"

Graph::Graph()
{

}

//inicializa o grafo
void Graph::addStreets(std::vector<Street> streets)
{
  //adiciona as ruas ao grafo
  this->streets = streets;
  adj = new list<iPair> [streets.size()];//aloca memoria para a lista de ruas adjascentes
}
//metodo para adicao de arestas entre dois pontos
void Graph::addEdge(Street orig, Street dest, double dist)
{
   int origPosition = streetIndex(orig);
   int destPosition = streetIndex(dest);
   //qInfo() << "Posição da origem: " << origPosition;
   adj[origPosition].push_back(make_pair(dist, destPosition));
}

int Graph::streetIndex(Street street)
{
    int index = 0;

    for(Street streetq : streets)
    {
         if(streetq.getName().compare(street.getName()) == 0)
         {
            return index;
         }

         index++;
    }

    return -1;
}

//retorna a distancia miníma entre duas ruas
double Graph::dijkstra(Street orig, Street dest, std::vector<QString> *road)
{
   int previous[streets.size()];//guardará as ruas passadas no menor caminho
   //guarda a distancia de cada rua
   double dist[streets.size()];
   //guardara o estado de expansao de uma rua
   bool visited[streets.size()];
   //fila de prioridades
   priority_queue < pair<double, int>,
        vector<pair<double, int> >, greater<pair<double, int> > > pq;

   for (size_t i = 0; i < streets.size(); i++) {
      dist[i] = INF;
      visited[i] = false;
      previous[i] = -1;
   }
   //inicializa a distancia do ponto inicial para ele mesmo ou seja 0
   dist[streetIndex(orig)] = 0.0;
   //insere o nó inicial na fila
   pq.push(make_pair(dist[streetIndex(orig)], streetIndex(orig)));
   //enquanto tiver elementos na fila
   while(!pq.empty())
   {
      pair<double, int> p = pq.top();//pega o par com maior distancia na fila
      int u = p.second;//pega o local
      pq.pop();//e remove-o da fila
      //se o vertice n foi expandido
      if(visited[u] == false)
      {
          //vamos expandi-lo
          visited[u] = true;
          list<pair<double, int> >::iterator it;
          //percorre todos os locais adjascentes a u
          for(it = adj[u].begin(); it != adj[u].end(); it++)
          {
              //obtem o vertices
              double custo = it->first;
              int v = it->second;
              //cout << "Local: " << v << "distancia: " << custo << endl;
              //se o caminho é menor - relaxamento
              if(dist[v] > (dist[u] + custo))
              {
                //atualiza o custo para v
                dist[v] = dist[u] + custo;
                //adicione-o na fila
                pq.push(make_pair(dist[v], v));
                previous[v] = u;
              }
           }
      }
   }

   int current = streetIndex(dest);
   //guardando o caminho passado
   while(current != streetIndex(orig))
   {
       road->push_back(streets.at(current).getName()+ ": "+QString::number(dist[current]/1000)+" km");
       current = previous[current];
   }
   //o caminho inicial
   road->push_back( streets.at(current).getName()+ ": "+QString::number(dist[current]/1000)+" km");
   //retorna o valor em kilometros
   return dist[streetIndex(dest)]/1000;
}

