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
    void walk3(Goomba& goomba);
    void walk4(Goomba& goomba);
    void walk5(Goomba& goomba);
    void checkDeath(const Jesusario& jesus, Goomba& goomba);
    void dead(Jesusario& jesus);
    void animation();
    float getX() const {return x;}
    float getY() const {return y;}
    sf::SoundBuffer goombaDeadBuffer;
    sf::Sound goombaDeadSound;
    bool alreadyDied = false, deleteSprite = false;
    bool die = false;
    int counter = 0, counter2 = 0;
    sf::Texture deadTexture;
    // sf::Sprite deadSprite;
};

#endif