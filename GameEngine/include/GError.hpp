/*
** EPITECH PROJECT, 2022
** Game-ECS
** File description:
** GError
*/

#pragma once

#include <exception>
#include <iostream>
#include <string>

class GError : public std::exception {
    public:
        /**
         * @brief Construct a new GError object
         * 
         * @param errorType type of the error define by name of the class where the error is throw
         * @param msg error message to know where the error is throw
         */
        GError(const std::string &errorType, const std::string &msg) {
            _errorType = errorType;
            _errorMsg = msg;
        };
        ~GError();
        /**
         * @brief Get the Type of the error
         * 
         * @return const std::string& 
         */
        const std::string &getType() { return _errorType; };
        /**
         * @brief return error message on the standard output
         * 
         * @return const char* 
         */
        const char *what() const noexcept { return _errorMsg.c_str(); };

    protected:
    private:
        std::string _errorType;
        std::string _errorMsg;
};

class WindowError : public GError {
    public:
        WindowError(const std::string &msg) : GError("WindowError", msg) {};
        ~WindowError();
};

class EventError : public GError {
    public:
        EventError(const std::string &msg) : GError("EventError", msg) {};
        ~EventError();
};

class SpriteError : public GError {
    public:
        SpriteError(const std::string &msg) : GError("SpriteError", msg) {};
        ~SpriteError();
};

class InputError : public GError {
    public:
        InputError(const std::string &msg) : GError("InputError", msg) {};
        ~InputError();
};

class MovementError : public GError {
    public:
        MovementError(const std::string &msg) : GError("MovementError", msg) {};
        ~MovementError();
};

class SoundError : public GError {
    public:
        SoundError(const std::string &msg) : GError("SoundError", msg) {};
        ~SoundError();
};

class StateError : public GError {
    public:
        StateError(const std::string &msg) : GError("StateError", msg) {};
        ~StateError();
};