/*
** EPITECH PROJECT, 2022
** ecs_test
** File description:
** main
*/

#include "Game.hpp"
#include "AllComponents.hpp"

Game game(600, 800, "Game");

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

int main(void)
{
    // register component
    game.ecs.registerComp<Transform>();
    game.ecs.registerComp<Sprite>();
    game.ecs.registerComp<Input>();
    // register system
    game._systems.push_back(game.ecs.registerSystem<Players>());
    //Set signature
    Signature s;
    s.set(game.ecs.getComponentId<Sprite>(), 1);
    s.set(game.ecs.getComponentId<Transform>(), 1);
    s.set(game.ecs.getComponentId<Input>(), 1);
    game.ecs.setSystemSignature<Players>(s);

    int e = game.ecs.createEntity();
    game.ecs.addComponent<Transform>(e);
    game.ecs.addComponent<Sprite>(e);
    game.ecs.addComponent<Input>(e);
    game.ecs.getComponent<Sprite>(e).setSprite("../../assets/soul.png");
    game.ecs.getComponent<Input>(e).registerInput(sf::Keyboard::Key::Z, []() { std::cout << "la moukat" << std::endl; });
    game.ecs.getComponent<Input>(e).registerInput(sf::Keyboard::Key::Q, []() { std::cout << "tete frai" << std::endl; });
    game.ecs.getComponent<Input>(e).registerInput(sf::Keyboard::Key::S, []() { std::cout << "zef" << std::endl; });
    game.ecs.getComponent<Input>(e).registerInput(sf::Keyboard::Key::D, []() { std::cout << "fichtre" << std::endl; });


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