#include<iostream>
#include<string>

using std::string;

#include"Person.h"
#include"Car.h"
using namespace del1;

namespace del1 {
string Person::getProperty(string property) const {

    if(property == "name") { return this->name; }
    if(property =="email") { return this->email; }
    return "Person::getProperty fail";
}

const bool Person::hasAvailableSeats() {
    //Dette går ikke hvis ikke instansen har en bil.
    std::cout << "Person::hasAvailableSeats() " << std::endl;
    return ((this->car != nullptr) && (this->car)->hasFreeSeats());
}

const std::ostream& operator<<(std::ostream& out, const Person& pers) {
    return out << pers.getProperty("name") << ", " << pers.getProperty("email");
}

const bool Person::operator==(const Person& rhs) {
    return this->name == rhs.getProperty("name");
}

const bool Person::operator<(const Person& rhs) {
    //Oppgavetekst, plis?
    return false;
}

} //namespace del1 slutt
