#ifndef JESUSARIO
#define JESUSARIO
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

const float SCREEN_HEIGHT = 1000;
const float SCREEN_WIDTH = 1000;
class Jesusario {
public:
    Jesusario();
    void drawJesus(sf::RenderWindow& window);
    void move();
    void animation();
    void animation2();
    float getX() const {return x;}
    float getY() const {return y;}
// private:
    float x;
    float y;
    int counter = 500;
    int right = 0, left = 0, left2 = 0, right2 = 0;;
    sf::Texture texture, texture2;
    sf::Sprite sprite;
    sf::SoundBuffer buffer2;
    sf::Sound sound2;
};


#endif