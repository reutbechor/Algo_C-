#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include "Algorithms.h"
#include "../Graph/Graph.h"

using namespace graph;

TEST_CASE("BFS test") {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    Graph expected(5);
    expected.addEdge(0, 1);
    expected.addEdge(0, 2);
    expected.addEdge(1, 3);
    expected.addEdge(1, 4);
    Graph bfsTree = Algorithms::bfs(g, 0);
    CHECK(bfsTree.isEqualsGraph(expected));
}

TEST_CASE("BFS Disconnected graph") {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3); // 4 and 5 disconnect
    Graph expected(6);
    expected.addEdge(0, 1);
    expected.addEdge(0, 2);
    expected.addEdge(1, 3);
    Graph bfsTree = Algorithms::bfs(g, 0); 
    CHECK(bfsTree.isEqualsGraph(expected));
    CHECK(bfsTree.getNeighbors(4) == nullptr);
    CHECK(bfsTree.getNeighbors(5) == nullptr);
}

TEST_CASE("DFS test") {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    Graph expected(5);
    expected.addEdge(0, 1);
    expected.addEdge(0, 2);
    expected.addEdge(1, 3);
    expected.addEdge(1, 4);
    Graph dfsTree = Algorithms::dfs(g, 0);
    CHECK(dfsTree.isEqualsGraph(expected));
}


TEST_CASE("DFS - Disconnected graph") {
    Graph g(4);
    g.addEdge(0, 1); 
    Graph dfsTree = Algorithms::dfs(g, 0);
    CHECK(dfsTree.getNeighbors(2) == nullptr);
    CHECK(dfsTree.getNeighbors(3) == nullptr);
}


TEST_CASE("Dijkstra test") {
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 1);
    Graph expected(4);
    expected.addEdge(0, 1, 1);
    expected.addEdge(1, 2, 2);
    expected.addEdge(2, 3, 1);

    Graph result = Algorithms::dijkstra(g, 0);
    CHECK(result.isEqualsGraph(expected));
}


TEST_CASE("Dijkstra - not connected graph test") {
    Graph g(4);
    g.addEdge(0, 1, 2); // 2 and 3 disconnect
    Graph result = Algorithms::dijkstra(g, 0); 
    CHECK(result.getNeighbors(2) == nullptr);
    CHECK(result.getNeighbors(3) == nullptr);
    CHECK(result.hasEdge(0, 1));
}

TEST_CASE("Dijkstra - negative weight") {
    Graph g(2);
    g.addEdge(0, 1, -1);
    CHECK_THROWS_AS(Algorithms::dijkstra(g, 0), std::invalid_argument);
}

TEST_CASE("Prim test") {
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 3);
    g.addEdge(3, 0, 4); // the edge should be in the tree
    Graph expected(4);
    expected.addEdge(0, 1, 1);
    expected.addEdge(1, 2, 2);
    expected.addEdge(2, 3, 3);
    Graph mst = Algorithms::prim(g);
    CHECK(Algorithms::isConnectedGraph(mst));
    CHECK(mst.isEqualsGraph(expected));
}


TEST_CASE("Prim disconnected graph") {
    Graph g(3);
    g.addEdge(0, 1, 1);
    CHECK_THROWS_AS(Algorithms::prim(g), std::invalid_argument);
}

TEST_CASE("kruskal test") {
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 3);
    g.addEdge(3, 0, 4); // the edge should not be un the tree
    Graph expected(4);
    expected.addEdge(0, 1, 1);
    expected.addEdge(1, 2, 2);
    expected.addEdge(2, 3, 3);
    Graph mst = Algorithms::kruskal(g);
    CHECK(Algorithms::isConnectedGraph(mst));
    CHECK(mst.isEqualsGraph(expected));
}

TEST_CASE("Kruskal disconnected graph") {
    Graph g(3);
    g.addEdge(0, 1, 1);
    CHECK_THROWS_AS(Algorithms::kruskal(g), std::invalid_argument);
}

TEST_CASE("isConnectedGraph ") {
    Graph g(3);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2);
    CHECK(Algorithms::isConnectedGraph(g));
}

TEST_CASE("isConnectedGraph not connected") {
    Graph g(3);
    g.addEdge(0, 1, 1);
    CHECK_FALSE(Algorithms::isConnectedGraph(g));
}
