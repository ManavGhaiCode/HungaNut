#include <iostream>
#include <GLFW/glfw3.h>

#include <log.h>
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
            NUT_ERROR("Unable to Init GLFW");
        }

        NUT_TRACE("Init GLFW");

        if (m_window.Init()) {
            ret = true;
            m_ruinning = true;
        } else {
            NUT_ERROR("Unable to Init Engine");
        }

        return ret;
    }

    void Engine::ShutDown() {
        m_window.ShutDown();
        glfwTerminate();

        NUT_TRACE("Shutdown Engine");
    }

    Engine* Engine::m_Instance = nullptr;
}