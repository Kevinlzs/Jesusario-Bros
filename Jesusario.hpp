#ifndef JESUSARIO_HPP
#define JESUSARIO_HPP
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Jesusario.hpp"

const float SCREEN_HEIGHT = 1000;
const float SCREEN_WIDTH = 1000;

class Goomba;

class Jesusario {
public:
    Jesusario();
    void drawJesus(sf::RenderWindow& window);
    void move();
    void animation();
    void animation2();
    void dead(Jesusario& jesus, Goomba& goomba);
    void bringDown();
    void gravity();
    float getX() const {return x;}
    float getY() const {return y;}
// private:
    float x;
    float y;
    bool die = false, onBlock = false, gameFinished = false, collision = false, alreadyJumped = false;
    int counter = 500;
    int right = 0, left = 0, left2 = 0, right2 = 0;;
    sf::Texture texture1, texture2, rightSprite, leftSprite, jumpRight, jumpLeft, jesusDied;
    sf::Sprite sprite;
    sf::SoundBuffer jumpBuffer, dieBuffer;
    sf::Sound jumpSound, dieSound;
};


#endif