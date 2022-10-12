/*
** EPITECH PROJECT, 2022
** ecs_test
** File description:
** main
*/

#include "Game.hpp"
#include "AllComponents.hpp"

Game game;

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

class Sprite {
    public:
        Sprite() = default;
        ~Sprite() = default;
        void setSprite(const std::string &path) {
            _texture.loadFromFile(path);
            _sprite.setTexture(_texture);
        }
        sf::Sprite getSprite(void) const { return _sprite; }
        void draw(sf::RenderWindow *window) {
            window->draw(_sprite);
        }
    private:
        sf::Texture _texture;
        sf::Sprite _sprite;
};

int main(void)
{
    // register component
    game.ecs.registerComp<Transform>();
    game.ecs.registerComp<Sprite>();

    // register system
    game._systems.push_back(game.ecs.registerSystem<Players>());

    //Set signature
    Signature s;
    s.set(game.ecs.getComponentId<Sprite>(), 1);
    s.set(game.ecs.getComponentId<Transform>(), 1);
    game.ecs.setSystemSignature<Players>(s);

    int e = game.ecs.createEntity();
    game.ecs.addComponent<Transform>(e);
    game.ecs.addComponent<Sprite>(e);

    game.ecs.getComponent<Sprite>(e).setSprite("../../assets/soul.png");

    sf::RenderWindow *_window = new sf::RenderWindow(sf::VideoMode(800, 600), "toto");

    while (_window->isOpen()) {
        sf::Event event;
        while (_window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                _window->close();
        }
        _window->clear();
        for (auto i : game._systems[0]->entitySet) {
            game.ecs.getComponent<Sprite>(i).draw(_window);
        }
        _window->display();
        usleep(1000);
    }
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