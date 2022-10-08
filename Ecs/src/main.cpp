/*
** EPITECH PROJECT, 2022
** ecs_test
** File description:
** main
*/

#include "EntityManager.hpp"
#include "ComponentManager.hpp"
#include "SystemManager.hpp"

int main(void)
{
/*     componentArray<int> test;

    test.insertInstance(0, 100);
    test.insertInstance(1, 200);
    test.insertInstance(2, 300);
    test.insertInstance(3, 400);
    test.insertInstance(4, 500);

    std::cout << "entity to index\n" << test.getEntityToIndexMap() << std::endl;
    std::cout << "index to entity\n" << test.getIndexToEntityMap() << std::endl;

    test.removeInstance(2);

    std::cout << "entity to index\n" << test.getEntityToIndexMap() << std::endl;
    std::cout << "index to entity\n" << test.getIndexToEntityMap() << std::endl;
    test.printCompInstance(); */
    std::unordered_map<std::string, int> map;

    map.insert({"toto", 1});
    std::cout << map["toto"] << std::endl;
    map.insert({"toto", 2});
    std::cout << map["toto"] << std::endl;
    std::cout << map.find("toto")->second << std::endl;
    return 0;
}