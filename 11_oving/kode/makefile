CC=g++
CFLAGS=-c -Wall -std=c++11
#LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system

ENTRYP=11.cpp
ENTRYT=tests.cpp
SOURCES=iteratorer.cpp

OBJECTS=$(SOURCES:.cpp=.o) $(ENTRYP:.cpp=.o)
EXECUTABLE=oving.out

all: $(ENTRYP) $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

test: $(ENTRYT) $(OBJECTS)
	$(CC) -Wall -std=c++11 -o $(EXECUTABLE)

clean:
	rm *.o
