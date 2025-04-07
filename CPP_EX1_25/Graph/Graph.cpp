#include "Graph.h"
#include "../Node/Node.h"
#include <iostream>
#include <stdexcept>
using namespace std;

namespace graph {

    // Constructor: create the adjacency list and set each node to nullptr
    Graph::Graph(int numVertices) {
        this->numVertices = numVertices;
        neighborList = new Node*[numVertices];
        for (int i = 0; i < numVertices; ++i) {
            neighborList[i] = nullptr; // no neighbors yet
        }
    }

    // Destructor: free memory used by each linked list
    Graph::~Graph() {
        for (int i = 0; i < numVertices; ++i) {
            Node* current = neighborList[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->neighbor;
                delete temp; // delete each node
            }
        }
        delete[] neighborList; // delete the array of pointers
    }

    void Graph::addEdge(int source, int dest, int weight) {
        if (source < 0 || source >= numVertices || dest < 0 || dest >= numVertices) {
            return; // invalid index
        }
        if (hasEdge(source, dest)) {
            return; // don't add duplicates
        }

        // Add edge from source to dest
        Node* newNode1 = new Node(dest, weight, neighborList[source]);
        neighborList[source] = newNode1;

        // Add edge from dest to source (undirected graph)
        Node* newNode2 = new Node(source, weight, neighborList[dest]);
        neighborList[dest] = newNode2;
    }

    void Graph::printGraph() {
        for (int i = 0; i < numVertices; ++i) {
            std::cout << "Vertex " << i << ":";
            Node* current = neighborList[i];
            while (current != nullptr) {
                std::cout << " -> " << current->vartexDest
                          << " (weight: " << current->weight << ")";
                current = current->neighbor;
            }
            cout << endl;
        }
    }

    void Graph::removeEdge(int source, int dest) {
        if (source < 0 || source >= numVertices || dest < 0 || dest >= numVertices) {
            throw invalid_argument("The edge does not exist");
        }

        bool removedSrc = false;
        bool removedDest = false;

        // Remove edge from source to dest
        Node* current = neighborList[source];
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->vartexDest == dest) {
                if (prev == nullptr)
                    neighborList[source] = current->neighbor;
                else
                    prev->neighbor = current->neighbor;
                delete current;
                removedSrc = true;
                break;
            }
            prev = current;
            current = current->neighbor;
        }

        // Remove edge from dest to source
        current = neighborList[dest];
        prev = nullptr;
        while (current != nullptr) {
            if (current->vartexDest == source) {
                if (prev == nullptr)
                    neighborList[dest] = current->neighbor;
                else
                    prev->neighbor = current->neighbor;
                delete current;
                removedDest = true;
                break;
            }
            prev = current;
            current = current->neighbor;
        }

        if (!removedSrc || !removedDest) {
            throw invalid_argument("The edge does not exist");
        }
    }

    bool Graph::hasEdge(int source, int dest) {
        if (source < 0 || source >= numVertices || dest < 0 || dest >= numVertices) {
            return false;
        }

        Node* current = neighborList[source];
        while (current != nullptr) {
            if (current->vartexDest == dest) {
                return true; // found the edge
            }
            current = current->neighbor;
        }
        return false; // edge not found
    }

    int Graph::getNumVertices() {
        return numVertices;
    }

    Node* Graph::getNeighbors(int vertix) {
        if (vertix < 0 || vertix >= numVertices) {
            throw std::invalid_argument("invalid verteix");
        }
        return neighborList[vertix]; // return head of linked list
    }

    bool Graph::isEqualsGraph(Graph& other) {
        if (numVertices != other.getNumVertices()) return false;

        for (int i = 0; i < numVertices; ++i) {
            Node* current = neighborList[i];
            while (current != nullptr) {
                int dest = current->vartexDest;
                int weight = current->weight;

                // Check if this edge exists in the other graph
                bool found = false;
                Node* otherNeighbors = other.getNeighbors(i);
                while (otherNeighbors != nullptr) {
                    if (otherNeighbors->vartexDest == dest && otherNeighbors->weight == weight) {
                        found = true;
                        break;
                    }
                    otherNeighbors = otherNeighbors->neighbor;
                }

                if (!found) return false;

                current = current->neighbor;
            }
        }

        return true; // all edges matched
    }

    bool Graph::isNonnegativeGraph() {
        for (int i = 0; i < numVertices; ++i) {
            Node* current = neighborList[i];
            while (current != nullptr) {
                if (current->weight < 0) {
                    return false; // found a negative weight
                }
                current = current->neighbor;
            }
        }
        return true; // all weights are non-negative
    }

}
