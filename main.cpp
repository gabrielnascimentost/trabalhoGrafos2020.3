#include <iostream>
#include <string>
#include <stdlib.h>
#include "Graph.h"
#include "AlgoritmoKruskal.h"
#include "AlgoritmoDijkstra.h"
#include "AlgoritmoPrim.h"
#include "AlgoritmoFloyd.h"

using namespace std;

Graph* leitura(ifstream& input_file, int directed, int weightedEdge, int weightedNode){

    //Variáveis para auxiliar na criação dos nós no Grafo
    int idNodeSource; //partida da aresta
    int idNodeTarget; //vertice alvo para arestas
    int order; //ordem

    //Pegando a ordem do grafo
    input_file >> order;

    //Criando objeto grafo
    Graph* graph = new Graph(order, directed, weightedEdge, weightedNode); /* criando novo grafo passando como parametro (ordem, direcionado,
    peso nas arestas,e peso nos vertices )*/

    //Leitura de arquivo

    if(!graph->getWeightedEdge() && !graph->getWeightedNode()){ //se o grafo nao tiver peso nas arestas nem nos vertices

        while(input_file >> idNodeSource >> idNodeTarget) {// le linha por linha
            if(!graph->searchNode(idNodeSource)){
                graph->insertNode(idNodeSource);
            }
            if(!graph->searchNode(idNodeTarget)){
                graph->insertNode(idNodeTarget);
            }
            graph->insertEdge(idNodeSource, idNodeTarget, 0);//insira uma nova aresta do vertice inicial para o vertice alvo

        }

    }else if(graph->getWeightedEdge() && !graph->getWeightedNode() ){//se  o grafo tiver peso nas arestas mas nao nos nós

        float edgeWeight;//cria uma variavel com o peso das arestas

        while(input_file >> idNodeSource >> idNodeTarget >> edgeWeight) { //enquanto nao sei o q
            if(!graph->searchNode(idNodeSource)){
                graph->insertNode(idNodeSource);
            }
            if(!graph->searchNode(idNodeTarget)){
                graph->insertNode(idNodeTarget);
            }
            graph->insertEdge(idNodeSource, idNodeTarget, edgeWeight);//insira uma nova aresta no grafo, passando o vertice de partida, vertice alvo, e o peso da aresta.

        }

    }else if(graph->getWeightedNode() && !graph->getWeightedEdge()){ // se o grafo tiver peso nos vertices mas nao nas arestas

        float nodeSourceWeight, nodeTargetWeight;//declara o peso dos 2 vertices

        while(input_file >> idNodeSource >> nodeSourceWeight >> idNodeTarget >> nodeTargetWeight) { // deve ser o metodo de escrita, ainda nao sei
            if(!graph->searchNode(idNodeSource)){
                graph->insertNode(idNodeSource);
                graph->getNode(idNodeSource)->setWeight(nodeSourceWeight);//retorna o no de partida e insere o peso
            }
            if(!graph->searchNode(idNodeTarget)){
                graph->insertNode(idNodeTarget);
                graph->getNode(idNodeTarget)->setWeight(nodeTargetWeight);// retorna o no alvo e insere o peso
            }
            graph->insertEdge(idNodeSource, idNodeTarget, 0);// insere nova aresta com peso 0 na aresta
        }

    }else if(graph->getWeightedNode() && graph->getWeightedEdge()){// se o grafo tiver peso nos vertices e nas arestas

        float nodeSourceWeight, nodeTargetWeight, edgeWeight;//declara as variaveis dos pesos

        while(input_file >> idNodeSource >> nodeSourceWeight >> idNodeTarget >> nodeTargetWeight) { //ainda nao entendi
            if(!graph->searchNode(idNodeSource)){
                graph->insertNode(idNodeSource);
                graph->getNode(idNodeSource)->setWeight(nodeSourceWeight);//retorna o no de partida e insere o peso
            }
            if(!graph->searchNode(idNodeTarget)){
                graph->insertNode(idNodeTarget);
                graph->getNode(idNodeTarget)->setWeight(nodeTargetWeight);// retorna o no alvo e insere o peso
            }
            graph->insertEdge(idNodeSource, idNodeTarget, edgeWeight);// insere nova aresta com no de partida, no alvo e peso como parametros
        }

    }

    return graph;//retorna o grafo
}

//Graph* leituraInstancia(ifstream& input_file, int directed, int weightedEdge, int weightedNode){
//
//    //Variáveis para auxiliar na criação dos nós no Grafo
//    int idNodeSource;
//    int idNodeTarget;
//    int order;
//    int numEdges;
//
//    //Pegando a ordem do grafo
//    input_file >> order;
//
//    //Criando objeto grafo
//    Graph* graph = new Graph(order, directed, weightedEdge, weightedNode);
//
//    //Leitura de arquivo
//    while(input_file >> idNodeSource >> idNodeTarget) {
//            if(!graph->searchNode(idNodeSource)){
//                graph->insertNode(idNodeSource);
//            }
//            if(!graph->searchNode(idNodeTarget)){
//                graph->insertNode(idNodeTarget);
//            }
//            graph->insertEdge(idNodeSource, idNodeTarget, 0);
//
//    }
//
//    return graph;
//}

int menu(){

    int selecao;

    cout << "----" << endl;
    cout << "----" << endl;
    cout << "[1] Subgrafo induzido por conjunto de vértices" << endl;
    cout << "[2] Caminho Mínimo entre dois vértices - Dijkstra" << endl;
    cout << "[3] Caminho Mínimo entre dois vértices - Floyd" << endl;
    cout << "[4] Árvore Geradora Mínima de Prim" << endl;
    cout << "[5] Árvore Geradora Mínima de Kruskal" << endl;
    cout << "[6] Imprimir caminhamento em largura" << endl;
    cout << "[7] Imprimir ordenacao topológica" << endl;
    cout << "[8] Algoritmo Guloso" << endl;
    cout << "[9] Algoritmo Guloso Randomizado " << endl;
    cout << "[10] Algoritmo Guloso Randomizado Reativo" << endl;
    cout << "[0] Sair" << endl;
    cout << "----" << endl;
    cout << "Opção escolhida: " << endl;
    cin >> selecao;

    return selecao;

}

void selecionar(int selecao, Graph* graph, ofstream& output_file){

    switch (selecao) {

        //Subgrafo induzido por um conjunto de vértices X (1)
        case 1:{
            cout<<"Digite o numero de vertices: "<<endl;
            int num;
            cin>>num;
            int * vet = new int[num];
            for(int i=0; i<num; i++)
            {
                cout<<"Digite o vertice["<<i<<"]=";
                cin>>vet[i];
            }
            Graph * b = graph->getVertexInduced(vet,num);
            if(b != NULL)
            {
                b->printGraph();
                delete b;
            }

            delete []vet;
            break;
        }
            //Caminho mínimo entre dois vértices usando Dijkstra (2)
        case 2:{
            int id1, id2;
            cout << "Digite os IDs dos vertices:" << endl;
            cin >> id1 >> id2;
            AlgoritmoDijkstra::doDijkstra(graph, id1,id2);
            break;
        }

            //Caminho mínimo entre dois vértices usando Floyd (3)
        case 3:{

            break;
        }

            //AGM Prim; (4)
        case 4:{
            Graph *newAGM;
            newAGM = AlgoritmoPrim::findAGMPrim(graph);
            string optionUser;
            cout << "Deseja imprimir a solucao (S ou N)? ";
            cin >> optionUser;
            if(optionUser == "S"){
                AlgoritmoPrim::printSolution(newAGM);
            }
            delete newAGM;
            break;
        }

           //AGM - Kruscal; (5)
        case 5:{
            Graph *newAGM;
            newAGM = AlgoritmoKruskal::findAGMKruskal(graph);
            string optionUser;
            cout << "Deseja imprimir a solucao (S ou N)? ";
            cin >> optionUser;
            if(optionUser == "S"){
                AlgoritmoKruskal::imprimeSolucao(newAGM);
            }
            delete newAGM;
            break;
        }

            //Busca em largura; (6)
        case 6:{
            int idNodeSearch;
            cout << "Para realizar a busca em largura, informe o id do No: ";
            cin >> idNodeSearch;
            if(graph->searchNode(idNodeSearch)){
                cout << "Realizando busca em largura..." << endl;
                graph->breadthFirstSearch(idNodeSearch);
                return;
            }
            cout << "No nao encontrado no grafo" << endl;
            break;
        }
            //Ordenação Topologica; (7)
        case 7:{
            graph->topologicalSorting();
            break;
        }
            //Algoritmo Guloso (8)
        case 8: {
            list<int> solucaoGuloso;
            float peso = graph->greed(graph->nosGrafo.front(),solucaoGuloso);
            cout << "Solucao Gulosa: " << peso;
            break;
        }
            //Algoritmo Guloso Randomizado (9)
        case 9: {
            graph->greedRandom();
            break;
        }
            //Algoritmo Guloso Randomizado Reativo (10)
        case 10:{
            cout << " Funcionalidade nao disponivel neste trabalho." << endl;
            break;
        }
        case 0:{
            cout << "Bye bye!" << endl;
            break;
        }
        default:
        {
            cout << " Error!!! invalid option!!" << endl;
        }

    }
}

int mainMenu(ofstream& output_file, Graph* graph){

    int selecao = 1;

    while(selecao != 0){
        system("clear");
        selecao = menu();

        if(output_file.is_open())
            selecionar(selecao, graph, output_file);

        else
            cout << "Unable to open the output_file" << endl;

        output_file << endl;

    }

    return 0;
}


int main(int argc, char const *argv[]) {

    //Verificação se todos os parâmetros do programa foram entrados
    if (argc != 6) {

        cout << "ERROR: Expecting: ./<program_name> <input_file> <output_file> <directed> <weighted_edge> <weighted_node> " << endl;
        return 1;

    }

    string program_name(argv[0]);
    string input_file_name(argv[1]);

    string instance;
    if(input_file_name.find("v") <= input_file_name.size()){
        string instance = input_file_name.substr(input_file_name.find("v"));
        cout << "Running " << program_name << " with instance " << instance << " ... " << endl;
    }

    //Abrindo arquivo de entrada
    ifstream input_file;
    ofstream output_file;
    input_file.open(argv[1], ios::in);
    output_file.open(argv[2], ios::out | ios::trunc);



    Graph* graph;

    if(input_file.is_open()){

        graph = leitura(input_file, atoi(argv[3]), atoi(argv[4]), atoi(argv[5]));

    }else
        cout << "Unable to open " << argv[1];


    mainMenu(output_file, graph);



    //Fechando arquivo de entrada
    input_file.close();

    //Fechando arquivo de saída
    output_file.close();

    return 0;
}

//int main(){
//    string input_file_name("C:\\Users\\Pichau\\CLionProjects\\trabalhoGrafos2020.3\\testeConexo.txt");
//    string instance;
//
//    if(input_file_name.find("v") <= input_file_name.size()){
//        string instance = input_file_name.substr(input_file_name.find("v"));
//        cout << "Running with instance " << instance << " ... " << endl;
//    }
//
//    //Abrindo arquivo de entrada
//    ifstream input_file;
//    ofstream output_file;
//    input_file.open("C:\\Users\\Pichau\\CLionProjects\\trabalhoGrafos2020.3\\testeConexo.txt", ios::in);
//    output_file.open("C:\\Users\\Pichau\\CLionProjects\\trabalhoGrafos2020.3\\saida.txt", ios::out | ios::trunc);
//
//
//
//    Graph* graph;
//
//    if(input_file.is_open()){
//
//        graph = leitura(input_file, 0, 0, 0);
//
//    }else
//        cout << "Unable to open " << "testeConexo.txt";
//
//
//    mainMenu(output_file, graph);
//
//
//
//    //Fechando arquivo de entrada
//    input_file.close();
//
//    //Fechando arquivo de saída
//    output_file.close();
//
//    return 0;
//
//
//}