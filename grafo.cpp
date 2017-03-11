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

using namespace std;

void Graph::add_adj(int origem, int destino, float distancia){
	grafo[origem].push_back(new Edge(origem, destino, distancia));
	grafo[destino].push_back(new Edge(destino, origem, distancia));
}

float Graph::prim(){
    float peso;

    return peso;
}
