/**********************************************************
*
* Flávio Augusto Müller
* Yan Uehara
*
* Trabalho 2 de Grafos
* Prof. Said Sadique
*
* utils.h
* Arquivo com a definição de classes e funções auxiliares
*
***********************************************************/

#include <vector>
#include <list>
#include <climits>

using namespace std;

//Classe Edge para guardar a distância entre dois vértices
class Edge{
	public:
        int start;
        int end;
		float distance;

		//Construtor para iniciar a distância como infinita
		Edge(){
			this->distance = INT_MAX;
		}

        Edge(int start, int end, float distance){
            this->start = start;
            this->end = end;
            this->distance = distance;

        }
};

class Graph{
    private:
        vector< list<Edge*> > grafo;
        int V;
    public:
        Graph(int tamanho):grafo(tamanho) {
            V = tamanho;
        }
        float prim();
        void add_adj(int origem, int destino, float distancia);
};
