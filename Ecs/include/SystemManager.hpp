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
        ~SystemManager();
        template <typename T>
        std::shared_ptr<T> RegisterSystem() {
            std::string name = typeid(T).name();
            
            auto system = std::make_shared<T>();
            _signatureMap.insert({name, _sysMap})
        }

    protected:
    private:
        std::unordered_map<std::string, Signature> _signatureMap;
        std::unordered_map<std::string, std::shared_ptr<System>> _sysMap;

};
