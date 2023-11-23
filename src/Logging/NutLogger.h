#ifndef _NUTLOGGER_H_
#define _NUTLOGGER_H_

#include <iostream>
#include <string>

#include "./color.h"
#include "./format.h"

namespace Nut {
    template<typename... Targs>
    void LogTrace(const std::string& msg, Targs ...args) {
        std::cout << WHITE;
        std::cout << format(msg, args...) << std::endl;
    }

    template<typename... Targs>
    void LogDebug(const std::string& msg, Targs ...args) {
        std::cout << BLUE;
        std::cout << format(msg, args...) << std::endl;
    }

    template<typename... Targs> 
    void LogInfo(const std::string& msg, Targs ...args) {
        std::cout << GREEN;
        std::cout << format(msg, args...) << std::endl;
    }

    template<typename... Targs>
    void LogWarn(const std::string& msg, Targs ...args) {
        std::cout << YELLOW;
        std::cout << format(msg, args...) << std::endl;
    }

    template<typename... Targs>
    void LogError(const std::string& msg, Targs ...args) {
        std::cout << RED;
        std::cout << format(msg, args...) << std::endl;
    }

    template<typename... Targs>
    void LogFatal(const std::string& msg, Targs ...args) {
        std::cout << BOLDRED;
        std::cout << format(msg, args...) << std::endl;
    }
}

#endif
