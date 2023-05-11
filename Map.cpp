#include <SFML/Graphics.hpp>
#include "Map.hpp"
#include <iostream>
using namespace std;

Map :: Map(){
    texture.loadFromFile("Images/marioMapLarger.png");
    mushroomT.loadFromFile("Images/mushroom.png");
    blockT.loadFromFile("Images/defaultBlock.png");
    blockAnimationT.loadFromFile("Images/blockAnimation.png");
    mushroomS.setTexture(mushroomT);
    sprite.setTexture(texture);
    mushroomAppearsB.loadFromFile("Sounds/smb_powerup_appears.wav");
    mushroomAppearsS.setBuffer(mushroomAppearsB);
    //blocks setting size
    b1.setSize(sf::Vector2f(60,60));
    b2.setSize(sf::Vector2f(235,60));
    b3.setSize(sf::Vector2f(60,60));
    b4.setSize(sf::Vector2f(141,60));
    b5.setSize(sf::Vector2f(390,60));
    b6.setSize(sf::Vector2f(190,60));
    b7.setSize(sf::Vector2f(60,60));
    b8.setSize(sf::Vector2f(60,60));
    b9.setSize(sf::Vector2f(60,60));
    b10.setSize(sf::Vector2f(60,60));
    b11.setSize(sf::Vector2f(60,60));
    b12.setSize(sf::Vector2f(60,60));
    b13.setSize(sf::Vector2f(60,60));
    b14.setSize(sf::Vector2f(160,60));
    b15.setSize(sf::Vector2f(190,60));
    b16.setSize(sf::Vector2f(120,60));
    b17.setSize(sf::Vector2f(200,60));
    b18.setSize(sf::Vector2f(60,120));
    b19.setSize(sf::Vector2f(60,120));
    b20.setSize(sf::Vector2f(60,120));
    b21.setSize(sf::Vector2f(60,120));

 
    

    
    //pipes setting size
    p1.setSize(sf::Vector2f(100,120));
    p2.setSize(sf::Vector2f(100,180));
    p3.setSize(sf::Vector2f(100,230));
    p4.setSize(sf::Vector2f(100,230));
    p5.setSize(sf::Vector2f(90,120));
    p6.setSize(sf::Vector2f(90,120));

    //stairs setting size
    s1.setSize(sf::Vector2f(50,50));
    s2.setSize(sf::Vector2f(50,50));
    s3.setSize(sf::Vector2f(50,50));
    s4.setSize(sf::Vector2f(45,210));
    s5.setSize(sf::Vector2f(45,210));
    s6.setSize(sf::Vector2f(50,50));
    s7.setSize(sf::Vector2f(50,50));
    s8.setSize(sf::Vector2f(50,50));
    s9.setSize(sf::Vector2f(50,50));
    s10.setSize(sf::Vector2f(50,50));
    s11.setSize(sf::Vector2f(50,50));
    s12.setSize(sf::Vector2f(90,50)); 
    s13.setSize(sf::Vector2f(45,420));
    s14.setSize(sf::Vector2f(45,420));
    s15.setSize(sf::Vector2f(45,45));
    s16.setSize(sf::Vector2f(45,45));
    s17.setSize(sf::Vector2f(45,45));
    s18.setSize(sf::Vector2f(45,45));
    s19.setSize(sf::Vector2f(45,45));
    s20.setSize(sf::Vector2f(45,45));
    s21.setSize(sf::Vector2f(45,45));
    s22.setSize(sf::Vector2f(45,45));
    s23.setSize(sf::Vector2f(45,45));
    s24.setSize(sf::Vector2f(45,45));
    s25.setSize(sf::Vector2f(45,45));
    s26.setSize(sf::Vector2f(45,840));


    sprite.setPosition(0,0);

    //blocks setting position
    mushroomS.setPosition(756, 459);
    blockS.setPosition(756, 459);
    b1.setPosition(750, 455);
    b2.setPosition(945, 455);
    b3.setPosition(1039, 229);
    b4.setPosition(3634, 455);
    b5.setPosition(3775, 229);
    b6.setPosition(4294, 229);
    b7.setPosition(4435, 455);
    b8.setPosition(4710, 455);
    b9.setPosition(5000, 455);
    b10.setPosition(5140, 455);
    b11.setPosition(5140, 229);
    b12.setPosition(5280,455);
    b13.setPosition(5555,455);
    b14.setPosition(5695,229);
    b15.setPosition(6038,229);
    b16.setPosition(6070,455);
    b17.setPosition(7920,455);
    b18.setPosition(3195,687);
    b19.setPosition(3351,687);
    b20.setPosition(3996,687);
    b21.setPosition(4199,687);


    //pipes setting position
    p1.setPosition(1323, 573);
    p2.setPosition(1793, 515);
    p3.setPosition(2170, 458);
    p4.setPosition(2685, 458);
    p4.setPosition(2685, 458);
    p5.setPosition(7692, 573);
    p6.setPosition(8447, 573);
    //stairs setting position
    s1.setPosition(6323, 630);
    s2.setPosition(6370, 572);
    s3.setPosition(6417, 514);
    s4.setPosition(6464, 459);
    s5.setPosition(6607, 459);
    s6.setPosition(6650, 514);
    s7.setPosition(6695, 572);
    s8.setPosition(6742, 630);
    s9.setPosition(6985, 630);
    s10.setPosition(7030, 572);
    s11.setPosition(7078, 514);
    s12.setPosition(7126, 459);
    s13.setPosition(7171, 520);
    s14.setPosition(7313, 459);
    s15.setPosition(7360, 514);
    s16.setPosition(7408, 572);
    s17.setPosition(7454, 630);
    s18.setPosition(8540, 630);
    s19.setPosition(8585, 572);
    s20.setPosition(8633, 514);
    s21.setPosition(8680, 459);
    s22.setPosition(8728, 401);
    s23.setPosition(8776, 343);
    s24.setPosition(8824, 285);
    s25.setPosition(8872, 227);
    s26.setPosition(8920, 227);
}
void Map :: drawMap(sf::RenderWindow& window){
    // r1.setFillColor(sf::Color(255,0,0));
    //blocks
    window.draw(b1);
    window.draw(b2);
    window.draw(b3);
    window.draw(b4);
    window.draw(b5);
    window.draw(b6);
    window.draw(b7);
    window.draw(b8);
    window.draw(b9);
    window.draw(b10);
    window.draw(b11);
    window.draw(b12);
    window.draw(b13);
    window.draw(b14);
    window.draw(b15);   
    window.draw(b16);   
    window.draw(b17);   
    window.draw(b18);   
    window.draw(b19);   
    window.draw(b20);   
    window.draw(b21);   

    //pipes
    window.draw(p1);
    // window.draw(p2);
    window.draw(p3);
    window.draw(p4);
    window.draw(p5);
    window.draw(p6);

    //stairs
    window.draw(s1);
    window.draw(s2);
    window.draw(s3);
    window.draw(s4);
    window.draw(s5);
    window.draw(s6);
    window.draw(s7);
    window.draw(s8);
    window.draw(s9);
    window.draw(s10);
    window.draw(s11);
    window.draw(s12);
    window.draw(s13);
    window.draw(s14);
    window.draw(s15);
    window.draw(s16);
    window.draw(s17);
    window.draw(s18);
    window.draw(s19);
    window.draw(s20);
    window.draw(s21);
    window.draw(s22);
    window.draw(s23);
    window.draw(s24);
    window.draw(s25);
    window.draw(s26);
    window.draw(sprite);
    if(!deleteMushroom){
        window.draw(mushroomS);
    } else {
        mushroomS.setPosition(1,999);
    }
    window.draw(blockS);
} 
void Map :: checkCollision(Jesusario& jesus, sf::RectangleShape blocks[]){
    this->blocks[0] = b1;
    this->blocks[1] = b2;
    this->blocks[2] = b3;
    this->blocks[3] = b4;
    this->blocks[4] = b5;
    this->blocks[5] = b6;
    this->blocks[6] = b7;
    this->blocks[7] = b8;
    this->blocks[8] = b9;
    this->blocks[9] = b10;
    this->blocks[10] = b11;
    this->blocks[11] = b12;
    this->blocks[12] = b13;
    this->blocks[13] = b14;
    this->blocks[14] = b15;
    this->blocks[15] = b16;
    this->blocks[16] = b17;
    this->blocks[17] = p1;
    this->blocks[18] = p2;
    this->blocks[19] = p3;
    this->blocks[20] = p4;
    this->blocks[21] = p5;
    this->blocks[22] = p6;
    this->blocks[23] = s1;
    this->blocks[24] = s2;
    this->blocks[25] = s3;
    this->blocks[26] = s4;
    this->blocks[27] = s5;
    this->blocks[28] = s6;
    this->blocks[29] = s7;
    this->blocks[30] = s8;
    this->blocks[31] = s9;
    this->blocks[32] = s10;
    this->blocks[33] = s11;
    this->blocks[34] = s12;
    this->blocks[35] = s13;
    this->blocks[36] = s14;
    this->blocks[37] = s15;
    this->blocks[38] = s16;
    this->blocks[39] = s17;
    this->blocks[40] = s18;
    this->blocks[41] = s19;
    this->blocks[42] = s20;
    this->blocks[43] = s21;
    this->blocks[44] = s22;
    this->blocks[45] = s23;
    this->blocks[46] = s24;
    this->blocks[47] = s25;
    this->blocks[48] = s26;
    this->blocks[49] = b18;
    this->blocks[50] = b19;
    this->blocks[51] = b20;
    this->blocks[52] = b21;
    
    jesus.onBlock = false;
    for(int i = 0; i < 53; i++){
        sf::FloatRect bounds = blocks[i].getGlobalBounds();
        int h = bounds.height;
        int w = bounds.width;
        // cout << blocks[i].getPosition().x << endl;
        //left side
        // cout << (shape.getPosition().x) << endl;
        if(jesus.smallJesus){
            if((int)jesus.getY() <= blocks[i].getPosition().y+h && (int)jesus.getY()+47 >= blocks[i].getPosition().y && (int)jesus.getX()+45 == blocks[i].getPosition().x){
                jesus.x = blocks[i].getPosition().x-45;
            } 
            if((int)jesus.getY() == blocks[i].getPosition().y+h && ((int)jesus.getX()+45 >= blocks[i].getPosition().x && (int)jesus.getX() <= blocks[i].getPosition().x+w)){
                jesus.y += 1;
                jesus.collision = true;
                if(i == 0){
                    hit = true;
                }
            //bottom
            // if((int)jesus.getY() >= shape.getPosition().y && (int)jesus.getY() <= shape.getPosition().y+h && (int)jesus.getX()+45 >= shape.getPosition().x){
            //     jesus.x = shape.getPosition().x-40;
            // }
            }
            if((int)jesus.getY() <= blocks[i].getPosition().y+h && (int)jesus.getY()+48 >= blocks[i].getPosition().y && (int)jesus.getX() == blocks[i].getPosition().x+w){
                jesus.x = blocks[i].getPosition().x+w+1;
                /*blocks[i].getPosition().x+62*/;
            //right
            }
            if(((int)jesus.getX()+44 >= blocks[i].getPosition().x) && ((int)jesus.getX() <= blocks[i].getPosition().x+w) && ((int)jesus.getY()+48 == blocks[i].getPosition().y)){
                jesus.onBlock = true;
                    //blocks[i].getPosition().y-45
                // jesus.y = blocks[i].getPosition().y-48;
            //top
            }
            // if(((int)jesus.getX()+45 < blocks[i].getPosition().x) || ((int)jesus.getX() > blocks[i].getPosition().x+w)){
            //     jesus.onBlock = false;
            //     cout << "ko" << endl;
        } else if(jesus.bigJesus){
            if((int)jesus.getY() <= blocks[i].getPosition().y+h && (int)jesus.getY()+95 >= blocks[i].getPosition().y && (int)jesus.getX()+60 == blocks[i].getPosition().x){
                jesus.x = blocks[i].getPosition().x-60;
            } 
            if((int)jesus.getY() == blocks[i].getPosition().y+h && ((int)jesus.getX()+60 >= blocks[i].getPosition().x && (int)jesus.getX() <= blocks[i].getPosition().x+w)){
                jesus.y += 1;
                jesus.collision = true;
            //bottom
            // if((int)jesus.getY() >= shape.getPosition().y && (int)jesus.getY() <= shape.getPosition().y+h && (int)jesus.getX()+45 >= shape.getPosition().x){
            //     jesus.x = shape.getPosition().x-40;
            // }
            }
            if((int)jesus.getY() <= blocks[i].getPosition().y+h && (int)jesus.getY()+96 >= blocks[i].getPosition().y && (int)jesus.getX() == blocks[i].getPosition().x+w){
                jesus.x = blocks[i].getPosition().x+w+1;
                /*blocks[i].getPosition().x+62*/;
            //right
            }
            if(jesus.bigJesus && ((int)jesus.getX()+59 >= blocks[i].getPosition().x) && ((int)jesus.getX() <= blocks[i].getPosition().x+w) && ((int)jesus.getY()+96 == blocks[i].getPosition().y)){
                jesus.onBlock = true;
            }
        }
    } 
    
}
void Map :: animation(Jesusario& jesus){
    if(hit && counter != 50){
        mushroomS.setPosition(x,y-=.1);
        counter++;
        mushroomAppears = true;
    } 
    if(!hit){
        blockS.setTexture(blockAnimationT);
        int xTexture = 48;
        blockS.setTextureRect(sf::IntRect(xTexture*counter2, 0, 48, 54));
        counter3++;
        if(counter3 == 1000){
            counter2++;
            if(counter2 >= 3){
                counter2 = 0;
            }
            counter3 = 0;
        }
    }
    if(hit){
        blockS.setTexture(blockT);
        blockS.setTextureRect(sf::IntRect(0, 0, 48, 54));
    }
}
void Map :: mushroom(Jesusario& jesus){
    if((int)jesus.getY() <= mushroomS.getPosition().y+48 && (int)jesus.getY()+48 >= mushroomS.getPosition().y && (int)jesus.getX()+45 == mushroomS.getPosition().x && jesus.smallJesus){
        jesus.bigJesus = true;
        jesus.smallJesus = false;
        deleteMushroom = true;
        jesus.gotMushroom = true;
    } 
    if((int)jesus.getY() <= mushroomS.getPosition().y+48 && (int)jesus.getY()+96 >= mushroomS.getPosition().y && (int)jesus.getX() == mushroomS.getPosition().x+48){
        jesus.bigJesus = true;
        jesus.smallJesus = false;
        deleteMushroom = true;
        jesus.gotMushroom = true;
    }
}