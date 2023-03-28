#include <SFML/Graphics.hpp>
#include "Jesusario.hpp"
#include <iostream>
using namespace std;

Jesusario :: Jesusario(){
    x = 200;
    y = 630;
    texture.loadFromFile("Images/jesus.png");
    sprite.setTexture(texture);
}
void Jesusario :: drawJesus(sf::RenderWindow& window){
    sprite.setPosition(x,y);
    window.draw(sprite);
}
void Jesusario :: move(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        if(x >= 0){
            x -= .25;
        }
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        x += .25;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        if(y <= 640 && counter != 0){
            y -= .8;
            counter--;
        }
    }
    if(y < 638){
        y += .3f;
    } else {
        counter = 400;
    }
}
void Jesusario :: animation(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        if(y <= 638){
            texture.loadFromFile("Images/jesusJumping.png");
            sprite.setTexture(texture);
        } else if(y > 638){
            texture.loadFromFile("Images/jesusMovingRight.png");
            sprite.setTexture(texture);
        }
        right += 1;
        right2++;
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        if(y <= 638){
            texture.loadFromFile("Images/jesusJumpingLeft.png");
            sprite.setTexture(texture);
        } else if(y > 638){
            texture.loadFromFile("Images/jesusMovingLeft.png");
            sprite.setTexture(texture);
        }
        left += 1;
        left2++;
    } else {
        if(right > left){
            texture.loadFromFile("Images/jesus.png");
            sprite.setTexture(texture);
            right = 0;
            left = 0;
        } else if(left > right){
            texture.loadFromFile("Images/jesusLeft.png");
            sprite.setTexture(texture);
            right = 0;
            left = 0;
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        if(right2 > left2){
            texture.loadFromFile("Images/jesusJumping.png");
            sprite.setTexture(texture);
            right2 = 0;
            left2 = 0;
        } else if(left2 > right2){
            texture.loadFromFile("Images/jesusJumpingLeft.png");
            sprite.setTexture(texture);
            right2 = 0;
            left2 = 0;
        }
    }
}
void Jesusario :: animation2(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        if(right2 > left2){
            texture.loadFromFile("Images/jesusJumping.png");
            sprite.setTexture(texture);
            right2 = 0;
            left2 = 0;
        } else if(left2 > right2){
            texture.loadFromFile("Images/jesusJumpingLeft.png");
            sprite.setTexture(texture);
            right2 = 0;
            left2 = 0;
        } 
    }
}