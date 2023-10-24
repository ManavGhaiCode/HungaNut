#include <Engine.h>
#include <SDL2/SDL.h>

#include <iostream>

namespace Hunga {
    Engine& Engine::Instance() {
        if (m_Instance == nullptr) {
            m_Instance = new Engine();
        }

        return *m_Instance;
    }

    bool Engine::Init() {
        bool ret = true;

        std::cout << "Initializing SDL..." << std::endl;

        if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
            std::cout << "Could not initialize SDL: " << SDL_GetError() << std::endl;
            ShutDown();
        }

        std::cout << "SDL initialized" << std::endl;

        return ret;
    }

    void Engine::ShutDown() {
        SDL_Quit();
    }

    Engine* Engine::m_Instance = nullptr;
}