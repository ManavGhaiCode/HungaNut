#include "log.h"
#include "Engine.h"
#include "Defines.h"
#include "Input/KeyBinds.h"
#include "API/Rendering.h"

#include <iostream>
#include <thread>
#include <string>
#include <chrono>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

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

        GameStart();

        while (m_running) {
            auto start = std::chrono::high_resolution_clock::now();

            m_window.PollEvents();
            m_InputManager.Update();

            GameUpdate();

            m_Renderer.Update();

            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> deltaTime = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);

            // NUT_TRACE(std::to_string(deltaTime.count()));
            // NUT_TRACE(std::to_string(1 / deltaTime.count()));
        }
        
        ShutDown();
    };

    bool Engine::Init() {
        bool ret = false;

        if (SDL_Init(SDL_INIT_VIDEO)) {
            NUT_ERROR("Couldn't Init SDL: ", SDL_GetError());
        }

        if (!IMG_Init(IMG_INIT_PNG)) {
            NUT_ERROR("Couldn't Init SDL_image: ", IMG_GetError());
            return ret;
        }

        if (m_window.Init()) {
            ret = true;
            m_running = true;
            m_Renderer.Init();
        }

        NUT_TRACE("Init Engine...");

        return ret;
    };

    void Engine::ShutDown() {
        m_window.ShutDown();
        m_Renderer.ShutDown();

        SDL_Quit();
        delete m_Instance;
    }

    Engine* Engine::m_Instance = nullptr;
};