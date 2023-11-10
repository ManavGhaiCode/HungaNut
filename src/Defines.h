#ifndef _DEFINES_H_
#define _DEFINES_H_

#include <streambuf>

#ifdef __linux__
    #define NUT_PLATFORM_LINUX
#elif WIN64 || WIN32
    #define NUT_PLATFORM_LINUX
#endif

#endif