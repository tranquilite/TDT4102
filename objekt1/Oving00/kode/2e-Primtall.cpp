#include<iostream>
using namespace std;

//2e - Primtall 1
bool isPrime(int n) {
    bool primeness = true;
    for(int i = 2; i < n; i++) {
        if(n%i == 0) {
            primeness = false;
            return primeness;
        }
    }
    return primeness;
}

//2f - Primtall 2
void naivePrimeNumberSearch(int n) {
    for(int i = 2; i < n; i++) {
        if(isPrime(i)) {
            cout << i << " is a prime" << endl;
        }
    }
}

int main() {
    int derp[8] = {2, 3, 4, 6, 7, 42, 41, 40}; 
    for(int i = 0; i < 8; i++) {isPrime(derp[i]);}
    for(int i = 0; i < 8; i++) {naivePrimeNumberSearch(derp[i]);}
    return 0;
}

