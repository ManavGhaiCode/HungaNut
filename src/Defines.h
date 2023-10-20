#ifndef _DEFINES_H_
#define _DEFINES_H_

#include <stdlib.h>

#define DEBUG
// #define RELEASE

#ifdef __linux__
    #define NUT_PLATFORM_LINUX
#elif _WIN32 || _WIN64
    #define NUT_PLATFORM_WINDOWS
#endif

#define HUNGANUT_DEFAULT_LOGGER_NAME "NutLogger"
#define NUT_BREAK exit(1);

#endif