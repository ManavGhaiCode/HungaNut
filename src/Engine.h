#ifndef _ENGINE_H_
#define _ENGINE_H_

#include <core/Window.h>
#include <managers/LogManager.h>
#include <managers/RenderManager.h>

namespace Hunga {
    class Engine {
        public:
            static Engine& Instance(); // for singletin stuff

            void Run(); // To start the game and run Update
            void Quit() { m_running = false; } // To stop the Game

            // For submitting render calls
            inline Managers::RenderManager& GetRenderManager() { return m_RenderManager; }

        private:

            // for internal setup
            [[nodiscard]] bool init();
            void ShutDown();

            // Window refence
            core::Window m_window;

            // managers
            Managers::LogManager m_LogManager;
            Managers::RenderManager m_RenderManager;

            // other vars
            bool m_running = false;
            bool m_IsInit = false;

            Engine() {};
            static Engine* m_instance;
    };
}

#endif