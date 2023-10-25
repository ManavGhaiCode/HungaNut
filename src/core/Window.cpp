#include <core/Window.h>
#include <Engine.h>
#include <log.h>

#include <SDL2/SDL.h>

namespace Hunga {
    bool Window::Init() {
        m_window = SDL_CreateWindow("Window!", 
            SDL_WINDOWPOS_UNDEFINED, 
            SDL_WINDOWPOS_UNDEFINED, 
            800, 600, 0
        );

        if (m_window == nullptr) {
            NUT_ERROR("Could not init Window: ", SDL_GetError())
            return false;
        }

        return true;
    }

    void Window::ShutDown() {
        SDL_DestroyWindow(m_window);
        m_window = nullptr;
    }

    void Window::PollEvents() {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                Engine::Instance().Quit();
            }
        }
    }
}