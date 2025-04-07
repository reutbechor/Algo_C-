CXX = g++
CXXFLAGS = -std=c++2a -Wall

SRC_DIRS = PriorityQueue
SOURCES = PriorityQueue.cpp Test_PriorityQueue.cpp
INCLUDES = -I.
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = test_pq

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: clean run

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJECTS)
