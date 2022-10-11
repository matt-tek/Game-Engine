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
    Transform() = default;
    void move(float off_x, float off_y) {
        _pos.x += off_x;
        _pos.y += off_y;
    }
    sf::Vector2f getPos(void) const
    {
        return _pos;
    }

    float getRotation(void) const
    {
        return _rotate;
    }
    private:
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
    ecs.addComponent<Transform>(e);
    std::cout << "1 = " << getEntityPositionX(e) << std::endl;
    ecs.getComponent<Transform>(e).move(1, 0);
    std::cout << "1 = " << getEntityPositionX(e) << std::endl;

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