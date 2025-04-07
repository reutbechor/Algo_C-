//reutbechor@gmail.com
CXX = g++
CXXFLAGS = -std=c++11 -Wall
INCLUDES = -I. 

SOURCES = Test_Queue.cpp Queue.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = test_queue

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: clean run

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJECTS)
