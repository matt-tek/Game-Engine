/*
** EPITECH PROJECT, 2022
** Game-Engine
** File description:
** AllSystems
*/

#pragma once

#include "Define.hpp"
#include "AllComponents.hpp"

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
        getXSprite(p)->getSprite()->setScale(sf::Vector2f{2, 2});
        game.ecs.getComponent<Transform>(p)->setPos(sf::Vector2f{
            getXTransform(entity)->getPos().x + 110,
            getXTransform(entity)->getPos().y + 26
        });
        getXTransform(p)->setVeclocity(sf::Vector2f{8.0f, 0.0f});
        getXSprite(p)->getSprite()->setPosition(getXTransform(p)->getPos());
    }

    void move(int off_x, int off_y, sf::Keyboard::Key k)
    {
        if (sf::Keyboard::isKeyPressed(k)) {
            getXTransform(0)->moveOffset(off_x, off_y);
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
        return;
    }
    private:
        sf::Vector2f vel = {2, 0};
};

class SystemTransform : public System {
    public:
    void update(void)
    {
        for (size_t i = 0; i < game.ecs.getLivingEntities().size(); i++) {
            if (game.ecs.entityHasComponent<Transform>(i)) {
                getXTransform(i)->move();
                if (game.ecs.entityHasComponent<Sprite>(i))
                    getXSprite(i)->getSprite()->setPosition(getXTransform(i)->getPos());
            }
        }
        return;
    }
    private:
};

class SystemSprite : public System {
    public:
    void update(void)
    {
        for (size_t i = 0; i < game.ecs.getLivingEntities().size(); i++) {
            if (game.ecs.entityHasComponent<Sprite>(i)) {
                getXSprite(i)->draw(game.getWindow());
            }
        }
        return;
    }
    private:
};