/*
** EPITECH PROJECT, 2022
** Game-Engine
** File description:
** componentManager
*/

#pragma once
#include "Include.hpp"
#include "Component.hpp"

#ifndef COMPONENTMANAGER_HPP_
#define COMPONENTMANAGER_HPP_

class ComponentManager {
    public:

    /**
    * @brief register T component to _registeredComp
    */
    template<typename T>
    void registerComp()
    {
        _registeredComp.insert({typeid(T).name(), currentComp});
        _componentsPtrArr.insert({typeid(T).name(), std::make_shared<componentArray<T>>()});
        currentComp++;
    }

    /**
    * @brief get T component's id with its name
    */
    template<typename T>
    int getCompTypeId()
    {
        return _registeredComp[typeid(T).name()];
    }

    /**
    * @brief add T component to entity
    * @param int entity to be targeted
    * @param T component to be attached to entity
    */
    template<typename T>
    void addComp(int entity)
    {
        T obj;

        getCompPtr<T>()->insertInstance(entity, obj);
    }


    /**
    * @brief remove T component from entity
    * @param int entity to be targeted
    * @param T component to be removed
    */
    template<typename T>
    void deleteComp(int entity)
    {
        getCompPtr<T>()->removeInstance(entity);
    }

    /**
    * @brief get component from entity
    * @param int entity to be targeted
    */
    template<typename T>
    T& getComp(int entity)
    {
        return getCompPtr<T>()->getComp(entity);
    }

    /**
    * @brief return casted pointer to given component with component's name
    */
    template<typename T>
	std::shared_ptr<componentArray<T>> getCompPtr()
	{
		return std::static_pointer_cast<componentArray<T>>
            (_componentsPtrArr[typeid(T).name()]);
	}

    /**
    * @brief remove entity if destroyed
    * @param entity to be targeted
    */
    void EntityDestroyed(int entity)
	{
		for (auto const& pair : _componentsPtrArr)
		{
			auto const& component = pair.second;

			component->entityIsDestroyed(entity);
		}
	}

    template<typename T>
    T *getCompClassPtr(void)
    {
        T object;

        return object.getComponent();
    }
    private:

    /**
    * @brief map giving index with component's name
    */
    std::unordered_map<const char*, int> _registeredComp;

    /**
    * @brief array of pointers to components
    */
    std::unordered_map<const char*, std::shared_ptr<IcomponentArray>> _componentsPtrArr;

    /**
    * @brief index to track current last component's id
    */
    std::size_t currentComp = 0;
};

#endif /* !COMPONENTMANAGER_HPP_ */
