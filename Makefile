# Definisanje promenljivih
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Definisanje izlaznog fajla i objektnog fajla
TARGET = hello_world
OBJ = main.o

# Pravilo za kompilaciju
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# Pravilo za kompilaciju objektnog fajla
main.o: main.cpp main.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# Pravilo za čišćenje (brisanjem objektnog fajla i izvršnog fajla)
clean:
	rm -f $(OBJ) $(TARGET)
