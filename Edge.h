/**************************************************************************************************
 * Implementation of the TAD Edge
**************************************************************************************************/

#ifndef EDGE_H_INCLUDED
#define EDGE_H_INCLUDED

using namespace std;

// Definition of the Edge class
class Edge{

    // Attributes
    private:
        int id;
        int target_id;
        Edge* next_edge;
        float weight;

    public:
        // Constructor
        Edge(int target_id);
        Edge(int id, int target_id);

    Edge(int id, int targetId, float weight);

    Edge(int id, int targetId, Edge *nextEdge, float weight);

    Edge();
    // Destructor
        ~Edge();
        // Getters
        int getId();
        int getTargetId();
        Edge* getNextEdge();
        float getWeight();
        // Setters
        void setNextEdge(Edge* edge);
        void setWeight(float weight);
        void setId(int id);
        void setTargetId(int targetId);

}; 

#endif // EDGE_H_INCLUDED