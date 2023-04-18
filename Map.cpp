#include <SFML/Graphics.hpp>
#include "Map.hpp"
using namespace std;

Map :: Map(){
    texture.loadFromFile("Images/marioMapLarger.png");
    sprite.setTexture(texture);
    r1.setSize(sf::Vector2f(200,100));
}
void Map :: drawMap(sf::RenderWindow& window){
    sprite.setPosition(0,0);
    r1.setPosition(200, 638);
    r1.setFillColor(sf::Color(255,0,0));
    window.draw(sprite);
    window.draw(r1);
} 
