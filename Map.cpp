#include <SFML/Graphics.hpp>
#include "Map.hpp"
#include <iostream>
using namespace std;

Map :: Map(){
    texture.loadFromFile("Images/marioMapLarger.png");
    sprite.setTexture(texture);
    b1.setSize(sf::Vector2f(60,60));
    b2.setSize(sf::Vector2f(300,60));
    b3.setSize(sf::Vector2f(60,60));
    b4.setSize(sf::Vector2f(180,60));
    b5.setSize(sf::Vector2f(390,60));
    p1.setSize(sf::Vector2f(100,130));
    p2.setSize(sf::Vector2f(100,180));
    p3.setSize(sf::Vector2f(100,230));
    p4.setSize(sf::Vector2f(100,230));
    
}
void Map :: drawMap(sf::RenderWindow& window){
    sprite.setPosition(0,0);
    b1.setPosition(750, 455);
    b2.setPosition(945, 455);
    b3.setPosition(1039, 229);
    b4.setPosition(3595, 455);
    b5.setPosition(3775, 229);
    p1.setPosition(1323, 558);
    p2.setPosition(1793, 508);
    p3.setPosition(2170, 458);
    p4.setPosition(2685, 458);
    // r1.setFillColor(sf::Color(255,0,0));
    window.draw(b1);
    window.draw(sprite);
    window.draw(b2);
    window.draw(b3);
    window.draw(b4);
    window.draw(b5);
    window.draw(p1);
    window.draw(p2);
    window.draw(p3);
    window.draw(p4);
} 
void Map :: checkCollision(Jesusario& jesus, sf::RectangleShape& shape){
    sf::FloatRect bounds = shape.getGlobalBounds();
    
    int h = bounds.height;
    int w = bounds.width;


    //left side
    // cout << (shape.getPosition().x) << endl;
    if((int)jesus.getY() <= shape.getPosition().y+h && (int)jesus.getY() >= shape.getPosition().y && (int)jesus.getX()+45 == shape.getPosition().x){
        jesus.x = shape.getPosition().x-45;
    } if((int)jesus.getY() == shape.getPosition().y+60 && ((int)jesus.getX()+45 >= shape.getPosition().x && (int)jesus.getX() <= shape.getPosition().x+60)){
        jesus.y += 1;
    //bottom
    // if((int)jesus.getY() >= shape.getPosition().y && (int)jesus.getY() <= shape.getPosition().y+h && (int)jesus.getX()+45 >= shape.getPosition().x){
    //     jesus.x = shape.getPosition().x-40;
    // }
    }  if((int)jesus.getY() <= shape.getPosition().y+60 && (int)jesus.getY() >= shape.getPosition().y && (int)jesus.getX() == shape.getPosition().x+60){
        jesus.y += 1/*shape.getPosition().x+62*/;
    //right
    }  if(((int)jesus.getX()+45 >= shape.getPosition().x) && ((int)jesus.getX() <= shape.getPosition().x+w) && ((int)jesus.getY()+48

        == shape.getPosition().y)){
            //shape.getPosition().y-45
        jesus.y = shape.getPosition().y-48;
    //top
    }
}