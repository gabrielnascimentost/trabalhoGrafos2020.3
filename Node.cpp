#include "Node.h"
#include "Edge.h"
#include <iostream>

using namespace std;

/**************************************************************************************************
 * Defining the Node's methods (definiçoes dos metodos do vertice)
**************************************************************************************************/

// Constructor
Node::Node(int id){ // construtor passando o identificador como parametro

    this->id = id; // seta o identificador
    this->in_degree = 0;// coloca grau de entrada como 0
    this->out_degree = 0;// coloca grau de saida como 0
    this->weight = 0;// declara peso 0
    this->first_edge = nullptr;//declara a primeira aresta como null
    this->last_edge = nullptr;//declara a ultima aresta como null
    this->next_node = nullptr;//poe o proximo vertice como null

};//fim do construtor

// Destructor
Node::~Node(){//destrutor

    Edge* next_edge = this->first_edge;//coloca o ponteiro para a proxima aresta como a primeira aresta a ser removida

    while(next_edge != nullptr){//enquanto proxima aresta diferente de null continua

        Edge* aux_edge = next_edge->getNextEdge();//aresta auxiliar recebe a proxima aresta da proxima aresta(aresta inicial)
        delete next_edge; //deleta a aresta inicial
        next_edge = aux_edge;// e coloca a variavel "proxima aresta" como a mesma aresta da auxiliar

    }//assim que deletar todas as arestas sai do loop

};//e acabou o destrutor

// Getters (declaraçoes de gets)
Edge* Node::getFirstEdge(){//pegar primeira aresta

    return this->first_edge;//retorna primeira aresta

}//fim do get de aresta

Edge* Node::getLastEdge(){//pegar ultima aresta

    return this->last_edge;//retorna a ultima aresta

}//fim do get ultima aresta

int Node::getId(){//pega o identificador do vertice

    return this->id;//retorna o identificador do vertice

}//fim do get identificador

int Node::getInDegree(){//pega grau de entrada

    return this->in_degree;//retorna grau de entrada

}//fim do get de grau de entrada

int Node::getOutDegree(){//pega grau de saida

    return this->out_degree;//retorna o grau de saida

}//fim do get de grau de saida

float Node::getWeight(){//pega o peso do vertice

    return this->weight;//retorna o peso do vertice

}//fim do get de peso do vertice

Node* Node::getNextNode(){//proximo vertice

    return this->next_node;//retorna o proximo vertice

}//fim do get do proximo vertice

// Setters (declaração dos sets)

void Node::setNextNode(Node* next_node){//inserir o proximo vertice passando como parrametro o proximo vertice a ser inserido

    this->next_node = next_node;//a variavel proximo vertice recebe o vertice que foi passado como parametro
 /*Explicaçao: voce chama a função no vertice que esta sem o proximo e passa o ponteiro para o proximo como parametro
 logo o ponteiro para o proximo vertice(que estava vazio) do no que voce chamou a funçao vai passar a ser o vertice que 
 voce passou como parametro*/
}

void Node::setWeight(float weight){//insere peso no vertice

    this->weight = weight;//insere peso no vertice

}

// Other methods (outros metodos)
void Node::insertEdge(int target_id, float weight){ //insere aresta passando como parametro o identificador e o peso
    // Verifies whether there are at least one edge in the node (faz a verificaçao se ja tem aresta no vertice)
    if(this->first_edge != nullptr){ //se a primeira aresta é diferente de null (é pq ja tem aresta)
        // Allocating the new edge and keeping the integrity of the edge list (aloca uma nova aresta e mantem a integridade da lista de arestas anteriores)
        Edge* edge = new Edge(target_id);//declara uma nova aresta
        edge->setWeight(weight);//coloca um peso, se nao tiver o padrao é 0
        this->last_edge->setNextEdge(edge);// a ultima aresta do vertice é declarada como proxima 
        this->last_edge = edge;// e a aresta é setada como a ultima (ou seja, a que foi implementada agora passa a ser a ultima e a antiga passa a ser a proxima)

    }
    else{ // se for a primeira aresta do vertice
         // Allocating the new edge and keeping the integrity of the edge list (alocaçao mantendo a integridade das arestas)
        this->first_edge = new Edge(target_id);//primeira aresta passa a receber uma nova aresta
        this->first_edge->setWeight(weight);//seta o peso da aresta (se houver)
        this->last_edge = this->first_edge;//ultima aresta e definida como a primeira

    }//fim da alocaçao de arestas

}

void Node::removeAllEdges(){ // remove todas as arestas
    // Verifies whether there are at least one edge in the node
    if(this->first_edge != nullptr){ // se a primeira aresta é dif de null ( se existe aresta no grafo)

        Edge* next = nullptr; //proxima aresta e declarada como null
        Edge* aux = this->first_edge;//aresta auxiliar e definida como a primeira
        // Removing all edges of the node (remove todas as arestas)
        while(aux != nullptr){// enquanto o auxiliar é diferente de null continua

            next = aux->getNextEdge();//proximo recebe o proximo do auxiliar
            delete aux;//deleta a aresta auxiliar
            /*OBS: acho que aqui deveria ter uma linha de codigo aux = next e ai repetir o processo*/
        } // sai do while

    }//sai do if

    this->first_edge = this->last_edge = nullptr; //se nao tem mais de uma aresta é pq tem uma ou zero, entao a primeira e a ultima sao colocadas como null

}//fim do removedor de todas as arestas

int Node::removeEdge(int id, bool directed, Node* target_node){  //remove uma aresta em especifico passando o identificador, se tem direção e o vertice alvo
    // Verifies whether the edge to remove is in the node
    if(this->searchEdge(id)){ // se a aresta existe (verifica se a aresta existe no grafo)

        Edge* aux = this->first_edge; // o auxiliar recebe a primeira aresta
        Edge* previous = nullptr; // o anterior recebe null
        // Searching for the edge to be removed (busca a aresta a ser removida)
        while(aux->getTargetId() != id){//enquanto o identificador do vertice auxiliar for diferente do identificador passado como paramentro, continua

            previous = aux;//o vertice anterior é igual ao auxiliar
            aux = aux->getNextEdge();//e o auxiliar recebe a proxima aresta

        } //assim que achar a aresta ele sai do while
        // Keeping the integrity of the edge list(mantendo a integridade da lista de arestas)
        if(previous != nullptr)//se o anterior for diferente de null
            previous->setNextEdge(aux->getNextEdge());//a proxima aresta do vertice recebe a proxima aresta do auxiliar

        else // se for null, é por que é a primeira aresta
            this->first_edge = aux->getNextEdge();//primeira aresta recebe a proxima aresta do auxiliar

        if(aux == this->last_edge)//se o auxiliar for igual a ultima aresta
            this->last_edge = previous;//a ultima aresta é igual a anterior

        if(aux->getNextEdge() == this->last_edge)//se a proxima aresta do auxiliar for igual a ultima aresta
            this->last_edge = aux->getNextEdge();//a ultima aresta recebe a proxima do auxiliar

        delete aux;//deleta a aresta do auxiliar
        // Verifies whether the graph is directed (verificaçao se o grafo e direcionado)
        if(directed)//se for direcionado
            this->decrementOutDegree();// reduz o grau de saida do vertice

        else{//se nao for direcionado

            this->decrementInDegree();//diminui o grau de entrada do vertice
            target_node->decrementInDegree();//diminui o grau de entrada do vertice alvo 

        }

        return 1;//retorna 1 e sai do if

    }//sai do "se existe aresta"

    return 0;//retorna 0 e sai da funçao de remoçao

}//sai da funçao de remoçao

bool Node::searchEdge(int target_id){ // existe aresta? passando o id como parametro
     // Verifies whether there are at least one edge in the node (verifica se existe aresta)
    if(this->first_edge != nullptr){ //se a primeira aresta é diferente de null
        // Searching for a specific edge of target id equal to target id (procura pela aresta especifica)
        for(Edge* aux = this->first_edge; aux != nullptr; aux = aux->getNextEdge())//começando com a primeira aresta, enquanto o auxiliar for diferente de null, aux recebe a proxima aresta
            if(aux->getTargetId() == target_id)//se o retorno do identificador da aresta for igual ao identificador passado
                return true;//retorna verdadeiro

    }//sai do if

    return false;//se percorreu tudo e nao achou, retorna falso

}//fim da busca pela aresta

void Node::incrementInDegree(){//incrementa o grau de entrada do vertice

    this->in_degree++;//grau do vertice de entrada recebe mais 1

}//fim

void Node::incrementOutDegree(){//incrementa grau de saida

    this->out_degree++;//grau de saida do vertice recebe mais 1

}

void Node::decrementInDegree(){//diminui o grau de entrada

    this->in_degree--;//grau de entrada recebe menos 1

}

void Node::decrementOutDegree(){//diminui o grau de saida

    this->out_degree--;//grau de saida recebe menos 1

}

Edge* Node::hasEdgeBetween(int target_id)//verifica se existe aresta entre passando o identificador como parametro
{

    for(Edge *auxEdge = this->first_edge; auxEdge != nullptr; auxEdge = auxEdge->getNextEdge())/*começando com a aresta auxiliar sendo
    igual a primeira aresta, enquanto a aresta auxiliar for diferente de null, a aresta auxiliar recebe a proxima aresta */
    {
        if(auxEdge->getTargetId() == target_id)//se o identificador da aresta for igual a passada como parametro
            return auxEdge;//retorna o ponteiro para essa aresta
    }//se sair é por que nao tem a aresta
    return nullptr;//portanto passe null caso nao encontre
}//fim da busca pela aresta
