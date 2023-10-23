#ifndef _DEFINES_H_
#define _DEFINES_H_

#define DEBUG
// #define RELEASE

#ifndef __linux__
    #define NUT_PLATFORM_LINUX
#elif WIN32 || WIN64
    #define NUT_PLATFORM_WINDOWS
#endif

#endif