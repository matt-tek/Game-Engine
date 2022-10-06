/*
** EPITECH PROJECT, 2022
** Game-ECS
** File description:
** Gstate
*/

#pragma once

/**
 * @brief GameState class
 * @note This class is used to manage all the game state
 */
enum class GameState {
    MENU,
    GAME,
    PAUSE,
    END
};

class Gstate {
    public:
        Gstate();
        ~Gstate();

    protected:
    private:
};
