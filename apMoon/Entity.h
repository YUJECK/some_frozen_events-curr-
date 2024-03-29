//
// Created by destructive_crab on 12/6/23.
//

#ifndef SOME_FROZEN_EVENTS_ENTITY_H
#define SOME_FROZEN_EVENTS_ENTITY_H

#include<vector>
#include "Component.h"
#include "Transform.h"

class Component;

class Entity {
public:
    std::string name;

private:
    std::vector<Component *> components;
    Transform* transform;

public:
    Entity();
    virtual ~Entity();

    virtual void start_entity() = 0;

    virtual void update_entity() = 0;

    virtual void destroy_entity() = 0;

    sf::Vector2<float> get_position();

    void set_position(sf::Vector2<float> position);

    bool move_position(sf::Vector2<float> position, float speed);

    float get_rotation();

    void set_rotation(float rotation);

    void add_component(Component* component);

    void update_all_components();

    template<class TComponent>
    bool has_component(TComponent &out)
    {
        int index = get_component_index<TComponent>();

        if(index < components.size())
        {
            out = (TComponent)components[index];
            return true;
        }

        return false;
    }

    template<class TComponent>
    bool has_component()
    {
        return get_component_index<TComponent>() == components.size();
    }

    template<class TComponent>
    int get_component_index()
    {
        for(int i = 0; i < components.size(); i++)
        {
            if(dynamic_cast<TComponent>(components[i]))
                return i;
        }

        return components.size();
    }

    template<class TComponent>
    TComponent* get_component()
    {
        TComponent * component = dynamic_cast<TComponent *>(components[get_component_index<TComponent>()]);

        return component;
    }

    template<class TComponent>
    void remove_component()
    {
        Component* component = nullptr;

        if(has_component<TComponent>(component))
            delete component;
    }

    void set_position(float x, float y);

    void rotate(float rotation);
};

#endif //SOME_FROZEN_EVENTS_ENTITY_H
