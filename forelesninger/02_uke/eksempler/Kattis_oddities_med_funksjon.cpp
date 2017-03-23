// Kattis, Oddities, with isEven as function
#include <iostream>
using namespace std;

bool isEven(int i) {
	return ((i % 2) == 0);
}

int main() {
	int n = 0;

	cin >> n;
	while (n--) {
		int num;
		cin >> num;
		if (isEven(num)) {
			cout << num << " is even" << endl;
		}
		else {
			cout << num << " is odd" << endl;
		}
	}
	return 0;
}