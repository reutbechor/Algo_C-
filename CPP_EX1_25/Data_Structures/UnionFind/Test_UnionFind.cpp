#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include "UnionFind.h"

using namespace graph;

TEST_CASE("UnionFind basic connectivity") {
    UnionFind uf(5);

    CHECK_FALSE(uf.areConnected(0, 1));
    uf.unionSets(0, 1);
    CHECK(uf.areConnected(0, 1));
    CHECK(uf.find(0) == uf.find(1));

    uf.unionSets(1, 2);
    CHECK(uf.areConnected(0, 2));
    CHECK(uf.find(0) == uf.find(2));
}

TEST_CASE("UnionFind separate sets") {
    UnionFind uf(6);

    uf.unionSets(0, 1);
    uf.unionSets(2, 3);
    uf.unionSets(4, 5);

    CHECK(uf.areConnected(0, 1));
    CHECK(uf.areConnected(2, 3));
    CHECK(uf.areConnected(4, 5));

    CHECK_FALSE(uf.areConnected(0, 2));
    CHECK_FALSE(uf.areConnected(1, 4));
}

TEST_CASE("UnionFind transitive union") {
    UnionFind uf(4);
    uf.unionSets(0, 1);
    uf.unionSets(1, 2);
    CHECK(uf.areConnected(0, 2));
    CHECK(uf.areConnected(1, 2));
}

TEST_CASE("UnionFind: self connection") {
    UnionFind uf(3);
    CHECK(uf.areConnected(1, 1));
    CHECK(uf.find(2) == uf.find(2));
}

TEST_CASE("UnionFind: redundant union") {
    UnionFind uf(3);
    uf.unionSets(0, 1);
    int rootBefore = uf.find(1);
    uf.unionSets(0, 1); // shouldn't change anything
    int rootAfter = uf.find(1);
    CHECK(rootBefore == rootAfter);
}
