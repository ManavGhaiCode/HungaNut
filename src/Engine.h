#ifndef _ENGINE_H_
#define _ENGINE_H_ 

#include "./Defines.h"

#include <iostream>

#ifdef NUT_PLATFORM_LINUX
    #include <SDL2/SDL.h>
#elif NUT_PLATFORM_WINDOWS
    #include "../ThirdParty/SDL/include/SDL.h"
#endif

namespace Hunga {
    int Sub(int a, int b) {
        return a - b;
    }

    bool init() {
        bool ret;

        if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
            std::cerr << "Error in intializing SDL2: " << SDL_GetError() << std::endl;
        } else {
            SDL_version version;
            SDL_VERSION(&version);

            std::cout << "SDL2 version: " << (int32_t)version.major << "." << (int32_t)version.minor << "." << (int32_t)version.patch << std::endl;
        }

        return ret;
    }

    void ShutDown() {
        SDL_Quit();
    }
}

#endif