#include "log.h"
#include "Engine.h"
#include "Defines.h"
#include "Input/KeyBinds.h"

#include <iostream>
#include <thread>
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
            NUT_ERROR("Unable it Init Engine... Shuting Down");
            ShutDown();

            return;
        }

        while (m_running) {
            m_window.PollEvents();
            m_InputManager.Update();

            if (m_InputManager.GetButton(MouseKeys::Left)) {
                NUT_TRACE("left was pressed");
            }
        }
        
        ShutDown();
    };

    bool Engine::Init() {
        bool ret = false;

        if (SDL_Init(SDL_INIT_EVERYTHING)) {
            NUT_ERROR("Couldn't create window: ", SDL_GetError());
        }

        if (m_window.Init()) {
            ret = true;
            m_running = true;
        }

        NUT_TRACE("Init Engine...");

        return ret;
    };

    void Engine::ShutDown() {
        m_window.ShutDown();

        SDL_Quit();
        delete m_Instance;
    }

    Engine* Engine::m_Instance = nullptr;
};