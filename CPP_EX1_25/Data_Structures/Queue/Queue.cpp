#include "Queue.h"
#include <stdexcept>

namespace graph {

    // Constructor: make a new array with given size and set initial positions
    Queue::Queue(int cap) : capacity(cap), front(0), rear(0), size(0) {
        data = new int[capacity]; // make space to hold the values
    }

    // Destructor: clean up the array memory
    Queue::~Queue() {
        delete[] data;
    }

    void Queue::enqueue(int value) {
        if (isFull()) {
            throw std::overflow_error("Queue is full");
        }

        data[rear] = value; // put the value at the end
        rear = (rear + 1) % capacity; // move rear forward (wrap around if needed)
        size++; // we added one item
    }

    int Queue::dequeue() {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }

        int value = data[front]; // take the value from the front
        front = (front + 1) % capacity; // move front forward (wrap around if needed)
        size--; // we removed one item
        return value;
    }

    bool Queue::isEmpty()  {
        return size == 0; // true if queue has no items
    }

    bool Queue::isFull() {
        return size == capacity; // true if queue is full
    }

}
