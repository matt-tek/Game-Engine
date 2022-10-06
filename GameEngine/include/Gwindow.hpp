/*
** EPITECH PROJECT, 2022
** Game-ECS
** File description:
** Gwindow
*/

#ifndef GWINDOW_HPP_
#define GWINDOW_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <string>
#include <unordered_map>
#include "GError.hpp"
#include "Gsprite.hpp"

class Gwindow {
    public:
        /**
         * @brief Construct a new Gwindow object
         * 
         * @param width width of the window
         * @param height height of the window
         * @param title name of the window
         */

        Gwindow(const int &width, const int &height, const std::string &title) {
            _width = width;
            _height = height;
            _windowName = title;
            _window = new sf::RenderWindow(sf::VideoMode(_width, _height), _windowName);
            _window->setFramerateLimit(60);
        };
        ~Gwindow() {
            delete _window;
        };
        void run() {
            while (_window->isOpen()) {
                sf::Event event;
                while (_window->pollEvent(event)) {
                    if (event.type == sf::Event::Closed)
                        _window->close();
                }
                
                _window->clear();
                _window->display();
            }
        };
        void addDrawableElement(Gsprite &sprite) {
            _renderObject.push_back(sprite);
        };
        /**
         * @brief getters
         */
        std::string getWindowName() const { return _windowName; };
        int getWidth() const { return _width; };
        int getHeight() const { return _height; };
        sf::RenderWindow *getWindow() const { return _window; };
        /**
         * @brief setters
         */
        void setWindowName(const std::string &windowName) { _windowName = windowName; };
        void setWidth(const int &width) { _width = width; };
        void setHeight(const int &height) { _height = height; };
        
    protected:
    private:
        std::string _windowName;
        sf::RenderWindow *_window;
        int _width;
        int _height;
        /**
         * @brief vector and map maybe to keep track of drawable object
         * 
         */
        std::vector<Gsprite> _renderObject;
};

#endif /* !GWINDOW_HPP_ */
