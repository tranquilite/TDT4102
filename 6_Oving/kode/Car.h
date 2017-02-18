#pragma once

class Car {
    private:
        int freeSeats;

    public:
        Car(int seatsTotal);
        const bool hasFreeSeats();
        void reserveFreeSeat();

};
