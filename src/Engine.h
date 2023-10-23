#ifndef _ENGINE_H_
#define _ENGINE_H_

#include <core/Window.h>

namespace Hunga {
    class Engine {
        public:
            static Engine& Instance(); // for singletin stuff
            void Run(); // for running the game
        private:

            bool Init(); // Init function
            void ShutDown(); // for turning off the game

            // void GetInfo(); // for Debug

            // for singletin stuff
            Engine() {};

            // window
            Window m_window;

            // other vars
            static Engine* m_Instance;
            bool m_ruinning = false;
    };
}

#endif