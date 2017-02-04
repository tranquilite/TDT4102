all: main

filer = utilities.cpp

main: main.cpp $(filer)
	g++ main.cpp $(filer) -o main.out

test: test.cpp $(filer)
	g++ test.cpp $(filer) -o test.out

clean:
	rm *.out
