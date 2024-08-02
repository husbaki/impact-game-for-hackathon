#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>

using namespace sf;
using namespace std;

Image image, image_floor, image_wall, image_wall_top,image_door_anim,c_image,e_image;
Texture texture, texture_floor, texture_wall, texture_wall_top, texture_door_anim,c_texture, e_texture;
Sprite sprite,sprite_floor, sprite_wall;
Event event;
vector <Sprite> sprite_wall_top(9);
vector <Sprite> sprite_door_anim(5);
vector <Sprite> c_sprite(6);
vector <Sprite> e_sprite(6);
float CurrentFrame=0;
int speed=5;
int n,room=1,sprite_diraction,directionx, directiony;

void draw()
{
    RenderWindow window(VideoMode(900, 600), "RPhMS parallel version");
    window.setFramerateLimit(60);
    Clock clock;
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            FloatRect sprite_bounds = sprite.getGlobalBounds();
            vector <FloatRect> sprite_wall_top_bounds = { 
                sprite_wall_top.at(0).getGlobalBounds(),
                sprite_wall_top.at(1).getGlobalBounds(),
                sprite_wall_top.at(2).getGlobalBounds(),
                sprite_wall_top.at(3).getGlobalBounds(),
            };

            vector <FloatRect> sprite_door_anim_bounds = {
                sprite_door_anim.at(0).getGlobalBounds(),
                sprite_door_anim.at(1).getGlobalBounds(),
                sprite_door_anim.at(2).getGlobalBounds(),
                sprite_door_anim.at(3).getGlobalBounds(),
            };
            
            vector <FloatRect> sprite_c_bounds = {
                sprite_wall_top.at(4).getGlobalBounds(),
                sprite_wall_top.at(5).getGlobalBounds(),
                sprite_wall_top.at(6).getGlobalBounds(),
                sprite_wall_top.at(7).getGlobalBounds(),
                sprite_wall_top.at(8).getGlobalBounds(),
            };

            vector <int> last_direction(2);
            last_direction.at(0) = directionx;
            last_direction.at(1) = directiony;
            if (sprite_bounds.intersects(sprite_c_bounds.at(1)) && room==2)
            {
                room = 1;
                sprite.setPosition(450, 205);
            }
            if (sprite_bounds.intersects(sprite_door_anim_bounds.at(0)) && room==1)
            {
                room = 2;
                sprite.setPosition(490, 296);
            }
            if (sprite_bounds.intersects(sprite_wall_top_bounds.at(1)) && room == 2)
            {
                room = 3;
                sprite.setPosition(490, 296);
            }
            if (sprite_bounds.intersects(sprite_wall_top_bounds.at(3)) && room == 3)
            {
                room = 2;
                sprite.setPosition(330, 196);
            }
            if (sprite_bounds.intersects(sprite_wall_top_bounds.at(0)))
            {
                sprite.move(last_direction.at(0), last_direction.at(1));
            }
            if (sprite_bounds.intersects(sprite_wall_top_bounds.at(1)))
            {
                sprite.move(last_direction.at(0), last_direction.at(1));
            }
            if (sprite_bounds.intersects(sprite_wall_top_bounds.at(2)))
            {
                sprite.move(last_direction.at(0), last_direction.at(1));
            }
            if (sprite_bounds.intersects(sprite_wall_top_bounds.at(3)))
            {
                sprite.move(last_direction.at(0), last_direction.at(1));
            }
            if (sprite_bounds.intersects(sprite_c_bounds.at(0)))
            {
                sprite.move(last_direction.at(0), last_direction.at(1));
            }
            if (sprite_bounds.intersects(sprite_c_bounds.at(1)))
            {
                sprite.move(last_direction.at(0), last_direction.at(1));
            }
            if (sprite_bounds.intersects(sprite_c_bounds.at(2)))
            {
                sprite.move(last_direction.at(0), last_direction.at(1));
            }
            if (sprite_bounds.intersects(sprite_c_bounds.at(3)))
            {
                sprite.move(last_direction.at(0), last_direction.at(1));
            }
            if (sprite_bounds.intersects(sprite_c_bounds.at(4)))
            {
                sprite.move(last_direction.at(0), last_direction.at(1));
            }
            directiony = 0;
            directionx = 0;
            

            
            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::D)
                {
                    sprite_diraction = 0;
                    CurrentFrame += time*0.1;
                    if (CurrentFrame >= 4) 
                        CurrentFrame =0;
                    sprite.setTextureRect(IntRect(int(CurrentFrame) * 64, 192, 60, 91));
                    sprite.move(speed, 0);
                    n = 0;
                    directionx-=5;
                }
                else if (event.key.code == Keyboard::A)
                {
                    sprite_diraction = 1;
                    CurrentFrame += time*0.1;
                    if (CurrentFrame >= 4) 
                        CurrentFrame = 0;
                    sprite.setTextureRect(IntRect(int(CurrentFrame) * 64, 96, 60, 91));
                    sprite.move(-speed, 0);
                    n = 1;
                    directionx+=5;
                }
                else if (event.key.code == Keyboard::S)
                {
                    sprite_diraction = 2;
                    CurrentFrame += time*0.1;
                    if (CurrentFrame >= 4) 
                        CurrentFrame = 0;
                    sprite.setTextureRect(IntRect(int(CurrentFrame) * 64, 0, 60, 91));
                    sprite.move(0, speed);
                    n = 2;
                    directiony-=5;
                }
                else if (event.key.code == Keyboard::W)
                {
                    sprite_diraction = 3;
                    CurrentFrame += time*0.1;
                    if (CurrentFrame >= 4) 
                        CurrentFrame = 0;
                    sprite.setTextureRect(IntRect(int(CurrentFrame) * 64, 288, 60, 91));
                    sprite.move(0, -speed);
                    n = 3;
                    directiony+=5;
                }
            }
            if (room == 1)
            {
                window.clear();
                for (int i=1;i<=7;i++)
                {
                    for (int j = 1; j <= 7;j++)
                    {
                        sprite_floor.setTextureRect(IntRect(144,48, 48, 48));
                        sprite_floor.setPosition(j*48+250, i*48+150);
                        window.draw(sprite_floor);
                    }
                }


                sprite_wall.setTextureRect(IntRect(480, 0, 48, 97));
                sprite_wall.setPosition(298, 101);
                sprite_wall.setColor(Color(255, 255, 255, 255));
                sprite_wall.setScale(7, 1);
                window.draw(sprite_wall);

                sprite_wall_top.at(0).setTextureRect(IntRect(11, 0, 40, 45));
                sprite_wall_top.at(0).setPosition(297, 94);
                sprite_wall_top.at(0).setScale(8.44f, 1);
                window.draw(sprite_wall_top.at(0));

                sprite_wall_top.at(1).setTextureRect(IntRect(70, 10, 10, 40));
                sprite_wall_top.at(1).setPosition(288, 94);
                sprite_wall_top.at(1).setScale(1, 11.25f);
                window.draw(sprite_wall_top.at(1));

                sprite_wall_top.at(2).setTextureRect(IntRect(11, 0, 40, 11));
                sprite_wall_top.at(2).setPosition(297, 534);
                sprite_wall_top.at(2).setScale(8.44f, 1);
                window.draw(sprite_wall_top.at(2));

                sprite_wall_top.at(3).setTextureRect(IntRect(70, 10, 10, 40));
                sprite_wall_top.at(3).setPosition(630, 94);
                sprite_wall_top.at(3).setScale(1, 11.25f);
                window.draw(sprite_wall_top.at(3));

                sprite_wall_top.at(4).setTextureRect(IntRect(11, 0, 40, 45));
                sprite_wall_top.at(4).setPosition(410, 360);
                sprite_wall_top.at(4).setScale(1, 1);
                window.draw(sprite_wall_top.at(4));

                sprite_wall_top.at(5).setTextureRect(IntRect(11, 0, 40, 45));
                sprite_wall_top.at(5).setPosition(520, 360);
                //sprite_wall_top.at(2).setScale(8.44f, 1);
                //window.draw(sprite_wall_top.at(5));

                sprite_wall_top.at(6).setTextureRect(IntRect(11, 0, 40, 45));
                sprite_wall_top.at(6).setPosition(400, 200);
                //sprite_wall_top.at(2).setScale(8.44f, 1);
                //window.draw(sprite_wall_top.at(6));

                sprite_wall_top.at(7).setTextureRect(IntRect(11, 0, 40, 45));
                sprite_wall_top.at(7).setPosition(520, 200);
                //sprite_wall_top.at(2).setScale(8.44f, 1);
                //window.draw(sprite_wall_top.at(7));

                sprite_wall_top.at(8).setTextureRect(IntRect(11, 0, 40, 45));
                sprite_wall_top.at(8).setPosition(350, 430);
                //sprite_wall_top.at(2).setScale(8.44f, 1);
                //window.draw(sprite_wall_top.at(8));

                sprite_door_anim.at(0).setTextureRect(IntRect(0, 0, 48, 95));
                sprite_door_anim.at(0).setPosition(457, 102);
                window.draw(sprite_door_anim.at(0));

                c_sprite.at(0).setTextureRect(IntRect(150, 510, 48, 80));
                c_sprite.at(0).setPosition(400, 300);
                c_sprite.at(0).setScale(1.5, 2);
                window.draw(c_sprite.at(0));

                c_sprite.at(1).setTextureRect(IntRect(150, 510, 48, 80));
                c_sprite.at(1).setPosition(520, 300);
                c_sprite.at(1).setScale(1.5, 2);
                window.draw(c_sprite.at(1));

                c_sprite.at(2).setTextureRect(IntRect(150, 510, 48, 80));
                c_sprite.at(2).setPosition(400, 160);
                c_sprite.at(2).setScale(1.5, 2);
                window.draw(c_sprite.at(2));

                c_sprite.at(3).setTextureRect(IntRect(150, 510, 48, 80));
                c_sprite.at(3).setPosition(520, 160);
                c_sprite.at(3).setScale(1.5, 2);
                window.draw(c_sprite.at(3));

                c_sprite.at(4).setTextureRect(IntRect(150, 510, 48, 80));
                c_sprite.at(4).setPosition(340, 370);
                c_sprite.at(4).setScale(1.5, 2);
                window.draw(c_sprite.at(4));

                window.draw(sprite);

                c_sprite.at(5).setTextureRect(IntRect(140, 200, 140, 100));
                c_sprite.at(5).setPosition(300, 120);
                c_sprite.at(5).setScale(1.1, 0.3);
                window.draw(c_sprite.at(5));


                window.display();
            }
            if (room == 2)
            {
                window.clear();
                
                for (int i = 1; i <= 4; i++)
                {
                    for (int j = 1; j <= 8; j++)
                    {
                        sprite_floor.setTextureRect(IntRect(336, 48, 48, 48));
                        sprite_floor.setPosition(j * 48 + 250, i * 48 + 150);
                        window.draw(sprite_floor);
                    }
                }

                sprite_wall.setTextureRect(IntRect(480, 0, 48, 97));
                sprite_wall.setPosition(298, 101);
                sprite_wall.setColor(Color(255, 255, 255, 255));
                sprite_wall.setScale(8, 1);
                window.draw(sprite_wall);

                sprite_door_anim.at(0).setTextureRect(IntRect(0, 0, 48, 95));
                sprite_door_anim.at(0).setPosition(457, 102);
                window.draw(sprite_door_anim.at(0));

                window.draw(sprite);

                sprite_wall_top.at(0).setTextureRect(IntRect(11, 0, 40, 45));
                sprite_wall_top.at(0).setPosition(297, 94);
                sprite_wall_top.at(0).setScale(9.65, 1);
                window.draw(sprite_wall_top.at(0));

                sprite_wall_top.at(1).setTextureRect(IntRect(11, 0, 40, 45));
                sprite_wall_top.at(1).setPosition(260, 94);

                sprite_wall_top.at(2).setTextureRect(IntRect(11, 0, 40, 11));
                sprite_wall_top.at(2).setPosition(298, 390);
                sprite_wall_top.at(2).setScale(4.75, 1);
                window.draw(sprite_wall_top.at(2));

                sprite_wall_top.at(3).setPosition(680, 94);

                sprite_wall_top.at(4).setTextureRect(IntRect(11, 0, 40, 45));
                sprite_wall_top.at(4).setPosition(563, 390);
                sprite_wall_top.at(4).setScale(3, 1);
                window.draw(sprite_wall_top.at(4));

                sprite_wall_top.at(5).setTextureRect(IntRect(11, 0, 40, 45));
                sprite_wall_top.at(5).setPosition(500, 390);
                window.draw(sprite_wall_top.at(5));

                sprite_wall_top.at(6).setTextureRect(IntRect(11, 0, 40, 45));
                sprite_wall_top.at(6).setPosition(1000, 200);
                //sprite_wall_top.at(2).setScale(8.44f, 1);
                window.draw(sprite_wall_top.at(6));

                sprite_wall_top.at(7).setTextureRect(IntRect(11, 0, 40, 45));
                sprite_wall_top.at(7).setPosition(1020, 200);
                //sprite_wall_top.at(2).setScale(8.44f, 1);
                window.draw(sprite_wall_top.at(7));

                sprite_wall_top.at(8).setTextureRect(IntRect(11, 0, 40, 45));
                sprite_wall_top.at(8).setPosition(1000, 200);
                //sprite_wall_top.at(2).setScale(8.44f, 1);

                window.display();
            }
            if (room == 3)
            {
                window.clear();

                for (int i = 1; i <= 5; i++)
                {
                    for (int j = 1; j <= 6; j++)
                    {
                        sprite_floor.setTextureRect(IntRect(336, 48, 48, 48));
                        sprite_floor.setPosition(j * 48 + 250, i * 48 + 150);
                        window.draw(sprite_floor);
                    }
                }

                sprite_wall.setTextureRect(IntRect(480, 0, 48, 97));
                sprite_wall.setPosition(298, 101);
                sprite_wall.setColor(Color(255, 255, 255, 255));
                sprite_wall.setScale(6.1, 1);
                window.draw(sprite_wall);

                sprite_wall_top.at(0).setTextureRect(IntRect(11, 0, 40, 45));
                sprite_wall_top.at(0).setPosition(297, 94);
                sprite_wall_top.at(0).setScale(7.4f, 1);
                window.draw(sprite_wall_top.at(0));

                sprite_wall_top.at(1).setTextureRect(IntRect(70, 10, 10, 40));
                sprite_wall_top.at(1).setPosition(288, 94);
                sprite_wall_top.at(1).setScale(1, 8.75f);
                window.draw(sprite_wall_top.at(1));

                sprite_wall_top.at(2).setTextureRect(IntRect(11, 0, 40, 11));
                sprite_wall_top.at(2).setPosition(390, 434);
                sprite_wall_top.at(2).setScale(5.1, 1);
                window.draw(sprite_wall_top.at(2));

                sprite_wall_top.at(3).setTextureRect(IntRect(70, 10, 10, 40));
                sprite_wall_top.at(3).setPosition(585, 94);
                sprite_wall_top.at(3).setScale(1, 8.75f);

                //e_sprite.at(0).setTextureRect(IntRect(150, 200, 30, 230));
                //e_sprite.at(0).setPosition(585, 94);
                //window.draw(e_sprite.at(0));

                sprite_wall_top.at(4).setPosition(10000, 390);

                sprite_wall_top.at(5).setPosition(11500, 390);

                window.draw(sprite);

                window.display();
            }
        }
    }
}

int main()
{
    Texture texture;
    if (!texture.loadFromFile("sprites/player_sheet.png")) {
        return EXIT_FAILURE;
    }
    image.loadFromFile("sprites/player_sheet.png");
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    sprite.setTextureRect(IntRect(0, 192, 64, 96));
    sprite.setPosition(300,300);

    image_floor.loadFromFile("sprites/floor.png");
    texture_floor.loadFromImage(image_floor);
    sprite_floor.setTexture(texture_floor);

    image_wall.loadFromFile("sprites/wall.png");
    texture_wall.loadFromImage(image_wall);
    sprite_wall.setTexture(texture_wall);

    image_wall_top.loadFromFile("sprites/wall_top.png");
    texture_wall_top.loadFromImage(image_wall_top);
    sprite_wall_top.at(0).setTexture(texture_wall_top);
    sprite_wall_top.at(1).setTexture(texture_wall_top);
    sprite_wall_top.at(2).setTexture(texture_wall_top);
    sprite_wall_top.at(3).setTexture(texture_wall_top);
    sprite_wall_top.at(4).setTexture(texture_wall_top);

    image_door_anim.loadFromFile("sprites/door_anim.png");
    texture_door_anim.loadFromImage(image_door_anim);
    sprite_door_anim.at(0).setTexture(texture_door_anim);

    c_image.loadFromFile("sprites/inside_C.png");
    c_texture.loadFromImage(c_image);
    c_sprite.at(0).setTexture(c_texture);
    c_sprite.at(1).setTexture(c_texture);
    c_sprite.at(2).setTexture(c_texture);
    c_sprite.at(3).setTexture(c_texture);
    c_sprite.at(4).setTexture(c_texture);
    c_sprite.at(5).setTexture(c_texture);   

    e_image.loadFromFile("sprites/inside_E.png");
    e_texture.loadFromImage(e_image);
    e_sprite.at(0).setTexture(e_texture);
    e_sprite.at(1).setTexture(e_texture);
    e_sprite.at(2).setTexture(e_texture);
    e_sprite.at(3).setTexture(e_texture);
    e_sprite.at(4).setTexture(e_texture);
    e_sprite.at(5).setTexture(e_texture);

    draw();
	return 0;
}