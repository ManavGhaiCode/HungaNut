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
        Init();
    }

    void Engine::Init() {
        if (!glfwInit()) {
            std::cout << "Unable to init glfw" << std::endl;
        }

        std::cout << "init glfw" << std::endl;
    }

    void Engine::ShutDown() {
        glfwTerminate();
    }

    Engine* Engine::m_Instance = nullptr;
}