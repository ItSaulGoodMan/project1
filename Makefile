CXX = g++
CXXFLAGS = -Wall -std=c++11 -pthread
LDFLAGS = -lboost_system -lboost_thread

TARGET = app
SRC = main.cpp server.cpp client.cpp
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
