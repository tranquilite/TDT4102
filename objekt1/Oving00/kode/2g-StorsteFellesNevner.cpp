#include<iostream>
using namespace std;

int findGreatestDivisor(int n) {
    if(n < 0) {  n = n*-1; }
    for(int i = n-1; n > 0; i--) {
        if(n%i == 0) {
            return i;
        }
    }
    return 0;
}

int main() {
    int test[8] = {-2, 3, 4, 6, 7, 42, 41, 40}; 
    for(int i = 0; i < 8; i++) {
        cout << findGreatestDivisor(test[i]) << endl;
    }
    return 0;
}
