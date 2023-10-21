#include <iostream>
#include <SDL2/SDL.h>
#include <glad/glad.h>

#include <core/Window.h>
#include <Engine.h>
#include <log.h>

struct SDL_Window;

namespace Hunga::core {
    // public
    Window::Window() : m_window(nullptr) {};
    Window::~Window() {
        if (m_window) {
            ShutDown();
        }
    };

    bool Window::Create() {
        m_window = SDL_CreateWindow( "Game!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 
        SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

        if (!m_window) {
            NUT_ERROR("Error in make the game window: {}", SDL_GetError());
            return false;
        }

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

        SDL_SetWindowMinimumSize(m_window, 200, 200);
        m_GLContext = SDL_GL_CreateContext(m_window);

        if (m_GLContext == nullptr) {
            NUT_ERROR("Error in making the current window context: {}", SDL_GetError());
            return false;
        }

        gladLoadGLLoader(SDL_GL_GetProcAddress);

        return true;
    };

    void Window::ShutDown() {
        SDL_DestroyWindow(m_window);
        SDL_GL_DeleteContext(m_GLContext);
        m_window = nullptr;
    };

    void Window::PumpEvent() {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    Engine::Instance().Quit();
                    break;
                    
                default:
                    break;
            }

            Engine::Instance().GetInputManager().Update();
        }
    }

    void Window::StartRender() {
        Engine::Instance().GetRenderManager().Clear();
    }

    void Window::EndRender() {
        SDL_GL_SwapWindow(m_window);
    }
};