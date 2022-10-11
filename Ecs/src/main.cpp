/*
** EPITECH PROJECT, 2022
** ecs_test
** File description:
** main
*/

#include "Game.hpp"
#include "AllComponents.hpp"

EcsApi ecs;
Game game;

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
    // register component
    ecs.registerComp<Transform>();
    ecs.registerComp<Gravity>();
    ecs.registerComp<Sprite>();

    // register system
    auto system = ecs.registerSystem<Players>();
    Signature s;
    std::cout << s << std::endl;
    s.set(ecs.getComponentId<Transform>());
    s.set(ecs.getComponentId<Sprite>());
    std::cout << s << std::endl;

    ecs.setSystemSignature<Players>(s);

    int e = ecs.createEntity();
    ecs.addComponent<Transform>(e);
    ecs.addComponent<Sprite>(e);

    std::cout << "1 = " << getEntityPositionX(e) << std::endl;
    ecs.getComponent<Transform>(e).move(1, 0);
    std::cout << "1 = " << getEntityPositionX(e) << std::endl;

    game.run();

    ecs.getComponent<Sprite>(e).setSprite("soul.png");
    ecs.getComponent<Sprite>(e).draw(game.getWindow()->getWindow());
    
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