#include<iostream>
using namespace std;

void compareListOfNumbers(int len, int liste[]) {
    int r[3] = {0, 0, 0};
    // Array er ikke iterable som i python.
    for(int i = 0; i < len; i++) {
        if(liste[i] < 0) {
            r[0]++;
        }
        else if(liste[i] == 0) {
            r[1]++;
        }
        else {
            r[2]++;
        }
    }
    cout << r[0] << " numbers were below zero" << endl;
    cout << r[1] << " numbers were zero" << endl;
    cout << r[2] << " numbers were above zero" << endl;
}


int main() {
    int test[5] = {1, 2, 3, 0, -4};
    size_t len = sizeof(test)/sizeof(*test);
    compareListOfNumbers(len, test);
    return 0;
}
