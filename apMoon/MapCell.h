//
// Created by User on 25.12.2023.
//

#ifndef SOME_FROZEN_EVENTS_MAPCELL_H
#define SOME_FROZEN_EVENTS_MAPCELL_H


#include "SFML/Graphics/Texture.hpp"
#include "Entity.h"

class MapCell {
public:
    MapCell(int index, const char* texture_path, bool dec);
    ~MapCell();

    bool is_decoration();
    int get_index();

    const char *get_tex_path() const;
    const Entity *get_entity();

    sf::Color get_pixel(int x, int y);

private:
    int index;
    bool isDecoration;
    const char* tex_path;
    sf::Image image;
    Entity * entity;

    void set_entity(Entity *entity);
};


#endif //SOME_FROZEN_EVENTS_MAPCELL_H
