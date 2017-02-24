#include<iostream>
#include <SFML/Graphics.hpp>

#include"Person.h"
#include"Car.h"
#include"tests.h"


int testSFML() {
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}

bool testPerson() {
    del1::Person personTest("Einar", "einar@tambarskjelve.trd");
    del1::Person personTestTo("Sigrid", "sigrid@undset.trd");

    std::cout << "Ekvivalens, samme: " << (personTest == personTest) << std::endl;
    std::cout << "Ekvivalens, ulik:  " << (personTest == personTestTo) << std::endl;
    std::cout << "Piper objekt til ostream: " << personTest;
    std::cout << std::endl;
    std::cout << "Tester medlemsfunksjoner etter forventet output";
    testPerson_rull(personTest);
    return 0;
}

bool testPerson_rull(Person& sig) {
    int forventning[10] = {0 ,0, 0, 0, 0, 0, 0, 0, 0, 0};
    for(int i=0; i < 10; i++) {
        //do test..
    }
    return false;
}
