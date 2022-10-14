/*
** EPITECH PROJECT, 2022
** Game-Engine
** File description:
** AllSystems
*/

#pragma once

#include "Define.hpp"
#include "AllComponents.hpp"

#ifndef ALLSYSTEMS_HPP_
#define ALLSYSTEMS_HPP_

extern Game game;

class Players : public System {
    public:
    void createShoot(int entity)
    {
        int p = game.ecs.createEntity();
        game.ecs.addComponent<Transform>(p);
        game.ecs.addComponent<Sprite>(p);
        getXSprite(p)->setSprite("../assets/player.png");
        getXSprite(p)->setRect(sf::IntRect{0, 0, 16, 9});
        game.ecs.getComponent<Transform>(p)->setPos(getXTransform(entity)->getPos());
        getXSprite(p)->getSprite()->setPosition(getXTransform(p)->getPos());
    }
    void move(int off_x, int off_y, sf::Keyboard::Key k)
    {
        if (sf::Keyboard::isKeyPressed(k)) {
            getXTransform(0)->move(off_x, off_y);
            getXSprite(0)->getSprite()->setPosition(getXTransform(0)->getPos());
        }
    }
    void update(void)
    {
        move(0, -10, sf::Keyboard::Key::Z);
        move(-10, 0, sf::Keyboard::Key::Q);
        move(0, 10, sf::Keyboard::Key::S);
        move(10, 0, sf::Keyboard::Key::D);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            createShoot(0);
        for (int i = 0; i < (int)entitySet.size(); i++) {
            game.ecs.getComponent<Transform>(i);
        }
        return;
    }
    private:
};

class Projectiles : public System {
    public:
    void update(void)
    {
        return;
    }
    private:
};

#endif /* !ALLSYSTEMS_HPP_ */
