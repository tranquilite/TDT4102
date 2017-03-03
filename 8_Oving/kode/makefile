CC=g++
CFLAGS=-c -Wall -std=c++11
#LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
LDFLAGS=

SOURCES=main.cpp o7_1.cpp o7_2.cpp o7_3.cpp o7_4.cpp

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=oving.out

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o
