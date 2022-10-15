/*
** EPITECH PROJECT, 2022
** ecs_test
** File description:
** main
*/

#include "Game.hpp"
#include "AllComponents.hpp"
#include "AllSystems.hpp"

Game game(800, 600, "Game");

int main(void)
{
    // register component
    game.ecs.registerComp<Transform>();
    game.ecs.registerComp<Sprite>();
    game.ecs.registerComp<Input>();
    // register system
    game._systems.push_back(game.ecs.registerSystem<Players>());
    game._systems.push_back(game.ecs.registerSystem<SystemSprite>());
    game._systems.push_back(game.ecs.registerSystem<SystemTransform>());
    //Set signature
    Signature s;
    s.set(game.ecs.getComponentId<Sprite>(), 1);
    s.set(game.ecs.getComponentId<Transform>(), 1);
    s.set(game.ecs.getComponentId<Input>(), 1);
    game.ecs.setSystemSignature<Players>(s);

    s.set(game.ecs.getComponentId<Transform>(), 0);
    s.set(game.ecs.getComponentId<Input>(), 0);
    game.ecs.setSystemSignature<SystemSprite>(s);

    s.set(game.ecs.getComponentId<Sprite>(), 0);
    s.set(game.ecs.getComponentId<Transform>(), 1);
    game.ecs.setSystemSignature<SystemTransform>(s);

    int e = game.ecs.createEntity();
    game.ecs.addComponent<Transform>(e)->addComponent<Sprite>(e);
    game.ecs.addComponent<Input>(e);
    game.ecs.getComponent<Sprite>(e)->setSprite("../assets/up_down.png");
    getXSprite(e)->getSprite()->setScale(sf::Vector2f{3, 3});
    getXSprite(e)->setRect(sf::IntRect{0, 0, 34, 19}); // +33
    game.run();
    return 0;
}
