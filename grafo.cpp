/**********************************************************
*
* Flávio Augusto Müller
* Yan Uehara
*
* Trabalho 2 de Grafos
* Prof. Said Sadique
*
* grafo.cpp
* Arquivo com a definição de classes e funções auxiliares
*
***********************************************************/

#include "grafo.h"
#include <queue>
#include <limits.h>

using namespace std;

//Método para adicionar uma nova aresta
void Graph::add_adj(int origem, int destino, float distancia){
	//Adiciona as aresta tanto no sentido a->b quanto b->a
	grafo[origem].push_back(new Edge(origem, destino, distancia));
	grafo[destino].push_back(new Edge(destino, origem, distancia));
}

//Função para calcular a árvore geradora mínima utlizando o algoritmo de Prim
float Graph::prim(){
    float dist; //Guarda a distância

	//Fila de prioridade para determinar a menor chave para ser pesquisada
	//	a fila é um pair<int, int>
	//	o 1o int é o valor de chave do vértice
	//	o 2o int é o ID do vértice
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

	int src = 0; //A origem é sempre o vértice de ID 0

	// V é a quantidade de vértices

    vector<float> key(V, INT_MAX); //Vetor de chaves

    vector<int> parent(V, -1); //Vetor de predecessores

    vector<bool> inMST(V, false); //Vetor para determinar se um vértice já está na árvore

	pq.push(make_pair(0, src)); //Insere o vértice raiz na fila
    key[src] = 0; //Chave da raiz é sempre 0

	//Enquanto existirem vértices na fila
 	while(!pq.empty()) {
		//Recupera o primeiro elemento (o do topo) e recupera o ID do vértice origem
		//Esse é o vétice u
		int u = pq.top().second;
        pq.pop(); //Remove o vértice da fila

        inMST[u] = true; //Marca como visitado

        list< Edge* >::iterator i; //Iterador de suporte
		//Para cada vértice v adjacente a u
		for (i = grafo[u].begin(); i != grafo[u].end(); ++i)
        {
            int v = (*i)->end; //Recupera o ID de v
            float distancia = (*i)->distance; //Recupera a distância

			//Se o vértice ainda não foi visitado e a distância é menor do que o valor de chave
            if (inMST[v] == false && key[v] > distancia)
            {
                key[v] = distancia; //Atualiza o valor de chave
				//Adiciona o vértice na fila, com seu valor de chave associado
				pq.push(make_pair(key[v], v));
                parent[v] = u; //Atualiza o predecessor
            }
        }
    }

	//Soma as distâncias para saber o menor peso de uma MST
	for (int i = 0; i < V; i++) {
		dist+=key[i];
	}

	//Retorna o peso
    return dist;
}
