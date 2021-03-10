
#include "Graph.h"
#include <iostream>
#include <queue>
#include <list>
#include <algorithm>

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
    return nosGrafo.at(id);//se existir retorna o vertice
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


/*float Graph::floydMarshall(int idSource, int idTarget){
    
}

   

float Graph::dijkstra(int idSource, int idTarget){
    
}

//function that prints a topological sorting
void Graph::topologicalSorting(){

}

Graph* Graph::getVertexInduced(int* listIdNodes){
    vector<int> *nosIdFromGrafo = new vector<int>(this->nosGrafo.size());


}

Graph* Graph::agmPrim(){

}
*/
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

/*Edge * Graph::getMimWeightEdge(Graph *g, Graph *agmPrim) {

}*/

const vector<Node *> &Graph::getNosGrafo() const {
    return nosGrafo;
}

void Graph::setNosGrafo(const vector<Node *> &nosGrafo) {
    Graph::nosGrafo = nosGrafo;
}


Edge * Graph::getEdge(int id, int idTarget) {
    for (auto edge : this->arestasGrafo) {
        if ((edge->getId() == id && edge->getTargetId() == idTarget)
            || (edge->getId() == id && edge->getTargetId()  == idTarget)) {
            return edge;
        }
    }
    return nullptr;
}

float Graph::greed(Node* proximovertice, list<int> solucao)
{
    float valorTotalPeso = 0;
    if(proximovertice!=nullptr)
    {   
        float menor = NULL;//atribui null pro menor
        int vertice1; //grava o id do vertice
        int vertice2; // e o vertice alvo da aresta
    
        for(auto i = proximovertice->getFirstEdge();i != proximovertice->getLastEdge(); i++)//percorre as arestas verificando a menor
        {
            if(menor = NULL)//se o menor ainda tiver null
            {
                menor = i->getWeight();//menor recebe o peso da aresta (primeira aresta)
                vertice1 = i->getId();//vertice 1 o id do vertice
                vertice2 = i->getTargetId();//vertice 2 o target do vertice
            }
            if(i->getWeight() < menor)//e assim verifica se o peso da aresta é menor que menor
            {//se for
                menor = i->getWeight();//menor recebe o peso
                vertice1 = i->getId();//pega o id do vertice inicial
                vertice2 = i->getTargetId();//e o id do vertice final
            }

        }   //feita a verificaçao de todas as arestas
        //inclui o id e o target id dos vertices
        solucao.push_back(vertice1);//adiciona o vertice a soluçao 
        solucao.push_back(vertice2); // e o vertice 2 tbm 
        valorTotalPeso = menor;//o valor total e o valor total mais o menor (no caso ele começaria com 0)
        valorTotalPeso += greed(getNode(vertice2),solucao,valorTotalPeso); // e o peso total recebe o peso conforme vai voltando na pilha de recursao
        return valorTotalPeso; // retorna o peso total    
    }
    else
    {
        return -1;
    }
}

float Graph::greedRandom()
{
    float pesoTotalArestas;//cria um valor que vai ser devolvido, um valor total do peso das arestas
    list<int> vetorSolucao = {}; //vetor solução com id e target id
    float menor = greed(nosGrafo[rand()],vetorSolucao,pesoTotalArestas);//variavel auxiliar para ser atualizada
    for(int i=0; i < 4;i++)//tirar uma media de 4 a 5 loops
    {
        float f = greed(nosGrafo[rand()],vetorSolucao,pesoTotalArestas);//recebe o primeiro valor
        if(menor > f )//e analisa se é menor que a variavel menor
        {
            menor = f;//se for menor vai receber f 
        }
    }
    pesoTotalArestas = menor;//depois de conferir com raizes randomicas pega a melhor soluçao
    return pesoTotalArestas;//e retorna o menor peso
}


string Graph::topologicalSorting() {
    stringAux.str(string());
    int tam = this->order;
    Node *auxNode = this->nosGrafo.at(0);
    Node *auxLastNode;
    Edge *auxEdge;
    queue<Node*> queueZeroOrder;
    queue<Node*> queueSolution;

    while (auxNode != NULL ) {
        if ( auxNode->getInDegree() == 0 ) {
            queueZeroOrder.push(auxNode);
        }
        auxNode = auxNode->getNextNode();
    }

    while ( !queueZeroOrder.empty() ) {
        auxLastNode = queueZeroOrder.front();
        queueZeroOrder.pop();
        queueSolution.push(auxLastNode);
        auxEdge = auxLastNode->getFirstEdge();
        while ( auxEdge != NULL ) {
            auxNode = this->getNode(auxEdge->getTargetId());
            auxNode->decrementInDegree();

            if ( auxNode->getInDegree() <= 0 ) {
                queueZeroOrder.push(auxNode);
            }
            auxEdge = auxEdge->getNextEdge();
        }
    }
    if ( queueSolution.size() != tam ) {
        stringAux << "existe um ciclo";
    } else {
        while ( !queueSolution.empty() ) {
            stringAux << queueSolution.front()->getId() << " - ";
            queueSolution.pop();
        }
    }
    return stringAux.str();
}


Graph * Graph::getVertexInduced(int *listIdNodes, int tam) {
    int *nodeVerify = new int[order];
    int *nodes = new int[order];
    int ind = 0;

    Graph* aux = new Graph();
    Node *node = nosGrafo.front();

    for(int i=0; i < order; ++i){
        nodeVerify[i] = 0;
        nodes[i] = node->getId();
        node = node->getNextNode();
    }

    for(int i = 0; i < tam; ++i)
    {
        if(!nosGrafo.at(listIdNodes[i])){
            cout<<"Node nao encontrado no grafo."<<endl;
            delete nodeVerify;
            delete nodes;
            return NULL;
        }

        if(!aux->searchNode(listIdNodes[i])){
            aux->insertNode(listIdNodes[i]);
        }

        for(int k = 0; k<tam ; k++){
            if(listIdNodes[i]==order)
                ind = k;
        }

        if(nodeVerify[ind] == 0){
            nodeVerify[ind] = 1;
        }else{
            cout<<"Nodes repetidos na lista."<<endl;
            delete nodeVerify;
            delete nodes;
            return NULL;
        }

        Node * v = getNode(listIdNodes[i]);
        vector<Edge*> auxEdges = arestasGrafo;
        for(int j=0; j<tam; j++)
        {
            if(listIdNodes[i]!=listIdNodes[j])
            {
                if(auxEdges.at(listIdNodes[j]))
                {
                    if(!aux->searchNode(listIdNodes[i]) && !aux->searchNode(listIdNodes[j]))
                    {
                        Edge * auxEdge = auxEdges.front();
                        while(auxEdge!=NULL)
                        {
                            if(auxEdge->getNextEdge()->getId() == listIdNodes[j])
                            {
                                Edge *auxEdgeK = new Edge(listIdNodes[i],listIdNodes[j],auxEdge->getWeight());
                                auxEdges.push_back(auxEdgeK);
                            }
                            auxEdge = auxEdge->getNextEdge();
                        }
                    }
                }
            }
        }
    }

    delete nodeVerify;
    delete nodes;
    return aux;
}



void Graph::printGraph() {
    cout << "Impressao Graph :" << endl;
    for (auto edge : arestasGrafo) {
        cout << "(" << edge->getId() << "," << edge->getTargetId() << ") ";
    }
    cout << endl;
}
