#ifndef _DEFINES_H_
#define _DEFINES_H_

#include <stdlib.h>

#define DEBUG
#define RELEASE

#ifdef __linux__
    #define NUT_PLATFORM_LINUX
#elif WIN64 || WIN32
    #define NUT_PLATFORM_LINUX
#endif

#define NUT_BREAK std::exit(1);

struct SDL_Texture;
typedef SDL_Texture Sprite;

#endif