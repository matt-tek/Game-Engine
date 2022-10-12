/*
** EPITECH PROJECT, 2022
** Game-Engine
** File description:
** SystemManager
*/

#pragma once
#include "Include.hpp"
#include "System.hpp"

class SystemManager {
    public:
        SystemManager() {
            _sysMap = {};
        };

        ~SystemManager() = default;

        /**
        * @brief Register a system to systems pointer array
        */
        template <typename T>
        std::shared_ptr<T> RegisterSystem() {
            const char *tmp = typeid(T).name();
            std::string name = tmp;
            auto system = std::make_shared<T>();

            _sysMap.insert({name, system});
            return system;
        }

        /**
        * @brief set a given system sisgnature
        * @param Signature to be applied
        */
        template<typename T>
        void setSignature(Signature signature)
        {
            _signatureMap[typeid(T).name()] = signature;
        }

        /**
        * @brief removed given entity from system array
        * @param entity to be destroyed
        */
        void entityDestroyed(int entity)
        {
            for (auto const i : _sysMap) {
                if (i.second->entitySet.find(entity) != i.second->entitySet.end())
                    i.second->entitySet.erase(entity);
            }
        }

        /**
        * @brief notify all systems that an entity's signature changed
        * @param entity to be targeted
        * @param signature new signature
        */
        void entityChanged(int entity, Signature signature)
        {
            for (auto const i : _sysMap) {
                if (i.second->entitySet.find(entity) != i.second->entitySet.end()
                    && _signatureMap[i.first] != signature)
                    i.second->entitySet.erase(entity);
                if (i.second->entitySet.find(entity) == i.second->entitySet.end()
                    && _signatureMap[i.first] == signature) {
                    i.second->entitySet.insert(entity);
                }
            }
        }

    protected:
    private:
        /**
        * @brief map giving signature with given system name
        */
        std::unordered_map<std::string, Signature> _signatureMap;

        /**
        * @brief map giving pointer to system with given system name
        */
        std::unordered_map<std::string, std::shared_ptr<System>> _sysMap;

};
