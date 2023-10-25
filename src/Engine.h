#ifndef _ENGINE_H_
#define _ENGINE_H_

#include <core/Window.h>

namespace Hunga {
    class Engine {
        public:
            // for singletin
            static Engine& Instance();
            void Run();

        private:
            // function
            // void GetInfo();
            bool Init();
            void ShutDown();

            // Window
            Window m_window;

            // other vars
            static Engine* m_Instance;
            bool m_running = false;

            Engine() {};
    };
}

#endif