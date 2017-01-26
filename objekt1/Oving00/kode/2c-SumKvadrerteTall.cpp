#include<iostream>
using namespace std;

int squareNumberSum(int n) {
    int totalSum = 0;
    int e = 0;
    for(int i = 0; i < n; i++) {
        totalSum += i*i;
        e = i+1;
        cout << (e*e) << endl;
    }
    cout << totalSum << endl;
    return totalSum;
}

int main() {
    squareNumberSum(6);
    return 0;
}
        
