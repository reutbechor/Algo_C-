CXX = g++
CXXFLAGS = -std=c++2a -Wall

INCLUDES = -I. -I./Graph -I./Node 
SOURCES = Test_Graph.cpp Graph.cpp ../Node/Node.cpp 
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = testGraph

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: clean run

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJECTS) test_graph


