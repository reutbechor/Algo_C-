//reutbechor@gmail.com
#pragma once

namespace graph {

class Node {
public:
    int vartexDest;
    int weight;
    Node* neighbor;

    Node(int vartexDest, int weight, Node* neighbor);
};

}
