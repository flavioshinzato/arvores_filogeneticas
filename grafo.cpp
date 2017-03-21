/**********************************************************
*
* Flávio Augusto Müller
* Yan Uehara
*
* Trabalho 2 de Grafos
* Prof. Said Sadique
*
* utils.cpp
* Arquivo com a definição de classes e funções auxiliares
*
***********************************************************/

#include "grafo.h"
#include <queue>
#include <limits.h>

using namespace std;

void Graph::add_adj(int origem, int destino, float distancia){
	grafo[origem].push_back(new Edge(origem, destino, distancia));
	grafo[destino].push_back(new Edge(destino, origem, distancia));
}

float Graph::prim(){
    float dist;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    int src = 0;

    vector<float> key(V, INT_MAX);

    vector<int> parent(V, -1);

    vector<bool> inMST(V, false);

	pq.push(make_pair(0, src));
    key[src] = 0;

 	while(!pq.empty()) {
 		int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        list< Edge* >::iterator i;
        for (i = grafo[u].begin(); i != grafo[u].end(); ++i)
        {
            int v = (*i)->end;
            float distancia = (*i)->distance;

            if (inMST[v] == false && key[v] > distancia)
            {
                key[v] = distancia;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }


	for (int i = 0; i < V; i++) {
		dist+=key[i];
	}

    return dist;
}
