#include "Graph.h"
#include "Node.h"
#include "Edge.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

class AlgoritmoKruskal {
public:
    static Graph* findAGMKruskal(Graph *grafo); // encontra a arvore geradora minima usando kruskal
    static bool ehCiclo(Node *vertice1, Node *vertice2); // confere se o vertice 1 e 2 passado por parametro geram ciclo
    static void imprimeSolucao(Graph *grafo); // imprime soluçao da agm caso a pessoa queira
};