#include <SFML/Graphics.hpp>
#include "Jesusario.hpp"
#include "Goomba.hpp"
#include <SFML/Audio.hpp>
#include <iostream>
using namespace std;

Jesusario :: Jesusario(){
    x = 200; //1st = 3230
    y = 638;
    jumpRight.loadFromFile("Images/jesusJumping.png");
    jumpLeft.loadFromFile("Images/jesusJumpingLeft.png");
    texture1.loadFromFile("Images/jesus.png");
    texture2.loadFromFile("Images/jesusLeft.png");
    rightSprite.loadFromFile("Images/jesusAnimation.png");
    leftSprite.loadFromFile("Images/jesusAnimationLeft.png");
    jesusDied.loadFromFile("Images/jesusDdead.png");
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
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !gameFinished){
        x = x;
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !gameFinished && !die){
        if(x >= 0){
            x -= .2;
        }
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !gameFinished && !die){
        if(x <= 9955){
            x += .2;
        }
    } 
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up ) && !gameFinished && !die){
        if(y <= 639 && counter != 0 && !collision && !alreadyJumped){
            onBlock = false;
            // sound2.play();
            y -= .65f;
            counter-=1;
        } else {
            counter = 0;
            alreadyJumped = true;
        }
    }
    //Gravity
    // if(y < 638 && !onBlock){
    //     y += .15f;
    // } else {
    //     collision = false;
    //     counter = 500;//make him jump longer
    // }
    //pits
    if(((x >= 3255 && x <= 3310) || (x >= 4055 && x <= 4155) || ((x >= 7214 && x <= 7270)) ) && y >= 638){
        y += .2f;
        die = true;
        x = x;
    }
    
    if(x >= 9350){
        gameFinished = true;
    }
}
void Jesusario :: animation(){
    if(die){
        sprite.setTexture(jesusDied);
        sprite.setTextureRect(sf::IntRect(0,0,45,48));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !gameFinished && !die){
        // texture.loadFromFile("Images/jesus.png");
        if(right > left){
            sprite.setTexture(texture1);
            sprite.setTextureRect(sf::IntRect(0,0,45,48));
        } else if(left > right){
            sprite.setTexture(texture2);
            sprite.setTextureRect(sf::IntRect(0,0,45,48));
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !gameFinished && !die){
        if(y < 638 && !onBlock){
            sprite.setTexture(jumpRight);
            sprite.setTextureRect(sf::IntRect(0,0,45,48));
        } else if(y >= 638 || 1){
            sprite.setTexture(rightSprite);
            int xTexture = 0;
            xTexture = (int)sprite.getPosition().x/30 % 3; 
            xTexture *= 45;
            sprite.setTextureRect(sf::IntRect(xTexture, 0, 45, 48));
        }
        right += 1;
        right2++;
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !gameFinished && !die){
        if(y < 638 && !onBlock){
            sprite.setTexture(jumpLeft);
            sprite.setTextureRect(sf::IntRect(0,0,45,48));
        } else if(y >= 638 || 1){
            sprite.setTexture(leftSprite);
            int xTexture = 0;
            xTexture = (int)sprite.getPosition().x/30 % 3; 
            xTexture *= 45;
            sprite.setTextureRect(sf::IntRect(xTexture, 0, 45, 48));
        }
        left += 1;
        left2++;
    } else {
        if(right > left && !gameFinished){
            // texture.loadFromFile("Images/jesus.png");
            sprite.setTexture(texture1);
            sprite.setTextureRect(sf::IntRect(0, 0, 45, 48));
            right = 0;
            left = 0;
        } else if(left > right && !gameFinished){
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
void Jesusario :: dead(Jesusario& jesus, Goomba& goomba)
{
    if((int)jesus.getY() <= (int)goomba.getY()+48 && (int)jesus.getY()+48 >= (int)goomba.getY() && (int)jesus.getX() == (int)goomba.getX()+48 || 
    (((int)jesus.getX()+45 >= goomba.getX()) && ((int)jesus.getX() <= (int)goomba.getX() + 45) && ((int)jesus.getY()+48 == (int)goomba.getY() + 48))){
        jesus.die = true;
    }
}
void Jesusario :: bringDown(){
    static int i = 0;
    if(die && y < 1000){
        if(i == 0){
            y-=75;
            i++;
        }
        y += .06f;
    }
}
void Jesusario :: gravity(){
    if(y < 638 && !onBlock){
        y += .15f;
    } else {
        collision = false;
        counter = 500;//make him jump longer
        alreadyJumped = false;
    }
}