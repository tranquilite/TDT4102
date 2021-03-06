#pragma once
#include<string>

#include"Car.h"
using namespace del1;

using std::string;

namespace del1 {
class Person {
    private:
        string name;
        string email;
        Car *car; //Husk å oppdatere Car-constructor!

    public:
        Person(string name) { this->name = name; }
        Person(string name, string email) : Person(name) {
            this->email = email;
        }
        Person(string name, string email, int seats) : Person(name, email) {
            this->car = new Car(seats);
        }
        
        string getProperty(string property) const;
        void setEmail(string new_email);
        const bool hasAvailableSeats();
        const bool operator==(const Person&);
        const bool operator<(const Person&);
        friend const std::ostream& operator<<(std::ostream&, const Person&);
};


} //namespace del1 slutt
