#pragma once

#include "../Graph/Graph.h"

namespace graph {

class Algorithms {
public:
    static Graph bfs(Graph& g, int source);
    static Graph dfs(Graph& g, int source);
    static Graph dijkstra(Graph& g, int source);
    static Graph prim(Graph& g);
    static Graph kruskal(Graph& g);
    static bool isConnectedGraph(Graph& g); // checking if the graph is connected for prim and kruskal
};

}
