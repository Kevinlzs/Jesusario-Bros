#ifndef GOOMBA_HPP
#define GOOMBA_HPP
#include <SFML/Graphics.hpp>
#include "Jesusario.hpp"
#include <SFML/Audio.hpp>
#include <iostream>
using namespace std;

class Goomba : public Jesusario {
public:
    Goomba();
    Goomba(int startingPoint);
    void drawGoomba(sf::RenderWindow& window);
    void walk(Goomba& goomba);
    void walk2(Goomba& goomba);
    void checkDeath(const Jesusario& jesus, Goomba& goomba);
    void dead();
    void animation();
    float getX() const {return x;}
    float getY() const {return y;}
};

#endif