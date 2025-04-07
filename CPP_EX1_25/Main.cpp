#include "Graph/Graph.h"
#include "Algorithms/Algorithms.h"
#include <iostream>

using namespace std;
using namespace graph;

int main() {
    cout << "Graph Project " << endl;
    Graph g(5);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 8);
    g.addEdge(3, 4, 3);
    cout << endl;
    cout << "Original Graph" << endl;
    g.printGraph();
    cout << endl;
    cout << "BFS Tree from vertex 0 " << endl;
    Graph bfsTree = Algorithms::bfs(g, 0);
    bfsTree.printGraph();
    cout << endl;
    cout << "DFS Tree from vertex 0 " << endl;
    Graph dfsTree = Algorithms::dfs(g, 0);
    dfsTree.printGraph();
    cout << endl;
    cout << "Dijkstra Tree from vertex 0 " << endl;
    Graph dijkstraTree = Algorithms::dijkstra(g, 0);
    dijkstraTree.printGraph();
    cout << endl;
    cout << "Minimum Spanning Tree - Prim " << endl;
    Graph primTree = Algorithms::prim(g);
    primTree.printGraph();
    cout << endl;
    cout << "Minimum Spanning Tree - Kruskal " << endl;
    Graph kruskalTree = Algorithms::kruskal(g);
    kruskalTree.printGraph();
    return 0;
}