CC=g++
CFLAGS=-c -Wall -std=c++11
#LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
LDFLAGS=

SOURCES=main.cpp Image.cpp ImageIO.cpp Matrix.cpp Vector.cpp

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=oving.out

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o
