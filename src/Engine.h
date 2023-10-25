#ifndef _ENGINE_H_
#define _ENGINE_H_

#include <core/Window.h>
#include <core/Renderer.h>

struct SDL_Window;

namespace Hunga {
    class Engine {
        public:
            // for singletin
            static Engine& Instance();
            void Run();

            inline SDL_Window& SDL_GetWindow() { return m_window.GetWindow(); };

        private:
            // function
            // void GetInfo();
            bool Init();
            void ShutDown();

            // Window
            Window m_window;
            Hunga::Renderer m_renderer;

            // other vars
            static Engine* m_Instance;
            bool m_running = false;

            Engine() {};
    };
}

#endif