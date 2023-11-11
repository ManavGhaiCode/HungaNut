#include "Engine.h"
#include "Defines.h"

#include <iostream>
#include <string>

#include <SDL2/SDL.h>

namespace Hunga {
    Engine& Engine::Instance() {
        if (m_Instance == nullptr) {
            m_Instance = new Engine();
        }

        return *m_Instance;
    };

    void Engine::Run() {
        if (!Init()) {
            std::cout << "Unable it Init Engine... Shuting Down" << std::endl;
            ShutDown();

            return;
        }

        while (m_running) {
            
        }
        
        ShutDown();
    };

    bool Engine::Init() {
        bool ret = false;

        if (SDL_Init(SDL_INIT_EVERYTHING)) {
            std::cout << "Couldn't create window: " << SDL_GetError() << std::endl;
        }

        if (m_window.Init()) {
            ret = true;
            m_running = true;
        }

        std::cout << "Init Engine..." << std::endl;

        return ret;
    };

    void Engine::ShutDown() {
        m_window.ShutDown();

        SDL_Quit();
        delete m_Instance;
    }

    Engine* Engine::m_Instance = nullptr;
};