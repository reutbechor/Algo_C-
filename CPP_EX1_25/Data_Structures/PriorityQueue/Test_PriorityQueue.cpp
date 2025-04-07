#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include "PriorityQueue.h"

using namespace graph;

TEST_CASE("Basic insert and minPQ") {
    PriorityQueue pq(5);
    pq.insert(0, 10);
    pq.insert(1, 5);
    pq.insert(2, 8);
    CHECK(pq.minPQ() == 1); 
    CHECK(pq.minPQ() == 2); 
    CHECK(pq.minPQ() == 0); 
}

TEST_CASE("minPQ throws when empty") {
    PriorityQueue pq(3);
    CHECK_THROWS_AS(pq.minPQ(), std::runtime_error);
}

TEST_CASE("Insert same element multiple times") {
    PriorityQueue pq(3);
    pq.insert(1, 7);
    pq.insert(1, 4); 
    pq.insert(2, 3);

    CHECK(pq.minPQ() == 2); 
    CHECK(pq.minPQ() == 1); 
    CHECK(pq.minPQ() == 1); 
}

TEST_CASE("IsEmpty works correctly") {
    PriorityQueue pq(2);
    CHECK(pq.isEmpty());
    pq.insert(0, 2);
    CHECK_FALSE(pq.isEmpty());
    pq.minPQ();
    CHECK(pq.isEmpty());
}
