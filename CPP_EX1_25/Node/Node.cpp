//reutbechor@gmail.com
#include "Node.h"

namespace graph{
    Node::Node(int vartexDest, int weight, Node* neighbor){
        this-> vartexDest = vartexDest;
        this-> weight = weight;
        this-> neighbor = neighbor;
    }
}