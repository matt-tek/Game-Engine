/*
** EPITECH PROJECT, 2022
** Game-Engine
** File description:
** Game
*/

#pragma once

#include "AllComponents.hpp"
#include "Include.hpp"
#include "EcsApi.hpp"

class Game {
    public:
        Game(const int &width, const int &height, const std::string &title) {
            _width = width;
            _height = height;
            _windowName = title;
            _window = new sf::RenderWindow(sf::VideoMode(_width, _height), _windowName);
            _window->setFramerateLimit(60);
        };

        ~Game() {
            delete _window;
        };

        void update() {
            return;
        };

        sf::RenderWindow *getWindow(void)
        {
            return _window;
        }

        void run() {
            while (_window->isOpen()) {
                sf::Event event;
                while (_window->pollEvent(event)) {
                    if (event.type == sf::Event::Closed)
                        _window->close();
                }
                _window->clear();
                for (size_t y = 0; y < _systems.size(); y++) {
                    _systems[y]->update();
                }
                _window->display();
                usleep(1000);
            }
        }
        EcsApi ecs;
        std::vector<std::shared_ptr<System>> _systems;
    private:
        /**
         * @brief window name
         */
        std::string _windowName;
        /**
         * @brief window from SFML library
         */
        sf::RenderWindow *_window;
        /**
         * @brief width of the window
         */
        int _width;
        /**
         * @brief height of the window
         */
        int _height;
};