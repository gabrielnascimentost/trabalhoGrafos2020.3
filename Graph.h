/**************************************************************************************************
 * Implementation of the TAD Graph
**************************************************************************************************/

#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include "Node.h"
#include <fstream>
#include <stack>
#include <list>
#include <vector>

using namespace std;

class Graph{

    //Atributes
    private:
        int order; //ordem do grafo (numero de vertices)
        int number_edges; //numero de arestas
        bool directed; // direcionado? s ou n
        bool weighted_edge; // peso nas arestas? s ou n
        bool weighted_node; // peso nos vertices? s ou n
        Node* first_node; // primeiro vertice (nó)
        Node* last_node; // ultimo vertice (nó)
        vector<Node*> nosGrafo; //nos do grafo ordenados em um vetor
        vector<Edge*> arestasGrafo;

    public:
        //Constructor
        Graph(int order, bool directed, bool weighted_edge, bool weighted_node); // construtor de grafos com parametros
        Graph(); // construtor para ser usado em grafos auxiliares
        //Destructor
        ~Graph();
        //Getters
        int getOrder(); // retorna a ordem
        int getNumberEdges(); // retorna numero de arestas
        bool getDirected(); // retorna se é direcionado
        bool getWeightedEdge(); // retorna se tem peso nas arestas
        bool getWeightedNode(); // retorna se tem peso nos vertices
        Node* getFirstNode(); // retorna o primeiro vertice
        Node* getLastNode(); // retorna ultimo vertice
        //Other methods
        void insertNode(int id); // insere vertice
        void insertEdge(int id, int target_id, float weight); //insere aresta
        void removeNode(int id);// remove vertice
        bool searchNode(int id); //verifica se o vertice existe no grafo
        Node* getNode(int id); // retorna um ponteiro pro vertice

        //methods phase1
        void topologicalSorting(); // ordenacao topologica de um DAG
        void breadthFirstSearch(int id); //busca em largura a partir de um no
        void auxBreadthFirstSearch(vector<Node*> nosFila); //busca em largura a partir de um no
        Graph* getVertexInduced(int* listIdNodes); // subvertice induzido
        Graph* agmKuskal(); // metodo arvore geradora minima de kruskal
        Graph* agmPrim(); // arvore geradora minima de prim
        Edge* getMimWeightEdge(Graph *g, Graph *agmPrim);
        float floydMarshall(int idSource, int idTarget); // metodo floyd
        float dijkstra(int idSource, int idTarget); // metodo de busca dijkstra

        //methods phase1
        float greed(); // algoritmo guloso
        float greedRandom(); // guloso randomizado
        float greedRactiveRandom(); // guloso randomizado reativo
        float greedRactiveRandom();

    const vector<Edge *> &getArestasGrafo() const;

    void setArestasGrafo(const vector<Edge *> &arestasGrafo);
    // guloso randomizado reativo
    private:
        //Metodos Auxiliares
        bool ehConexo();
        void verificaCaminho(Node* vertice,int indice,vector<Node*> visitados );
        list<Edge*> criaListaArestas();
    private:
};

#endif // GRAPH_H_INCLUDED
