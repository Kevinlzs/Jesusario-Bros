#include <SFML/Graphics.hpp>
#include "Map.hpp"
using namespace std;

Map :: Map(){
    texture.loadFromFile("Images/marioMap.png");
    sprite.setTexture(texture);
}
void Map :: drawMap(sf::RenderWindow& window){
    sprite.setPosition(0,0);
    window.draw(sprite);
}