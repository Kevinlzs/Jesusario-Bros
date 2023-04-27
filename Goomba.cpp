#include <SFML/Graphics.hpp>
#include "Map.hpp"
#include "Goomba.hpp"
#include "Jesusario.hpp"
#include <iostream>
#include <string>
using namespace std;

Goomba::Goomba(){
    x = 300;
    y = 638;
    texture1.loadFromFile("Images/goomba1.png");
    sprite.setTexture(texture1);
}

void Goomba :: drawGoomba(sf::RenderWindow& window){
    sprite.setPosition(x,y);
    window.draw(sprite);
}

void Goomba :: walk()
{      
    static string direction = "right";
    int counter = 500;
    if(direction == "right")
    {     
        x += .125;
    }
    else if(direction == "left")
    {
        x -= .125;
    }
    if((int)x <= 200)
    {
        direction = "right";
    }
    if((int)x >= 1300)
    {
        direction = "left";
    }
}
        
void Goomba :: die()
{
    if(jesus.getX() >= goomba.getX() && jesus.getX() <= goomba.getX() + 50)
    {
        if(jesus.getY() == goomba.getY())
        {
            
        }
    }
}