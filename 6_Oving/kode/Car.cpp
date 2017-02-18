#include "Car.h"

Car::Car(int seatsTotal) {
    this->freeSeats = seatsTotal;
}

const bool Car::hasFreeSeats() {
    return (this->freeSeats >= 1);
}

void Car::reserveFreeSeat() {
    if(this->hasFreeSeats()) {
        (this->freeSeats)--;
    }
}
