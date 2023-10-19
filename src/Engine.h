#ifndef _ENGINE_H_
#define _ENGINE_H_

#include <core/Window.h>
#include <managers/LogManager.h>

namespace Hunga {
    class Engine {
        public:
            static Engine& Instance(); // for singletin stuff

            void Run(); // To start the game and run Update
            void Quit() { m_running = false; } // To stop the Game

        private:

            // for internal setup
            bool init();
            void ShutDown();

            // Window refence
            core::Window m_window;

            // managers
            Managers::LogManager m_LogManager;

            // other vars
            bool m_running = true;

            Engine() {};
            static Engine* m_instance;
    };
}

#endif