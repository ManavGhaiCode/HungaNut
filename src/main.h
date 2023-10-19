#include <iostream>
#include "./Engine.h"

void StartGame() {
    Hunga::init();
}

int main() {
    std::cout << "Hello World" << std::endl;
    StartGame();
    Hunga::ShutDown();

    return 0;
}