//
// Created by Pichau on 09/03/2021.
//

#ifndef TRABALHOGRAFOS2020_3_ALGORITMOPRIM_H
#define TRABALHOGRAFOS2020_3_ALGORITMOPRIM_H


#include "Graph.h"
#include <limits>

class AlgoritmoPrim {
public:
    static Graph* findAGMPrim(Graph *graph);
    static Edge* minimalEdge(Graph *graph, Graph *minimalAgmPrim);
    static void printSolution(Graph *graph);
};


#endif //TRABALHOGRAFOS2020_3_ALGORITMOPRIM_H
