#include <iostream>

#include "./Engine.h"
#include "./Defines.h"

void StartGame() {
    Hunga::Engine& hunga = Hunga::Engine::Instance();
    if (hunga.init()) {} else {
        hunga.ShutDown();
    }

    #ifdef DEBUG
        std::cout << "press enter to continue... ";
        std::cin.ignore();
    #endif
}

int main() {
    StartGame();

    return 0;
}