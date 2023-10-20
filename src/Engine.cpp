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
    // public

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

    // private

    bool Engine::init() {
        NUT_ASSERT(!m_IsInit, "Engine::init() called more than once... ")

        bool ret = false;
        m_LogManager.init();

        NUT_TRACE("HungaNut v{}.{}.{}", 0, 0, 1);
        
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
            NUT_ERROR("Error in intializing SDL2: {}", SDL_GetError());
        }

        #ifdef DEBUG
            SDL_version version;
            SDL_VERSION(&version);

            NUT_INFO("SDL2 version: v{}.{}.{}", (int32_t)version.major, (int32_t)version.minor, (int32_t)version.patch);
        #endif

        if (m_window.Create()) {
            ret = true;
            m_IsInit = true;
            m_running = true;
        }

        if (!ret) {
            NUT_ERROR("Error in initializing Engine shuting down");
            ShutDown();
        }

        return ret;
    }

    void Engine::ShutDown() {
        // not allowing the game to runn any more
        m_running = false;
        m_IsInit = false;

        // Manager shutdown
        m_LogManager.ShutDown();

        // SDL ShutDown
        m_window.ShutDown();
        SDL_Quit();
    }

    Engine* Engine::m_instance = nullptr;
}