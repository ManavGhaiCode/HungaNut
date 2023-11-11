#ifndef _NUTLOGGER_H_
#define _NUTLOGGER_H_

#include <iostream>
#include "./color.h"
#include "./format.h"

namespace Hunga {
    template<typename... Targs>
    void LogTrace(char msg[], Targs ...args) {
        std::cout << WHITE;
        std::cout << format(msg, args...) << std::endl;
    }

    template<typename... Targs>
    void LogDebug(char msg[], Targs ...args) {
        std::cout << BLUE;
        std::cout << format(msg, args...) << std::endl;
    }

    template<typename... Targs> 
    void LogInfo(char msg[], Targs ...args) {
        std::cout << GREEN;
        std::cout << format(msg, args...) << std::endl;
    }

    template<typename... Targs>
    void LogWarn(char msg[], Targs ...args) {
        std::cout << YELLOW;
        std::cout << format(msg, args...) << std::endl;
    }

    template<typename... Targs>
    void LogError(char msg[], Targs ...args) {
        std::cout << RED;
        std::cout << format(msg, args...) << std::endl;
    }

    template<typename... Targs>
    void LogFatal(char msg[], Targs ...args) {
        std::cout << BOLDRED;
        std::cout << format(msg, args...) << std::endl;
    }
}

#endif
