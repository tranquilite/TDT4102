CC=g++
CFLAGS=-c -Wall -std=c++11 -v
#LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system

SOURCES=main.cpp SafeArray.cpp FancySafeArray.cpp Sudoku.cpp tests.cpp

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=oving.out

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o
