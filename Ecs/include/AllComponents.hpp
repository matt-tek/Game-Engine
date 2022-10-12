/*
** EPITECH PROJECT, 2022
** Game-Engine
** File description:
** AllComponents
*/

#pragma once
#include "Game.hpp"

class Transform {
    public:
    Transform() = default;
    void move(float off_x, float off_y) {
        _pos.x += off_x;
        _pos.y += off_y;
    }
    sf::Vector2f getPos(void) const
    {
        return _pos;
    }

    float getRotation(void) const
    {
        return _rotate;
    }
    private:
    sf::Vector2f _pos = {0.0f, 0.0f};
    float _rotate = 0.0f;
};

class Gravity {
    public:
    Gravity *getComponent(void)
    {
        return this;
    }
    sf::Vector2f _pos = {0.0f, 0.0f};
    float _rotate = 0.0f;
};