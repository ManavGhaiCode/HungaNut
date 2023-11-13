#ifndef _ENGINE_H_
#define _ENGINE_H_

#include "Window.h"
#include "Input/InputManager.h"
#include "Renderer/Renderer.h"

namespace Hunga {
    class Engine {
        public:
            static Engine& Instance();

            void Run();
            inline void Quit() { m_running = false; };
            inline SDL_Window& GetWidnow() { return *m_window.GetWindow(); };
            inline Renderer& GetRenderer() { return m_Renderer; };

        private:
            bool Init();
            void ShutDown();

            // vars
            bool m_running = false;
            Renderer m_Renderer;
            Window m_window;

            // Managers
            InputManager m_InputManager;

            // singletin stuff
            static Engine* m_Instance;
            Engine() {};
    };

    extern void GameStart();
    extern void GameUpdate();
};

#endif