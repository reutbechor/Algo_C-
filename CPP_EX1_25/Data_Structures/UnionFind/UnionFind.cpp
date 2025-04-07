
#include "UnionFind.h"
#include <stdexcept>

namespace graph {

// Constructor: set each node to be its own parent
UnionFind::UnionFind(int size) : size(size) {
    parent = new int[size]; // array to hold parent of each node
    rank = new int[size];   // array to track tree depth
    for (int i = 0; i < size; ++i) {
        parent[i] = i;   // each node is its own parent
        rank[i] = 0;     // all ranks start at 0
    }
}

// Destructor: free the memory we used
UnionFind::~UnionFind() {
    delete[] parent;
    delete[] rank;
}

int UnionFind::find(int x) {
    if (x < 0 || x >= size) {
        throw std::out_of_range("Index out of range in find()");
    }

    // If x is not the root, go find its root (with path compression)
    if (parent[x] != x) {
        parent[x] = find(parent[x]); // make root point directly to the top
    }
    return parent[x]; // return the root
}

void UnionFind::unionSets(int x, int y) {
    int rootX = find(x); // find root of x
    int rootY = find(y); // find root of y

    if (rootX == rootY) return; // already connected

    // Union by rank: attach smaller tree under the larger one
    if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
    } else if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else {
        parent[rootY] = rootX;
        rank[rootX]++; // increase rank since we added to it
    }
}

bool UnionFind::areConnected(int x, int y) {
    return find(x) == find(y); // true if x and y have the same root
}

}
