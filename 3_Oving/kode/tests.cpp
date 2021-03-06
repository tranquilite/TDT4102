#include<iostream>
#include<cmath>
using namespace std;
#include"cannonball.h"


void enTest() {
double test[3] = {0, 2.5, 5};
cout<< "\t acclY() velY() velX() posX() "
    << " posY()" << endl; 
for(int i=0; i < 3; i++) {
    cout<< "T=" << test[i] << "\t" 
        << acclY() << "\t"
        << velY(25, test[i]) << "\t"
        << velX(50, test[i]) << "\t"
        << posX(0, 50, test[i]) << "\t"
        << posY(0, 25, test[i]) << "\t"
        << endl;
    }
    cout << flightTime(25);
}


int main() {

    enTest();
    return 0;    
}

// posY T=0, 0; T=2.5, 31.84; T=5, 2.375
// posY T=0, 0; T=2.5, -30,65; T=5, -122.675
// posY T=0, 0; T=2.5, -29,47; T=5, -252.875
