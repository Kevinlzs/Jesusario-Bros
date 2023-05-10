#include <SFML/Graphics.hpp>
#include "Map.hpp"
#include "Goomba.hpp"
#include "Jesusario.hpp"
#include <iostream>
#include <string>
using namespace std;

Goomba :: Goomba(){
    x = 300;
    y = 638;
    texture1.loadFromFile("Images/goomba1.png");
    deadTexture.loadFromFile("Images/goombaDead.png");
    sprite.setTexture(texture1);
    sprite.setTextureRect(sf::IntRect(0,0,49,48));
    die = false;
    goombaDeadBuffer.loadFromFile("Sounds/stomp.wav");
    goombaDeadSound.setBuffer(goombaDeadBuffer);
}
Goomba :: Goomba(int startingPoint){
    x = startingPoint;
    y = 638;
    texture1.loadFromFile("Images/goomba1.png");
    deadTexture.loadFromFile("Images/goombaDead.png");
    sprite.setTexture(texture1);
    sprite.setTextureRect(sf::IntRect(0,0,49,48));
    die = false;
    goombaDeadBuffer.loadFromFile("Sounds/stomp.wav");
    goombaDeadSound.setBuffer(goombaDeadBuffer);

}
void Goomba :: drawGoomba(sf::RenderWindow& window){
    if(!deleteSprite){
        sprite.setPosition(x,y);
        window.draw(sprite);
    }
}
void Goomba :: walk(Goomba& goomba){      
    static string direction = "right";
    static float counter = 0;
    if(direction == "right" && !die){     
        goomba.x += .05;
        counter += .1;
    }
    else if(direction == "left" && !die){
        goomba.x -= .05;
        counter -= .1;
    }
    if((int)counter <= 0){
        direction = "right";
    }
    else if((int)counter >= 680){
        direction = "left";
    }
}
void Goomba :: walk2(Goomba& goomba){      
    static string direction = "right";
    static float counter = 0;
    if(direction == "right" && !die){     
        goomba.x += .05;
        counter += .05;
    }
    else if(direction == "left" && !die){
        goomba.x -= .05;
        counter -= .05;
    }
    if((int)counter <= 0){
        direction = "right";
    }
    else if((int)counter >= 390){
        direction = "left";
    }
}
void Goomba :: walk3(Goomba& goomba){      
    static string direction = "right";
    static float counter = 0;
    if(direction == "right" && !die){     
        goomba.x += .05;
        counter += .05;
    }
    else if(direction == "left" && !die){
        goomba.x -= .05;
        counter -= .05;
    }
    if((int)counter <= 0){
        direction = "right";
    }
    else if((int)counter >= 390){
        direction = "left";
    }
}
void Goomba :: checkDeath(const Jesusario& jesus, Goomba& goomba){
    if(!jesus.die && jesus.smallJesus)
    {
        if(((int)jesus.getX()+45 >= (int)goomba.getX() && ((int)jesus.getX() <= goomba.getX()+50) && ((int)jesus.getY()+48 == goomba.getY()))){
            goomba.die = true;
        }
    } else if(!jesus.die && jesus.bigJesus){
        if(((int)jesus.getX()+60 >= (int)goomba.getX() && ((int)jesus.getX() <= goomba.getX()+50) && ((int)jesus.getY()+96 == goomba.getY()))){
            goomba.die = true;
        }
    }
}
void Goomba :: dead(Jesusario& jesus){
    if(die && y < 1000){
        // sprite.setRotation(180);
        // static int i = 0;
        // for(;i < 1;i++){
        //     x += 50;
        // }
        // y += .1f;
        if(!alreadyDied){
            jesus.y -= 80;
            alreadyDied = true;
        }
        sprite.setTexture(deadTexture);
        sprite.setTextureRect(sf::IntRect(0,0,48,48));
        counter++;
    }
}
void Goomba :: animation(){
    // sprite.setTexture(texture1);
    if(!die){
        int xTexture = 0;
        xTexture = (int)sprite.getPosition().x/30 % 2; 
        xTexture *= 50;
        sprite.setTextureRect(sf::IntRect(xTexture+50, 0, 49, 48));
    }
    if(die && counter == 3000){
        deleteSprite = true;
    }
}