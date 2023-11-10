#ifndef _MAIN_H_
#define _MAIN_H_

#include "Engine.h"
#include "Defines.h"

#include <iostream>

int main() {
    std::cout << "HungaNut Starting..." << std::endl;

    Hunga::Engine& hunga = Hunga::Engine::Instance();

    return 0;
}

#endif