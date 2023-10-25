#ifndef _MAIN_H_
#define _MAIN_H_

#include <Engine.h>
#include <iostream>

#include <log.h>

int main( void ) {
    NUT_TRACE("Hunga Engine...\n")

    Hunga::Engine& hunga = Hunga::Engine::Instance();
    hunga.Run();

    std::cout << "Please hit ENTER to continue: ";
    std::cin.ignore();

    return 0;
}

#endif