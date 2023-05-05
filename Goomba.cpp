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
    sprite.setTexture(texture1);
    die = false;
    goombaDeadBuffer.loadFromFile("Sounds/stomp.wav");
    goombaDeadSound.setBuffer(goombaDeadBuffer);
}
Goomba :: Goomba(int startingPoint){
    x = startingPoint;
    y = 638;
    texture1.loadFromFile("Images/goomba1.png");
    sprite.setTexture(texture1);
    die = false;
    goombaDeadBuffer.loadFromFile("Sounds/stomp.wav");
    goombaDeadSound.setBuffer(goombaDeadBuffer);

}
void Goomba :: drawGoomba(sf::RenderWindow& window){
    sprite.setPosition(x,y);
    window.draw(sprite);
}
void Goomba :: walk(Goomba& goomba){      
    static string direction = "right";
    static float counter = 0;
    if(direction == "right" && !die){     
        goomba.x += .125;
        counter += .1;
    }
    else if(direction == "left" && !die){
        goomba.x -= .125;
        counter -= .1;
    }
    if((int)counter <= 0){
        direction = "right";
    }
    else if((int)counter >= 275){
        direction = "left";
    }
}
void Goomba :: walk2(Goomba& goomba){      
    static string direction = "right";
    static float counter = 0;
    if(direction == "right" && !die){     
        goomba.x += .125;
        counter += .1;
    }
    else if(direction == "left" && !die){
        goomba.x -= .125;
        counter -= .1;
    }
    if((int)counter <= 0){
        direction = "right";
    }
    else if((int)counter >= 320){
        direction = "left";
    }
}
void Goomba :: checkDeath(const Jesusario& jesus, Goomba& goomba){
    if(!jesus.die)
    {
        if(((int)jesus.getX()+45 >= (int)goomba.getX() && ((int)jesus.getX() <= goomba.getX()+50) && ((int)jesus.getY()+48 == goomba.getY()))){
            goomba.die = true;
        }
    }
}
void Goomba :: dead(){
    if(die && y < 1000){
        sprite.setRotation(180);
        static int i = 0;
        for(;i < 1;i++){
            x += 50;
        }
        y += .1f;
    }
}
// void Goomba :: animation(){
//     goomba 
// }