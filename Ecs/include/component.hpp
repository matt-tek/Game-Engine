/*
** EPITECH PROJECT, 2022
** ecs_test
** File description:
** component
*/

#include "include.hpp"

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

class IcomponentArray {
    public:
    ~IcomponentArray() = default;
    virtual void entityIsDestroyed(int entity) = 0;
};

template<typename T>
class componentArray : public IcomponentArray {
    public:
    void entityIsDestroyed(int entity) override {
        return;
    }

    void insertInstance(int entity, T component)
    {
        compInstances[lastElem] = component;
        entityToIndex[entity] = lastElem;
        indexToEntity[lastElem] = entity;
        lastElem++;
        return;
    }

    void removeInstance(int entity)
    {
        entityToIndex[0].erase();
    }

    private:
    int lastElem = 0;
    std::array<T, MAX_ENTITIES> compInstances;
    std::unordered_map<int, int> indexToEntity;
    std::unordered_map<int, int> entityToIndex;
};

#endif /* !COMPONENT_HPP_ */
