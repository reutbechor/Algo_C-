#pragma once

namespace graph {

struct PQElement {//define a struct for pq use
    int vertex;
    int weight;
};

class PriorityQueue {
private:
    PQElement* elements;
    int capacity;
    int size;

public:
    PriorityQueue(int capacity = 100);
    ~PriorityQueue();
    void insert(int vertex, int weight);
    int minPQ(); // return the minimum and dequeue
    bool isEmpty();
};

}
