#ifndef MAP
#define MAP
#include <SFML/Graphics.hpp>


class Map {
public:
    Map();
    void drawMap(sf::RenderWindow& window);
private:
    sf::Sprite sprite;
    sf::Texture texture; 
    sf:: RectangleShape b1, b2, b3, b4, b5, b6, p1, p2, p3, p4;
};


#endif