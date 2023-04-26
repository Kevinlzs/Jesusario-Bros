#include <SFML/Graphics.hpp>
#include "Map.hpp"
#include <iostream>
using namespace std;

Map :: Map(){
    texture.loadFromFile("Images/marioMapLarger.png");
    sprite.setTexture(texture);
    //blocks settting size
    b1.setSize(sf::Vector2f(60,60));
    b2.setSize(sf::Vector2f(300,60));
    b3.setSize(sf::Vector2f(60,60));
    b4.setSize(sf::Vector2f(180,60));
    b5.setSize(sf::Vector2f(390,60));
    b6.setSize(sf::Vector2f(190,60));
    b7.setSize(sf::Vector2f(60,60));
    b8.setSize(sf::Vector2f(60,60));
    b9.setSize(sf::Vector2f(60,60));
    b10.setSize(sf::Vector2f(60,60));
    b11.setSize(sf::Vector2f(60,60));
    // b12.setSize(sf::Vector2f(60,60));

    
    //pipes setting size
    p1.setSize(sf::Vector2f(100,130));
    p2.setSize(sf::Vector2f(100,180));
    p3.setSize(sf::Vector2f(100,230));
    p4.setSize(sf::Vector2f(100,230));

    sprite.setPosition(0,0);

    //blocks setting position
    b1.setPosition(750, 455);
    b2.setPosition(945, 455);
    b3.setPosition(1039, 229);
    b4.setPosition(3595, 455);
    b5.setPosition(3775, 229);
    b6.setPosition(4294, 229);
    b7.setPosition(4435, 455);
    b8.setPosition(4710, 455);
    b9.setPosition(5200, 455);

    //pipes setting position
    p1.setPosition(1323, 558);
    p2.setPosition(1793, 508);
    p3.setPosition(2170, 458);
    p4.setPosition(2685, 458);
}
void Map :: drawMap(sf::RenderWindow& window){
    // r1.setFillColor(sf::Color(255,0,0));
    //blocks
    window.draw(b1);
    window.draw(sprite);
    window.draw(b2);
    window.draw(b3);
    window.draw(b4);
    window.draw(b5);
    window.draw(b6);
    window.draw(b7);
    window.draw(b8);
    window.draw(b9);

    //pipes
    window.draw(p1);
    window.draw(p2);
    window.draw(p3);
    window.draw(p4);
} 
void Map :: checkCollision(Jesusario& jesus, sf::RectangleShape blocks[]){
    this->blocks[0] = b1;
    this->blocks[1] = b2;
    this->blocks[2] = b3;
    this->blocks[3] = b4;
    this->blocks[4] = b5;
    this->blocks[5] = b6;
    this->blocks[6] = p1;
    this->blocks[7] = p2;
    this->blocks[8] = p3;
    this->blocks[9] = p4;
    for(int i = 0; i < 10; i++){
        sf::FloatRect bounds = blocks[i].getGlobalBounds();
        int h = bounds.height;
        int w = bounds.width;
        // cout << blocks[i].getPosition().x << endl;
        //left side
        // cout << (shape.getPosition().x) << endl;
        if((int)jesus.getY() <= blocks[i].getPosition().y+h && (int)jesus.getY()+48 >= blocks[i].getPosition().y && (int)jesus.getX()+45 == blocks[i].getPosition().x){
            jesus.x = blocks[i].getPosition().x-45;
        } 
        if((int)jesus.getY() == blocks[i].getPosition().y+h && ((int)jesus.getX()+45 >= blocks[i].getPosition().x && (int)jesus.getX() <= blocks[i].getPosition().x+w)){
            jesus.y += 1;
        //bottom
        // if((int)jesus.getY() >= shape.getPosition().y && (int)jesus.getY() <= shape.getPosition().y+h && (int)jesus.getX()+45 >= shape.getPosition().x){
        //     jesus.x = shape.getPosition().x-40;
        // }
        }  
        if((int)jesus.getY() <= blocks[i].getPosition().y+h && (int)jesus.getY()+48 >= blocks[i].getPosition().y && (int)jesus.getX() == blocks[i].getPosition().x+w){
            jesus.x = blocks[i].getPosition().x+w+1;
            /*blocks[i].getPosition().x+62*/;
        //right
        }  
        if(((int)jesus.getX()+45 >= blocks[i].getPosition().x) && ((int)jesus.getX() <= blocks[i].getPosition().x+w) && ((int)jesus.getY()+48 == blocks[i].getPosition().y)){
                //blocks[i].getPosition().y-45
            jesus.y = blocks[i].getPosition().y-48;
        //top
        }
    }
}