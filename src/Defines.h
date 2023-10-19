#ifndef _DEFINES_H_
#define _DEFINES_H_

#ifdef __linux__
    #define NUT_PLATFORM_LINUX
#elif _WIN32 || _WIN64
    #define NUT_PLATFORM_WINDOWS
#endif

#endif