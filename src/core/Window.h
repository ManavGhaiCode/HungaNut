#include <iostream>
#include <SDL2/SDL.h>

struct SDL_Window;

namespace Hunga::core {
    class Window {
        public:
            Window() : m_window(nullptr) {};
            ~Window() {
                if (m_window) {
                    ShutDown();
                }
            };

            bool Create() {
                m_window = SDL_CreateWindow("Game!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);

                if (!m_window) {
                    std::cerr << "Error making window: " << SDL_GetError();
                    return 1;
                }

                return 0;
            };

            void ShutDown() {
                SDL_DestroyWindow(m_window);
                m_window = nullptr;
            };

        private:
            SDL_Window* m_window;
    };
}