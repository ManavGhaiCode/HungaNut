#include <iostream>
#include <SDL2/SDL.h>

#include "./Window.h"
#include "../Engine.h"

struct SDL_Window;

namespace Hunga::core {
    // public
    Window::Window() : m_window(nullptr) {};
    Window::~Window() {
        if (m_window) {
            ShutDown();
        }
    };

    bool Window::Create() {
        m_window = SDL_CreateWindow("Game!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);

        if (!m_window) {
            std::cerr << "Error making window: " << SDL_GetError();
            return 1;
        }

        return 0;
    };

    void Window::ShutDown() {
        SDL_DestroyWindow(m_window);
        m_window = nullptr;
    };

    void Window::PumpEvent() {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    Engine::Instance().Quit();
                    break;
                    
                default:
                    break;
            }
        }
    }
};