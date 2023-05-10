#ifndef MAP_HPP
#define MAP_HPP
#include <SFML/Graphics.hpp>
#include "Jesusario.hpp"

class Map {
public:
    Map();
    void drawMap(sf::RenderWindow& window);
    void checkCollision(Jesusario& jesus, sf::RectangleShape blocks[]);
    void animation(Jesusario& jesus);
    void mushroom(Jesusario& jesus);
// private:
    bool hit = false, deleteMushroom = false, mushroomAppears = false;
    sf::Sprite sprite, mushroomS, blockS;
    sf::Texture texture, mushroomT, blockT, blockAnimationT;
    sf::SoundBuffer mushroomAppearsB;
    sf::Sound mushroomAppearsS;
    int counter = 0, x = 756, y = 460, counter2 = 0, counter3 = 0; 
    sf::RectangleShape b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21;
    sf::RectangleShape p1, p2, p3, p4, p5, p6;
    sf::RectangleShape s1, s2, s3, s4, s5, s6, s7 ,s8, s9, s10, s11, s12, s13, s14, s15, s16, s17, s18, s19, s20, s21, s22, s23, s24, s25, s26;
    sf::RectangleShape blocks[53] = {b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16, b17, b18, b19, b20, b21, p1, p2, p3, p4, p5, p6,
                                     s1, s2, s3, s4, s5, s6, s7 ,s8, s9, s10, s11, s12, s13, s14, s15, s16, s17, s18, s19, s20, s21, s22, s23, s24, s25, s26};
};


#endif