//reutbechor@gmail.com
#pragma once
#include "../Node/Node.h"


namespace graph {
class Graph {
private:
    int numVertices;
    Node** neighborList;

public:
    Graph(int numVertices);
    ~Graph();
    void addEdge(int source, int dest, int weight = 1);
    void printGraph();
    void removeEdge(int source, int dest);
    bool hasEdge(int source, int dest);
    int getNumVertices();
    Node* getNeighbors(int vertix);
    bool isEqualsGraph(Graph& g);
    bool isNonnegativeGraph();


};

}