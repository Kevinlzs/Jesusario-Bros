#ifndef MAP
#define MAP
#include <SFML/Graphics.hpp>
#include "Jesusario.hpp"

class Map {
public:
    Map();
    void drawMap(sf::RenderWindow& window);
    void checkCollision(Jesusario& jesus, sf::RectangleShape blocks[]);
// private:
    sf::Sprite sprite;
    sf::Texture texture; 
    sf::RectangleShape b1, b2, b3, b4, b5, b6, b7, b8, b9, b10
    sf::RectangleShape b11, b12, p1, p2, p3, p4;
    sf::RectangleShape blocks[11] = {b1, b2, b3, b4, b5, b6, b7, b8, b9, b10};
};


#endif