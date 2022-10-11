/*
** EPITECH PROJECT, 2022
** ecs_test
** File description:
** main
*/

#include "Game.hpp"

EcsApi ecs;

class Transform {
    public:
    sf::Vector2f _pos = {0.0f, 0.0f};
    float _rotate = 0.0f;
};

class Gravity {
    public:
    Gravity *getComponent(void)
    {
        return this;
    }
    sf::Vector2f _pos = {0.0f, 0.0f};
    float _rotate = 0.0f;
};

class Players : public System {
    public:
    void update(void)
    {
        for (int i = 0; i < (int)entitySet.size(); i++) {
            ecs.getComponent<Transform>(i);
        }
        return;
    }
    private:
};

int main(void)
{
    ecs.registerComp<Transform>();
    ecs.registerComp<Gravity>();

    auto system = ecs.registerSystem<Players>();
    Signature s;
    std::cout << s << std::endl;
    s.set(ecs.getComponentId<Transform>());
    std::cout << s << std::endl;
    ecs.setSystemSignature<Players>(s);
    ecs._components->getCompClassPtr<Gravity>();

    int e = ecs.createEntity();
    int e2 = ecs.createEntity();
    Transform t;
    ecs.addComponent<Transform>(e, t);
    std::cout << "1 = " << ecs.getComponent<Transform>(e)._pos.x << std::endl;
    ecs.getComponent<Transform>(e)._pos.x = 1.0f;
    std::cout << "1 = " << ecs.getComponent<Transform>(e)._pos.x << std::endl;

    ecs.addComponent<Transform>(e2, t);
    std::cout << "2 = " << ecs.getComponent<Transform>(e2)._pos.x << std::endl;
    ecs.getComponent<Transform>(e2)._pos.x = 3.0f;
    std::cout << "2 = " << ecs.getComponent<Transform>(e2)._pos.x << std::endl;

    std::cout << "1 = " << ecs.getComponent<Transform>(e)._pos.x << std::endl;
    std::cout << "2 = " << ecs.getComponent<Transform>(e2)._pos.x << std::endl;
    return 0;
}





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