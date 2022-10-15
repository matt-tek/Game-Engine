/*
** EPITECH PROJECT, 2022
** Game-Engine
** File description:
** EcsApi
*/

#pragma once
#include "ComponentManager.hpp"
#include "EntityManager.hpp"
#include "SystemManager.hpp"

#ifndef ECSAPI_HPP_
#define ECSAPI_HPP_

using namespace std;

/**
* @brief class grouping all managers
*/
class EcsApi {
    public:
    EcsApi() {
        _entities = std::make_unique<EntityManager>();
        _components = std::make_unique<ComponentManager>();
        _systems = std::make_unique<SystemManager>();
    }

    /**
    * @brief return newly assiocated entity's id
    */
    int createEntity()
    {
        _livingEntities.push_back(_entities->createEntity());
        return _livingEntities[_livingEntities.size() - 1];
    }

    std::vector<int> getLivingEntities(void)
    {
        return _livingEntities;
    }

    /**
    * @brief destroy an entity
    * @param int entity to be destroyed
    */
    void destroyEntity(int entity)
    {
        _livingEntities.erase(std::remove(_livingEntities.begin(), _livingEntities.end(), entity), _livingEntities.end());
        _entities->destroyEntity(entity);
    }

    /**
    * @brief register a component in the game engine
    */
    template <typename T>
    void registerComp()
    {
        _components->registerComp<T>();
    }

    /**
    * @brief add a component to an entity
    * @param int entity to be targeted
    * @param T generic type component to be added
    */
    template <typename T>
    EcsApi *addComponent(int entity)
    {
        Signature replace;

        _components->addComp<T>(entity);
        replace = _entities->getSignature(entity);
        replace.set(_components->getCompTypeId<T>(), true);
        _entities->setSignature(entity, replace);
        _systems->entityChanged(entity, replace);
        return this;
    }

    /**
    * @brief remove component from entity, entityt's signature will change
    * @param int entity to be targeted
    */
    template <typename T>
    void removeComponent(int entity)
    {
        Signature replace;

        _components->deleteComp<T>(entity);
        replace.set(_components->getCompTypeId<T>(), false);
        _entities->setSignature(entity, replace);
    }

    /**
    * @brief return sprecified entity's component
    * @param int entity to be targeted
    */
    template <typename T>
    T *getComponent(int entity)
    {
        return &_components->getComp<T>(entity);
    }

    /**
    * @brief get specified component id
    */
    template <typename T>
    int getComponentId()
    {
        return _components->getCompTypeId<T>();
    }

    /**
    * @brief Register a system to the game engine
    */
    template <typename T>
    std::shared_ptr<T> registerSystem()
    {
        return _systems->RegisterSystem<T>();
    }

    /**
    * @brief set a system's signature
    * @param Signature new signature to be applied
    */
    template <typename T>
    void setSystemSignature(Signature signature)
    {
        _systems->setSignature<T>(signature);
    }

    Signature getSignature(int entity)
    {
        return _entities->getSignature(entity);
    }

    template <typename T>
    bool entityHasComponent(int entity)
    {
        Signature s = _entities->getSignature(entity);

        if (s[_components->getCompTypeId<T>()] == 1)
            return true;
        return false;
    }

    std::unique_ptr<ComponentManager> _components;

    private:

    std::vector<int> _livingEntities;

    /**
    * @brief pointer to entity manager class
    */
    std::unique_ptr<EntityManager> _entities;

    /**
    * @brief pointer to component manager class
    */

    /**
    * @brief pointer to system manager class
    */
    std::unique_ptr<SystemManager> _systems;
};

#endif /* !ECSAPI_HPP_ */
