#include<iostream>
#include<cmath>
using namespace std;
#include"cannonball.h"
#include"utilities.h"

void enTest();

int main() {
    double velocityX = 12;
    double velocityY = 24;
    cout << velocityX << " " << velocityY << endl;
    getVelocityVector(28, 56, &velocityX, &velocityY);
    cout << velocityX << " " << velocityY << endl;

    cout << getDistanceTraveled(velX(50,0), velY(25,0)) << endl;
    targetPractice(98,velX(50,0), velY(25,0));

    cout << randomWithLimits(0,50) << endl;
    cout << randomWithLimits(20, 50) << endl;
    cout << randomWithLimits(40,100) << endl;
    return 0;
}

void enTest() {
double test[3] = {0, 2.5, 5};
cout<< "\t acclX() acclY() velX() velY() posX() "
    << "\t posY()" << endl; 
for(int i=0; i < 3; i++) {
    cout<< "T=" << test[i] << "\t" 
        << acclX() << "\t"
        << acclY() << "\t"
        << velX(50, test[i]) << "\t"
        << velY(25, test[i]) << "\t"
        << posX(velX(25, test[i]), test[i]) << "\t"
        << posY(velY(25, test[i]), test[i]) << "\t"
        << " NEXT " << endl;
    }
}
