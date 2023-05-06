#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Jesusario.hpp"
#include "Map.hpp"
#include "Goomba.hpp"
#include <iostream>
using namespace std;

// const float SCREEN_HEIGHT = 800;
// const float SCREEN_WIDTH = 700;
int main() {
    sf::RenderWindow window(sf::VideoMode(700, 800), "Jesusario");
    Map map;
    Goomba goomba(1410);
    Goomba goomba2(2260);
    Jesusario jesus;
    sf::View myView(sf::Vector2f(300.f, 3000.f), sf::Vector2f(700.f, 800.f));
    sf::SoundBuffer buffer;
    sf::SoundBuffer gameFinishedBuffer;
    sf::Texture logo1;
    sf::Sprite logo;
    logo1.loadFromFile("Images/untitled.png");
    logo.setTexture(logo1);
    logo.setPosition(20,-80);
    buffer.loadFromFile("Sounds/marioSong.flac");
    gameFinishedBuffer.loadFromFile("Sounds/winSound.wav");
    sf::Sound sound, gameFinishedSound;
    sound.setBuffer(buffer);
    gameFinishedSound.setBuffer(gameFinishedBuffer);
    bool songPlayedForDeath = true;
    bool songGoombaDeath = true;
    bool songGoombaDeath2 = true;

    sound.play();
    // sf::Texture texture;
    // texture.loadFromFile("Images/jesus.png");
    // sf::Sprite sprite(texture);
    // sprite.setPosition(300,300);
    while (window.isOpen()){
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)){
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed){
                window.close();
            }
            if (event.type == sf::Event::Resized){
                // update the view to the new size of the window
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Up) && !jesus.die){
                jesus.jumpSound.play();
            }
            if(jesus.gameFinished){
                sound.stop();
                if(!jesus.die)
                {
                    gameFinishedSound.play();
                }
                else
                {
                    jesus.dieSound.play();
                }
            }
        }
        window.clear(sf::Color(100, 149, 237));
        map.drawMap(window);
        window.draw(logo);
        goomba.drawGoomba(window);
        goomba2.drawGoomba(window);
        jesus.drawJesus(window);
        jesus.move();
        jesus.gravity();
        goomba.walk(goomba);
        goomba2.walk2(goomba2);
        myView.setCenter(jesus.getX(),400);
        // window.getDefaultView();
        window.setView(myView); //Allows for camera to follow Jesusario
        map.checkCollision(jesus, map.blocks);
        goomba.checkDeath(jesus, goomba);
        goomba.dead();
        goomba2.checkDeath(jesus, goomba2);
        goomba2.dead();
        jesus.dead(jesus, goomba);
        jesus.dead(jesus, goomba2);
        jesus.bringDown();
        jesus.animation();
        goomba.animation();
        goomba2.animation();
        if(jesus.die && songPlayedForDeath){
            sound.stop();
            jesus.dieSound.play();
            songPlayedForDeath = false;
        }
        if(goomba.die && songGoombaDeath){
            goomba.goombaDeadSound.play();
            songGoombaDeath = false;
        }
        if(goomba2.die && songGoombaDeath2){
            goomba.goombaDeadSound.play();
            songGoombaDeath2 = false;
        }
        // jesus.animation2();
        window.display();
        // window.draw(sprite);
    }
    
    return 0;
}