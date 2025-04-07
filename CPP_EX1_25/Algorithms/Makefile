CXX = g++
CXXFLAGS = -std=c++2a -Wall

INCLUDES = -I. \
           -I../Graph \
           -I../Node \
           -I../Data_Structures/Queue \
           -I../Data_Structures/PriorityQueue \
           -I../Data_Structures/UnionFind

SOURCES = Test_Algorithms.cpp Algorithms.cpp \
          ../Graph/Graph.cpp ../Node/Node.cpp \
          ../Data_Structures/Queue/Queue.cpp \
          ../Data_Structures/PriorityQueue/PriorityQueue.cpp \
          ../Data_Structures/UnionFind/UnionFind.cpp

OBJECTS = $(SOURCES:.cpp=.o)
TARGET = test_algorithms

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: clean run

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJECTS)
