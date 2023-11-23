#include "log.h"
#include "Engine.h"
#include "Window.h"

#include <iostream>
#include <SDL2/SDL.h>

namespace Hunga {
    bool Window::Init() {
        m_window = SDL_CreateWindow("Window!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_VULKAN);

        if (m_window == nullptr) {
            NUT_ERROR("Unable to Init window", SDL_GetError());
            return false;
        }

        return true;
    }

    void Window::ShutDown() {
        SDL_DestroyWindow(m_window);
    }

    void Window::PollEvents() {
        SDL_Event event;

        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                Engine::Instance().Quit();
            }
        }
    }
}