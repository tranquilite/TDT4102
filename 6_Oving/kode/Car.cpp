#include<iostream>
#include "Car.h"

namespace del1 {
Car::Car() { this->freeSeats = 0; }
Car::Car(int freeSeatsTotal) { this->freeSeats = freeSeatsTotal; }

const bool Car::hasFreeSeats() {
    return ((this->freeSeats) > 1); //Antar sjåfør trenger en plass.
}

void Car::reserveFreeSeat() {
    if(this->hasFreeSeats()) {
        (this->freeSeats)--;
    }
}

} //namespace del1 slutt
