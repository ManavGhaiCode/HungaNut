#ifndef _DEFINES_H_
#define _DEFINES_H_

#include <cstdint>
#include <stdlib.h>

// Defines

#define DEBUG
#define RELEASE

#define MAX_ENTITIES 10000u
#define MAX_COMPONENTS 100u

#ifdef __linux__
    #define NUT_PLATFORM_LINUX
#elif WIN64 || WIN32
    #define NUT_PLATFORM_LINUX
#endif

#define NUT_BREAK std::exit(1);
#define NUT_TYPEOF(Type) #Type

// typedefs

typedef uint16_t _HungaEntity;

#endif