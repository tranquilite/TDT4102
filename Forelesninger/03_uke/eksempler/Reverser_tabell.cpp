#include <iostream>
using namespace std;

void reverser(const int orginal[], int kopi[], int size) {
	for (int i = 0, j = size - 1; i < size; i++, j--) {
		kopi[j] = orginal[i];
	}
}

int main() {
	int tabA[5] = { 1, 2, 3, 4, 5 };
	int tabB[5] = {};

	reverser(tabA, tabB, 5);
	for (int i = 0; i < 5; i++) {
		cout << tabB[i] << " ";
	}
}
