/*
** EPITECH PROJECT, 2022
** ecs_test
** File description:
** main
*/

#include "Game.hpp"
#include "AllComponents.hpp"
#include "AllSystems.hpp"

Game game(600, 800, "Game");

int main(void)
{
    // register component
    game.ecs.registerComp<Transform>();
    game.ecs.registerComp<Sprite>();
    game.ecs.registerComp<Input>();
    // register system
    game._systems.push_back(game.ecs.registerSystem<Players>());
    game._systems.push_back(game.ecs.registerSystem<Projectiles>());
    //Set signature
    Signature s;
    s.set(game.ecs.getComponentId<Sprite>(), 1);
    s.set(game.ecs.getComponentId<Transform>(), 1);
    s.set(game.ecs.getComponentId<Input>(), 1);
    game.ecs.setSystemSignature<Players>(s);

    s.set(game.ecs.getComponentId<Input>(), 0);
    game.ecs.setSystemSignature<Projectiles>(s);

    int e = game.ecs.createEntity();
    game.ecs.addComponent<Transform>(e)->addComponent<Sprite>(e);
    game.ecs.addComponent<Input>(e);
    game.ecs.getComponent<Sprite>(e)->setSprite("../assets/up_down.png");
    getXSprite(e)->getSprite()->setScale(sf::Vector2f{3, 3});
    getXSprite(e)->setRect(sf::IntRect{0, 0, 34, 19}); // +33

    game.run();
    return 0;
}





/*     sf::RenderWindow *_window = new sf::RenderWindow(sf::VideoMode(800, 600), "toto");

    while (_window->isOpen()) {
        sf::Event event;
        while (_window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                _window->close();
        }
        game.ecs.getComponent<Transform>(e).move(1.0f, 0.0f);
        game.ecs.getComponent<Sprite>(e).draw(_window);
        _window->display();
    } */
/*     componentArray<int> test;

    test.insertInstance(0, 100);
    test.insertInstance(1, 200);
    test.insertInstance(2, 300);
    test.insertInstance(3, 400);
    test.insertInstance(4, 500);

    std::cout << "entity to index\n" << test.getEntityToIndexMap() << std::endl;
    std::cout << "index to entity\n" << test.getIndexToEntityMap() << std::endl;

    test.removeInstance(2);/o index\n" << test.getEntityToIndexMap() << std::endl;
    std::cout << "index to entity\n" << test.getIndexToEntityMap() << std::endl;
    test.printCompInstance(); */