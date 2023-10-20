#ifndef _WINDOW_H_
#define _WINDOW_H_

struct SDL_Window;
using SDL_GLContext = void*;

namespace Hunga::core {
    class Window {
        public:
            Window();
            ~Window();

            bool Create();
            void ShutDown();
            void PumpEvent();

        private:
            SDL_Window* m_window;
            SDL_GLContext m_GLContext;
    };
}

#endif