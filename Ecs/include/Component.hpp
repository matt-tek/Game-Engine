/*
** EPITECH PROJECT, 2022
** ecs_test
** File description:
** component
*/

#pragma once
#include "Include.hpp"
#include <ostream>

/**
* @brief simple interface to facilitate entityIsDestroyed
*/
class IcomponentArray {
    public:
    ~IcomponentArray() = default;
    virtual void entityIsDestroyed(int entity) = 0;
};

template<typename T>
class componentArray : public IcomponentArray {
    public:

    /**
    * @brief Insert T component instance to entity
    * @param int entity to be targeted
    * @param T component to be inserted
    */
    void insertInstance(int entity, T component)
    {
        _compInstances[currentEntity] = component;
        _entityToIndex[entity] = currentEntity;
        _indexToEntity[currentEntity] = entity;
        currentEntity++;
        return;
    }

    /**
    * @brief remove entity's component
    * @param int entity to be targeted
    */
    void removeInstance(int entity)
    {
        size_t lastElem = _compInstances.size() - 1;

        _compInstances[_entityToIndex.at(entity)] = _compInstances[lastElem];
        _indexToEntity.erase(_entityToIndex.at(entity));
        _entityToIndex.erase(entity);
    }

    /**
    * @brief print index - entities arrays
    */
    void printCompInstance() const
    {
        for (auto &i : _compInstances)
            std::cout << "array = " << i << std::endl;
    };

    /**
    * @brief get index to entity mao
    */
    std::unordered_map<int, int> getIndexToEntityMap()
    {
        return _indexToEntity;
    };

    /**
    * @brief get entity to index
    */
    std::unordered_map<int, int> getEntityToIndexMap()
    {
        return _entityToIndex;
    };

    /**
    * @brief get entity's component
    * @param int entity to be targeted
    */
    T& getComp(int entity)
    {
        return _compInstances[_entityToIndex[entity]];
    }


    /**
    * @brief removing instance of entity if destroyed
    * @param int entity to be targeted
    */
    void entityIsDestroyed(int entity) override
    {
		if (_entityToIndex.find(entity) != _entityToIndex.end())
		{
			removeInstance(entity);
		}
	}

    private:

    /**
    * @brief index to track current last entity's id
    */
    std::size_t currentEntity = 0;

    /**
    * @brief array containing all existing T components
    */
    std::array<T, MAX_ENTITIES> _compInstances;

    /**
    * @brief map giving entity with given index
    */
    std::unordered_map<int, int> _indexToEntity;

    /**
    * @brief map giving index with given entity
    */
    std::unordered_map<int, int> _entityToIndex;
};

template <typename T, typename S>
std::ostream& operator<<(std::ostream& os, const std::unordered_map<T, S>&v)
{
    for (auto it : v)
        os << it.first << " : " << it.second << "\n";
    return os;
}
