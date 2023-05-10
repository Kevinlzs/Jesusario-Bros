#include <SFML/Graphics.hpp>
#include "Jesusario.hpp"
#include "Goomba.hpp"
#include <SFML/Audio.hpp>
#include <iostream>
using namespace std;

Jesusario :: Jesusario(){
    x = 300; //1st = 3230// castle door = 9625
    y = 638;
    strongJesus.loadFromFile("Images/strongJesus.png");
    strongJesusLeft.loadFromFile("Images/strongJesusLeft.png");
    strongJesusAnimation.loadFromFile("Images/bigJesusAnimation.png");
    strongJesusAnimationLeft.loadFromFile("Images/bigJesusAnimationLeft.png");
    mariachi.loadFromFile("Images/mariachiPixel.png");
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
    if(!deleteSprite){
        sprite.setPosition(x,y);
        window.draw(sprite);
    }
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
        fellInPits = true;
        if(y > 850){
            die = true;
        }
    } else if(((x >= 3255 && x <= 3310) || (x >= 4055 && x <= 4155) || ((x >= 7214 && x <= 7270)) ) && y >= 589 && bigJesus){
        y += .2f;
        fellInPits = true;
        if(y > 850){
            die = true;
        }
    } else if(y > 850){
        fellInPits = true;
        die = true;
    }
    
    if(x >= 9340){
        gameFinished = true;
    }
}
void Jesusario :: animation(){
    // if(invincible && invincibleCounter != 20000){
    //     sprite.setTexture(strongJesus);
    //     sprite.setTextureRect(sf::IntRect(0,0,60,96));
    // }
    if(die && smallJesus){
        sprite.setTexture(jesusDied);
        sprite.setTextureRect(sf::IntRect(0,0,45,48));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !gameFinished && !die && smallJesus){
        // texture.loadFromFile("Images/jesus.png");
        if(right > left){
            sprite.setTexture(texture1);
            sprite.setTextureRect(sf::IntRect(0,0,45,48));
        } else if(left > right){
            sprite.setTexture(texture2);
            sprite.setTextureRect(sf::IntRect(0,0,45,48));
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !gameFinished && !die && smallJesus){
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
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !gameFinished && !die && smallJesus){
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
        if(right > left && !gameFinished && smallJesus){
            // texture.loadFromFile("Images/jesus.png");
            sprite.setTexture(texture1);
            sprite.setTextureRect(sf::IntRect(0, 0, 45, 48));
            right = 0;
            left = 0;
        } else if(left > right && !gameFinished && smallJesus){
            sprite.setTexture(texture2);
            sprite.setTextureRect(sf::IntRect(0, 0, 45, 48));
            right = 0;
            left = 0;
        }
    if(smallJesus){
        sprite.setTextureRect(sf::IntRect(0, 0, 45, 48));
        right = 0;
        left = 0;
    }
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
void Jesusario :: dead(Jesusario& jesus, Goomba& goomba){
    if(!goomba.die && jesus.smallJesus && !invincible){
        if((int)jesus.getY() <= (int)goomba.getY()+48 && (int)jesus.getY()+48 >= (int)goomba.getY() && (int)jesus.getX() == (int)goomba.getX()+48 || 
        (((int)jesus.getX()+45 >= goomba.getX()) && ((int)jesus.getX() <= (int)goomba.getX() + 45) && ((int)jesus.getY()+48 == (int)goomba.getY() + 48))){
            jesus.die = true;
        }
    } else if(!goomba.die && jesus.bigJesus){
        if((int)jesus.getY() <= (int)goomba.getY()+48 && (int)jesus.getY()+96 >= (int)goomba.getY() && (int)jesus.getX() == (int)goomba.getX()+48 || 
        (((int)jesus.getX()+60 >= goomba.getX()) && ((int)jesus.getX() <= (int)goomba.getX() + 48) && ((int)jesus.getY()+96 == (int)goomba.getY() + 48))){
            // jesus.die = true;
            jesus.bigJesus = false;
            jesus.smallJesus = true;
            jesus.invincible = true;
            sprite.setTexture(texture1);
            sprite.setTextureRect(sf::IntRect(0,0,45,48));
        }
    }
}
void Jesusario :: bringDown(){
    static int i = 0;
    if(die && y < 1000 && !fellInPits){
        if(i == 0){
            y-=75;
            i++;
        }
        y += .06f;
    }
}
void Jesusario :: gravity(){
    if(y < 638 && !onBlock && smallJesus){
        y += .15f;
    } else if(y < 590 && !onBlock && bigJesus){
        y += .15f;
    } else{
        collision = false;
        counter = 500;//make him jump longer
        alreadyJumped = false;
    }
}
void Jesusario :: clearedLevel(){
    if(gameFinished && x < 9625){
        x += .1f;
        sprite.setTexture(rightSprite);
        int xTexture = 0;
        xTexture = (int)sprite.getPosition().x/30 % 3; 
        xTexture *= 45;
        sprite.setTextureRect(sf::IntRect(xTexture, 0, 45, 48));
    } else if(x > 9625){
        deleteSprite = true;
    }
}
void Jesusario :: drawMariachis(sf::RenderWindow& window){
    if(gameFinished){
        mariachiOne.setTexture(mariachi);
        mariachiTwo.setTexture(mariachi);
        mariachiTwo.setTextureRect(sf::IntRect(126, 0, -126, 162));
        mariachiOne.setPosition(9480, 542);
        mariachiTwo.setPosition(9690, 542);
        window.draw(mariachiOne);
        window.draw(mariachiTwo);
    }
}
void Jesusario :: animation2(){
    // if(bigJesus){
    //     sprite.setTexture(strongJesus);
    //     sprite.setTextureRect(sf::IntRect(0,0,60,96));
    // }
    // if(die && smallJesus){
    //     sprite.setTexture(jesusDied);
    //     sprite.setTextureRect(sf::IntRect(0,0,45,48));
    // }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !gameFinished && !die && bigJesus){
        // texture.loadFromFile("Images/jesus.png");
        if(right > left){
            sprite.setTexture(strongJesus);
            sprite.setTextureRect(sf::IntRect(0,0,62,96));
        } else if(left > right){
            sprite.setTexture(strongJesusLeft);
            sprite.setTextureRect(sf::IntRect(0,0,62,96));
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !gameFinished && !die && bigJesus){
        if(y < 590 && !onBlock){
            sprite.setTexture(strongJesus);
            sprite.setTextureRect(sf::IntRect(0,0,61,96));
        } else if(y >= 638 || 1){
            sprite.setTexture(strongJesusAnimation);
            int xTexture = 0;
            xTexture = (int)sprite.getPosition().x/30 % 3; 
            xTexture *= 66;
            sprite.setTextureRect(sf::IntRect(xTexture, 0, 66, 96));
        }
        right += 1;
        right2++;
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !gameFinished && !die && bigJesus){
        if(y < 590 && !onBlock){
            sprite.setTexture(strongJesusLeft);
            sprite.setTextureRect(sf::IntRect(0,0,62,96));
        } else if(y >= 638 || 1){
            sprite.setTexture(strongJesusAnimationLeft);
            int xTexture = 0;
            xTexture = (int)sprite.getPosition().x/30 % 3; 
            xTexture *= 66;
            sprite.setTextureRect(sf::IntRect(xTexture, 0, 66, 96));
        }
        left += 1;
        left2++;
    } else {
        if(right > left && !gameFinished && bigJesus){
            // texture.loadFromFile("Images/jesus.png");
            sprite.setTexture(strongJesus);
            sprite.setTextureRect(sf::IntRect(0, 0, 60, 96));
            right = 0;
            left = 0;
        } else if(left > right && !gameFinished && bigJesus){
            sprite.setTexture(strongJesusLeft);
            sprite.setTextureRect(sf::IntRect(0, 0, 60, 96));
            right = 0;
            left = 0;
        }
    if(bigJesus){
        sprite.setTextureRect(sf::IntRect(0, 0, 60, 96));
        right = 0;
        left = 0;
    }
    }
}
void Jesusario :: invincibleTimer(){
    if(invincible && invincibleCounter != 10000){
        invincibleCounter++;
    } else {
        invincibleCounter = 0;
        invincible = false;
    }
}