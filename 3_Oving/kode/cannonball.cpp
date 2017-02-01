#include<iostream>
#include<cmath>

using std::cout;
using std::endl;
using std::cin;

#include "cannonball.h"
#include "utilities.h"

//2 - Implementer funksjoner

double acclY() { return -9.81;}
double acclX() { return 0.0;  }

double velY(double initVelocity, double time) {
    double vel_Y = initVelocity + (acclY() * time);
    return vel_Y;
}

double velX(double initVelocity, double time) {
    double vel_X = initVelocity + (acclX() * time);
    return vel_X;
}

double posX(double initPosition, double initVelocity,
            double time) { 
    double posisjon = (initVelocity * time) + 
               ( ( acclX() * pow(time, 2) ) / 2.0);

    return 0;
}

double posY(double initPosition, double initVelocity,
            double time) { 
    double posisjon = initPosition + (initVelocity * time) + 
                ( ( pow(time, 2) * acclY() ) / 2.0 );
    //posisjon = initPosition + initVelocity * time + ((pow(time,2) * acclY()) / 2);
    return posisjon;
}

void printTime (int s) {
    //Copypasta fra forrige øving.
    int t = (s / 3600), m = 0;
    s = s - t*3600;
    m = (s / 60);
    s = s - m*60;
    //med noen mindre tips
    if(t > 0)   { cout << t << " time"   << ((t>1)?"r":"")  <<  endl; }
    if(m > 0)   { cout << m << " minutt" << ((m>1)?"er":"") <<  endl; }
    if(s > 0)   { cout << s << " sekund" << ((s>1)?"er":"") <<  endl; }
}

double flightTime(double initVelocity) {
    return 2*(initVelocity/acclY());
}

//Del 2
//3 - Implementer funksjoner

void getUserInput(double *theta, double *absVelocity) {
    cout << "Oppgi vinkel (i grader): "; cin >> *theta;
    cout << "Oppgi hastighet(absolutt): "; cin >> *absVelocity;
}

double degToRad(double deg) {
    const double PI = 3.14;
    return ((PI / 180) * deg);
}

double getVelocityX(double theta, double absVelocity) {
    return absVelocity * cos(theta);
}

double getVelocityY(double theta, double absVelocity) {
    return absVelocity * sin(theta);
}

void getVelocityVector(double theta, double absVelocity,
                        double *velocityX, double *velocityY) {
    *velocityX = getVelocityX(theta, absVelocity);
    *velocityY = getVelocityY(theta, absVelocity);
}

double getDistanceTraveled(double velocityX, double velocityY) {
    return 2*(velocityX/velocityY)*velocityX;
}

double targetPractice(double distanceToTarget,
                        double velocityX, double velocityY) {
    double resultat = getDistanceTraveled(velocityX, velocityY);
    double avvik = pow(distanceToTarget - resultat, 2);
    if (avvik == 5) {
        cout << "blink\n";
    } else {
        cout << "utenfor feilmargin\n";
    }
    return avvik;
}

void playTargetPractice() {
    double *theta = new double;
    double *absVelocity = new double;
    getUserInput(theta, absVelocity);
    double velX = getVelocityX(*theta, *absVelocity);
    double velY = getVelocityY(*theta, *absVelocity);
    
    targetPractice(randomWithLimits(100, 1000), velX, velY);
    //cout << "Funk da ni jävlar!";
}
