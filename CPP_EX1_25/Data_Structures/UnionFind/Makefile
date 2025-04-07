CXX = g++
CXXFLAGS = -std=c++2a -Wall

SRC_DIRS = UnionFind
SOURCES = UnionFind.cpp Test_UnionFind.cpp
INCLUDES = -I.
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = test_unionfind

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: clean run

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJECTS)
