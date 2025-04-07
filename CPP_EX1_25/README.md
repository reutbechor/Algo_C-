# Graph Project - README



## Project Structure

The project is modular, where each component is placed in a dedicated folder. Each has its own `Makefile`, and there's a global Makefile in the root:

```
.
├── Algorithms/
│   ├── Algorithms.h/.cpp
│   ├── Test_Algorithms.cpp
│   └── Makefile
│
├── Data_Structures/
│   ├── Queue/
│   │   ├── Queue.h/.cpp
│   │   ├── Test_Queue.cpp
│   │   └── Makefile
│   ├── PriorityQueue/
│   │   ├── PriorityQueue.h/.cpp
│   │   ├── Test_PriorityQueue.cpp
│   │   └── Makefile
│   └── UnionFind/
│       ├── UnionFind.h/.cpp
│       ├── Test_UnionFind.cpp
│       └── Makefile
│
├── Graph/
│   ├── Graph.h/.cpp
│   ├── Test_Graph.cpp
│   └── Makefile
│
├── Node/
│   ├── Node.h/.cpp
│
├── Main.cpp
├── doctest.h
├── Makefile
└── README.md
```

---

## Algorithm Implementation Summary

This section briefly describes how each algorithm is implemented:

### BFS 
- Validates the start vertex
- Uses a `visited` array to track visited nodes
- Uses a `Queue` to perform the traversal
- Adds edges to the BFS tree during traversal
- Returns a new graph representing the BFS tree

### DFS 
- Validates the start vertex
- Uses `color` and `parent` arrays
- Recursive traversal using colors (white, gray, black)
- Adds edges to the DFS tree when exploring new neighbors
- Returns a new graph representing the DFS tree

### Dijkstra
- Validates the start vertex and checks for non-negative weights
- Uses arrays `dist`, `parent`, and `visited`
- Uses a `PriorityQueue` to select the closest unvisited vertex
- Updates distances and paths
- Builds a new graph representing the shortest path tree

### Prim
- Checks if the graph is connected
- Uses arrays `key`, `parent`, `inMST`
- Selects the minimum key vertex not yet in MST
- Updates keys of adjacent vertices
- Builds a new graph representing the MST

### Kruskal
- Checks if the graph is connected
- Collects all edges in a 2D array
- Sorts edges by weight using Bubble Sort
- Uses `UnionFind` to prevent cycles
- Builds a new MST graph

### isConnectedGraph
- Runs BFS from vertex 0
- Verifies all vertices are reachable from the start
- Returns true if connected, false otherwise

---

## Custom Data Structures

### Queue
- Used in: BFS
- Implementation: circular array
- Main functions: `enqueue`, `dequeue`, `isEmpty`, `isFull`

### PriorityQueue
- Used in: Dijkstra, Prim
- Implementation: array of (vertex, weight), linear search for minimum
- Main functions: `insert`, `minPQ`, `isEmpty`

### UnionFind
- Used in: Kruskal
- Implementation: `parent`, `rank`, path compression, union by rank
- Main functions: `find`, `unionSets`, `areConnected`

---

## Running the Main Example

The `Main.cpp` file demonstrates the main algorithms on a sample graph.

It prints:

- The original graph
- BFS and DFS trees from vertex 0
- Dijkstra result from vertex 0
- MST trees using Prim and Kruskal

---

##  Running Tests by Folder

Each component includes its own test file and `Makefile`. You can run the tests by navigating to the folder and running:

For example, to test the Queue:
```bash
cd Data_Structures/Queue
make test
```

This will:
- Compile `Test_Queue.cpp`
- Use `doctest` to run all test cases automatically

Similarly:
```bash
cd Data_Structures/PriorityQueue
make test
```

Or:
```bash
cd Algorithms
make test
```

### Global testing from the root:
```bash
make test
```
(Assuming the root `Makefile` supports recursive test execution)

##  Makefile

The root `Makefile` includes the following commands:

- `make Main` – Run the example in `Main.cpp`
- `make test` – Run all unit tests from all folders
- `make valgrind` – Run the main example with valgrind to check for memory leak
- `make clean` – Remove all compilation artifacts (`.o`, `.out`, `a.out`, temp files) from all folders


## Learning Resources

 - During the development of this project, I used ChatGPT as a learning assistant to:

- Understand how to build and structure a proper README.md file

- Get guidance on how to use the doctest library effectively for unit testing in C++
