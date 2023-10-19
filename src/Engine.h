#ifndef _ENGINE_H_
#define _ENGINE_H_

#include "./core/Window.h"

namespace Hunga {
    class Engine {
        public:
            static Engine& Instance();

            void Run();

            void Quit() { m_running = false; }

        private:
            bool init();

            void ShutDown();

            core::Window m_window;
            bool m_running = true;

            Engine() {};
            static Engine* m_instance;
    };
}

#endif