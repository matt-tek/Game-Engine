/*
** EPITECH PROJECT, 2022
** ecs_test
** File description:
** define
*/

#ifndef DEFINE_HPP_
#define DEFINE_HPP_

#include <bitset>
#include <memory>
#include <unistd.h>

#define MAX_ENTITIES 5000
#define MAX_COMPONENTS 20

/**
* @brief get entity's x position
* @param int entity to be targeted
*/
#define getEntityPositionX(a) ecs.getComponent<Transform>(a).getPos().x

/**
* @brief get entity's y position
* @param int entity to be targeted
*/
#define getEntityPositionY(a) ecs.getComponent<Transform>(a).getPos().y

#define getXTransform(x) game.ecs.getComponent<Transform>(x)
#define getXSprite(x) game.ecs.getComponent<Sprite>(x)

/**
* @brief Signaature showing attached compoonents
*/
using Signature = std::bitset<MAX_COMPONENTS>;

#endif /* !DEFINE_HPP_ */
