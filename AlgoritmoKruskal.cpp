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
        list<Edge*> arestas = grafo->criaListaArestas(); // cria uma cópia das arestas do grafo
    
        // ordena a lista de arestas por peso em ordem crescente
        arestas.sort([](Edge* aresta1, Edge* aresta2) { // ordena as arestas
            return aresta1->getWeight() < aresta2->getWeight();//returna as arestas ordenadas por peso
        });

        for (auto i = arestas.begin(); AGM->getNumberEdges() < grafo->getOrder() - 1; i++) {//para i= inicio da lista, ate o final da lista < vertices -1 do grafo
            Edge* aresta = *i; //aresta vai ser igual a aresta do "for"

            if (!AGM->searchNode(aresta->getId())) {// se o grafo nao possui o vertice identificado
                AGM->insertNode(aresta->getId()); //cria esse vertice novo na agm*/
            }

            if (!AGM->searchNode(aresta->getTargetId())) {//se nao possui o segunudo vertice (ou vertice alvo)
                AGM->insertNode(aresta->getTargetId());//cria esse vertice na agm
            }

            Node* vertice1 = AGM->getNode(aresta->getId());//usa um auxiliar para o vertice 1
            Node* vertice2 = AGM->getNode(aresta->getTargetId());//usa um auxiliar para o vertice 2 (para ambos serem usados no "eh ciclo?")

            if (!ehCiclo(vertice1, vertice2)) 
            {//verifica se forma ciclo entre os vertices, se nao formar...
                AGM->insertEdge(vertice1->getId(),vertice2->getId(),aresta->getWeight());//insere a aresta na agm com os vertices originais como ligaçao
            }
        }

        imprimirSolucao(arvoreGeradoraMinima);
    } else {
        cout << "O grafo eh desconexo." << endl;
    }
}

bool AlgoritmoKruskal::ehCiclo(Node* vertice1, Node* vertice2) {
    

    return false;
}