#include "GameObjects.h"

#include "cannonball.h"
#include <cmath>

// implement all (member) functions in this file

Target::Target(double size, double position) {
    this->size = size;
    this->position = position;
    shape = sf::RectangleShape(sf::Vector2f(50.0, 20.0));
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(110, 60);
}

void Target::update() { }

void Target::draw(sf::RenderWindow& window) { window.draw(shape); }

bool hitTarget(const Cannonball& c, const Target& t) {
    return c.shape.getGlobalBounds().intersects(t.shape.getGlobalBounds());
}

double Cannonball::getPosX() const {
    return startPosX + startVelX*getAirTime();
}

double Cannonball::getPosY() const {
    return startPosX + startVelY * getAirTime() + (acclY()*getAirTime()*getAirTime())/2;
}

bool Cannonball::hasLanded() const {
    return getPosY() + size < 0;
}

double Cannonball::getAirTime() const {
    return SPEED_FACTOR*clock.getElapsedTime().asSeconds();
}

double Cannon::getTipX() const {
    return length*cos(degToRad(theta));
}

double Cannon::getTipY() const {
    return length*sin(degToRad(theta));
}
