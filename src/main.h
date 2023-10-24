#ifndef _MAIN_H_
#define _MAIN_H_

#include <Engine.h>
#include <iostream>

int main( void ) {
    std::cout << "Hunga Engine...\n" << std::endl;

    Hunga::Engine& hunga = Hunga::Engine::Instance();
    hunga.Init();

    std::cout << "Please hit ENTER to continue: ";
    std::cin.ignore();

    return 0;
}

#endif