#ifndef _WINDOW_H_
#define _WINDOW_H_

struct SDL_Window;
namespace Hunga {
    class Window {
        public:
            bool Init();
            void ShutDown();

        private:
            SDL_Window *m_window;
    };
};

#endif