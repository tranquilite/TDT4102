#include<iostream>
using namespace std;

// Fig. 12
void triangleNumbersBelow(int n) {
    int acc = 1, num = 2;
    cout << "Triangle numbers below " << n << ":" << endl;
    while((acc+num) < n){
        acc = acc+num;
        num++;
        cout << acc << endl;
    }
}

//Fig. 13
bool isTriangleNumber(int number){
    int acc = 1;
    while(number > 0) {
        number = number - acc;
        acc = acc + 1;
    }
    if(number == 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    triangleNumbersBelow(16);
    triangleNumbersBelow(5);

    int testy[6] = {2, 3, 32, 16, 42, 6};
    for(int i=0; i<6; i++) {
        cout << testy[i] << ": " << isTriangleNumber(testy[i]) << endl;
    }

    return 0;
}
