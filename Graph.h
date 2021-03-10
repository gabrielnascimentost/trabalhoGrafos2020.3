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
#include <sstream>

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
        stringstream stringAux;


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
        Node* getNode(int id); // retorna um ponteiro pro vertice
        Edge* getEdge(int id, int idTarget);

        //Other methods
        void insertNode(int id); // insere vertice
        void insertEdge(int id, int target_id, float weight); //insere aresta
        void removeNode(int id);// remove vertice
        bool searchNode(int id); //verifica se o vertice existe no grafo
        void setArestasGrafo(const vector<Edge *> &arestasGrafo);
        bool ehConexo();
        vector<Node*> verificaCaminho(Node* vertice,int indice,vector<Node*> visitados );
        list<Edge*> criaListaArestas();
        vector<Edge*> arestasGrafo;
        vector<Node*> nosGrafo; //nos do grafo ordenados em um vetor
        const vector<Edge *> &getArestasGrafo() const;


        //methods phase1
        string topologicalSorting(); // ordenacao topologica de um DAG
        void breadthFirstSearch(int id); //busca em largura a partir de um no
        void auxBreadthFirstSearch(vector<Node*> nosFila); //busca em largura a partir de um no
        Graph* getVertexInduced(int* listIdNodes, int tam); // subvertice induzido

        //methods phase2
        float greed(Node* verticeQualquer, list<int> solucao); // algoritmo guloso
        float greedRandom(); // guloso randomizado
        float greedRactiveRandom(); // guloso randomizado reativo

        const vector<Node *> &getNosGrafo() const;
        void setNosGrafo(const vector<Node *> &nosGrafo);
        void printGraph()


};

#endif // GRAPH_H_INCLUDED
