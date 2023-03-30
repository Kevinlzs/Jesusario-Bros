#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Jesusario.hpp"
#include "Map.hpp"
#include <iostream>
using namespace std;

// const float SCREEN_HEIGHT = 800;
// const float SCREEN_WIDTH = 700;
int main()
{
    sf::RenderWindow window(sf::VideoMode(700, 800), "Jesusario");
    Map map;
    Jesusario jesus;
    sf::View myView;
    sf::SoundBuffer buffer;
    buffer.loadFromFile("Sounds/marioSong.flac");
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.play();
    // sf::Texture texture;
    // texture.loadFromFile("Images/jesus.png");
    // sf::Sprite sprite(texture);
    // sprite.setPosition(300,300);
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed){
                window.close();
            }
            if (event.type == sf::Event::Resized){
                // update the view to the new size of the window
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }
        }
        window.clear(sf::Color(100, 149, 237));
        map.drawMap(window);
        jesus.drawJesus(window);
        jesus.move();
        myView.setCenter(jesus.getX(),300);
        // window.getDefaultView();
        window.setView(myView); //Allows for camera to follow Jesusario
        jesus.animation();
        // jesus.animation2();
        window.display();
        // window.draw(sprite);
    }
    return 0;
}