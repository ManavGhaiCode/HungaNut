#ifndef _ENGINE_H_
#define _ENGINE_H_

#include "Scene.h"
#include "Window.h"
#include "Input/InputManager.h"
#include "Events/EventManager.h"
#include "Renderer/Renderer.h"

namespace Hunga {
    class Engine {
        public:
            static Engine& Instance();

            void Run();
            inline void Quit() { m_running = false; };
            inline InputManager& GetInputManager() { return m_InputManager; };
            inline EventManager& GetEventManager() { return m_EventManager; };
            inline SDL_Window& GetWidnow() { return *m_window.GetWindow(); };
            inline Renderer& GetRenderer() { return m_Renderer; };

        private:
            bool Init();
            void ShutDown();

            // vars
            bool m_running = false;
            Renderer m_Renderer;
            Window m_window;
            Scene m_Scene;

            // Managers
            InputManager m_InputManager;
            EventManager m_EventManager;

            // singletin stuff
            static Engine* m_Instance;
            Engine() {};
    };

    extern void CreateScene(Scene& scene);

    extern void GameEnd();
    extern void GameStart();
    extern void GameUpdate();
};

#endif