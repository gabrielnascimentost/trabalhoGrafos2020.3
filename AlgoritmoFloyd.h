//
// Created by Pichau on 08/03/2021.
//

#ifndef TRABALHOGRAFOS2020_3_ALGORITMOFLOYD_H
#define TRABALHOGRAFOS2020_3_ALGORITMOFLOYD_H

#include <string>
#include <vector>
#include "Graph.h"

using namespace std;

class AlgoritmoFloyd {

public:
    AlgoritmoFloyd(Graph *grafo);
    virtual ~AlgoritmoFloyd();
    int floyd(string idOrigem, string idDestino);

private:
    vector<vector<int>>* floydAux();
    Graph *grafo;
};


#endif //TRABALHOGRAFOS2020_3_ALGORITMOFLOYD_H
