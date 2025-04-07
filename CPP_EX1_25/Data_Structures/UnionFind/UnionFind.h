//reutbechor@gmail.com
#pragma once

namespace graph {

class UnionFind {
private:
    int* parent;
    int* rank;
    int size;

public:
    UnionFind(int size);
    ~UnionFind();
    int find(int x);
    void unionSets(int x, int y);
    bool areConnected(int x, int y);
};

}