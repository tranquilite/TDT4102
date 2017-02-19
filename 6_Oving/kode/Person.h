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
        Car* car;

    public:
        Person(string name) { this->name = name; }
        Person(string name, string email) : Person(name) {
            this->email = email;
        }
        
        const string getProperty(string property);
        void setEmail(string new_email);
        const bool hasAvailableSeats();

};

} //namespace del1 slutt
