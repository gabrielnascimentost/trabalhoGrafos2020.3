//
// Created by Pichau on 08/03/2021.
//

#include <iostream>
#include <limits.h>
#include "AlgoritmoDijkstra.h"

using namespace std;

void AlgoritmoDijkstra::doDijkstra(Graph *grafo, int idNode1, int idNode2) {
    Node *NodeInit = grafo->getNode(idNode1);
    NodeInit->setDist(0);

    vector<Node *> nodes = grafo->getNosGrafo();

    while (!nodes.empty()) {
        Node *nodeAux = findNoMimDist(nodes);

        for (auto nodeAdj : nodeAux->adjNodes) {
            Edge *edge = grafo->getEdge(idNode1, idNode2);

            if (nodeAdj->getDist() > nodeAux->getDist() + edge->getWeight()) {
                nodeAdj->setDist(nodeAux->getDist() + edge->getWeight());
                grafo->getNode(nodeAdj->getId())->setDist(nodeAdj->getDist());
            }
        }
        nodes.at(nodeAux->getId()) = nullptr;
    }

    int cost = grafo->getNode(idNode2)->getDist()3;

    if (cost < INT_MAX) {
        cout << "O custo do caminho mínimo utilizando o algoritmo Dijstra é: " << grafo->getNode(idNode2)->getDist() << endl;
    } else {
        cout << "Nao existe caminho entre os dois vértices apresentados." << endl;
    }

}


Node * AlgoritmoDijkstra::findNoMimDist(vector<Node *> nodes) {
    Node *nodeDistMinimal = nodes.front();

    for (auto i = nodes.begin(); i != nodes.end(); i++) {
        Node *node = *i;
        if (node->getDist() < nodeDistMinimal->getDist()) {
            nodeDistMinimal = node;
        }
    }
    return nodeDistMinimal;
}