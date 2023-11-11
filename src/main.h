#ifndef _MAIN_H_
#define _MAIN_H_

#include "log.h"
#include "Engine.h"
#include "Defines.h"

#include <iostream>

int main() {
    NUT_TRACE("HungaNut Starting...");

    Hunga::Engine& hunga = Hunga::Engine::Instance();
    hunga.Run();

    NUT_TRACE("Press ENTER to continue...");
    std::cin.ignore();

    return 0;
}

#endif