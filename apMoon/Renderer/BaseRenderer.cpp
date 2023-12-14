//
// Created by destructive_crab on 12/8/23.
//

#include "BaseRenderer.h"
#include "RendererManager.h"
#include "../Inputs/InputService.h"
#include<math.h>

#define PI 3.14159265359

void BaseRenderer::draw(IRendererComponent *drawables[], int drawablesCount, sf::RenderWindow* window) {
    if(!window1)
    {
        window1 = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML not works!!");
    }

    window1->clear();

    double posX = World::get_instance()->get_player_pos().x / CELL_SIZE;
    double posY = World::get_instance()->get_player_pos().y / CELL_SIZE;

    double dirX = cos(World::get_instance()->get_player()->get_rotation() * (PI / 180)), dirY = sin(World::get_instance()->get_player()->get_rotation() * (PI / 180));
    double planeX = 0, planeY = 0.66;

    for (int x = 0; x < MAP_WIDTH; x++)
    {
        double cameraX = 2 * x / double (MAP_WIDTH) - 1;
        double rayDirX = dirX + planeX * cameraX;
        double rayDirY = dirY + planeY * cameraX;

        int mapX = int(posX);
        int mapY = int(posY);

        double sideDistX;
        double sideDistY;

        double deltaDistX = std::abs(1/rayDirX);
        double deltaDistY = std::abs(1/rayDirY);

        double perpWallDist;

        int stepX;
        int stepY;

        int hit = 0;
        int side;

        if(rayDirX < 0)
        {
            stepX = -1;
            sideDistX = (posX - mapX) * deltaDistX;
        }
        else
        {
            stepX = 1;
            sideDistX = (mapX + 1.0 - posX) * deltaDistX;
        }

        if(rayDirY < 0)
        {
            stepY = 1;
            sideDistY = (posY - mapY) * deltaDistY;
        }
        else
        {
            stepY = 1;
            sideDistY = (mapY + 1.0 - posY) * deltaDistY;
        }

        //DDA
        while(hit == 0)
        {
            if (sideDistX < sideDistY)
            {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            }
            else
            {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }

            if (World::get_instance()->get_map()->get(mapX, mapY) == 1) {
                hit = 1;
            }
        }

        if(side == 0)
        {
            perpWallDist = sideDistX - deltaDistX;
        }
        else
        {
            perpWallDist = sideDistY - deltaDistY;
        }

        int lineHeight = (int)(MAP_HEIGHT / perpWallDist);

        int drawStart = -lineHeight / 2 + MAP_HEIGHT / 2;

        if(drawStart < 0) {
            drawStart = 0;
        }

        int drawEnd = lineHeight / 2 + MAP_HEIGHT / 2;

        if(drawEnd >= MAP_HEIGHT)
        {
            drawEnd = MAP_HEIGHT - 1;
        }

        drawLine(x, drawStart, drawEnd, window, World::get_instance()->get_map()->get(mapX, mapY), side);

        for (int i = 0; i < drawablesCount; ++i) {
            window1->draw(*drawables[i]->get_drawable());
        }

        sf::View view;
        view.setCenter(World::get_instance()->get_player_pos());
        window1->setView(view);

        window1->display();
    }
}

void BaseRenderer::drawLine(int x, int y1, int y2, sf::RenderWindow * window, int wallinx, int side) {

    sf::RectangleShape* shape = new sf::RectangleShape;
    shape->setSize(sf::Vector2f(CELL_SIZE, (y2-y1) * CELL_SIZE));
    shape->setPosition(x * CELL_SIZE, y1 * CELL_SIZE);

    switch (wallinx) {
        case 1:
            shape->setFillColor(sf::Color::White);
            break;
        case 2:
            shape->setFillColor(sf::Color::Red);
            break;
        case 3:
            shape->setFillColor(sf::Color::Green);
            break;
        case 4:
            shape->setFillColor(sf::Color::Blue);
            break;
    }

    if(side == 1)
    {
        shape->setFillColor(sf::Color(shape->getFillColor().r / 2, shape->getFillColor().g / 2, shape->getFillColor().b / 2));
    }

    window->draw(*shape);

    delete shape;
}
