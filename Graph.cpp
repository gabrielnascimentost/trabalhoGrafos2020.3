
#include "Graph.h"
#include "Node.h"
#include "Edge.h"
#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <list>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <float.h>
#include <iomanip>
#include <algorithm>

using namespace std;

/**************************************************************************************************
 * Defining the Graph's methods
**************************************************************************************************/

// Constructor
Graph::Graph(int order, bool directed, bool weighted_edge, bool weighted_node)
{

    this->order = order;
    this->directed = directed;
    this->weighted_edge = weighted_edge;
    this->weighted_node = weighted_node;
    this->first_node = this->last_node = nullptr;
    this->number_edges = 0;
}

// Destructor
Graph::~Graph()
{

    Node *next_node = this->first_node;

    while (next_node != nullptr)
    {

        next_node->removeAllEdges();
        Node *aux_node = next_node->getNextNode();
        delete next_node;
        next_node = aux_node;
    }
}

// Getters
int Graph::getOrder()
{

    return this->order;
}
int Graph::getNumberEdges()
{

    return this->number_edges;
}
//Function that verifies if the graph is directed
bool Graph::getDirected()
{

    return this->directed;
}
//Function that verifies if the graph is weighted at the edges
bool Graph::getWeightedEdge()
{

    return this->weighted_edge;
}

//Function that verifies if the graph is weighted at the nodes
bool Graph::getWeightedNode()
{

    return this->weighted_node;
}


Node *Graph::getFirstNode()
{

    return this->first_node;
}

Node *Graph::getLastNode()
{

    return this->last_node;
}

// Other methods
/*
    The outdegree attribute of nodes is used as a counter for the number of edges in the graph.
    This allows the correct updating of the numbers of edges in the graph being directed or not.
*/
void Graph::insertNode(int id)
{
    if(searchNode(id)){
        cout << "O no jah existe no grafo.\n";
        return;
    }
    Node *no = new Node(id);
    nosGrafo.push_back(no);
    cout << "No inserido com sucesso.\n";
}

void Graph::insertEdge(int id, int target_id, float weight)
{
    if(!searchNode(id)){
        cout << "O no de origem nao existe no grafo.\n";
        return;
    }else if(!searchNode(target_id)){
        cout << "O no destino nao existe no grafo.\n";
        return;
    }
    else{
        nosGrafo[id]->insertEdge(target_id,weight);
        cout << "Aresta inserida com sucesso!\n";
    }
}

void Graph::removeNode(int id){ 
    if(!searchNode(id)){
        cout << "O no nao existe no grafo!\n";
    }
    delete (nosGrafo[id]);
    nosGrafo.erase(nosGrafo.begin() + id - 1);
}

bool Graph::searchNode(int id)
{
    for (auto no : nosGrafo)
        if (no->getId() == id)
            return true;
    return false;
}

Node *Graph::getNode(int id)
{
    if(!searchNode(id)){
        cout << "O no nao existe no grafo!\n";
    }
    return nosGrafo[id];
}


//Function that prints a set of edges belongs breadth tree

void Graph::breadthFirstSearch(int idNo){
    Node *primeiro = getNode(idNo);
    vector<Node*> *filaNos = new vector<Node*>;
    filaNos->push_back(primeiro);
    auxBreadthFirstSearch(*filaNos);
}

void Graph::auxBreadthFirstSearch(vector<Node *> nosFila) {
    while(!nosFila.empty()){
        Node *auxNo = nosFila.front();
        cout << "No visitado:" << auxNo->getId() << endl;
        auxNo->setVisited(true);

        for(Node *adj : auxNo->getAdjNodes()){
            if(!adj->isVisited()){
                int aux = count(nosFila.begin(), nosFila.end(), adj);
                if(aux == 0){
                    nosFila.push_back(adj);
                }
            }
        }
        nosFila.erase(nosFila.begin());
    }
}


float Graph::floydMarshall(int idSource, int idTarget){
    
}

   

float Graph::dijkstra(int idSource, int idTarget){
    
}

//function that prints a topological sorting
void Graph::topologicalSorting(){

}

Graph* Graph::getVertexInduced(int* listIdNodes){
    vector<int> *nosIdFromGrafo = new vector<int>(this->nosGrafo.size());

}

Graph* Graph::agmKuskal(){

}
Graph* Graph::agmPrim(){

}
