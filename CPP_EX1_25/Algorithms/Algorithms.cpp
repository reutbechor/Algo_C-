//reutbechor@gmail.com
#include "Algorithms.h"
#include "../Graph/Graph.h"
#include "../Node/Node.h" 
#include "../Data_Structures/Queue/Queue.h"
#include "../Data_Structures/PriorityQueue/PriorityQueue.h"
#include "../Data_Structures/UnionFind/UnionFind.h"
#include <stdexcept>

using namespace graph;

// BFS - builds and returns a BFS tree starting from 'start' node
Graph Algorithms::bfs(Graph& g, int start) {
    int numVertices = g.getNumVertices();

    if (start < 0 || start >= numVertices) {
        throw std::invalid_argument("Invalid start vertex");
    }

    bool* visited = new bool[numVertices];  // track which nodes were visited
    for (int i = 0; i < numVertices; ++i) {
        visited[i] = false;
    }

    Queue q(numVertices);
    Graph tree(numVertices);  // the BFS tree we will build

    q.enqueue(start);
    visited[start] = true;

    while (!q.isEmpty()) {
        int current = q.dequeue();
        Node* neighbor = g.getNeighbors(current);

        while (neighbor != nullptr) {
            int v = neighbor->vartexDest;
            if (!visited[v]) {
                visited[v] = true;
                q.enqueue(v);
                tree.addEdge(current, v, neighbor->weight);  // add edge to BFS tree
            }
            neighbor = neighbor->neighbor;
        }
    }

    delete[] visited;
    return tree;
}

// Recursive DFS helper function
void dfsVisit(Graph& g, int u, int* color, int* parent, int& time, Graph& tree) {
    color[u] = 1; // gray - visiting
    time++;

    Node* neighbors = g.getNeighbors(u);
    while (neighbors != nullptr) {
        int v = neighbors->vartexDest;
        if (color[v] == 0) { // white - not visited yet
            parent[v] = u;
            tree.addEdge(u, v, neighbors->weight); // add edge to DFS tree
            dfsVisit(g, v, color, parent, time, tree);
        }
        neighbors = neighbors->neighbor;
    }

    color[u] = 2; // black - done
    time++;
}

// DFS - builds and returns a DFS tree
Graph Algorithms::dfs(Graph& g, int start) {
    int numVertices = g.getNumVertices();

    if (start < 0 || start >= numVertices) {
        throw std::invalid_argument("Invalid start vertex");
    }

    int* color = new int[numVertices];   // 0 = white, 1 = gray, 2 = black
    int* parent = new int[numVertices];

    for (int i = 0; i < numVertices; ++i) {
        color[i] = 0;
        parent[i] = -1;
    }

    int time = 0;
    Graph tree(numVertices);
    dfsVisit(g, start, color, parent, time, tree);

    delete[] color;
    delete[] parent;
    return tree;
}

// Dijkstra algorithm - builds shortest path tree from 'start' node
Graph Algorithms::dijkstra(Graph& g, int start) {
    int numVertices = g.getNumVertices();

    if (start < 0 || start >= numVertices) {
        throw std::invalid_argument("the vertix does not exist");
    }

    if (!g.isNonnegativeGraph()) {
        throw std::invalid_argument("the graph has negative edge");
    }

    int* dist = new int[numVertices];      // shortest distance from start
    int* parent = new int[numVertices];    // parent in shortest path tree
    bool* visited = new bool[numVertices]; // has node been processed

    for (int i = 0; i < numVertices; ++i) {
        dist[i] = 999999999; // infinity
        parent[i] = -1;
        visited[i] = false;
    }

    dist[start] = 0;
    PriorityQueue pq(numVertices);
    pq.insert(start, 0);

    while (!pq.isEmpty()) {
        int u = pq.minPQ(); // get node with smallest distance
        visited[u] = true;

        Node* neighbor = g.getNeighbors(u);
        while (neighbor != nullptr) {
            int v = neighbor->vartexDest;
            int w = neighbor->weight;

            // Relaxation step
            if (!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.insert(v, dist[v]); // reinsert with updated distance
            }

            neighbor = neighbor->neighbor;
        }
    }

    Graph result(numVertices);
    for (int v = 0; v < numVertices; ++v) {
        if (parent[v] != -1) {
            result.addEdge(v, parent[v], dist[v] - dist[parent[v]]);
        }
    }

    delete[] dist;
    delete[] parent;
    delete[] visited;
    return result;
}

// Checks if the graph is connected using BFS
bool Algorithms::isConnectedGraph(Graph& g) {
    int numVertices = g.getNumVertices();
    if (numVertices == 1) {
        return true;
    }

    Graph bfsTree = bfs(g, 0); // start BFS from node 0

    for (int i = 0; i < numVertices; ++i) {
        // if node exists in graph but not in BFS tree => disconnected
        if (g.getNeighbors(i) != nullptr && bfsTree.getNeighbors(i) == nullptr && i != 0) {
            return false;
        }

        // if node has no neighbors at all => disconnected
        if (g.getNeighbors(i) == nullptr) {
            return false;
        }
    }

    return true;
}

// Prim's algorithm - builds and returns minimum spanning tree
Graph Algorithms::prim(Graph& g) {
    if (!isConnectedGraph(g)) {
        throw std::invalid_argument("the graph is not connect");
    }

    int numVertices = g.getNumVertices();
    bool* inMST = new bool[numVertices]; // is node already in the MST
    int* key = new int[numVertices];     // minimum edge weight to reach this node
    int* parent = new int[numVertices];  // parent of each node in the MST

    for (int i = 0; i < numVertices; ++i) {
        key[i] = 999999999;
        inMST[i] = false;
        parent[i] = -1;
    }

    key[0] = 0; // start from node 0

    for (int count = 0; count < numVertices - 1; ++count) {
        int u = -1;
        int minKey = 999999999;

        // Find the node with the smallest key not in MST
        for (int i = 0; i < numVertices; ++i) {
            if (!inMST[i] && key[i] < minKey) {
                minKey = key[i];
                u = i;
            }
        }

        if (u == -1) break;
        inMST[u] = true;

        Node* neighbor = g.getNeighbors(u);
        while (neighbor != nullptr) {
            int v = neighbor->vartexDest;
            int weight = neighbor->weight;

            // Update key if better edge is found
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
            }

            neighbor = neighbor->neighbor;
        }
    }

    Graph mst(numVertices);
    for (int i = 0; i < numVertices; ++i) {
        if (parent[i] != -1) {
            mst.addEdge(i, parent[i], key[i]);
        }
    }

    delete[] inMST;
    delete[] key;
    delete[] parent;

    return mst;
}

// Kruskal's algorithm - builds and returns MST
Graph Algorithms::kruskal(Graph& g) {
    if (!isConnectedGraph(g)) {
        throw std::invalid_argument("the graph is not connected");
    }

    int numVertices = g.getNumVertices();
    Graph mst(numVertices);
    graph::UnionFind uf(numVertices);

    const int maxEdges = numVertices * numVertices;
    int** edges = new int*[maxEdges]; // 2D array to store all edges (u, v, w)
    int edgeCount = 0;

    // Collect all edges (avoid duplicates)
    for (int u = 0; u < numVertices; ++u) {
        Node* current = g.getNeighbors(u);
        while (current != nullptr) {
            int v = current->vartexDest;
            int w = current->weight;
            if (u < v) {
                edges[edgeCount] = new int[3]{u, v, w}; // edge as (u,v,w)
                edgeCount++;
            }
            current = current->neighbor;
        }
    }

    // Sort edges by weight using Bubble Sort
    for (int i = 0; i < edgeCount - 1; ++i) {
        for (int j = 0; j < edgeCount - i - 1; ++j) {
            if (edges[j][2] > edges[j + 1][2]) {
                int* temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    // Build MST - add edge only if it doesn't create a cycle
    for (int i = 0; i < edgeCount; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        if (!uf.areConnected(u, v)) {
            uf.unionSets(u, v);
            mst.addEdge(u, v, w);
        }
    }

    // Free allocated memory
    for (int i = 0; i < edgeCount; ++i) {
        delete[] edges[i];
    }
    delete[] edges;

    return mst;
}
