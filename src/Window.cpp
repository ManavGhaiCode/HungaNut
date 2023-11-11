#include "Window.h"

#include <iostream>
#include <SDL2/SDL.h>

namespace Hunga {
    bool Window::Init() {
        m_window = SDL_CreateWindow("Window!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);

        if (m_window == nullptr) {
            std::cout << "Unable to Init window" << std::endl;
            return false;
        }

        return true;
    }

    void Window::ShutDown() {
        SDL_DestroyWindow(m_window);
    }
}