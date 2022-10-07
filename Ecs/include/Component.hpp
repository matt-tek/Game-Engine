/*
** EPITECH PROJECT, 2022
** ecs_test
** File description:
** component
*/

#pragma once
#include "Include.hpp"
#include <ostream>

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
        _compInstances[currentEntity] = component;
        _entityToIndex[entity] = currentEntity;
        _indexToEntity[currentEntity] = entity;
        currentEntity++;
        return;
    }

    void removeInstance(int entity)
    {
        size_t lastElem = _compInstances.size() - 1;

        _compInstances[_entityToIndex.at(entity)] = _compInstances[lastElem];
        _indexToEntity.erase(_entityToIndex.at(entity));
        _entityToIndex.erase(entity);
    }
    void printCompInstance() const
    {
        for (auto &i : _compInstances)
            std::cout << "array = " << i << std::endl;
    };
    std::unordered_map<int, int> getIndexToEntityMap() const { return _indexToEntity; };
    std::unordered_map<int, int> getEntityToIndexMap() const { return _entityToIndex; };
    T& getComponent(int entity)
    {
        return _compInstances[_entityToIndex[entity]];
    }

    private:
    std::size_t currentEntity = 0;
    std::array<T, MAX_ENTITIES> _compInstances;
    std::unordered_map<int, int> _indexToEntity;
    std::unordered_map<int, int> _entityToIndex;
};

template <typename T, typename S>
std::ostream& operator<<(std::ostream& os, const std::unordered_map<T, S>&v)
{
    for (auto it : v) 
        os << it.first << " : " << it.second << "\n";
    return os;
}
