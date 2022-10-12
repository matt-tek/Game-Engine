/*
** EPITECH PROJECT, 2022
** Game-Engine
** File description:
** AllSystems
*/

#pragma once

#include "AllComponents.hpp"

#ifndef ALLSYSTEMS_HPP_
#define ALLSYSTEMS_HPP_

extern Game game;

class Players : public System {
    public:
    void update(void)
    {
        for (int i = 0; i < (int)entitySet.size(); i++) {
            game.ecs.getComponent<Transform>(i);
        }
        return;
    }
    private:
};

#endif /* !ALLSYSTEMS_HPP_ */
