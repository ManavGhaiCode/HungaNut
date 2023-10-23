#include <iostream>

#include <GLFW/glfw3.h>
#include <Engine.h>

namespace Hunga {   
    Engine& Engine::Instance() {
        if (!m_Instance) {
            m_Instance = new Engine();
        }

        return *m_Instance;
    }

    void Engine::Run() {
        if (!Init()) {
            return;
        }

        while (m_ruinning) {
            glClear(GL_COLOR_BUFFER_BIT);

            double r = 0.39;
            double g = 0.58;
            double b = 0.92;

            glClearColor(r, g, b, 1.0);

            m_window.SwapBuffers();
            glfwPollEvents();
        }

        ShutDown();
    }

    bool Engine::Init() {
        bool ret = false;        

        if (!glfwInit()) {
            std::cout << "Unable to init glfw" << std::endl;
        }

        std::cout << "init glfw" << std::endl;

        if (m_window.Init()) {
            ret = true;
            m_ruinning = true;
        }

        return ret;
    }

    void Engine::ShutDown() {
        m_window.ShutDown();
        glfwTerminate();
    }

    Engine* Engine::m_Instance = nullptr;
}