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
};


#endif