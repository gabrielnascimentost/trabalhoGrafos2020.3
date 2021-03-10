//
// Created by Pichau on 09/03/2021.
//

#include <iostream>
#include "AlgoritmoPrim.h"

Graph* AlgoritmoPrim::findAGMPrim(Graph *graph) {
    if (graph->ehConexo()) {
        auto *agmPrim = new Graph();

        auto *nodeInit = new (graph->getNosGrafo().front()->getId());
        agmPrim->arestasGrafo.push_back(nodeInit);

        while (agmPrim->getNosGrafo().size() < graph->getNosGrafo().size()) {
            Edge *edge = minimalEdge(graph, agmPrim);

            auto *node1 = new Node(edge->getId());
            auto *node2 = new Node(edge->getTargetId());

            if (!agmPrim->searchNode(node1->getId())) {
                agmPrim->nosGrafo.push_back(node1);
            }

            if (!agmPrim->searchNode(node2->getId())){
                agmPrim->nosGrafo.push_back(node2);
            }

            agmPrim->arestasGrafo.push_back(edge);
        }

        return agmPrim;
    } else {
        cout << "O grafo eh desconexo." << endl;
    }
}
}

Edge* AlgoritmoPrim::minimalEdge(Graph *graph, Graph *minimalAgmPrim) {
    auto *minimalWeightEdge = new Edge();
    int minimalWeight = numeric_limits<int>::max();

    for (auto edge : graph->arestasGrafo) {
        if (!(minimalAgmPrim->searchNode(edge->getId())
              && minimalAgmPrim->searchNode(edge->getTargetId()))) {
            if (minimalAgmPrim->searchNode(edge->getId())
                || minimalAgmPrim->searchNode(edge->getTargetId())) {
                if (edge->getWeight() < minimalWeight) {
                    minimalWeightEdge = edge;
                    minimalWeight = edge->getWeight();
                }
            }
        }
    }

    return minimalWeightEdge;

}

void AlgoritmoPrim::printSolution(Graph *graph) {
    cout << "Arvore Geradora Minima - Prim:" << endl;
    for (auto edge : graph->arestasGrafo) {
        cout << "(" << edge->getId() << "," << edge->getTargetId() << ") ";
    }
    cout << endl;
}