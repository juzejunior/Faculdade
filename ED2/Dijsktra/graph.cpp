#include "graph.h"

Graph::Graph()
{
  // entrou = true;
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
   adj[destPosition].push_back(make_pair(dist, origPosition));
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

//imprimir todos os caminhos de uma origem
double Graph::dijkstra(Street orig, std::vector<QString> *roads, std::vector<std::vector<QString>> *todosCaminhos)
{
    for (int i = 0; i < streets.size(); ++i){
        dijkstra(orig, streets.at(i), roads);
        todosCaminhos->push_back(*roads);
        roads->clear();
    }
    return 0;
}

//imprimir todos os caminhos alternativos
double Graph::dijkstra(Street orig, Street dest, std::vector<QString> *roads, std::vector<std::vector<QString>> *todosCaminhos)
{
   int previous[streets.size()];//guardará as ruas passadas no menor caminho
   //guarda a distancia de cada rua
   double dist[streets.size()];
   //guardara o estado de expansao de uma rua
   bool visited[streets.size()];
   //guarda todas as distancias percorridas
   std::vector<double> distance;
   //vector de vector para guardar os indices dos locais passados em cada rota alternativa
   int alternative_routs[streets.size()][streets.size()];
   //inicializa as ruas alternativas
   for(int i = 0; i < streets.size(); i++)
   {
       for(int j = 0; j < streets.size(); j++)
       {
            alternative_routs[i][j] = -1;
       }
   }
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
          int i = 0;
          int j = 0;
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
                  //guarda o local atual na rota para futura impressao
                  alternative_routs[i][j] = u;
                  j++;//incrementa para o proximo local desta rota
                  //atualiza o custo para v
                  dist[v] = dist[u] + custo;
                  //se chegou ao destino guarde sua distancia final e vá para a proxima rota
                  if (streetIndex(dest) == v) {
                      distance.push_back(dist[v]);
                      i++;
                  }
                  //adicione-o na fila
                  pq.push(make_pair(dist[v], v));
                  previous[v] = u;
              }
           }
      }
   }


   for(int i = 0; i < streets.size(); i++)
   {
       for(int j = 0; j < streets.size(); j++)
       {
            if(alternative_routs[i][j] != -1)
            {
                qInfo() << "Rota " << i+1 <<": ";
                qInfo() << streets.at(alternative_routs[i][j]).getName() << "-> ";
            }
       }
   }

   return 0;
}

//imprimir todos os caminhos alternativos
void Graph::printAllPaths(Street orig, Street dest, std::vector<QString> *todosCaminhos)
{
    Street dest2 = dest;
    //marca todos os vertices como nao visitados ainda
    bool *visited = new bool[streets.size()];
    //array para guardar os caminhos
    int *path = new int[streets.size()];
    int path_index = 0; //iniciliza o caminho como vazio
    //inicializa todos os vertices como n visitados
    for(int i = 0; i < streets.size(); i++)
        visited[i] = false;
    //funcao recursiva para imprimir o caminho
    printAllPathsUtil(orig, dest, dest2, visited, path, path_index, todosCaminhos);
}

//funcao recursiva para printar todos os caminhos ate o destino
void Graph::printAllPathsUtil(Street orig, Street dest, Street dest2,
                              bool visited[], int path[],
                              int &path_index,
                              std::vector<QString> *todosCaminhos)
{
    static bool entrou = true;
    //marque o local atual e guarde em path
    visited[streetIndex(orig)] = true;
    path[path_index] = streetIndex(orig);
    path_index++;

    //se o vertice atual é o final = ao destino
    if(streetIndex(orig) == streetIndex(dest))
    {
       for(int i = 0; i < path_index; i++){
           if (entrou){
               if (streets.at(i).getName() != dest2.getName()){
                   todosCaminhos->push_back(streets.at(i).getName() + " -> ");
               } else {
                   todosCaminhos->push_back(streets.at(i).getName());
                   entrou = false;
               }
           }
       }
       todosCaminhos->push_back("\n\n");
    }else{
        // Recur for all the vertices adjacent to current vertex
        list<pair<double, int> >::iterator it;
        //percorre todos os locais adjascentes a u

        //for(int i = )
        for(it = adj[streetIndex(orig)].begin(); it != adj[streetIndex(orig)].end(); it++)
        {
           if(!visited[it->second]){

                printAllPathsUtil(streets.at(it->second), dest, dest2, visited, path, path_index, todosCaminhos);
           }
        }
    }
    //remove o local atual do caminho e marca como invisitavel
    path_index--;
    visited[streetIndex(orig)] = false;
    //entrou = true;
}
