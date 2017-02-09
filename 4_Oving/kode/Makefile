all: main

filer = utilities.cpp tests.cpp mastermind.cpp

main: main.cpp $(filer)
	g++ main.cpp $(filer) -o a.out

test: tests.cpp $(filer)
	g++ tests.cpp $(filer) -o test.out

clean:
	rm *.out
