#ifndef _ENGINE_H_
#define _ENGINE_H_ 

#include "./Defines.h"
#include "./core/Window.h"

#include <iostream>

#ifdef NUT_PLATFORM_LINUX
    #include <SDL2/SDL.h>
#elif NUT_PLATFORM_WINDOWS
    #include "../ThirdParty/SDL/include/SDL.h"
#endif

namespace Hunga {
    class Engine {
        public:
            static Engine& Instance() {
                if (!m_instance) {
                    m_instance = new Engine();
                }

                return *m_instance;
            }

            bool init() {
                bool ret = true;
        
                if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
                    std::cerr << "Error in intializing SDL2: " << SDL_GetError() << std::endl;
                    ret = false;
                } else {
                    SDL_version version;
                    SDL_VERSION(&version);

                    std::cout << "SDL2 version: " << (int32_t)version.major << "." << (int32_t)version.minor << "." << (int32_t)version.patch << std::endl;
                }

                if (!m_window.Create()) {
                    ret = false;
                }

                return ret;
            }

            void ShutDown() {
                m_window.ShutDown();
                SDL_Quit();
            }

        private:
            core::Window m_window;

            Engine() {};
            static Engine* m_instance;
    };
}

Hunga::Engine* Hunga::Engine::m_instance = nullptr;

#endif