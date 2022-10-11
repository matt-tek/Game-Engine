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

enum GameState{
    MENU,
    GAME,
    PAUSE,
    END
};

class StateManager {
    public:
        StateManager() = default;
        ~StateManager() = default;
        void setState(GameState state) {
            _state = state;
        }
        GameState getState() const {
            return _state;
        }
    private:
        GameState _state;
};

class Game {
    public:
        Game() {
            _win = new Window(800, 600, "Game");
            _stateManager = new StateManager();
            _stateManager->setState(MENU);
        };
        ~Game() {
            delete _win;
            delete _stateManager;
        };
        void run() {
            _win->run();
        }
        Window *getWindow() const { return _win; };
    private:
        StateManager *_stateManager;
        Window *_win;
        EcsApi ecs;
};

