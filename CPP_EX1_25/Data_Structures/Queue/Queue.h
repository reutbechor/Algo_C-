//reutbechor@gmail.com
#pragma once

namespace graph {
    class Queue {
    private:
        int* data;
        int capacity;
        int front;
        int rear;
        int size;

    public:
        Queue(int capacity = 100);
        ~Queue();
        void enqueue(int value);
        int dequeue();
        bool isEmpty();
        bool isFull();
    };
}
