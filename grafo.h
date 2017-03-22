/**********************************************************
*
* Flávio Augusto Müller
* Yan Uehara
*
* Trabalho 2 de Grafos
* Prof. Said Sadique
*
* grafo.h
* Arquivo com a definição de classes e metódos auxiliares
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

        //Contrutor indicando a quais vértices pertence a aresta
        Edge(int start, int end, float distance){
            this->start = start;
            this->end = end;
            this->distance = distance;

        }
};

//Classe Graph para armanezar o grafo criado a partir das chaves geradas pelas entradas
class Graph{
    private:
        vector< list<Edge*> > grafo;
        int V;
    public:
        //Construtor da classe utilizando somente o tamanho do grafo
        Graph(int tamanho):grafo(tamanho) {
            V = tamanho;
        }
        //Método que chama o algoritmo de Prim
        float prim();
        //Método para adicionar um vértice adjacente
        void add_adj(int origem, int destino, float distancia);
};
