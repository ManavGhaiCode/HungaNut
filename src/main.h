#ifndef _MAIN_H_
#define _MAIN_H_

#include <iostream>
#include <Engine.h>

int main() {
    Hunga::Engine& hunga = Hunga::Engine::Instance();
    hunga.Run();

    std::cout << "Type ENTER to exit: ";
    std::cin.ignore();

    return 0;
}

#endif