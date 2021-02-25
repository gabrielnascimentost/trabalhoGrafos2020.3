/**************************************************************************************************
 * Implementation of the TAD Node (Definiçoes para a classe dos vertices)
**************************************************************************************************/

#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
#include "Edge.h" // Include of the Edge class (incluindo o arestas.h)

using namespace std;

// Definition of the Node class (definiçoes da classe vertice)
class Node{ //classe vertice

    // Attributes (atributos)
    private:
        Edge* first_edge; //ponteiro para o primeiro aresta
        Edge* last_edge; // ponteiro para o ultimo aresta
        int id; // identificador do vertice
        unsigned int in_degree; // int sem sinal (nao sei oq) **deve ser o valor de entrada
        unsigned int out_degree;// int sem sinal (nao sei oq) ** e o valor de saida 
        float weight;// peso dos vertices
        Node* next_node;// proximo vertice

    public: // declaraçoes publicas
        // Constructor
        Node(int id); // construtor, passando como parametro o identificador do vertice
        // Destructor
        ~Node(); // destrutor
        // Getters (declaraçao dos gets)
        Edge* getFirstEdge();//retorna o primeiro aresta
        Edge* getLastEdge();//retorna o ultimo aresta
        int getId();//retorna o identificador
        int getInDegree();//retorna o valor de entrada do vertice *talvez seja
        int getOutDegree();//retorna o valor de saida do vertice *talvez seja
        float getWeight();//retorna o peso do vertice se houver
        Node* getNextNode();//retorna o proximo vertice
        // Setters (declaraçao do sets)
        void setNextNode(Node* node);//insere o proximo vertice
        void setWeight(float weight);//insere o peso no vertice
        // Other methods
        bool searchEdge(int target_id);//existe esse vertice no grafo? passando o id do vertice alvo
        void insertEdge(int target_id, float weight);//insere novo vertice passando como parametro id e peso (se houver), se nao houver passa 0
        void removeAllEdges();// remove todas as arestas
        int removeEdge(int id, bool directed, Node* target_node);// remove aresta
        void incrementOutDegree();//incrementa grau de saida
        void decrementOutDegree();//decrementa grau de saida
        void incrementInDegree();//incrementa grau de entrada
        void decrementInDegree();//decrementa grau de entrada
        Edge* hasEdgeBetween(int target_id);//tem aresta entre o vertice que foi chamado e o passado por parametro?
        // Auxiliar methods (metodos auxiliares)

};

#endif // NODE_H_INCLUDED
