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
    // Declara as variáveis
    int num_vertices;
    int total_vertices;
    string raiz;
    string especie1;
    string especie2;
    float distancia;
    Graph *grafo;
    map<string, int> nametable; //map para guardar o mapeamento nome -> ID

    while(true){

        int count = 0; //Variável para guardar o ID

        //Pairs para armazenar o valor de retorno na inserção do mapeamento
        //pair.first é um map <string, int>
        //  string é o nome da espécie e o int é o ID atribuido
        //pair.second é um bool que indica se o valor foi ou não inserido
        //  caso não tenha sido inserido pair.first contém o elemento já existente
        //  caso tenha inserido pair.first contém o elemento inserido em si
        std::pair<std::map<string, int>::iterator, bool> ret1;
        std::pair<std::map<string, int>::iterator, bool> ret2;

        //Lê a primeira linha
        cin >> num_vertices >> raiz;
        grafo = new Graph(num_vertices); //Cria um grafo
        ret1 = nametable.insert(make_pair(raiz, count)); //Insere a raiz
        count++; //ID++

        //Condição parada
        if(num_vertices == 0 && raiz == "FIM" )
            return 0;

        total_vertices = (num_vertices*(num_vertices-1))/2;

        for (int i = 0; i < total_vertices; i++) {
            cin >> especie1 >> especie2 >> distancia; //Lê a espécie

            //Tenta inserir um mapeamento na tabela da 1a espécie
            ret1 = nametable.insert(make_pair(especie1, count));
            if(ret1.second){
                count++; //Se o elemento foi inserido, incrementa o ID
            }

            //O mesmo para a segunda espécie
            ret2 = nametable.insert(make_pair(especie2, count));
            if(ret2.second){
                count++;
            }

            //Cria a aresta com os IDs recuperados e a distancia dada
            grafo->add_adj(ret1.first->second, ret2.first->second, distancia);
        }

        //Chama o a função que utiliza o algoritmo de Prim e retorna o resultado
        float dist = grafo->prim();

        //Seta a precisão para duas casas decimais
        cout << fixed << setprecision(2);
        cout << dist << endl;

        delete grafo; //Deleta o grafo
        nametable.clear(); //Limpa a tabela de mapeamento
    }
}
