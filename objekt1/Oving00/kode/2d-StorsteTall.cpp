#include<iostream>
using namespace std;

int max(int a, int b) {
    if(a > b) {
        cout << "a is greater than b" << endl;
        return a;
    } else {
        cout << "a is greater than, or equal, to b" << endl;
        return b;
    }
}

int main() {
    max(2, 4);
    max(2, 2);
    max(4, 2);
    max(6, 8);
    return 0;
}
