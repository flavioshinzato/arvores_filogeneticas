/**********************************************************
*
* Flávio Augusto Müller
* Yan Uehara
*
* Trabalho 2 de Grafos
* Prof. Said Sadique
*
* main.cpp
* Arquivo principal
*
***********************************************************/

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <map>

#include "grafo.h"

using namespace std;

int main(int argc, char* argv[]){
    int num_vertices;
    int total_vertices;
    string raiz;
    string especie1;
    string especie2;
    float distancia;
    Graph *grafo;
    map<string, int> nametable;

    while(true){

        int count = 0;

        std::pair<std::map<string, int>::iterator, bool> ret1;
        std::pair<std::map<string, int>::iterator, bool> ret2;

        //Lê a primeira linha
        cin >> num_vertices >> raiz;
        grafo = new Graph(num_vertices);
        ret1 = nametable.insert(make_pair(raiz, count));
        count++;

        //Condição parada
        if(num_vertices == 0 && raiz == "FIM" )
            return EXIT_SUCCESS;

        total_vertices = (num_vertices*(num_vertices-1))/2;

        for (int i = 0; i < total_vertices; i++) {
            cin >> especie1 >> especie2 >> distancia;

            ret1 = nametable.insert(make_pair(especie1, count));
            if(ret1.second){
                count++;
            }
            ret2 = nametable.insert(make_pair(especie2, count));
            if(ret2.second){
                count++;
            }

            grafo->add_adj(ret1.first->second, ret2.first->second, distancia);
        }

        //Chama o método disjkstra e retorna o resultado
        float dist = grafo->prim();

        //Seta a precisão para duas casas decimais
        cout << fixed << setprecision(2);
        cout << dist << endl;

        delete grafo; //Deleta o grafo
        nametable.clear();
    }
}
