/*
** EPITECH PROJECT, 2022
** ecs_test
** File description:
** ecs
*/

#pragma once
#include "Include.hpp"

class EntityManager {
    public:
    /**
    * @brief Initialize all entities to i starting from 0
    *
    */
    EntityManager(void)
    {
        for (int i = 0; i < MAX_ENTITIES; i++)
            _entities.push(i);
    }

    /**
    * @brief Attribute _entities front element to returned entity
    *
    */
    int createEntity(void)
    {
        int ret = _entities.front();

        _entities.pop();
        return ret;
    }

    /**
    * @brief put destroyed entity's id at the back of _entities
    *
    * @param int entity to be destroyed
    */
    void destroyEntity(int entity)
    {
        _entities.push(entity);
        _signatures[entity].reset();
    }

    /**
    * @brief define an entity's signature
    *
    * @param int entity to be targeted
    * @param bitset signature to be applied
    */
    void setSignature(int entity, std::bitset<MAX_COMPONENTS> signature)
    {
        _signatures[entity] = signature;
    }

    /**
    * @brief return an entity's signature
    *
    * @param int entity to be targeted
    */
    std::bitset<MAX_COMPONENTS> getSignature(int entity)
    {
        return _signatures[entity];
    }

    private:

    /**
    * @brief queue of all id_free entities
    */
    std::queue<int> _entities;

    /**
    * @brief array conatining entitie's signatures
    */
    std::array<std::bitset<MAX_COMPONENTS>, MAX_ENTITIES> _signatures;
};
