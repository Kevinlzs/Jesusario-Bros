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
    void drawGoomba(sf::RenderWindow& window);
    void walk();
    void die();
    float x;
    float y;
    float getX() const {return x;}
    float getY() const {return y;}
    bool isAlive;
    sf::Texture texture1;
    sf::Sprite sprite;
};

#endif