/*
** EPITECH PROJECT, 2022
** Game-ECS
** File description:
** Gsprite
*/

#pragma once
#include <SFML/Window.hpp>
#include "GError.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <vector>
#include <string>

class Gsprite : public sf::Sprite {
    public:
        Gsprite(const std::string &texturePath, const std::string &name) {
            _name = name;
            _texturePath = texturePath;
            if (!_texture->loadFromFile(_texturePath))
                throw SpriteError("Error: spritesheet not found");
            sf::Sprite::setTexture(*_texture);
        };
        ~Gsprite() {
            delete _texture;
        };
        /**
         * @brief getters
         * 
         */
        std::string getName() const { return _name; };
        std::string getTexturePath() const { return _texturePath; };
        int getId() const { return _id; };
        /**
         * @brief setters
         * 
         */
        void setName(const std::string &name) { _name = name; };
        void setTexturePath(const std::string &texturePath) { _texturePath = texturePath; };
        void setId(const int &id) { _id = id; };
    protected:
    private:
        int _id;
        std::string _name;
        std::string _texturePath;
        sf::Texture *_texture;

};


#pragma once

// #include "Engine.hpp"
// #include <SFML/Graphics/Sprite.hpp>
// #include <string>

// class Sprite : public sf::Sprite
// {
//   private:
//     sf::Texture& _texture;

// public:
//     Sprite(const std::string& textureName)
//         : _texture(game->resourceManager().getTexture(textureName))
//     {
//         sf::Sprite::setTexture(_texture);
//     }

//     Sprite(const Sprite& other)
//         : _texture(other._texture)
//     {
//         sf::Sprite::setTexture(_texture);
//     }

//     void setTexture(const std::string& textureName)
//     {
//         _texture = game->resourceManager().getTexture(textureName);
//         sf::Sprite::setTexture(_texture);
//     }

//     ~Sprite() = default;

// };

