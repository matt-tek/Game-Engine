/*
** EPITECH PROJECT, 2022
** Game-Engine
** File description:
** Game
*/

#pragma once

#include "Include.hpp"
#include "EcsApi.hpp"
#include "Window.hpp"

class Game {
    public:
        Game() {
            _win = new Window(800, 600, "Game");
        };
        ~Game() {
            delete _win;
        };
        void run() {
            _win->run();
        }
        Window *getWindow() const { return _win; };
        EcsApi ecs;
        std::vector<std::shared_ptr<System>> _systems;
    private:
        Window *_win;
};