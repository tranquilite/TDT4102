#include<iostream>

using std::cout;
using std::endl;

#include"Person.h"
#include"Car.h"
#include "tests.h"

int main() {
    cout << std::endl;
    //..hva er sluttresultatet etter linkeren?
    //kompileren genererer objektkode, men gjør linker noe annet
    //enn å linke objektkodene, slik at det fortsatt er objektkode
    //som kommer ut?

    //testSFML();
    del1::Person ahnold("ahnold");
    del1::Person *akagi = new del1::Person("Akagi", "ritsuko@nerv.jp");
    cout << akagi->getProperty("email") << endl;
    cout << akagi->getProperty("name");

    cout << endl << endl;
    return 0;
}
