#include<string>

using std::string;

#include"Person.h"
#include"Car.h"

//Person::Person(string name) { this->name = name; }
//Person::Person(string name, string email) { this->email = email; }

const string Person::getProperty(string property) {

    if(property == "name") { return this->name; }
    if(property =="email") { return this->email; }
    return "Person::getProperty fail";
}
        
