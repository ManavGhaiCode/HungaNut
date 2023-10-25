#include <log.h>
#include <Engine.h>
#include <SDL2/SDL.h>

#include <iostream>

namespace Hunga {
    // public

    Engine& Engine::Instance() {
        if (m_Instance == nullptr) {
            m_Instance = new Engine();
        }

        return *m_Instance;
    }

    void Engine::Run() {
        if (!Init()) {
            return;
        }

        while (m_running) {
            m_window.PollEvents();
        }
    }

    // priavte

    bool Engine::Init() {
        bool ret = true;

        NUT_TRACE("Initializing SDL...")

        if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
            NUT_ERROR("Could not initialize SDL: ", SDL_GetError());
            ShutDown();
        }

        if (m_window.Init()) {
            ret = true;
        } else {
            std::cout << "Unable to init Engine: " << SDL_GetError() << std::endl;
        }

        return ret;
    }

    void Engine::ShutDown() {
        SDL_Quit();
    }

    Engine* Engine::m_Instance = nullptr;
}