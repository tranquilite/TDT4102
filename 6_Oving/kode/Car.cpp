#include "Car.h"

namespace del1 {
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

} //namespace del1 slutt
