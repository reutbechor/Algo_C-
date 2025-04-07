#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include "Graph.h"

using namespace graph;

TEST_CASE("Graph - addEdge and hasEdge") {
    Graph g(4);
    g.addEdge(0, 1, 5);
    g.addEdge(2, 3, 10);
    g.addEdge(2, 3);
    CHECK(g.hasEdge(0, 1));
    CHECK(g.hasEdge(1, 0));
    CHECK(g.hasEdge(2, 3));
    CHECK_FALSE(g.hasEdge(0, 2));
}

TEST_CASE("Graph - addEdge not valid") {
    Graph g(4);
    g.addEdge(0, 5, 5);
    CHECK_FALSE(g.hasEdge(0, 2));
}


TEST_CASE("Graph - removeEdge") {
    Graph g(3);
    g.addEdge(0, 1, 4);
    g.addEdge(1, 2, 3);

    CHECK(g.hasEdge(0, 1));
    g.removeEdge(0, 1);
    CHECK_THROWS_AS(g.removeEdge(0, 1), std::invalid_argument);
    CHECK_THROWS_AS(g.removeEdge(12, 1), std::invalid_argument);
    CHECK_FALSE(g.hasEdge(0, 1));
    CHECK_FALSE(g.hasEdge(1, 0));
}

TEST_CASE("Graph - addEdge and removeEdge") {
    Graph g(4);
    g.addEdge(0, 1, 5);
    g.addEdge(2, 3, 10);
    g.removeEdge(1, 0);
    CHECK_FALSE(g.hasEdge(0, 1));
    CHECK_FALSE(g.hasEdge(0, 2));
}

TEST_CASE("Graph - getNumVertices") {
    Graph g(7);
    CHECK(g.getNumVertices() == 7);
}

TEST_CASE("Graph - getNeighbors") {
    Graph g(3);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 4);

    Node* n = g.getNeighbors(0);
    int count = 0;
    while (n != nullptr) {
        count++;
        CHECK((n->vartexDest == 1 || n->vartexDest == 2));
        CHECK((n->weight == 2 || n->weight == 4));
        n = n->neighbor;
    }
    CHECK(count == 2);
}

TEST_CASE("Graph - isEqualsGraph true") {
    Graph g1(3), g2(3);
    g1.addEdge(0, 1, 2);
    g1.addEdge(1, 2, 3);
    g2.addEdge(0, 1, 2);
    g2.addEdge(1, 2, 3);
    CHECK(g1.isEqualsGraph(g2));
}

TEST_CASE("Graph - isEqualsGraph false") {
    Graph g1(3), g2(3);
    g1.addEdge(0, 1, 2);
    g2.addEdge(0, 1, 5); // משקל שונה
    CHECK_FALSE(g1.isEqualsGraph(g2));
}

TEST_CASE("Graph - isEqualsGraph false (miss edge)") {
    Graph g1(3), g2(3);
    g1.addEdge(0, 1, 2);
    g1.addEdge(1, 2, 3);
    g2.addEdge(0, 1, 2);
    CHECK_FALSE(g1.isEqualsGraph(g2));
}

TEST_CASE("Graph - isNonnegativeGraph") {
    Graph g(3);
    g.addEdge(0, 1, 5);
    g.addEdge(1, 2, 0);
    CHECK(g.isNonnegativeGraph());

    g.addEdge(2, 0, -1);
    CHECK_FALSE(g.isNonnegativeGraph());
}

