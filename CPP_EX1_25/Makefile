//reutbechor@gmail.com
# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++2a -Wall

# Include paths for headers
INCLUDES = -I. -I./Graph -I./Node -I./Algorithms \
           -I./Data_Structures/Queue \
           -I./Data_Structures/PriorityQueue \
           -I./Data_Structures/UnionFind

# Source files needed for main program
MAIN_SOURCES = Main.cpp Algorithms/Algorithms.cpp Graph/Graph.cpp Node/Node.cpp \
               Data_Structures/Queue/Queue.cpp \
               Data_Structures/PriorityQueue/PriorityQueue.cpp \
               Data_Structures/UnionFind/UnionFind.cpp

# Common source files shared by all test targets
COMMON_TEST_SOURCES = Algorithms/Algorithms.cpp Graph/Graph.cpp Node/Node.cpp \
                      Data_Structures/Queue/Queue.cpp \
                      Data_Structures/PriorityQueue/PriorityQueue.cpp \
                      Data_Structures/UnionFind/UnionFind.cpp

# Test source files
TEST_FILES = Algorithms/Test_Algorithms.cpp \
             Graph/Test_Graph.cpp \
             Data_Structures/Queue/Test_Queue.cpp \
             Data_Structures/PriorityQueue/Test_PriorityQueue.cpp \
             Data_Structures/UnionFind/Test_UnionFind.cpp

# Object files for the main executable
MAIN_OBJECTS = $(MAIN_SOURCES:.cpp=.o)

# Output file name for the main executable
MAIN_TARGET = main_program

.PHONY: all Main test valgrind clean

# Compile all sources and build the main program
all: $(MAIN_TARGET)

# Compile and run the main program
Main: $(MAIN_TARGET)
	./$(MAIN_TARGET)

# Link all object files into the main executable
$(MAIN_TARGET): $(MAIN_OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(MAIN_OBJECTS) -o $@

# Generate binary names for test targets
TEST_BINARIES = $(TEST_FILES:.cpp=)

# Compile and run all test files
test: $(TEST_BINARIES)
	@for test in $(TEST_BINARIES); do echo "Running $$test..."; ./$$test; done

# Compile each test target with the shared sources
Algorithms/Test_Algorithms: Algorithms/Test_Algorithms.cpp $(COMMON_TEST_SOURCES)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@

Graph/Test_Graph: Graph/Test_Graph.cpp $(COMMON_TEST_SOURCES)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@

Node/Test_Node: Node/Test_Node.cpp $(COMMON_TEST_SOURCES)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@

Data_Structures/Queue/Test_Queue: Data_Structures/Queue/Test_Queue.cpp $(COMMON_TEST_SOURCES)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@

Data_Structures/PriorityQueue/Test_PriorityQueue: Data_Structures/PriorityQueue/Test_PriorityQueue.cpp $(COMMON_TEST_SOURCES)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@

Data_Structures/UnionFind/Test_UnionFind: Data_Structures/UnionFind/Test_UnionFind.cpp $(COMMON_TEST_SOURCES)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@

# Run the main program using valgrind to check for memory leaks
valgrind: $(MAIN_TARGET)
	valgrind --leak-check=full ./$(MAIN_TARGET)

# Clean all compiled binaries and object files
clean:
	rm -f $(MAIN_TARGET) $(MAIN_OBJECTS) \
	   Algorithms/Test_Algorithms Graph/Test_Graph Node/Test_Node \
	   Data_Structures/Queue/Test_Queue \
	   Data_Structures/PriorityQueue/Test_PriorityQueue \
	   Data_Structures/UnionFind/Test_UnionFind

