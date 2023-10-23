#include <core/Window.h>
#include <Engine.h>

namespace Hunga {
    void Window::Init() {
        m_window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);

        if (!m_window) {
            Engine::Instance().ShutDown();
        }

        glfwMakeContextCurrent(m_window);
    }

    void Window::ShutDown() {
        delete m_window;
    }
}