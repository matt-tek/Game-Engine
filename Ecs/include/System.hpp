/*
** EPITECH PROJECT, 2022
** Game-Engine
** File description:
** System
*/

#include "Include.hpp"

#ifndef SYSTEM_HPP_
#define SYSTEM_HPP_

/**
* @brief generic to be inherited from to create systems
*/
class System {
    public:
    std::set<int> entitySet;
};

#endif /* !SYSTEM_HPP_ */
