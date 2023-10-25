#include <core/Window.h>
#include <SDL2/SDL.h>

namespace Hunga {
    bool Window::Init() {
        m_window = SDL_CreateWindow("Window!", 
            SDL_WINDOWPOS_UNDEFINED, 
            SDL_WINDOWPOS_UNDEFINED, 
            800, 600, 0
        );

        if (m_window == nullptr) {
            return false;
        }

        return true;
    }

    void Window::ShutDown() {
        SDL_DestroyWindow(m_window);
        m_window = nullptr;
    }
}