all: main

filer = 

main: main.cpp $(filer)
	g++ main.cpp $(filer) -o a.out
    

invoc: main.cpp $(filer)
	g++ -v main.cpp $(filer) -o a.out
    
test: tests.cpp $(filer)
	g++ tests.cpp $(filer) -o test.out

clean:
	rm *.out
