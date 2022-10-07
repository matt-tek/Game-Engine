/*
** EPITECH PROJECT, 2022
** ecs_test
** File description:
** ecs
*/

#pragma once
#include "Include.hpp"

class entityManager {
    public:
    entityManager(void)
    {
        for (int i = 0; i < MAX_ENTITIES; i++)
            _entities.push(i);
    }

    int createEntity(void)
    {
        int ret = _entities.front();

        _entities.pop();
        return ret;
    }

    void destroyEntity(int entity)
    {
        _entities.push(entity);
        _signatures[entity].reset();
    }

    void setSignature(int entity, std::bitset<MAX_COMPONENTS> signature)
    {
        _signatures[entity] = signature;
    }

    std::bitset<MAX_COMPONENTS> getSignature(int entity)
    {
        return _signatures[entity];
    }

    private:
    std::queue<int> _entities;
    std::array<std::bitset<MAX_COMPONENTS>, MAX_ENTITIES> _signatures;
};
