all: main

filer = utilities.cpp tests.cpp

main: main.cpp $(filer)
	g++ main.cpp $(filer) -o main.out

test: tests.cpp $(filer)
	g++ tests.cpp $(filer) -o test.out

clean:
	rm *.out
