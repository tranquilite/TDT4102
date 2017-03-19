// Call by value and call by reference
#include<iostream>

using namespace std;

void readValues_V(int a, int b) {
	cout << "Call-by-Value: tast to verdier \n";
	// cin >> a >> b;
	cin >> a;
	cin >> b;
}
void readValues_R(int &a, int &b) {
	cout << "Call-by-Reference: tast to verdier \n";
	cin >> a >> b;
}

void main() {
	int a = 2, b = 3;
	readValues_V(a, b);
	a = static_cast<int>(sqrt(100));
	cout << a << " " << b << endl;
	a = 4; b = 5;
	readValues_R(a, b);
	cout << a << " " << b << endl;
}