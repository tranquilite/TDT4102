#pragma once

namespace del1 {
class Car {
    private:
        int freeSeats;

    public:
        Car();
        Car(int seatsTotal);
        const bool hasFreeSeats();
        void reserveFreeSeat();
};

} //namespace del1 slutt
