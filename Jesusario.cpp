#include <SFML/Graphics.hpp>
#include "Jesusario.hpp"
#include <SFML/Audio.hpp>
#include <iostream>
using namespace std;

Jesusario :: Jesusario(){
    x = 300; //1st = 3230
    y = 638;
    jumpRight.loadFromFile("Images/jesusJumping.png");
    jumpLeft.loadFromFile("Images/jesusJumpingLeft.png");
    texture1.loadFromFile("Images/jesus.png");
    texture2.loadFromFile("Images/jesusLeft.png");
    rightSprite.loadFromFile("Images/jesusAnimation.png");
    leftSprite.loadFromFile("Images/jesusAnimationLeft.png");
    sprite.setTexture(texture1);
    // sprite.setTextureRect(sf::IntRect(0, 0, 45, 48));
    jumpBuffer.loadFromFile("Sounds/marioJump.wav");
    jumpSound.setBuffer(jumpBuffer);
    dieBuffer.loadFromFile("Sounds/mariodie.wav");
    dieSound.setBuffer(dieBuffer);
}
void Jesusario :: drawJesus(sf::RenderWindow& window){
    sprite.setPosition(x,y);
    window.draw(sprite);
}
void Jesusario :: move(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        x = x;
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        if(x >= 0){
            x -= .2;
        }
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        x += .2;
    } 
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        if(y <= 638 && counter != 0){
            // sound2.play();
            y -= .85;
            counter--;
        }
    }
    //Gravity
    if(y < 638 ){
        y += .2f;
    } else {
        counter = 500;//make him jump longer
    }
    //pits
    if(((x >= 3255 && x <= 3310) || (x >= 4055 && x <= 4155) || ((x >= 7214 && x <= 7270)) ) && y >= 638){
        y += .3f;
        die = true;
        
         x = x;
    }
    
    // if(y > 639){
    //     y += .2f;
    //     // x = x;
    // }

  
}
void Jesusario :: animation(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        // texture.loadFromFile("Images/jesus.png");
        if(right > left){
            sprite.setTexture(texture1);
            sprite.setTextureRect(sf::IntRect(0,0,45,48));
        } else if(left > right){
            sprite.setTexture(texture2);
            sprite.setTextureRect(sf::IntRect(0,0,45,48));
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        if(y < 638){
            sprite.setTexture(jumpRight);
            sprite.setTextureRect(sf::IntRect(0,0,45,48));
        } else if(y >= 638){
            sprite.setTexture(rightSprite);
            int xTexture = 0;
            xTexture = (int)sprite.getPosition().x/30 % 3; 
            xTexture *= 45;
            sprite.setTextureRect(sf::IntRect(xTexture, 0, 45, 48));
        }
        right += 1;
        right2++;
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        if(y < 638){
            sprite.setTexture(jumpLeft);
            sprite.setTextureRect(sf::IntRect(0,0,45,48));
        } else if(y >= 638){
            sprite.setTexture(leftSprite);
            int xTexture = 0;
            xTexture = (int)sprite.getPosition().x/30 % 3; 
            xTexture *= 45;
            sprite.setTextureRect(sf::IntRect(xTexture, 0, 45, 48));
        }
        left += 1;
        left2++;
    } else {
        if(right > left){
            // texture.loadFromFile("Images/jesus.png");
            sprite.setTexture(texture1);
            sprite.setTextureRect(sf::IntRect(0, 0, 45, 48));
            right = 0;
            left = 0;
        } else if(left > right){
            sprite.setTexture(texture2);
            sprite.setTextureRect(sf::IntRect(0, 0, 45, 48));
            right = 0;
            left = 0;
        }
    sprite.setTextureRect(sf::IntRect(0, 0, 45, 48));
    right = 0;
    left = 0;
    }
    // if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
    //     if(right2 > left2){
    //         texture.loadFromFile("Images/jesusJumping.png");
    //         sprite.setTexture(texture);
    //         right2 = 0;
    //         left2 = 0;
    //     } else if(left2 > right2){
    //         texture.loadFromFile("Images/jesusJumpingLeft.png");
    //         sprite.setTexture(texture);
    //         right2 = 0;
    //         left2 = 0;
    //     }
    // }
}
void Jesusario :: animation2(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        if(right2 > left2){
            // texture.loadFromFile("Images/jesusJumping.png");
            sprite.setTexture(jumpRight);
            sprite.setTextureRect(sf::IntRect(0,0,45,48));
            right2 = 0;
            left2 = 0;
        } else if(left2 > right2){
            // texture.loadFromFile("Images/jesusJumpingLeft.png");
            sprite.setTexture(jumpLeft);
            sprite.setTextureRect(sf::IntRect(0,0,45,48));
            right2 = 0;
            left2 = 0;
        } 
    }
    sprite.setTextureRect(sf::IntRect(0, 0, 45, 48));
}