#include <Defines.h>
#include <core/Window.h>

#include <iostream>

#ifdef NUT_PLATFORM_LINUX
    #include <SDL2/SDL.h>
#elif NUT_PLATFORM_WINDOWS
    #include <SDL/include/SDL.h>
#endif

#include <log.h>
#include <Engine.h>

namespace Hunga {
    Engine& Engine::Instance() {
        if (!m_instance) {
            m_instance = new Engine();
        }

        return *m_instance;
    }

    void Engine::Run() {
        // init the window
        if (!init()) {
            ShutDown();
            return;
        }

        // main game loop def
        while (m_running) {
            m_window.PumpEvent();
        }

        ShutDown();
    }

    bool Engine::init() {
        bool ret = true;
        m_LogManager.init();
        
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
            std::cerr << "Error in intializing SDL2: " << SDL_GetError() << std::endl;
            ret = false;
        }

        #ifdef DEBUG
            SDL_version version;
            SDL_VERSION(&version);
        #endif

        NUT_TRACE("HungaNut v{}.{}", 0, 1);
        std::cout << "SDL2 version: " << (int32_t)version.major << "." << (int32_t)version.minor << "." << (int32_t)version.patch << std::endl;


        if (!m_window.Create()) {
            ret = false;
        }

        return ret;
    }

    void Engine::ShutDown() {
        // not allowing the game to runn any more
        m_running = false;

        // Manager shutdown
        m_LogManager.ShutDown();

        // SDL ShutDown
        m_window.ShutDown();
        SDL_Quit();
    }

    Engine* Engine::m_instance = nullptr;
}