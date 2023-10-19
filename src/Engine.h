#ifndef _ENGINE_H_
#define _ENGINE_H_ 

#define SDL_LIB "../ThirdParty/SDL/include/SDL.h"

#include SDL_LIB

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

            std::cout << "SDL2 version: " << version.major << "." << version.minor << "." << version.patch << std::endl;
        }

        return ret;
    }

    void ShutDown() {
        SDL_Quit();
    }
}

#endif