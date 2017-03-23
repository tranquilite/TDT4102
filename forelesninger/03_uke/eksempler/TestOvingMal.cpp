// TestOvingMal.cpp
#include <iostream>
using namespace std;

void oppgave1() { /* empty */ }

void oppgave2a() {
	cout << "... tester oppgave 2a\n";
}
void oppgave2b() {
	cout << "... tester oppgave 2b\n";	 
}
void oppgave2c() {
	cout << "... tester oppgave 2c\n";
	// din kode her for 2c
}
void oppgave2() {
	cout << "Test av oppgave 2 starter" << endl;
	bool finished = false;
	char c = ' ';
	while (!finished) {
		cout << "Tast a for deloppg. a, b for\n";
		cout << "deloppgave b osv., q for å avslutte\n";
		cin >> c;
		switch (c) {
		case 'a':
			oppgave2a();
			break;
		case 'b':
			oppgave2b();
			break;
		case 'c':
			oppgave2c();
			break;
		case 'q':
			finished = true;
			break;
		default :
			cout << "*** ugyldig valg ***\n";
		}
	}
}

void oppgave3() {
	// another empty function
}

	void main() {
	setlocale(LC_ALL, "norwegian"); // Sett norsk tegnsett for Windows
	// Man kan ha en tilsvarende switch her der man velger mellom oppgave 1, 2 el. 3
	oppgave1();
	oppgave2();
	oppgave3();
}
