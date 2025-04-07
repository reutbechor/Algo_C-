#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include "Queue.h"

using namespace graph;

TEST_CASE("Basic enqueue and dequeue") {
    Queue q(3);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    CHECK(q.dequeue() == 10);
    CHECK(q.dequeue() == 20);
    CHECK(q.dequeue() == 30);
}

TEST_CASE("Queue throws on dequeue when empty") {
    Queue q(2);
    CHECK_THROWS_AS(q.dequeue(), std::runtime_error);
}

TEST_CASE("Queue behaves correctly after wrap around") {
    Queue q(3);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    CHECK(q.dequeue() == 1);
    q.enqueue(4);  // זה צריך להיכנס במיקום שהתפנה
    CHECK(q.dequeue() == 2);
    CHECK(q.dequeue() == 3);
    CHECK(q.dequeue() == 4);
}

TEST_CASE("Queue handles single element") {
    Queue q(1);
    q.enqueue(42);
    CHECK(q.dequeue() == 42);
    CHECK_THROWS_AS(q.dequeue(), std::runtime_error);
}

TEST_CASE("Queue isEmpty works") {
    Queue q(2);
    CHECK(q.isEmpty());
    q.enqueue(5);
    CHECK_FALSE(q.isEmpty());
    q.dequeue();
    CHECK(q.isEmpty());
}
