/*
** EPITECH PROJECT, 2022
** Game-Engine
** File description:
** EcsApi
*/

#include "ComponentManager.hpp"
#include "EntityManager.hpp"
#include "SystemManager.hpp"

#ifndef ECSAPI_HPP_
#define ECSAPI_HPP_

class EcsApi {
    public:
    EcsApi() {
        _entities = std::make_unique<EntityManager>();
        _components = std::make_unique<ComponentManager>();
        _systems = std::make_unique<SystemManager>();
    }

    int createEntity()
    {
        _entities->createEntity();
    }

    void destroyEntity(int entity)
    {
        _entities->destroyEntity();
    }

    template <typename T>
    void registerComp()
    {
        _components->registerComp();
    }
    private:
    std::unique_ptr<EntityManager> _entities;
    std::unique_ptr<ComponentManager> _components;
    std::unique_ptr<SystemManager> _systems;
};

#endif /* !ECSAPI_HPP_ */
