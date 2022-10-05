/*
** EPITECH PROJECT, 2022
** Game-ECS
** File description:
** main
*/

#include <iostream>
#include <memory>
#include "Gwindow.hpp"
#include "Gsprite.hpp"

int main(void)
{
    std::unique_ptr<Gwindow> window = std::make_unique<Gwindow>(1920, 1080, "Game-ECS");
    std::unique_ptr<Gsprite> sprite = std::make_unique<Gsprite>("assets/soul.png.png", "player");
    std::cout << "hello world" << std::endl;
    window->run();
    return 0;
}