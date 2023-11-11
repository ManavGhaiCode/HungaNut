#ifndef _DEFINES_H_
#define _DEFINES_H_

#include <streambuf>

#define DEBUG
#define RELEASE

#ifdef __linux__
    #define NUT_PLATFORM_LINUX
#elif WIN64 || WIN32
    #define NUT_PLATFORM_LINUX
#endif

#endif