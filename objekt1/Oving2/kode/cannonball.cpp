#include<iostream>
#include<cmath>

using namespace std;
#include"cannonball.h"

//Tenk om gcc ga ekstrapoeng for 79-tegnsbegrensning/linje.
//BDFL van Rossum hadde vært stolt.
//men helt feil sammenheng.

const double g = -9.81;

double acclX() { return 0; }
double acclY() { return g; }

//Skriveom <(")
double velX(double initVelocity, double time) {
    double fartX = initVelocity + (acclX()*time);
    return fartX;
}

double velY(double initVelocity, double time) {
    double fartY = 0;
    // v = v_0 + at
    fartY = initVelocity + (acclY()*time);
    return fartY;
}


double posX(double initVelocity, double time) {
    double startPos = 0, posisjon = 0; 
    posisjon = startPos + (initVelocity*time) + ((acclX()*pow(time,2))/2);
    return posisjon;
}

double posY(double initVelocity, double time) {
    double startPos = 0, posisjon = 0; 
    posisjon = startPos + (initVelocity * time) + (acclY() * pow(time,2))*0.5;
    return posisjon;
}

//Memo: Kan visst bli negativ, oooog. Burde være *2
double flightTime(double initVelocity) {
    double flight_Time = 0;
    //Post-godkjenning: Gange med to. <(")
    //Siden flytid er flytid opp (til a_y=0)
    //pluss flytid ned (til a_y=0 igjen).
    flight_Time = 2*(initVelocity / acclY());

    return flight_Time;
}

void printTime(double time) {
    //Crtl+V y p fra oving1.cpp..
    double t = 0, m = 0, s = time;
    //*kunne* brukt modulo-aritmetikk, men eh.
    //KISS, og if it works, don't break it.
    t = (s / 3600);
    s = s - t*3600;
    m = (s / 60);
    s = s - m*60;

    if(t > 0) { cout << t << " time"; }
    if(t > 1) { cout << "r"; }
    if(m > 0) { if(t>0) { cout << ", "; } cout << m << " minutt"; }
    if(t > 1) { cout << "er"; }
    if(s >= 0) { if(t>0 or m > 0) { cout << " og "; } cout << s << "sekund"; }
    if(s > 1) { cout << "er\n"; }
    //EAFP
}

// DEL 2
// IMPLEMENTER FUNKSJONENE

double getVelocityX(double theta, double absVelocity) {
    return (absVelocity * cos(theta));
}

double getVelocityY(double theta, double absVelocity) {
    return (absVelocity * sin(theta));
}

//så uoversiktlig som du får det.
//Memo: Fiks, eller skjerp deg.
void getVelocityVector(double theta, double absVelocity,
                         double *velocityX, double *velocityY) {
    *velocityX = getVelocityX(theta, absVelocity);
    *velocityY = getVelocityY(theta, absVelocity);
}

double getDistanceTraveled(double velocityX, double velocityY) {
    //..hastigheten i X er sånn ca. const?
    //vi tar fra videregående at..
    //SCREW GJENBRUK. TREKLEMMERNE FRA EMIL KAN TA SEG EN BOLLE
    double t, distance_traversed;

    t = 2*(velocityX/velocityY);
    distance_traversed = t*velocityX;

    return distance_traversed;
    //Jeg bruker minst fire tørk. Hallo. Det er vinter.
    //Nulltoleranse for selv det minste av fuktighet.
}

double targetPractice(double distanceToTarget, double velocityX, double velocityY) {
    //ta dTT. Heng meg. Finn noen andre til å løse dette.
    //Lever blåkopi av LF, og kall det helg. (neida. Joda. Det frister?)
    //(3 sek. Sjekker github.)

    double resultat = getDistanceTraveled(velocityX, velocityY);
    double avvik    = pow(distanceToTarget - resultat, 2);
    if(avvik == 0) {
        cout << "..Robin Hood, eller?";
    } else {
        cout << "Du bommet med rundt " << sqrt(avvik) << " meter." << endl;
    }
    return 0;
}
