#include "PriorityQueue.h"
#include <stdexcept>

namespace graph {

// Constructor: create a new array for the queue with given capacity
PriorityQueue::PriorityQueue(int capacity) : capacity(capacity), size(0) {
    elements = new PQElement[capacity]; // allocate memory for elements
}

// Destructor: free the memory we used for the array
PriorityQueue::~PriorityQueue() {
    delete[] elements;
}

void PriorityQueue::insert(int vertex, int weight) {
    if (size >= capacity) {
        throw std::overflow_error("PriorityQueue is full");
    }

    // Add new element at the end of the array
    elements[size].vertex = vertex;
    elements[size].weight = weight;
    size++;
}

int PriorityQueue::minPQ() {
    if (isEmpty()) {
        throw std::underflow_error("PriorityQueue is empty");
    }

    // Find the index of the element with the smallest weight
    int minIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (elements[i].weight < elements[minIndex].weight) {
            minIndex = i;
        }
    }

    int result = elements[minIndex].vertex;

    // Remove the element by shifting everything after it one step left
    for (int i = minIndex; i < size - 1; ++i) {
        elements[i] = elements[i + 1];
    }

    size--; // decrease the number of elements
    return result; // return the vertex with the smallest weight
}

bool PriorityQueue::isEmpty() {
    return size == 0; // true if queue has no elements
}

}
