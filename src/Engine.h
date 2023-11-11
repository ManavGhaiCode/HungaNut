#ifndef _ENGINE_H_
#define _ENGINE_H_

#include "Window.h"
#include "Input/InputManager.h"

namespace Hunga {
    class Engine {
        public:
            static Engine& Instance();

            void Run();
            inline void Quit() { m_running = false; };

        private:
            bool Init();
            void ShutDown();

            // vars
            bool m_running = false;
            Window m_window;

            // Managers
            InputManager m_InputManager;

            // singletin stuff
            static Engine* m_Instance;
            Engine() {};
    };
};

#endif