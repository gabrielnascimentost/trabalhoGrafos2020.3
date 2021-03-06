
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
#include <list>
#include <algorithm>
#include "AlgoritmoKruskal.h"

using namespace std;

/**************************************************************************************************
 * Defining the Graph's methods
**************************************************************************************************/

// Constructor
Graph::Graph(int order, bool directed, bool weighted_edge, bool weighted_node) //construtor, passando como parametro, ordem, direção se tem ou nao, peso da aresta e peso do no
{

    this->order = order;//ordem vai receber ordem
    this->directed = directed;//direção se tem ou nao
    this->weighted_edge = weighted_edge;//define peso das arestas (se tem ou nao)
    this->weighted_node = weighted_node;//peso nos vertices
    this->first_node = this->last_node = nullptr;//primeiro e ultimo no alocado como null
    this->number_edges = 0;//numero de arestas 0
}

Graph::Graph() {}

// Destructor
Graph::~Graph()
{

    Node *next_node = this->first_node;//o proximo no vai ser dito como o primeiro

    while (next_node != nullptr)//enquanto proximo no diferente de null
    {

        next_node->removeAllEdges();//remove todas as arestas do proximo no
        Node *aux_node = next_node->getNextNode();//no auxiliar vai ser o proximo vertice do proximo vertice
        delete next_node;//deleta o proximo vertice
        next_node = aux_node;//proximo no vai ser igual ao no auxiliar
    }
}

// Getters
int Graph::getOrder()//pega ordem(numero de vertices)
{

    return this->order;//retorna ordem do grafo
}
int Graph::getNumberEdges()//pega numero de arestas
{

    return this->number_edges;//retorna numero de arestas
}
//Function that verifies if the graph is directed
bool Graph::getDirected()//verifica se é direcionado
{

    return this->directed;//retorna se é direcionado ou nao
}
//Function that verifies if the graph is weighted at the edges
bool Graph::getWeightedEdge()//pega peso da aresta
{

    return this->weighted_edge;//retorna o peso da aresta
}

//Function that verifies if the graph is weighted at the nodes
bool Graph::getWeightedNode()//pega peso do vertice
{

    return this->weighted_node;//retorna peso do vertice
}


Node *Graph::getFirstNode()//pega o primeiro vertice
{

    return this->first_node;//retorna o primeiro vertice
}

Node *Graph::getLastNode()//pega o ultimo vertice
{

    return this->last_node;//retorna o ultimo vertice
}

// Other methods
/*
    The outdegree attribute of nodes is used as a counter for the number of edges in the graph.
    This allows the correct updating of the numbers of edges in the graph being directed or not.
*/
void Graph::insertNode(int id)//insere vertice passando id
{
    if(searchNode(id)){//pesquisa o id do vertice
        cout << "O no jah existe no grafo.\n";//se ja existir printa que ja existe
        return;//e volta
    }
    Node *no = new Node(id);//aloca um novo no dinamicamente
    nosGrafo.push_back(no);//cria um novo no
    cout << "No inserido com sucesso.\n";//printa que foi inserido com sucesso
}

void Graph::insertEdge(int id, int target_id, float weight)//inseri aresta passando id do vertice de origem, vertice alvo, e o peso
{
    if(!nosGrafo.empty()){
        if(!searchNode(id)){//se nao existir o no
            cout << "O no de origem nao existe no grafo.\n";//printa que nao tem vertice
            return;//e volta
        }else if(!searchNode(target_id)){//se nao existir o vertice alvo
            cout << "O no destino nao existe no grafo.\n";//printa que nao existe
            return;//e volta
        }
        else{//caso tenha os 2
            Edge *auxEdge = new Edge(id, target_id);
            arestasGrafo.push_back(auxEdge);
            nosGrafo[id]->insertEdge(id, target_id,weight);//insere aresta no grafo passando o vertice inicial, final e peso
            nosGrafo[id]->setLastEdge(auxEdge);
            cout << "Aresta inserida com sucesso!\n";//printa aresta inserida com sucesso
        }
    }
}

void Graph::removeNode(int id){ //remove vertice
    if(!searchNode(id)){//se o vertice nao existe no grafo entra no if
        cout << "O no nao existe no grafo!\n";//o vertice nao existe
    }
    delete (nosGrafo[id]);//se existe deleta esse vertice
    nosGrafo.erase(nosGrafo.begin() + id - 1);//apaga o no e diminui o id em 1
}

bool Graph::searchNode(int id)//pesquisa vertice
{
    for (int i = 0; i < nosGrafo.size(); i++)//percorre os vertices do grafo
        if (nosGrafo[i]->getId() == id)//se o id do vertice passado for igual
            return true;//retorna que existe o vertice
    return false;//se nao, retorna falso
}

Node *Graph::getNode(int id)//pega vertice pelo id
{
    if(!searchNode(id)){//pesquisa o vertice no grafo, se ele nao existir (!true = false && !false == true (ou seja se ele for falso vai entrar no if))
        cout << "O no nao existe no grafo!\n";//o vertice nao existe
    }
    return nosGrafo[id];//se existir retorna o vertice
}

const vector<Edge *> &Graph::getArestasGrafo() const {
    return arestasGrafo;
}

void Graph::setArestasGrafo(const vector<Edge *> &arestasGrafo) {
    Graph::arestasGrafo = arestasGrafo;
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
    AlgoritmoKruskal *algoritmoKruskal;
    return algoritmoKruskal->findAGMKruskal(this);
}

void Graph::imprimeSolucaoKuskal(Graph *graph) {
    AlgoritmoKruskal *algoritmoKruskal;
    algoritmoKruskal->imprimeSolucao(graph);
}

Graph* Graph::agmPrim(){

}

vector<Node*> Graph::verificaCaminho(Node* v,int indice, vector<Node*> visitados) //verifica se há caminho no grafo, passando o vertice inicial, o indice e o vetor que vai retornar
{
    visitados[indice]=v;//insere o primeiro vertice no primeiro indice do vetor
    indice++;//sobe o indice
    if(v->getFirstEdge()!=nullptr)//se a primeira aresta deste vertice é diferente de null
    {
       if(v->hasEdgeBetween(v->getNextNode()->getId())!=nullptr)//e se há aresta entre esse vertice e o proximo
        {
           for (int i = 0; i < indice; i++)//verifica nos visitados
            {
               if(v->getNextNode() != visitados[i])//se o vertice ainda nao foi visitado
                {
                    verificaCaminho(v->getNextNode(),indice,visitados);//entra recursivamente para inserir esse vertice no vetor solução
                }
                else//se o vertice ja esta no vetor solução nao faz nada
                {

                }
            }
        }

    }
    else // se a aresta nao existe no vertice testado
    {
        //nao faz nada
    }
    return visitados;

}

bool Graph::ehConexo(){ // verifica se o grafo é conexo

    vector<Node*> vet;// cria um vetor soluçao que sera verificado
    if(this->first_node == nullptr || this->first_node == this->last_node)//verifica se é um grafo vazio ou se tem somente uma aresta
    {
        return false;//se for o caso retorna que nao é conexo
    }
    else//em todos os outros casos
    {
        vet = verificaCaminho(this->first_node,0,vet);//verifica se tem pelo menos um caminho no grafo
        if(vet.size() == nosGrafo.size() )//depois da verificaçao se o tamanho do vetor for o mesmo do numero de vertices no grafo
        {
            return true;//retorna que é conexo
        }
        else//se nao for o mesmo
        {
            return false;//nao é conexo
        }

    }

}

list<Edge*> Graph::criaListaArestas()//cria um vetor com as arestas do grafo
{
    list<Edge*> Arestas;//cria uma lista de arestas
    for(auto i=this->first_node->getFirstEdge(); i != this->getLastNode()->getLastEdge(); i->getNextEdge() )//começa do inicio e pega todas as arestas do grafo
    {
       Arestas.push_back(i);//aloca de forma dinamica na lista as arestas
    }
    return Arestas;//retorna o vetor no final para ser usado
}

Edge * Graph::getMimWeightEdge(Graph *g, Graph *agmPrim) {

}