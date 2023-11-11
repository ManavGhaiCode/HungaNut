#ifndef _ENGINE_H_
#define _ENGINE_H_

#include "Window.h"

namespace Hunga {
    class Engine {
        public:
            static Engine& Instance();

            void Run();
            void Quit();

        private:
            bool Init();
            void ShutDown();

            // vars
            bool m_running = false;
            Window m_window;

            // singletin stuff
            static Engine* m_Instance;
            Engine() {};
    };
};

#endif