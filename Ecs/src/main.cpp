/*
** EPITECH PROJECT, 2022
** ecs_test
** File description:
** main
*/

#include "Game.hpp"

EcsApi ecs;

struct Transform {
    sf::Vector2f _pos;
    float _rotate;
};

struct Gravity {
    sf::Vector2f _pos;
    float _rotate;
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

    int e = ecs.createEntity();
    Transform t;
    ecs.addComponent<Transform>(e, t);
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