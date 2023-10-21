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

#include <cstdint>

#include <core/graphics/mesh.h>
#include <core/graphics/shader.h>

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
            // test mesh
float vertices[]
            {
                 0.5f,  0.5f, 0.f,
                 0.5f, -0.5f, 0.f,
                -0.5f, -0.5f, 0.f,
                -0.5f,  0.5f, 0.f
            };
            uint32_t elements[]
            {
                0, 3, 1,
                1, 3, 2
            };
            std::shared_ptr<Graphics::Mesh> mesh = std::make_shared<Graphics::Mesh>(&vertices[0], 4, 3, &elements[0], 6);

            // Test Shader
            const char* vertexShader = R"(
                #version 410 core
                layout (location = 0) in vec3 position;
                out vec3 vpos;
                void main()
                {
                    vpos = position + vec3(0.5, 0.5, 0);
                    gl_Position = vec4(position, 1.0);
                }
            )";

            const char* fragmentShader = R"(
                #version 410 core
                out vec4 outColor;
                in vec3 vpos;
                uniform vec3 color = vec3(0.0);
                void main()
                {
                    outColor = vec4(vpos, 1.0);
                }
            )";

            std::shared_ptr<Graphics::Shader> shader = std::make_shared<Graphics::Shader>(vertexShader, fragmentShader);
            shader->SetUniformFloat3("color", 1, 0, 0);

            m_RenderManager.SetWireFrameMode(true);

            m_window.PumpEvent();
            m_window.StartRender();

            auto rc = std::make_unique<Graphics::RenderMesh>(mesh, shader);
            m_RenderManager.Submit(std::move(rc));

            m_RenderManager.Flush();
            m_window.EndRender();
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
            // start Mangers
            m_RenderManager.init();

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

        // Manager shutdown - should be done in reverse order
        m_RenderManager.ShutDown();
        m_LogManager.ShutDown();

        // SDL ShutDown
        m_window.ShutDown();
        SDL_Quit();
    }

    Engine* Engine::m_instance = nullptr;
}