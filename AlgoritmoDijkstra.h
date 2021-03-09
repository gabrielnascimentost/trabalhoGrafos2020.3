//
// Created by Pichau on 08/03/2021.
//

#ifndef TRABALHOGRAFOS2020_3_ALGORITMODIJKSTRA_H
#define TRABALHOGRAFOS2020_3_ALGORITMODIJKSTRA_H


#include "Graph.h"

class AlgoritmoDijkstra {
public:
    static void doDijkstra(Graph *grafo, int idVertice1, int idVertice2);
    static Node *findNoMimDist(vector<Node *> nodes);
};


#endif //TRABALHOGRAFOS2020_3_ALGORITMODIJKSTRA_H
