#include <core/Window.h>
#include <Engine.h>

namespace Hunga {
    bool Window::Init() {
        bool ret = false;

        m_window = glfwCreateWindow(640, 480, "Window!", NULL, NULL);
        glfwMakeContextCurrent(m_window);

        if (m_window) {
            ret = true;
        }

        return ret;
    }

    void Window::ShutDown() {
        m_window = nullptr;
    }

    void Window::SwapBuffers() {
        glfwSwapBuffers(m_window);
    }
}