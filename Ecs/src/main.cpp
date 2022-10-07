/*
** EPITECH PROJECT, 2022
** ecs_test
** File description:
** main
*/

#include "entity.hpp"
#include "component.hpp"

int main(void)
{
    componentArray<int> test;

    test.insertInstance(0, 100);
    test.insertInstance(1, 200);
    test.insertInstance(2, 300);
    test.insertInstance(3, 400);
    test.insertInstance(4, 500);

    std::cout << "entity to index\n" << test._entityToIndex << std::endl;
    std::cout << "index to entity\n" << test._indexToEntity << std::endl;

    test.removeInstance(2);

    std::cout << "entity to index\n" << test._entityToIndex << std::endl;
    std::cout << "index to entity\n" << test._indexToEntity << std::endl;
    test.printCompInstance();
    return 0;
}