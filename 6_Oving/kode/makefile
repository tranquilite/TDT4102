CC=g++
CFLAGS=-c -Wall -std=c++11
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system

SOURCES=main.cpp Car.cpp Person.cpp

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=oving

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o
