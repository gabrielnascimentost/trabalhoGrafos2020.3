#include "AlgoritmoKruskal.h"
#include "Graph.h"
#include "Node.h"
#include "Edge.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

void AlgoritmoKruskal::findAGMKruskal(Graph *grafo) { // encontra a arvore geradora minima usando algoritmo de kruskal
    if (grafo->ehConexo()) {//verifica se o grafo eh conexo
        Graph* AGM = new Graph(); //criou um grafo solução
        vector<Edge*> arestas = grafo->criaListaArestas(); // cria uma cópia das arestas do grafo

        for (int i = 0; i <= AGM->getNumberEdges(); i++)
        {
           
        }
        

        // ordena a lista de arestas por peso em ordem crescente
        arestas.sort([](Edge *aresta1, Edge *aresta2) { // ordena as arestas
            return aresta1->getWeight() < aresta2->getWeight();//returna as arestas ordenadas por peso
        });

        for (auto i = arestas.begin(); AGM->number_edges.size() < grafo->vertices.size() - 1; i++) {//para i= inicio da lista, ate o final da lista < vertices -1 do grafo
            Aresta* aresta = *i; //aresta vai ser igual a aresta do for

            if (!arvoreGeradoraMinima->possuiVertice(aresta->vertice1->id)) {// se o grafo possui vertice identificado
                arvoreGeradoraMinima->vertices.push_back(new Vertice(aresta->vertice1->id));//copia esse vertice para a agm
            }

            if (!arvoreGeradoraMinima->possuiVertice(aresta->vertice2->id)) {//se possui o segunudo vertice
                arvoreGeradoraMinima->vertices.push_back(new Vertice(aresta->vertice2->id));//copia esse vertice
            }

            Vertice *vertice1 = arvoreGeradoraMinima->getVertice(aresta->vertice1->id);//vertice 1 vira o overtice da agm
            Vertice *vertice2 = arvoreGeradoraMinima->getVertice(aresta->vertice2->id);//vertice 2 faz a msm coisa

            if (!arestaFormaCiclo(vertice1, vertice2)) {//verifica se forma ciclo entre os vertices
                auto *novaAresta = new Aresta(vertice1, vertice2, aresta->peso);//copia a aresta entre os vertices se nao formar ciclo

                arvoreGeradoraMinima->arestas.push_back(novaAresta);//copia ela
            }
        }

        imprimirSolucao(arvoreGeradoraMinima);
    } else {
        cout << "O grafo eh desconexo." << endl;
    }
}