#include<string>

using std::string;

#include"Person.h"
#include"Car.h"
using namespace del1;

namespace del1 {
const string Person::getProperty(string property) {

    if(property == "name") { return this->name; }
    if(property =="email") { return this->email; }
    return "Person::getProperty fail";
}

const bool Person::hasAvailableSeats() {
    //Dette går ikke hvis ikke instansen har en bil.
    return ((this->car)->hasFreeSeats());
}

} //namespace del1 slutt
