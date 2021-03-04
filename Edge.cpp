#include "Edge.h"
#include <iostream>

using namespace std;

/**************************************************************************************************
 * Defining the Edge's methods (definindo metodos das arestas)
**************************************************************************************************/

// Constructor
Edge::Edge(int id,int target_id){  // construtor da aresta passando como parametro o identificador do vertice alvo

    this->id = id; //defini identificador do vertice de partida
    this->target_id = target_id; // defini identificador do vertice alvo( de chegada )
    this->next_edge = nullptr; // proxima aresta declara como null
    this->weight = 0; // defini o peso como 0

}

Edge::Edge() {}

// Destructor
Edge::~Edge(){ // destrutor

    if (this->next_edge != nullptr){ //se a proxima aresta for diferente de null
        delete this->next_edge; // deleta a proxima aresta
        this->next_edge = nullptr; // proxima aresta igual a null
    }

}

// Getters
int Edge::getId()//get do id do vertice de partida da aresta
{
    return this->id;//retorna o id do vertice de partida da aresta
}
int Edge::getTargetId(){ // get do id do vertice alvo da aresta

    return this->target_id;//retorna o id do vertice alvo da aresta

}

Edge* Edge::getNextEdge(){ //get da proxima aresta

    return this->next_edge;// retorna a proxima aresta

}

float Edge::getWeight(){// get do peso da aresta

    return this->weight;//retorna o peso da aresta

}

// Setters
void Edge::setNextEdge(Edge* edge){ // set de valores da proxima aresta passando como parametro o ponteiro pra aresta

    this->next_edge = edge; // declara a proxima aresta como a aresta passada por parametro 

}

void Edge::setWeight(float weight){//set do peso da aresta

    this->weight = weight;//define o peso da aresta como o peso passado por parametro

}

