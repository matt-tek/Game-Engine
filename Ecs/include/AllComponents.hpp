/*
** EPITECH PROJECT, 2022
** Game-Engine
** File description:
** AllComponents
*/

#pragma once
#include "Include.hpp"
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

class Sprite {
    public:
        Sprite() = default;
        ~Sprite() = default;
        void setSprite(const std::string &path) {
            _texture.loadFromFile(path);
            _sprite.setTexture(_texture);
        }
        sf::Sprite getSprite(void) const { return _sprite; }
        void draw(sf::RenderWindow *window) {
            window->draw(_sprite);
        }
    private:
        sf::Texture _texture;
        sf::Sprite _sprite;
        bool _isVisible;
};

class Input {
    public:
    void registerInput(sf::Keyboard::Key key, std::function<void()> func)
    {
        _inputs.insert({key, func});
        return;
    }

    void checkInput() {
        for (auto &i : _inputs) {
            if (sf::Keyboard::isKeyPressed(i.first)) {
                i.second();
            }
        }
    }
    private:
        std::unordered_map<sf::Keyboard::Key, std::function<void()>> _inputs;
};
